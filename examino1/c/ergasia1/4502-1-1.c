#include <stdio.h>
#include <stdlib.h>

int main(){
	int randnum, guess, i;
	srand(4502);
	randnum = rand() % 300 + 1;
	for (i=0; i<8; i++){
		printf("Mantepse enan arithmo (apomenoun %i prospathies): ", 8-i);
		scanf("%i", &guess);
		if (guess > randnum) printf("O magikos arithmos einai mikroteros.\n");
		else if (guess < randnum) printf("O magikos arithmos einai megaliteros.\n");
		else {printf("RIGHT!\nVrikes ton magiko arithmo stin %ih prospathia", i+1); return;}
	}
	printf("FAILURE!");
}
