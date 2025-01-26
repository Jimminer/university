#include <stdio.h>

void myfunc(int *, int , int );

int main(void)
{
int n;

printf("Enter a number between 1 and 10: ");
myfunc(&n, 1, 10);
printf("main %d", n);
return 0;
}
void myfunc(int *num, int min, int max)
{

dï
{
scanf("%d", num);

} while(*num<min || *num>max);

return;
}