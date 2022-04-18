#include <stdio.h>
#include <windows.h>

float tmoney;
char ttype[3];
unsigned short acc;
char day, month, year;

int main(){
    SYSTEMTIME st;
    GetSystemTime(&st);
    printf("%i/%i/%i\n\n", st.wDay, st.wMonth, st.wYear - 2000);
    //printf("Kalispera%sKalispera", 1 > 0 ? "+": "");
    // FILE *file, *f;
    // int temp;
    // file = fopen("transactions", "rb+");
    // remove("peos3.txt");
    // f = fopen("peos3.txt", "a+");
    // fseek(file, 0, SEEK_END);
    // while (fread(&temp, -1, 1, file) > 0){
    //     fseek(file, -2, SEEK_CUR);
    //     fseek(file, -sizeof(year), SEEK_CUR);
    //     fread(&year, sizeof(year), 1, file);
    //     fseek(file, -sizeof(month), SEEK_CUR);
    //     fread(&month, sizeof(month), 1, file);
    //     fseek(file, -sizeof(day), SEEK_CUR);
    //     fread(&day, sizeof(day), 1, file);
    //     fseek(file, -sizeof(acc), SEEK_CUR);
    //     fread(&acc, sizeof(acc), 1, file);
    //     fseek(file, -1, SEEK_CUR);
    //     fseek(file, -sizeof(ttype), SEEK_CUR);
    //     fread(&ttype, sizeof(ttype), 1, file);
    //     fseek(file, -sizeof(tmoney), SEEK_CUR);
    //     fread(&tmoney, sizeof(tmoney), 1, file);
    //     fprintf(f, "Account: %i\nTransaction Type: %s\nMoney: %f\nDate: %i/%i/%i\n\n", acc, ttype, tmoney, day, month, year);
    // }
    // while (fread(&tmoney, sizeof(tmoney), 1, file) > 0){
    //     fread(&ttype, sizeof(ttype), 1, file);
    //     fseek(file, 1, SEEK_CUR);
    //     fread(&acc, sizeof(acc), 1, file);
    //     fread(&day, sizeof(day), 1, file);
    //     fread(&month, sizeof(month), 1, file);
    //     fread(&year, sizeof(year), 1, file);
    //     fseek(file, 3, SEEK_CUR);
    //     fprintf(f, "Account: %i\nTransaction Type: %s\nMoney: %f\nDate: %i/%i/%i\n\n", acc, ttype, tmoney, day, month, year);
    // }
    







    int thirides[3] = {200, 400, 400};
    printf("%i+%i+%i = %i", thirides[0], thirides[1], thirides[2], thirides[0]*20 + thirides[1]*10 + thirides[1]*5);








    return 0;
}