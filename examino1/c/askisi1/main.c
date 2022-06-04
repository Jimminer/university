#include <stdio.h>

void ergasia1(){
	int _Telikos_vathmos_=5;
	printf("\n%i\n", _Telikos_vathmos_);
}

void ergasia2(){
	int sum = 0.0;
	sum = 5 + 3;
	printf("Result is %d\n", sum);
}

void ergasia3(){
	int MAX = 2010;
	int a = 3, b = 4, c;
	c = a + b;
	MAX = 1969;
	printf("a + b = %d and MAX is now %d\n", c, MAX);
}

void ergasia4(){
	int Num1, Num2, Num3;
	printf("Number 1: ");
	scanf("%i", &Num1);
	printf("\nNumber 2: ");
	scanf("%i", &Num2);
	printf("\nNum1: %i, Num2: %i, Num1 - Num2: %i\n", Num1, Num2, Num1 - Num2);
	Num3 = Num1;
	Num1 = Num2;
	Num2 = Num3;
	printf("Num1: %i, Num2: %i, Num1 - Num2: %i", Num1, Num2, Num1 - Num2);
}

void ergasia5(){
	float r1, r2;
	int mode;
	printf("Antistaths R1: ");
	scanf("%f", &r1);
	printf("Antistaths R2: ");
	scanf("%f", &r2);
	printf("Dialekse sindesimotita:\n1: Se seira, 2: Se parallhlia\n");
	scanf("%i", &mode);
	if (mode == 1) {
		printf("R: %f Ohm", r1 + r2);
	}
	else {
		printf("R: %f Ohm", (r1*r2)/(r1+r2));
	}
}

int daypermonth1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daypermonth2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int checkyear(int year, int month){
	if (year%4 != 0 && year%400 != 0) return daypermonth1[month]; else return daypermonth2[month];
}

void ergasia6(){
	int d1, m1, y1, d2, m2, y2, d3, i, m;
	printf("Hmeromhnia genisis:\n\n");
	printf("Mera: ");
	scanf("%i", &d1);
	printf("Mhnas: ");
	scanf("%i", &m1);
	printf("Xronos: ");
	scanf("%i", &y1);
	printf("\nTorinh hmeromhnia:\n\n");
	printf("Mera: ");
	scanf("%i", &d2);
	printf("Mhnas: ");
	scanf("%i", &m2);
	printf("Xronos: ");
	scanf("%i", &y2);
	
	if (d1 > checkyear(y1, m1-1) || m1 > 12) {printf("H hmeromhnia genisis einai lathos!"); return;}
	if (d2 > checkyear(y2, m2-1) || m2 > 12) {printf("H torinh hmeromhnia einai lathos!"); return;}
	if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 >= d2)) {printf("H hmeromhnia genisis proigeitai ths torinis hmeromhnias!"); return;}

	d3 = checkyear(y1, m1-1) - d1;
	if (y2 > y1) {
		for (i = (m1 + 1); i <= 12; i++) {
			d3 = d3 + checkyear(y1, i-1);
		}
	}
	else {
		if (m2 > m1){
			for (i = (m1 + 1); i < m2; i++) {
				d3 = d3 + checkyear(y1, i-1);
			}
			d3 += d2;
		}
		else{
			d3 = d2 - d1;
		}
	}
	for (i = (y1 + 1); i <= y2; i++) {
		if (i == y2) {
			for (m = 1; m <= m2; m++) {
				d3 = d3 + checkyear(i, m-1);
			}
			d3 = d3 - checkyear(i, m2-1) + d2;
		}
		else {
			for (m = 1; m <= 12; m++) {
				d3 = d3 + checkyear(i, m-1);
			}
		}
	}
	printf("\nOi dio hmeromhnies exoun %i meres diafora", d3);
}

void ergasia7(){
	int number1, number2, tmp;
	printf("Dialekse arithmo: ");
	scanf("%i", &number1);
	if (number1 <= 10){
		printf("O arithmos prepei na einai megaliteros tou 10!");
		return;
	}
	tmp = number1;
	
	while (tmp>0){
		number2 += tmp%10;
		number2 *= 10;
		tmp /= 10;
	}
	if (number1 == number2/10) printf("O %i einai karkinikos", number1); else printf("O %i den einai karkinikos", number1);
}

void ergasia8(){
	int done = 0, i;
	float num1, num2;
	char mop;
	printf("Dialekse ton 1o arithmo: ");
	scanf("%f", &num1);
	printf("Dialekse ton 2o arithmo: ");
	scanf("%f", &num2);
	printf("Dialekse mathimatiki praksi ( + , - , x , / ): ");
	
	if (num1 == 0 && num2 == 0) return;
	for (i=0; done == 0; i++) {
		scanf("%c", &mop);
		if (mop == '+') {printf("%f + %f = %f", num1, num2, num1 + num2); done = 1;}
		else if (mop == '-') {printf("%f - %f = %f", num1, num2, num1 - num2); done = 1;}
		else if (mop == 'x') {printf("%f x %f = %f", num1, num2, num1 * num2); done = 1;}
		else if (mop == '/') {if (num1 != 0 && num2 == 0) {printf("Den mporeis na diaireseis me to 0!"); return;} else {printf("%f / %f = %f", num1, num2, num1 / num2); done = 1;}}
	}
}

void ergasia9(){
	int number, i;
	printf("Dialekse arithmo: ");
	scanf("%i", &number);
	for (i=1; i<number; i+=2) {
		if (number%i == 0 && i != 1 && i != number) {printf("O arithmos %i den einai protos", number); return;}
	}
	printf("O arithmos %i einai protos", number);
}

void ergasia10(){
	int number, i, total = 0;
	printf("Dialekse arithmo: ");
	scanf("%i", &number);
	for (i=1; i<number; i++){
		if (number%i == 0) total += i;
	}
	if (number == total) printf("O arithmos %i einai teleios", number);
	else printf("O arithmos %i den einai teleios", number);
}

int main(){
	int ergasia;
	printf("Dimitrios Gkoumas (cs04502)\n");
	
	for (;;) {
		printf("\n\nEpilogh ergasias (1-10): ");
		scanf("%i", &ergasia);
		switch(ergasia){
			case 1: {ergasia1(); return 0;}
			case 2: {ergasia2(); return 0;}
			case 3: {ergasia3(); return 0;}
			case 4: {ergasia4(); return 0;}
			case 5: {ergasia5(); return 0;}
			case 6: {ergasia6(); return 0;}
			case 7: {ergasia7(); return 0;}
			case 8: {ergasia8(); return 0;}
			case 9: {ergasia9(); return 0;}
			case 10: {ergasia10(); return 0;}
			default:
				printf("H ergasia pou epilexthike den iparxei!\n");
		}
	}
	return 0;
}
