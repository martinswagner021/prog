#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
   int i;
   printf("Programa: %s\n",argv[0]);
   printf("Quantidade de argumentos: %d\n",argc);
   for (i = 1 ; i < argc ; ++i)
   {
      printf("Argv[%02d] = %s\n",i,argv[i]);
   }
   i = 0;
   while (env[i] != NULL)
   {
      printf("Env[%03d] = %s\n",i+1,env[i]);
      ++i;
   }
   printf("Qtd env = %d\n",i);
   return(0);
}
