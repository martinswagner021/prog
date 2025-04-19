#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>

// ao inv�s de define pode ser uma vari�vel global setada por par�metro
#define STDERROR // comentar essa linha se for imprimir para arquivo

#define DIR_OUT "/home/USUARIO/" // trocar o diret�rio pelo que deseje para a sa�da da instrumenta��o
#define STR_SIZE 500

int G_level;
void print_erro(int level,char *msg, ...)
{
   va_list arg_list;
#ifndef STDERROR
   char efe_path[STR_SIZE];
   FILE *arq;
   if (level<=G_level)
   {
      sprintf(efe_path,"%slog_%ld_%d.txt%c",DIR_OUT,(long int)getpid(),level,(char)('\0'));
      arq = fopen(efe_path,"at");
      va_start(arg_list, msg);
      vfprintf(arq,msg,arg_list);
      fflush(arq);
      fclose(arq);
      va_end(arg_list);
   }
#else
   if (level <= G_level)
   {
      va_start(arg_list, msg);
      vfprintf(stderr,msg,arg_list);
      va_end(arg_list);
   }
#endif
   return;
}

// Vers�o completa!!!
int main(void)
{
    G_level = 1;
    print_erro(1,"teste %d\n",1);
    return(0);
}

