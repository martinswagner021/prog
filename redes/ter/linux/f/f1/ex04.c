#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void mvfprintf(FILE *arq,char *string, ...)
{
   va_list args;
   int n_args = strlen(string);
   if(n_args == 0)
   {
      printf("0 argumentos , ERRO !!\n");
   }
   else
   {
      va_start(args,string);
      vfprintf(arq,string,args);
      va_end(args);
   }
   return;
}

int main (void)
{
   mvfprintf(stdout,"Chamada com %d argumento variavel.\n",1);
   mvfprintf(stdout,"Chamada com %d argumento %s.\n",2,"variavel");
   mvfprintf(stdout,"");
   return(0);
}
