import grpc
import pubsub_pb2
import pubsub_pb2_grpc

def run():  
    channel = grpc.insecure_channel('localhost:50051')
    stub = pubsub_pb2_grpc.PubSubServiceStub(channel)
    for message in stub.Subscribe(pubsub_pb2.SubscribeRequest(torcida="flamengo")):
        print("Mensagem recebida: " + message.message)

if __name__ == '__main__':
    run()