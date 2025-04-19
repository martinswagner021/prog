#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   FILE *arq;
   if (argc != 2)
   {
      printf("\nERRO: para <tempo>\n");
      return(1);
   }
   arq = fopen("t.txt","at");
   fprintf(arq,"%d;%d\n",getpid(),atoi(argv[1]));
   fflush(arq);
   fclose(arq);
   printf("Sou %d e vou dormir %d segundos\n",getpid(),atoi(argv[1]));   
   sleep(atoi(argv[1]));
   printf("Sou %d e dormi %d segundos\n",getpid(),atoi(argv[1]));   
   return(0);
}
