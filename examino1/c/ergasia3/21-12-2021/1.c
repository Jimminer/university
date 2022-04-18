#include <stdio.h>

int main(void)
{
  FILE *fp;
  int i;
  
  fp = fopen("81220-1.txt","w"); 	// Δημιουργεί και ανοίγει το αρχείο 1.
  
  putc('H', fp);
  putc('E', fp);
  putc('L', fp);
  putc('L', fp);
  putc('O', fp);
  putc(' ', fp);
   
  for (i = 1; i <= 20; i++) putc('*', fp);	//Γράφει 20 φορές τον χαρακτήρα *
  
  fclose(fp);
  return 0;
}
