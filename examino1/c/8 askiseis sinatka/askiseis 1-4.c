#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int ergasia;
	printf("Dimitrios Gkoumas (cs04502)\n");
	srand(time(NULL));
	
	int getrand(from, to) {
		return (rand() % (to - from + 1) + from);
	}
	
	int ergasia1(){
		int arr[100], i;
		float avrg=0;
		printf("Kanoniki seira:\n\n");
		for(i = 0; i<=99; i++){
			arr[i] = getrand(20, 80);
			printf("%-3i", arr[i]);
			avrg += arr[i];
		}
		printf("\n\nAnapodh seira:\n\n");
		for(i = 99; i>=0; i--){
			printf("%-3i", arr[i]);
		}
		avrg /= 100;
		printf("\n\nMesos oros: %f\n", avrg);
	}
	
	int ergasia2(){
		int arr[10][10], i, m, min = 500, max = 100;
		for(i=0; i<=9; i++){
			for(m=0; m<=9; m++){
				arr[i][m] = getrand(100, 500);
				printf("%-4i", arr[i][m]);
			}
			printf("\n");
		}
		for(i=0; i<=9; i++){
			if (arr[i][i] < min) min = arr[i][i];
			if (arr[i][9-i] > max) max = arr[i][9-i];
		}
		printf("\nMikroteros arithmos kirias diagoniou: %i\nMegaliteros arithmos defterevousas diagoniou: %i\n", min, max);
	}
	
	int ergasia3(){
		int stds[20], i, m, n, temp, accept, dupe, selection, found = 0;
		float grades[20][5], min = 10.0, max = 0.0, avrg = 0.0;
		printf("Epilegmena AEM:\n\n");
		for(i=0; i<=19; i++){
			accept = 0;
			while (accept == 0) {
				dupe = 0;
				temp = getrand(4500, 4650);
				for(n=0; n<=i; n++){
					if (stds[n] == temp) dupe = 1;
				}
				if (dupe == 0) {stds[i] = temp; accept = 1;}
			}
			printf("%-5i ", stds[i]);
			for(m=0; m<=4; m++){
				grades[i][m] = getrand(0, 100);
			}
		}
		
		printf("\n\nDialekse AEM gia na deis tis vathmologies: ");
		scanf("%i", &selection);
		printf("\nVathmologies: ");
		for(i=0; i<=19; i++){
			if (stds[i] == selection) {
				found = 1;
				for(m=0; m<=4; m++) {
					avrg += grades[i][m]/10;
					if (grades[i][m]/10 < min) min = grades[i][m]/10;
					if (grades[i][m]/10 > max) max = grades[i][m]/10;
					printf("%.1f, ", grades[i][m]/10);
				}
			}
		}
		if (found == 0) printf("To AEM pou epilexthike den iparxei!\n");
		else printf("\nElaxistos vathmos: %.1f\nMegistos vathmos: %.1f\nMesos oros vathmon: %.1f\n", min, max, avrg/5);
	}
	
	int ergasia4(){
		char arr[20], i;
		printf("Grapse mia leksi eos 20 grammata: ");
		scanf("%20s", &arr);
		for(i=strlen(arr)-1; i>=0; i--) printf("%c", arr[i]);
		printf("\n");
	}
	
	for (;;) {
		printf("\n\nEpilogh ergasias (1-4): ");
		scanf("%i", &ergasia);
		switch(ergasia){
			case 1: {ergasia1(); system("pause"); return 0;}
			case 2: {ergasia2(); system("pause"); return 0;}
			case 3: {ergasia3(); system("pause"); return 0;}
			case 4: {ergasia4(); system("pause"); return 0;}
			default:
				printf("H ergasia pou epilexthike den iparxei!\n");
		}
	}
}
