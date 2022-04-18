#include <stdio.h>
#include <string.h>
int main(void)
{
char str[12]="123456789";
int i;
for(i=strlen(str)-1; i>=0; i--)
printf("%c", str[i]);
return 0;
}