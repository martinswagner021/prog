#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int G_level;
void print_erro(int level,char *msg, ...)
{
   va_list arg_list;
   if (level <= G_level)
   {
      va_start(arg_list, msg);
      vfprintf(stderr,msg,arg_list);
      va_end(arg_list);
   }

   return;
}

// Versão para tela!!!
int main(void)
{
    G_level = 1;
    print_erro(1,"teste %d\n",1);
    return(0);
}
