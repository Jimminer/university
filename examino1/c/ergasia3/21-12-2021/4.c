#include <stdio.h>

int main(void)
{
  char text[] = "University Of Western Macedonia", buffer[50];
  int i;
  FILE *fp;
  
  fp = fopen("81220-3.txt", "w");  // ������� ��� �������
  
  if (fp != NULL)
  {           
    fputs(text, fp);        // ����� ��� ������
    fclose(fp);             // ������ �� ������
  }
  system("pause");
  
  fp = fopen("81220-3.txt", "r"); // ������� ������� ��� ��������
  
  if (fp != NULL)
  {          
    for (i = 0; i < 5; i++)
	{
      fgets(buffer, 50, fp); // ������� ��� �� ������
      puts(buffer); 		// ������ ��������   
 	   buffer="0";// ������������ �������
    }
    
	fclose(fp);              // ������ �� ������
  
  }
  system("pause");
  return 0;
}
