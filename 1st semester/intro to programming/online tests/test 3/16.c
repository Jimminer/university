#include <stdio.h>
#include <string.h>

struct foo
{
char c;
int i;
char str[20];
};

union bar
{
char c;
int i;
char str[20];
};

int main(void)
{
struct foo myfoo;
union bar mybar;

myfoo.c = 'a';
myfoo.i = 10;
strcpy(myfoo.str, "the struct");

mybar.c = 'a';
mybar.i = 10;
strcpy(mybar.str, "the union");

printf("%c %d\n", myfoo.c, myfoo.i);
printf("%c %d\n", mybar.c, mybar.i);

return 0;
}