#include <stdio.h>
#include <string.h>

int main(void)
{
char onom1[20]="Sinatka", onom2[]="Ioannis";

strcat(onom1, onom2);
printf("%s\n", onom1);

strcpy(onom1, onom2);
printf("%s %s\n", onom1, onom2);

return 0;
}