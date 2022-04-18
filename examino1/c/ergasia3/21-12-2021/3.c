#include <stdio.h>

int main(void)
{
  FILE *fp;
  char line[100];
  int count = 0;
  
  if ((fp = fopen("81220-2.txt","r")) == NULL)
  {
    fprintf(stderr,"Σφάλμα κατά το άνοιγμα του: 81220-2.txt\n");
	return 1;
  }
  // Διάβασε γραμμή-γραμμή από το αρχείο
  while (fgets(line, 100, fp) != NULL) 
  {
	puts(line);
	count++;
}	
  printf("Το αρχείο έχει %d γραμμές.\n", count);
  fclose(fp);
  return 0;
}
