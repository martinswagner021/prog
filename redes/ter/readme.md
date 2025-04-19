# Procolo

## Regra de negócio
- porta do servidor 8888
- cada cliente com sua porta
- todas as mensagens do protocolo recebem uma resposta
- multitarefa, múltiplos clientes podem comunicar-se ao mesmo tempo
- conversa P2P
- conversa broadcast

cliente se apresenta -> servidor fornece lista -> cliente envia mensagem broadcast | direcionada -> cliente desconecta

## Requisitos não funcionais
- protocolo TCP para transporte

## Estrutura global da mensagem

len;tipo;...

- separador ';'
- len primeiro
- tipo (apresentação, lista, dados, desconexão)

### Mensagem apresentação para o servidor
- ip origem
- porta origem
- nome ou identificação

### Mensagem de desconexão

### Lista
- Em qualquer alteração de conexão ou desconexão
- Broadcast

- NOME1:IP1:PORTA1,NOME2:IP2:PORTA2,NOME:IP3:PORTA3

### Dados
- nome origem
- mensagem

## Duvidas
- IP e fornecido aos clientes, já seria conhecido?
- cliente falar com mais de um cliente p2p?
- mesma porta para o cliente apresentar ao servidor e outro cliente?
- se um host perde conexão, posso ignorar o host pendurado?
- preciso saber se recebi um broadcast?