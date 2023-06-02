#include "stdio.h"

int f (int *i) {
*i = *i + 5;
return 4;
}
void main() {
int x = 3;
x = x + f(&x);
printf("%d\n", x);
}