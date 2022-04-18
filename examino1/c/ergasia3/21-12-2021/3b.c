#include <stdio.h>

int main(void)
{
  FILE *fp;
  char line[100];
  int count = 0;
  
  if ((fp = fopen("81220-2.txt","r")) == NULL)
  {
    fprintf(stderr,"Σφάλμα κατά το άνοιγμα του: 81220-2.txt\n");
    system("pause");    
	return 1;
  }
  // Διάβασε γραμμή-γραμμή από το αρχείο

  while (fgets(line, 100, fp) != NULL) 
  {
  printf("%s", line);	
  count++;
  }
  printf("\n\nΤο αρχείο έχει %d γραμμές.\n", count);
  fclose(fp);
  system("pause");
  return 0;
}
