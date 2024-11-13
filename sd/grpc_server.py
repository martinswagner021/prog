import asyncio
import grpc
import pubsub_pb2
import pubsub_pb2_grpc

class PubSubService(pubsub_pb2_grpc.PubSubServiceServicer):
    def __init__(self):
        self.subscribers = []

    async def Subscribe(self, request, context):
        client_id = request.client_id
        subscriber_queue = asyncio.Queue()
        self.subscribers.append(subscriber_queue)
        try:
            while True:
                message = await subscriber_queue.get()
                yield pubsub_pb2.Message(client_id=client_id, message=message)
        finally:
            self.subscribers.remove(subscriber_queue)

    async def Publish(self, request, context):
        message = request.message
        for subscriber in self.subscribers:
            await subscriber.put(message)
        return pubsub_pb2.Message(client_id="server", message="Message sent to subscribers.")

async def serve():
    server = grpc.aio.server()
    pubsub_pb2_grpc.add_PubSubServiceServicer_to_server(PubSubService(), server)
    server.add_insecure_port("[::]:50051")
    await server.start()
    await server.wait_for_termination()

if __name__ == "__main__":
    asyncio.run(serve())
