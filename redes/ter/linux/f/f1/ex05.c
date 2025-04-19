#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void soma(int n, ...)
{
   int i,val,total=0;
   va_list vl;
   va_start(vl,n);
   total=va_arg(vl,int);
   for (i=1;i<n;i++)
   {
     val=va_arg(vl,int);
     total += val;
   }
   va_end(vl);
   printf("A soma eh %d.\n",total);
   return;
}

int main(void)
{
   soma(3,5,10,15);
   return(0);
}
