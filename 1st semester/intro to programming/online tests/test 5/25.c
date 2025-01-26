#include <stdio.h>
int main(void)
{
char str[80];
printf("Enter a string: ");
if(gets(str))
printf("Here is your string: %s", str);
return 0;
}