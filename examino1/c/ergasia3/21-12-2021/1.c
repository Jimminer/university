#include <stdio.h>

int main(void)
{
  FILE *fp;
  int i;
  
  fp = fopen("81220-1.txt","w"); 	// ���������� ��� ������� �� ������ 1.
  
  putc('H', fp);
  putc('E', fp);
  putc('L', fp);
  putc('L', fp);
  putc('O', fp);
  putc(' ', fp);
   
  for (i = 1; i <= 20; i++) putc('*', fp);	//������ 20 ����� ��� ��������� *
  
  fclose(fp);
  return 0;
}
