import asyncio
import grpc
import pubsub_pb2
import pubsub_pb2_grpc

async def subscribe(stub, client_id):
    request = pubsub_pb2.SubscribeRequest(client_id=client_id)
    async for message in stub.Subscribe(request):
        print(f"Received message for {client_id}: {message.message}")

async def publish(stub, message):
    request = pubsub_pb2.PublishRequest(message=message)
    response = await stub.Publish(request)
    print(f"Server response: {response.message}")

async def main():
    async with grpc.aio.insecure_channel("localhost:50051") as channel:
        stub = pubsub_pb2_grpc.PubSubServiceStub(channel)
        
        # Start the subscriber
        client_id = "client1"
        asyncio.create_task(subscribe(stub, client_id))

        # Publish some messages
        await asyncio.sleep(1)  # Delay to allow subscribe task to start
        await publish(stub, "Hello, world!")
        await publish(stub, "Another message")
        await asyncio.sleep(3)  # Delay to keep the program running

if __name__ == "__main__":
    asyncio.run(main())
