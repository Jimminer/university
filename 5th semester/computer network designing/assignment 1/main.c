#include <stdio.h>

#define MAX_GOS         100
#define MAX_SERVICES    100

void getInput(int *minLoad, int *maxLoad, int *gosCount, int *serviceCount, double *gos, double *services);
int calculateServiceCapacity(int load, double gos, double block);

int main(){
    int minLoad = 1, maxLoad = 0;
    int gosCount = 0, serviceCount = 0;
    double gos[MAX_GOS];
    double services[MAX_SERVICES];

    getInput(&minLoad, &maxLoad, &gosCount, &serviceCount, gos, services);

    printf("Load          ");
    for (int i=0; i<gosCount; i++){
        printf("GOS %-10.2lf", gos[i]);
    }
    printf("Service\n");

    for (int k=0; k<serviceCount; k++){
        for (int i=minLoad; i<=maxLoad; i++){
            printf("%-14i", i);
            for (int m=0; m<gosCount; m++){
                printf("%-14i", calculateServiceCapacity(i, gos[m]/100, services[k]) );
            }
            printf("%i\n", k+1);
        }
        printf("\n\n");
    }
}

void getInput(int *minLoad, int *maxLoad, int *gosCount, int *serviceCount, double *gos, double *services){
    while (*minLoad >= *maxLoad){
        printf("Enter min load: ");
        scanf("%i", minLoad);

        printf("Enter max load: ");
        scanf("%i", maxLoad);

        printf("\n");
    }

    double input;

    printf("Enter GOS (newline separated, -1 to stop):\n    ");
    while(*gosCount < MAX_GOS && scanf("%lf", &input) && input != -1){
        gos[*gosCount] = input;
        (*gosCount)++;

        printf("    ");
    }
    printf("\n");

    printf("Enter service starting blocking probability (newline separated, -1 to stop):\n    ");
    while(*serviceCount < MAX_SERVICES && scanf("%lf", &input) && input != -1){
        services[*serviceCount] = input;
        (*serviceCount)++;

        printf("    ");
    }
    printf("\n");
}

int calculateServiceCapacity(int load, double gos, double block){
    int capacity = 0;

    do{
        capacity++;
        block = load * block / ( (capacity) + load * block );
    } while(block > gos);

    return(capacity);
}