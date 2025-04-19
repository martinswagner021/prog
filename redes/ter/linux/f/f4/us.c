// No codeblocks inclua no menu em: Project -> Build Options... -> Linker settings -> Other link options -l wsock32
//#define WIN // Se não for no windows comente essa linha e compile no terminal: gcc -o us us.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef WIN
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

#define TAM_MENSAGEM 255     /* mensagem de maior tamanho */

#define PORTA_SERVIDOR_UDP 8888

int criar_socket(int porta)
{
    int sock;
    struct sockaddr_in endereco; /* Endereço Local */

    /* Criação do socket datagrama/UDP para recepção e envio de pacotes */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        printf("\nErro na criação do socket!\n");fflush(stdout);
        return(-1);
    }

    if (porta > 0)
    {
        /* Construção da estrutura de endereço local */
        memset(&endereco, 0, sizeof(endereco));       /* Zerar a estrutura */
        endereco.sin_family      = AF_INET;           /* Família de endereçamento da Internet */
        endereco.sin_addr.s_addr = htonl(INADDR_ANY); /* Qualquer interface de entrada */
        endereco.sin_port        = htons(porta);      /* Porta local */

        /* Instanciar o endereco local */
        if (bind(sock, (struct sockaddr *) &endereco, sizeof(endereco)) < 0)
        {
           printf("\nErro no bind()!\n");fflush(stdout);
           return(-1);
        }
    }

    return(sock);
}


int receber_mensagem(char *mensagem,int sock,struct sockaddr_in *endereco)
{
    /* Define o tamanho do endereço de recepção e envio */
    int tamanho_endereco  = sizeof(struct sockaddr_in);

    /* Limpar o buffer da mensagem */
    memset((void *) mensagem,(int) NULL,TAM_MENSAGEM);

    /* Espera pela recepção de alguma mensagem de algum cliente */
    if (recvfrom(sock, mensagem, TAM_MENSAGEM - 1, 0,
            (struct sockaddr *) endereco, &tamanho_endereco) < 0)
    {
        printf("\nErro na recepção da mensagem\n");fflush(stdout);
        return(-1);
    }

    printf("\nUDP Servidor: Recebi (%s)\n",mensagem);fflush(stdout);

    return(0);
}

int enviar_mensagem(char *mensagem,int sock,struct sockaddr_in *endereco)
{
    /* Devolve o conteúdo do datagrama para o cliente */
    if (sendto(sock, mensagem, strlen(mensagem), 0,
             (struct sockaddr *) endereco, sizeof(struct sockaddr)) != strlen(mensagem))
    {
        printf("\nErro no envio da mensagem\n");fflush(stdout);
        return(-1);
    }

    printf("\nUDP Servidor: Enviei (%s)\n",mensagem);fflush(stdout);

    return(0);
}

int main()
{
    int                sock;                   /* Socket */
    int                resultado;              /* Resultado das funções */
    struct sockaddr_in endereco;               /* Endereço do Cliente */
    char               mensagem[TAM_MENSAGEM]; /* Buffer para a recepção da string de echo */
#ifdef WIN
    WORD wPackedValues;
    WSADATA  SocketInfo;
    int      nLastError,
	         nVersionMinor = 1,
	         nVersionMajor = 1;
    wPackedValues = (WORD)(((WORD)nVersionMinor)<< 8)|(WORD)nVersionMajor;
    nLastError = WSAStartup(wPackedValues, &SocketInfo);
#endif

    sock = criar_socket(PORTA_SERVIDOR_UDP);
    if (sock < 0)
    {
        printf("\nErro na criação do socket!\n");
        return(1);
    }


    for (;;) /* Loop eterno */
    {
        /* Recebe mensagem do cliente */
        resultado = receber_mensagem(mensagem,sock,&endereco);
        if (resultado < 0)
        {
            printf("\nErro no recebimento da mensagem\n");
            return(1);
        }

        /* Devolve a mensagem para o cliente */
        resultado = enviar_mensagem(mensagem,sock,&endereco);
        if (resultado < 0)
        {
            printf("\nErro no envio da mensagem\n");
            return(1);
        }
    }
    /* não passa por aqui */
}
