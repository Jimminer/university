#include <stdio.h>
int main(void)
{
char ch;
do {
ch = getchar();
putchar('.');
} while(ch != 'n');
return 0;
}