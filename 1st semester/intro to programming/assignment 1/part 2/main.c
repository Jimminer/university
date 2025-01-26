#include <stdio.h>
#include <stdlib.h>

int add(int, int), sub(int, int), mult(int, int), divv(int, int);

int main(){
	int praksi, apantisi, n1, n2, n3, i;
	srand(4502);
	
	for (i=0; i<10; i++){
		praksi = rand() % 4;
		
		switch(praksi){
			case 0: {n1 = rand() % 901 + 100; n2 = rand() % 901 + 100; n3 = add(n1, n2); printf("Erotisi: %i + %i = ", n1, n2); break;}
			case 1: {n1 = rand() % 901 + 100; n2 = rand() % 901 + 100; if (n1<n2) {int temp = n1; n1 = n2; n2 = temp;} n3 = sub(n1, n2); printf("Erotisi: %i - %i = ", n1, n2); break;}
			case 2: {n1 = rand() % 30 + 1; n2 = rand() % 30 + 1; n3 = mult(n1, n2); printf("Erotisi: %i x %i = ", n1, n2); break;}
			case 3: {n2 = rand() % 20 + 1; n1 = n2*(rand() % 20 + 1); n3 = divv(n1, n2); printf("Erotisi: %i : %i = ", n1, n2); break;}
		}
		scanf("%i", &apantisi);
		if (apantisi == n3) printf("<<Right !!>>\n\n");
		else printf("<<Error>>\n\n");
	}
	return 0;
}

int add(int n1, int n2){return n1+n2;}
int sub(int n1, int n2){return n1-n2;}
int mult(int n1, int n2){return n1*n2;}
int divv(int n1, int n2){return n1/n2;}
