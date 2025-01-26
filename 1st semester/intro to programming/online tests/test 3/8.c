#include <stdio.h>
void f2(int num[]), f3(int *num);
int main(void)
{
int count[5] = {1, 2, 3, 4, 5};
f2(count);
f3(count);
return 0;
}
void f2(int num[])
{
int i;
for(i=0; i<5; i++) printf("%d ", num[i]);
}
void f3(int *num)
{
int i;
for(i=0; i<5; i++) printf("%d ", num[i]);
}