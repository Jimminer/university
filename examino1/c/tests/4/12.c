#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void load(void);
struct catalog {
char name[80];    /* author name */
char title[80];   /* title */
char pub[80];     /* publisher */
unsigned date;    /* copyright date */
unsigned char ed; /* edition */
} cat[100];
int top = 0;
int main(void)
{
load();
printf("%s", cat[2].title);
return 0;
}
void load(void)
{
FILE *fp;
if((fp = fopen("fcat", "rb"))==NULL) {
printf("Catalog file not on disk.n");
return;
}
if(fread(&top, sizeof top, 1, fp) != 1) {
printf("Error reading count.n");
exit(1);
}
if(fread(cat, sizeof cat, 1, fp) != 1) {
printf("Error reading catalog data.n");
exit(1);
}
fclose(fp);
}