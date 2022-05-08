#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules/dataStructures.h"
#include "modules/dataStructuresVars.h"

typedef struct PilotRecord{
    char Lname[24];
    char Fname[24];
    char Phone[15];
    char Gender;
    unsigned short int BirthDay;
    unsigned short int BirthMonth;
    unsigned short int BirthYear;
    unsigned short int Hours;
}PilotRecord;

typedef struct dates{
    int d1;
    int m1;
    int y1;
    int d2;
    int m2;
    int y2;
}dates;

BinTree *init();
PilotRecord findPilot(int location);
PilotRecord findPilotUsingPhone(char *phone);
void searchPilotHours(BinTree *pilotTree, int from, int to);
void searchPilotHoursMen(BinTree *pilotTree, int from, int to);
void searchPilotHoursWomen(BinTree *pilotTree, int from, int to);
int datecompare(dates data);

int main(){
    int from, to;
    char phone[15];
    BinTree *pilotTree = init();
    PilotRecord pilot;

    printf("To diadiko dentro dimiourgithike.\n");

    getchar();


    printf("\nGia to 2o erotima:\nApo poses mexri poses ores na psaxo gia pilotous? (apo, eos):");
    scanf("%i, %i", &from, &to);
    printf("\n\n");
    searchPilotHours(pilotTree, from, to);


    printf("\nGia to 3o erotima:\nApo poses mexri poses ores na psaxo gia pilotous? (apo, eos):");
    scanf("%i, %i", &from, &to);
    printf("\n\n");
    searchPilotHoursMen(pilotTree, from, to);


    printf("\nGia to 4o erotima:\nApo poses mexri poses ores na psaxo gia pilotous? (apo, eos):");
    scanf("%i, %i", &from, &to);
    printf("\n\n");
    searchPilotHoursWomen(pilotTree, from, to);


    printf("\nGia to 5o erotima:\nGia poio tilefono pilotou na psaxo? ");
    scanf("%s", phone);
    printf("\n\n");
    pilot = findPilotUsingPhone(phone);
    printf("EPITHETO           ONOMA            FYLLO ORES    HM/NIA     TILEFONO\n-----------------------------------------------------------------------\n");
    printf("%-18s %-18s %-3c %-7i %02i-%02i-%02i %-10s\n", pilot.Lname, pilot.Fname, pilot.Gender, pilot.Hours, pilot.BirthDay, pilot.BirthMonth, pilot.BirthYear, pilot.Phone);

    return 0;
}

BinTree *init(){
    int i;
    PilotRecord temp;
    BinTree *pilotTree = createBinTree();
    BTData data;

    for (i=0; i<1024; i++){
        temp = findPilot(i);
        data.hours = temp.Hours;
        data.location = i;
        addBinTree(pilotTree, temp.Hours, data);
    }

    return pilotTree;
}

void searchPilotHours(BinTree *pilotTree, int from, int to){
    int i;
    BTData data;
    PilotRecord pilot;

    printf("EPITHETO           ONOMA            FYLLO ORES    HM/NIA     TILEFONO\n-----------------------------------------------------------------------\n");
    for (i=from; i<=to; i++){
        data = findBinTree(pilotTree, i);
        if (data.hours == i){
            pilot = findPilot(data.location);
            printf("%-18s %-18s %-3c %-7i %02i-%02i-%02i %-10s\n", pilot.Lname, pilot.Fname, pilot.Gender, pilot.Hours, pilot.BirthDay, pilot.BirthMonth, pilot.BirthYear, pilot.Phone);
        }
    }
}

void searchPilotHoursMen(BinTree *pilotTree, int from, int to){
    int i;
    BTData data;
    PilotRecord pilot;
    dates dateData;

    printf("EPITHETO           ONOMA            FYLLO ORES    HM/NIA     TILEFONO\n-----------------------------------------------------------------------\n");
    for (i=from; i<=to; i++){
        data = findBinTree(pilotTree, i);
        if (data.hours == i){
            pilot = findPilot(data.location);
            dateData.d1 = pilot.BirthDay; dateData.m1 = pilot.BirthMonth; dateData.y1 = pilot.BirthYear; dateData.d2 = 1; dateData.m2 = 1; dateData.y2 = 1980;
            if (pilot.Gender == 'M' && datecompare(dateData) == 1){
                printf("%-18s %-18s %-3c %-7i %02i-%02i-%02i %-10s\n", pilot.Lname, pilot.Fname, pilot.Gender, pilot.Hours, pilot.BirthDay, pilot.BirthMonth, pilot.BirthYear, pilot.Phone);
            }
        }
    }
}

void searchPilotHoursWomen(BinTree *pilotTree, int from, int to){
    int i;
    BTData data;
    PilotRecord pilot;

    printf("EPITHETO           ONOMA            FYLLO ORES    HM/NIA     TILEFONO\n-----------------------------------------------------------------------\n");
    for (i=from; i<=to; i++){
        data = findBinTree(pilotTree, i);
        if (data.hours == i){
            pilot = findPilot(data.location);
            if (pilot.Gender == 'F'){
                printf("%-18s %-18s %-3c %-7i %02i-%02i-%02i %-10s\n", pilot.Lname, pilot.Fname, pilot.Gender, pilot.Hours, pilot.BirthDay, pilot.BirthMonth, pilot.BirthYear, pilot.Phone);
            }
        }
    }
}

PilotRecord findPilot(int location){
    FILE *file;
    int counter = 0;
    PilotRecord output;

    if ((file = fopen("pilots.txt", "rb")) != NULL){
        while (fread(&output, sizeof(PilotRecord), 1, file) > 0){
            if (counter++ == location) break;
        }
        fclose(file);
    }
    else{
        printf("The file pilots.txt was not found!\n");
    }

    return output;
}

PilotRecord findPilotUsingPhone(char *phone){
    FILE *file;
    PilotRecord output;

    if ((file = fopen("pilots.txt", "rb")) != NULL){
        while (fread(&output, sizeof(PilotRecord), 1, file) > 0){
            if (strcmp(output.Phone, phone) == 0) break;
        }
        fclose(file);
    }
    else{
        printf("The file pilots.txt was not found!\n");
    }

    return output;
}

int datecompare(dates data){
    if ((data.y1 > data.y2) || (data.y1 == data.y2 && data.m1 > data.m2) || (data.y1 == data.y2 && data.m1 == data.m2 && data.d1 >= data.d2)){
        return 1;
    }
    return 2;
}