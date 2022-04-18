#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int buf;
  
  if ((fp = fopen("81220-4.bin", "rb")) == NULL)
  {
    puts("Σφάλμα κατά το άνοιγμα του αρχείου ανάγνωσης");
    exit(1);
  }
  
  while (fread(&buf, sizeof(int), 1, fp) > 0) printf("%5d", buf);
  
  fclose(fp);
  system("pause");
  
  return 0;
}
