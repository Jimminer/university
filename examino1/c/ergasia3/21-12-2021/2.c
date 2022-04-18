#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int c;
  fp = fopen("81220-1.txt", "r");
  if (fp == NULL)
  {
    printf("Δεν μπορώ να ανοίξω το αρχείο 81220-1.txt\n");
    system("pause");
    exit(1);
  }
  else
  {
    while ((c=getc(fp)) != EOF) putchar(c);
    fclose(fp);
  }
  return 0;
}
