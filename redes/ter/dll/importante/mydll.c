#include <stdio.h>
// Como compilar?
// gcc -shared -o mydll.dll mydll.c
// Como fazer o libmydll.so?
// gcc -o mydll.o my
void display_msg(char* msg) {
    printf("%s\n", msg);
}