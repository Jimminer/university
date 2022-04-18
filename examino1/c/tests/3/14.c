#include <stdio.h>
void f(int i);
int main(void)
{
f(0);
return 0;
}
void f(int i)
{
if(i<10) {
f(i+1);
printf("%d ", i);
}
}