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
    printf("� rd ����� %d ������� ������� ��������� ��� %d byte ���.", rd, ftell(fp));
    fread(&num, 4, 1, fp);
    if (feof(fp)) break;
    printf("���� ��� ������� ��� ������ %d � ������� ��������� ��� %d byte\n", num, ftell(fp));
    i++;
  } while(i<10);
  
  fclose(fp);
  
  system("pause");
  return 0;
}
