#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int num, i=0, rd;
  
  fp = fopen("81220-4.bin","rb");
    
  do
  {
    rd=rand()%10+1;
	fseek(fp, 4*rd, 0);
    printf("Ο rd είναι %d δείκτης αρχείου βρίσκεται στο %d byte του.", rd, ftell(fp));
    fread(&num, 4, 1, fp);
    if (feof(fp)) break;
    printf("Τώρα που διάβασε τον αριθμό %d ο δείκτης βρίσκεται στο %d byte\n", num, ftell(fp));
    i++;
  } while(i<10);
  
  fclose(fp);
  
  system("pause");
  return 0;
}
