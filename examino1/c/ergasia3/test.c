#include <stdio.h>
#include <windows.h>

unsigned short num, pin;
char name[28], surname[28];
float money;

struct lefteris{
    unsigned short num, pin;
    char name[28], surname[28];
    float money;
} skata;

float tmoney;
char ttype[3];
unsigned short acc;
char day, month, year;

int main(){
    SYSTEMTIME stm;
    GetSystemTime(&stm);
    int currentdate[3] = {0, 0, 0};
    currentdate[0] = stm.wDay;
    currentdate[1] = stm.wMonth;
    currentdate[2] = stm.wYear;
    printf("Current Date: %i/%i/%i", currentdate[0], currentdate[1], currentdate[2]);

    FILE *file, *f;
    file = fopen("accounts", "rb+");
    remove("peos1.txt");
    f = fopen("peos1.txt", "a+");
    while (fread(&num, sizeof(num), 1, file) > 0){
        fread(&pin, sizeof(pin), 1, file);
        fread(&name, sizeof(name), 1, file);
        fread(&surname, sizeof(surname), 1, file);
        fread(&money, sizeof(money), 1, file);
        // printf("Num: %i\nPin: %i\nName: %s %s\nMoney: %f\n\n", num, pin, name, surname, money);
        fprintf(f, "Num: %i\nPin: %i\nName: %s %s\nMoney: %f\n\n", num, pin, name, surname, money);
    }
    fclose(file);
    fclose(f);
    // file = fopen("accounts", "rb+");
    // remove("peos3.txt");
    // f = fopen("peos3.txt", "a+");
    // while (fread(&skata, sizeof(skata), 1, file) > 0){
    //     // printf("Num: %i\nPin: %i\nName: %s %s\nMoney: %f\n\n", num, pin, name, surname, money);
    //     fprintf(f, "Num: %i\nPin: %i\nName: %s %s\nMoney: %f\n\n", skata.num, skata.pin, skata.name, skata.surname, skata.money);
    // }
    // fclose(file);
    // fclose(f);
    file = fopen("transactions", "rb+");
    remove("peos2.txt");
    f = fopen("peos2.txt", "a+");
    while (fread(&tmoney, sizeof(tmoney), 1, file) > 0){
        fread(&ttype, sizeof(ttype), 1, file);
        fseek(file, 1, SEEK_CUR);
        fread(&acc, sizeof(acc), 1, file);
        fread(&day, sizeof(day), 1, file);
        fread(&month, sizeof(month), 1, file);
        fread(&year, sizeof(year), 1, file);
        fseek(file, 3, SEEK_CUR);
        fprintf(f, "Account: %i\nTransaction Type: %s\nMoney: %f\nDate: %i/%i/%i\n\n", acc, ttype, tmoney, day, month, year);
    }
    // float gay = 55.2;
    // fseek(file, 0, SEEK_SET);
    // fwrite(&gay, sizeof(gay), 1, file);
    fclose(file);
    fclose(f);
    return 0;
}