# Procolo Caramelo

## Tamanho da mensagem
Toda mensagem trocada inicia-se com 3 bytes para definir o tamanho da mensagem.

## Separador
Os campos das mensagens serão separados por ';'

## Estruturas e exemplos
### Mensagem de apresentação (Tipo 0)
Enviada para conectar-se ao chat.

**tamanho ; tipo ; ip origem ; porta escutando ; nome ou identificação**

Ex: 028;0;111.111.111.111;9999;joão

### Mensagem de desconexão (Tipo 1)
Enviada para desconectar-se do chat.

**tamanho ; tipo ; ip origem**

Ex: 018;1;111.111.111.111

### Mensagem lista (Tipo 2)
Enviada a partir do servidor para todos os hosts conectados atualizarem suas listas de pessoas no chat.

**tamanho ; tipo ; ip 1 : porta 1 : nome 1 ; ip 2 : porta 2 : nome 2**

Ex: 059;2;111.111.111.111:9999:Fulano;222.222.222.222:9999:Ciclano

### Mensagem chat
Enviada de um usuário para o outro, pode ser direcionada a um usuário, ou todos que estejam no chat.

**tamanho ; tipo ; ip origem ; porta origem ; nome origem ; mensagem**

#### Privada (Tipo 3)

Ex: 039;3;111.111.111.111;9999;Fulano;mensagem

#### Broadcast (Tipo 4)

Ex: 039;4;111.111.111.111;9999;Fulano;mensagem