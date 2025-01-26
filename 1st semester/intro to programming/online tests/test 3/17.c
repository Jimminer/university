#include <string.h>
#include <stdio.h>
int main(void)
{
char str1[]="Sinatka", str2[]="Ioannis";
int i;
i = strcmp(str1, str2);

if(!i) printf("The strings are equal\n");
else if(i<0)
printf("%s is < than %s\n", str1, str2);
else
printf("%s is > than %s\n", str1, str2);
return 0;
}

