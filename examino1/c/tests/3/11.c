#include <stdio.h>
struct s_type {
int i;
double d;
};
void f(struct s_type temp);
int main(void)
{
struct s_type var1;
i = 99;
d = 98.6;
f(var1);
return 0;
}
void f(struct s_type temp)
{
printf("%d %.2f", temp.i, temp.d);
}