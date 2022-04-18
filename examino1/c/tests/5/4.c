#include <stdio.h>
struct s_type {
int i;
char ch;
double d;
char str[80];
} s;
int main(void)
{
i=1234;
ch='M';
d=7.3;
printf("Enter a name: ");
scanf("%s", s.str);
printf("%d %c %.1f %s", s.i, s.ch, s.d, s.str);
return 0;
}