# Procolo Caramelo

## Regra de negócio
- porta do servidor 8888
- cada cliente com sua porta
- todas as mensagens do protocolo recebem uma resposta
- multitarefa, múltiplos clientes podem comunicar-se ao mesmo tempo
- conversa P2P
- conversa broadcast
- [STR-Tok](https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/)

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
- ip origem
- nome ou identificação

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


## Protocolo W

PS: Sempre começam com 3 caracteres para definir o tamanho da mensagem

### Tipos de mensagem
- Mensagem de apresentação: Tipo = 0
- Mensagem de desconexão: Tipo = 1
- Mensagem de tabela: Tipo = 2
- Mensagem de chat privado: Tipo = 3
- Mensagem de chat broadcast: Tipo = 4

### Mensagem de apresentação
tamanho;tipo;ip origem;porta escutando;nome ou identificação

999;0;111.111.111.111;9999;joão

### Mensagem de desconexão
tamanho;tipo;ip origem
999;1;111.111.111.111

### Mensagem lista
tamanho;tipo;IP1:PORTA1:NOME1,IP2:PORTA2:NOME2,IP2:PORTA2:NOME2
999;2;111.111.111.111:9999:Fulano,222.222.222.222:9999:Ciclano

tamanho;tipo;IP1:PORTA1:NOME1;IP2:PORTA2:NOME2;IP2:PORTA2:NOME2
999;2;111.111.111.111:9999:Fulano,222.222.222.222:9999:Ciclano

### Mensagem chat
tamanho;tipo;ip origem;porta origem;nome origem;mensagem

#### Privada
999;3;111.111.111.111;9999;Fulano;mensagem

#### Broadcast
999;4;111.111.111.111;9999;Fulano;mensagem

### 
