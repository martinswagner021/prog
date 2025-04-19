#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int mpid[5],mtempo[5],i;
   int mpara[5] = {20,30,40,50,60};
   int final[5] = { 0, 0, 0, 0, 0};
   int ainda_tem = 5;
   char linha[100];
   FILE *arq;
   
   for (i = 0 ; i < 5 ; ++i)
   {
       sprintf(linha,"./para %d &%c",mpara[i],(char)('\0'));
       system(linha);
       sleep(1);
   }
   arq = fopen("t.txt","rt");
   for (i = 0 ; i < 5 ; ++i)
   {
      fscanf(arq,"%d;%d\n",&(mpid[i]),&(mtempo[i]));
   }
   fflush(arq);
   fclose(arq);
   while (ainda_tem>0)
   {
      for (i = 0 ; i < 5 ; ++i)
      {
         if (!final[i])
         {
            sprintf(linha,"ps p %d -o comm= >>/dev/null ; echo $? > res.txt%c",mpid[i],(char)('\0'));
            //printf("%s\n",linha);
            system(linha);
            sleep(1);
            arq = fopen("res.txt","rt");
            if (((char)fgetc(arq)) != ((char)('0')))
            {
               final[i] = 1;
               printf("O %d que dormiu %d segundos acabou!\n",mpid[i],mtempo[i]); 
               --ainda_tem;  
            }
            fclose(arq);
         }
      }
   }
   printf("\nTerminaram todos!\n");
   return(0);
}
