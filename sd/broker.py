import grpc
import asyncio

import pubsub_pb2
import pubsub_pb2_grpc

class PubSubService(pubsub_pb2_grpc.PubSubServiceServicer):
    def __init__(self):
        self.subscribers = {}

    async def Subscribe(self, request, context):
        torcida = request.torcida
        if torcida not in self.subscribers:
            self.subscribers[torcida] = []
        subscriber_queue = asyncio.Queue()
        self.subscribers[torcida].append(subscriber_queue)
        print(self.subscribers.items())
        while True:
            message = await subscriber_queue.get()
            yield message

    async def Publish(self, request, context):
        torcida = request.torcida
        message = request.message
        if torcida in self.subscribers:
            for subscriber in self.subscribers[torcida]:
                await subscriber.put(pubsub_pb2.Message(torcida=torcida, message=message))
        return pubsub_pb2.Message(message=f"Mensagem enviada aos torcedores do {request.torcida}.")

async def serve():
    server = grpc.aio.server()
    pubsub_pb2_grpc.add_PubSubServiceServicer_to_server(PubSubService(), server)
    server.add_insecure_port('[::]:50051')
    await server.start()
    await server.wait_for_termination()

if __name__ == '__main__':
    asyncio.run(serve())