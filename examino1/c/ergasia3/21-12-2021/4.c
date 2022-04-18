#include <stdio.h>

int main(void)
{
  char text[] = "University Of Western Macedonia", buffer[50];
  int i;
  FILE *fp;
  
  fp = fopen("81220-3.txt", "w");  // άνοιγμα για εγγραφή
  
  if (fp != NULL)
  {           
    fputs(text, fp);        // γράψε στο αρχείο
    fclose(fp);             // κλείσε το αρχείο
  }
  system("pause");
  
  fp = fopen("81220-3.txt", "r"); // άνοιγμα αρχείου για ανάγνωση
  
  if (fp != NULL)
  {          
    for (i = 0; i < 5; i++)
	{
      fgets(buffer, 50, fp); // διάβασε από το αρχείο
      puts(buffer); 		// τύπωσε δεδομένα   
 	   buffer="0";// επανεκκίνηση αρχείου
    }
    
	fclose(fp);              // κλείσε το αρχείο
  
  }
  system("pause");
  return 0;
}
