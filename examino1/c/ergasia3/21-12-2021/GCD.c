#include <stdio.h>

int GreatComDivis(int, int);

int main(void)
{
  int k1, k2, m;
	
	printf("\n��������� :");
	scanf("%d", &k1);
	printf("������������ :");
	scanf("%d", &k2);
	m=GreatComDivis(k1, k2);
	printf("� �������� ������ ��������� ��� %d ��� %d ����� %d", k1, k2, m);
	return 0;
	
}


int GreatComDivis(int n1, int n2)
{
int temp;
if(n2==0) return n1;
temp=n2; 
n2=n1%n2;
n1=temp;
GreatComDivis(n1, n2);
}
