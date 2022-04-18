#include <stdio.h>


struct _FRACTION{
  int numarator, denominator;
};

typedef struct _FRACTION Fraction;

Fraction ReadFraction(void);
Fraction AddFraction(Fraction f1, Fraction f2);
Fraction SubFraction(Fraction f1, Fraction f2);
Fraction MulFraction(Fraction f1, Fraction f2);
Fraction DivFraction(Fraction f1, Fraction f2);
int GreatComDivis(int, int);

int main(void)
{
  Fraction f1, f2, temp;
  printf("\nΔώσε το πρώτο κλάσμα");
  f1=ReadFraction();
  printf("\nΔώσε το δεύτερο κλάσμα");
  f2=ReadFraction();
  printf("\nΤα κλάσματα που δόθηκαν είναι %-d/%d  και %-d/%d", f1.numarator, f1.denominator, f2.numarator, f2.denominator);
  temp=AddFraction(f1, f2);
  printf("\nΤο άθροισμα\t %-d/%d + %-d/%d = %-d/%d", f1.numarator, f1.denominator, f2.numarator, f2.denominator, temp.numarator, temp.denominator);
  temp=SubFraction(f1, f2);
  printf("\nΗ διαφορά\t %-d/%d - %-d/%d = %-d/%d", f1.numarator, f1.denominator, f2.numarator, f2.denominator, temp.numarator, temp.denominator);
  temp=MulFraction(f1, f2);
  printf("\nΤο γινόμενο\t %-d/%d X %-d/%d = %-d/%d", f1.numarator, f1.denominator, f2.numarator, f2.denominator, temp.numarator, temp.denominator);
  temp=DivFraction(f1, f2);
  printf("\nΤο πηλίκο\t %-d/%d : %-d/%d = %-d/%d", f1.numarator, f1.denominator, f2.numarator, f2.denominator, temp.numarator, temp.denominator);
  return 0;
}

Fraction ReadFraction( void )
{
	Fraction temp;
	printf("\nΑριθμητής :");
	scanf("%d", &temp.numarator);
	printf("Παρονομαστής :");
	scanf("%d", &temp.denominator);
	return temp;
}

Fraction AddFraction(Fraction f1, Fraction f2)
{
	Fraction temp;
	int divisor;
	temp.numarator=f1.numarator*f2.denominator+f2.numarator*f1.denominator;
	temp.denominator=f1.denominator*f2.denominator;
	divisor=GreatComDivis(temp.numarator, temp.denominator);
	temp.numarator/=divisor;
	temp.denominator/=divisor;
	return temp;
}


Fraction SubFraction(Fraction f1, Fraction f2)
{
	Fraction temp;
	int divisor, flag=0;
	temp.numarator=f1.numarator*f2.denominator-f2.numarator*f1.denominator;
	if(temp.numarator<0) 
	{
	flag=1;
	temp.numarator=-temp.numarator;
	}
	temp.denominator=f1.denominator*f2.denominator;
	divisor=GreatComDivis(temp.numarator, temp.denominator);
	temp.numarator/=divisor;
	if(flag>0) temp.numarator=-temp.numarator;
	temp.denominator/=divisor;
	return temp;
}


Fraction MulFraction(Fraction f1, Fraction f2)
{
	Fraction temp;
	int divisor;
	temp.numarator=f1.numarator*f2.numarator;
	temp.denominator=f1.denominator*f2.denominator;
	divisor=GreatComDivis(temp.numarator, temp.denominator);
	temp.numarator/=divisor;
	temp.denominator/=divisor;
	return temp;
}

Fraction DivFraction(Fraction f1, Fraction f2)
{
	Fraction temp;
	int divisor;
	temp.numarator=f1.numarator*f2.denominator;
	temp.denominator=f1.denominator*f2.numarator;
	divisor=GreatComDivis(temp.numarator, temp.denominator);
	temp.numarator/=divisor;
	temp.denominator/=divisor;
	return temp;
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
