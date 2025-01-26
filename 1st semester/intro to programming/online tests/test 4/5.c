#include <stdio.h>
#include <stdlib.h>
int main(void)
{
FILE *fp;
int i;
if((fp = fopen("ftext", "wb"))==NULL) {
printf("Cannot open file.n");
exit(1);
}
i = 100;
if(fwrite(&i, 2, 1, fp) != 1) {
printf("Write error occurred.n");
exit(1);
}
fclose(fp);
if((fp = fopen("ftext", "rb"))==NULL) {
printf("Cannot open file.n");
exit(1);
}
if(fread(&i, 2, 1, fp) != 1) {
printf("Read error occurred.n");
exit(1);
}
printf("i is %d", i);
fclose(fp);
return 0;
}