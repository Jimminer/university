#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void)
{
  FILE *fp;
  int i, buf, n, cnt = 0;
  
  if ((fp = fopen("81220-4-2.bin", "w")) == NULL)
  {
    puts("Σφάλμα κατά τη δημιουργία του αρχείου.");
    exit(1);
  }
  
  for (i = 1; i <= N; i++)
  {
    buf = rand() % 10000;
    n = fwrite(&buf, sizeof(int), 1, fp);
    cnt++;
    printf("%5d", buf);
  }
  
  fclose(fp);
  
  printf("\nΤο αρχείο με τους %d ακεραίους έχει δημιουργηθεί\n", cnt);
  system("pause");
  return 0;
}
