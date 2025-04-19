#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LINE 100

typedef struct {
    char data[MAX_LINE];
    int empty;
} Buffer;

Buffer input_buffer;
Buffer output_buffer;

// Os primeiros estão guardando os buffers
pthread_mutex_t input_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t output_mutex = PTHREAD_MUTEX_INITIALIZER;

// São sinais que indicam que os foram colocados dados nos buffers
pthread_cond_t input_produced = PTHREAD_COND_INITIALIZER;
pthread_cond_t input_consumed = PTHREAD_COND_INITIALIZER;

// São sinais que indicam que os foram retiradps dados nos buffers
pthread_cond_t output_produced = PTHREAD_COND_INITIALIZER;
pthread_cond_t output_consumed = PTHREAD_COND_INITIALIZER;

int file_complete = 0;

void* reader_thread(void* arg) {
    FILE* input_file = fopen((char*)arg, "r");
    if (!input_file) {
        perror("Falha ao abrir o arquivo de input");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), input_file)) {
        line[strcspn(line, "\n")] = '\0';

        // Espero o buffer esvaziar
        pthread_mutex_lock(&input_mutex);
        while (!input_buffer.empty) {
            pthread_cond_wait(&input_consumed, &input_mutex);
        }

        // Escreve no buffer
        strcpy(input_buffer.data, line);
        input_buffer.empty = 0;
        
        // Sinais que o buffer pode ser usado
        pthread_cond_signal(&input_produced);
        pthread_mutex_unlock(&input_mutex);
    }

    pthread_mutex_lock(&input_mutex);
    file_complete = 1;
    pthread_cond_signal(&input_produced);
    pthread_mutex_unlock(&input_mutex);

    fclose(input_file);
    return NULL;
}

void* processor_thread(void* arg) {
    while (1) {
        // Aguardar buffer de entrada ter dado
        // Protege o buffer the input antes de checar o estado do buffer para que não tenha nenhuma outra thread alterando
        pthread_mutex_lock(&input_mutex); 
        while (input_buffer.empty && !file_complete) {
            // deixa outros utilizarem o buffer, e ota a thread para dormir, quando aciono bloqueia o buffer novamente
            pthread_cond_wait(&input_produced, &input_mutex); 
        }

        if (file_complete && input_buffer.empty) {
            pthread_mutex_unlock(&input_mutex); // Libera o buffer para evitar deadlock
            break;
        }

        // Pega os dados
        char line[MAX_LINE];
        strcpy(line, input_buffer.data);
        input_buffer.empty = 1;
        
        // Sinal do buffer vazio
        pthread_cond_signal(&input_consumed); // Acorda a thread esperando essa condição
        pthread_mutex_unlock(&input_mutex); // Libera o buffer para uso

        // Processamento
        for (int i = 0; line[i]; i++) {
            line[i] = toupper(line[i]);
        }

        // Aguarda o buffer de output estar vazio
        pthread_mutex_lock(&output_mutex);
        while (!output_buffer.empty) {
            pthread_cond_wait(&output_consumed, &output_mutex);
        }

        // Adicona o dado
        strcpy(output_buffer.data, line);
        output_buffer.empty = 0;
        
        // Sinal que o buffer de output pode ser usado
        pthread_cond_signal(&output_produced);
        pthread_mutex_unlock(&output_mutex);
    }

    pthread_mutex_lock(&output_mutex);
    file_complete = 2;
    pthread_cond_signal(&output_produced);
    pthread_mutex_unlock(&output_mutex);

    return NULL;
}

void* writer_thread(void* arg) {
    FILE* output_file = fopen((char*)arg, "w");
    if (!output_file) {
        perror("Falha ao abrir o arquivo de output");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Aguarda o buffer de output ter dado
        pthread_mutex_lock(&output_mutex);
        while (output_buffer.empty && file_complete != 2) {
            pthread_cond_wait(&output_produced, &output_mutex);
        }

        if (file_complete == 2 && output_buffer.empty) {
            pthread_mutex_unlock(&output_mutex);
            break;
        }

        // Pega o dado de output
        char line[MAX_LINE];
        strcpy(line, output_buffer.data);
        output_buffer.empty = 1;
        
        // Sinaliza que o buffer ta vazio
        pthread_cond_signal(&output_consumed);
        pthread_mutex_unlock(&output_mutex);

        fprintf(output_file, "%s\n", line);
    }

    fclose(output_file);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Para utilizar escreva: %s arquivo_entrada.txt arquivo_saida.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_buffer.empty = 1;
    output_buffer.empty = 1;

    pthread_t reader, processor, writer;
    if (pthread_create(&reader, NULL, reader_thread, argv[1])) {
        perror("Falha ao criar reader thread");
        return EXIT_FAILURE;
    }
    if (pthread_create(&processor, NULL, processor_thread, NULL)) {
        perror("Falha ao criar processor thread");
        return EXIT_FAILURE;
    }
    if (pthread_create(&writer, NULL, writer_thread, argv[2])) {
        perror("Falha ao criar writer thread");
        return EXIT_FAILURE;
    }

    // Aguarda threads terminarem
    pthread_join(reader, NULL);
    pthread_join(processor, NULL);
    pthread_join(writer, NULL);

    pthread_mutex_destroy(&input_mutex);
    pthread_mutex_destroy(&output_mutex);
    pthread_cond_destroy(&input_produced);
    pthread_cond_destroy(&input_consumed);
    pthread_cond_destroy(&output_produced);
    pthread_cond_destroy(&output_consumed);

    printf("Termino. Aquivo %s atualizado\n", argv[2]);
    return EXIT_SUCCESS;
}