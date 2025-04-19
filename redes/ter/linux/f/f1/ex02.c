#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   int i;

   printf("Programa: %s\n",argv[0]);
   printf("Quantidade de argumentos: %d\n",argc);
   for (i = 1 ; i < argc ; ++i)
   {
      printf("Argv[%02d] = %s\n",i,argv[i]);
   }

   return(0);
}
