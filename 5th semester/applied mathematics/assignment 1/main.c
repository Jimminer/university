#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void inputValues(int *a, int *b, int *y0, double *dt, int *funcSelection);

int main(){
    int a;
    int b;
    int y0;
    double dt;
    int funcSelection;
    int steps;
    double *results;

    inputValues(&a, &b, &y0, &dt, &funcSelection);

    steps = (b - a) / dt;
    results = (double*)malloc(sizeof(double) * steps);

    if (funcSelection == 1){
        printf("\nProblem 1: approximating y(t), t -> [%i, %i] in %i steps\n", a, b, steps);
        yFunc1(y0, dt, steps - 1, results);
        printf("    (0, %i)\n", y0);
        for (int i=0; i<steps; i++){
            printf("    (%lf, %lf)\n", dt*(i + 1), results[i]);
        }
    }

    else if(funcSelection == 2){
        printf("\nProblem 2: approximating y(t), t -> [%i, %i] in %i steps\n", a, b, steps);
        yFunc2(y0, dt, steps - 1, results);
        printf("    (0, %i)\n", y0);
        for (int i=0; i<steps; i++){
            printf("    (%lf, %lf)\n", dt*(i + 1), results[i]);
        }
    }

    else{
        printf("Invalid function selection\n");
    }
}

void inputValues(int *a, int *b, int *y0, double *dt, int *funcSelection){
    printf("Enter a: ");
    scanf("%i", a);
    printf("Enter b: ");
    scanf("%i", b);
    printf("Enter y0: ");
    scanf("%i", y0);
    printf("Enter dt: ");
    scanf("%lf", dt);
    printf("Select function to approximate (1 or 2): ");
    scanf("%i", funcSelection);
}