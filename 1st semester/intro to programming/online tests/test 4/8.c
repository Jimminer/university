#include <stdio.h>
int main(void)
{
char *p, str[80];
printf("Enter a string: ");
p = gets(str);
if(p)
printf("%s %s", p, str);
return 0;
}