#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "modules/getch_.h"

int mainpage();
int askpass(int);
int getrand(int, int);
int flipnumber(int);
int running = 1;
int ipalilos_pass = 4502;
char ipalilos_username[] = "GKOUMAS";
float getfrand(float, float);
double database(int, int, float);
void enimerosi();
void metafora();
void analipsi();
void katathesi();
void ipalilos1();
void ipalilos2();
void ipalilos3();
void shutdownatm();

void clearscreen(){
#ifdef WINDOWS
    system("cls");
#else
    system ("clear");
#endif
}

int main(){
    srand(time(NULL));
    for(;;){
        if (running != 1) break;
        switch(mainpage()){
            case 1: {enimerosi(); printf("\nPatiste ena pliktro gia na pate sto kirio menu."); getch_(); break;}
            case 2: {metafora(); printf("\nPatiste ena pliktro gia na pate sto kirio menu."); getch_(); break;}
            case 3: {analipsi(); printf("\nPatiste ena pliktro gia na pate sto kirio menu."); getch_(); break;}
            case 4: {katathesi(); printf("\nPatiste ena pliktro gia na pate sto kirio menu."); getch_(); break;}
            case 101: {ipalilos1(); printf("\nPatiste ena pliktro gia na pate sto kirio menu."); getch_(); break;}
            case 102: {ipalilos2(); printf("\nPatiste ena pliktro gia na pate sto kirio menu."); getch_(); break;}
            case 103: {ipalilos3(); printf("\n"); getchar(); break;}
        }
    }
    return 0;
}

int mainpage(){
    int selection;
    for(;;){
        clearscreen();
        printf("\tPEIRAMATIKO ATM TMHMATOS PLHROFORIKHS\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n1. ENHMEROSH\t\t\t\t3. ANALHPSH\n2. METAFORA\t\t\t\t4. KATATHESH\n\n");
        printf("Parakalo dialekse mia epilogh: ");
        scanf("%i", &selection);
        if ((selection >= 1 && selection <= 4) || (selection >= 101 && selection <= 103)) return selection;
        else printf("H epilogh afth den iparxei!\n");
    }
}

void enimerosi(){
    int account, i;
    clearscreen();
    printf("Parakalo dialekse ton trapeziko logariasmo sou: ____\b\b\b\b");
    scanf("%i", &account);
    if (account >= 4001 && account <= 5000){
        for (i=0; i<3; i++){
            if (askpass(account) == flipnumber(account)){
                printf("\nO logariasmos %i exei: %.2f$", account, database(account, 1, 0));
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

void metafora(){
    int account=0, receiver=0, i;
    double lefta=0;
    clearscreen();
    printf("Parakalo dialekse ton trapeziko logariasmo sou: ____\b\b\b\b");
    scanf("%i", &account);
    if (account >= 4001 && account <= 5000){
        for (i=0; i<3; i++){
            if (askpass(account) == flipnumber(account)){
                printf("\nO logariasmos %i exei: %.2f$", account, database(account, 1, 0));
                printf("\n\nDialekse to logariasmo ston opoio thes na metafereis lefta: ____\b\b\b\b");
                scanf("%i", &receiver);
                if (receiver >= 4001 && receiver <= 5000){
                    if (account != receiver){
                        printf("Dialekse to poso pou thes na metafereis: ");
                        scanf("%lf", &lefta);
                        if (lefta <= database(account, 1, 0)){
                            database(account, 2, database(account, 1, 0) - lefta);
                            database(receiver, 2, database(receiver, 1, 0) + lefta);
                            printf("\nH metafora pragmatopoihthike me epitixia!\nO logariasmos sou tora exei: %.2f$", database(account, 1, 0));
                        }
                        else printf("Den exeis arketa lefta gia na pragmatopoihseis afth th metafora!");
                    }
                    else printf("Den mporeis na metafereis lefta ston diko sou logariasmo!");
                }
                else printf("O logariasmos aftos den iparxei!");
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

void analipsi(){
    int account, i;
    double lefta;
    clearscreen();
    printf("Parakalo dialekse ton trapeziko logariasmo sou: ____\b\b\b\b");
    scanf("%i", &account);
    if (account >= 4001 && account <= 5000){
        for (i=0; i<3; i++){
            if (askpass(account) == flipnumber(account)){
                printf("\nO logariasmos %i exei: %.2f$", account, database(account, 1, 0));
                printf("\nDialekse to poso pou thes na paralaveis: ");
                scanf("%lf", &lefta);
                if (lefta <= database(account, 1, 0)){
                    int a = (int)database(1, 3, 0), b = (int)database(2, 3, 0), c = (int)database(3, 3, 0), d = 0, e = 0, f = 0;
                    while((d+1)*20 <= lefta && (d+1) <= a){
                        d+=1;
                    }
                    while((e+1)*10 <= (lefta - d*20) && (e+1) <= b){
                        e+=1;
                    }
                    while((f+1)*5 <= (lefta - d*20 - e*10) && (f+1) <= c){
                        f+=1;
                    }
                    if (lefta == d*20 + e*10 + f*5){
                        database(account, 2, database(account, 1, 0) - lefta);
                        database(1, 4, a - d);
                        database(2, 4, b - e);
                        database(3, 4, c - f);
                        printf("\nH analipsi pragmatopoihthike me epitixia\nO logariasmos sou tora exei: %.2f$", database(account, 1, 0));
                    }
                    else printf("To ATM den mporei na se eksipiretisei!");
                }
                else printf("Den exeis arketa lefta gia na pragmatopoihseis afth thn analhpsh!");
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

void katathesi(){
    int account, i, a = (int)database(1, 3, 0), b = (int)database(2, 3, 0), c = (int)database(3, 3, 0), d = 0, e = 0, f = 0;
    clearscreen();
    printf("Parakalo dialekse ton trapeziko logariasmo sou: ____\b\b\b\b");
    scanf("%i", &account);
    if (account >= 4001 && account <= 5000){
        for (i=0; i<3; i++){
            if (askpass(account) == flipnumber(account)){
                printf("\nO logariasmos %i exei: %.2f$", account, database(account, 1, 0));
                printf("\nPosa xartonomismata ton 20$ tha valeis: ");
                scanf("%i", &d);
                printf("Posa xartonomismata ton 10$ tha valeis: ");
                scanf("%i", &e);
                printf("Posa xartonomismata ton 5$ tha valeis: ");
                scanf("%i", &f);
                database(account, 2, database(account, 1, 0) + d*20 + e*10 + f*5);
                database(1, 4, a + d);
                database(2, 4, b + e);
                database(3, 4, c + f);
                printf("\nH katathesh pragmatopoihthike me epitixia kai prostethikan %i$ ston logariasmo sou!\nO logariasmos sou tora exei: %.2f$", d*20 + e*10 + f*5, database(account, 1, 0));
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

void ipalilos1(){
    int i;
    char account[24];
    clearscreen();
    printf("Parakalo vale to onoma xristi: ");
    scanf("%s", account);
    if (strcmp(account, ipalilos_username) == 0){
        for (i=0; i<3; i++){
            if (askpass(0) == ipalilos_pass){
                printf("\nTa xaronomismata tou ATM einai:\n20$: %i -> %i$\n10$: %i -> %i$\n5$: %i -> %i$\nSinolika lefta: %i$", (int)database(1, 3, 0), (int)database(1, 3, 0)*20, (int)database(2, 3, 0), (int)database(2, 3, 0)*10, (int)database(3, 3, 0), (int)database(3, 3, 0)*5, (int)database(1, 3, 0)*20 + (int)database(2, 3, 0)*10 + (int)database(3, 3, 0)*5);
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

void ipalilos2(){
    int a = (int)database(1, 3, 0), b = (int)database(2, 3, 0), c = (int)database(3, 3, 0), d = 0, e = 0, f = 0, i;
    char account[24];
    clearscreen();
    printf("Parakalo vale to onoma xristi: ");
    scanf("%s", account);
    if (strcmp(account, ipalilos_username) == 0){
        for (i=0; i<3; i++){
            if (askpass(0) == ipalilos_pass){
                d = getrand(25, 75);
                e = getrand(50, 150);
                f = getrand(100, 200);
                database(1, 4, a + d);
                database(2, 4, b + e);
                database(3, 4, c + f);
                printf("\nProstethikan kainourgia xartonomismata.");
                printf("\nTa nea xartonomismata tou ATM einai:\n20$: %i -> %i$\n10$: %i -> %i$\n5$: %i -> %i$\nSinolika lefta: %i$", (int)database(1, 3, 0), (int)database(1, 3, 0)*20, (int)database(2, 3, 0), (int)database(2, 3, 0)*10, (int)database(3, 3, 0), (int)database(3, 3, 0)*5, (int)database(1, 3, 0)*20 + (int)database(2, 3, 0)*10 + (int)database(3, 3, 0)*5);
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

void ipalilos3(){
    int i;
    char account[24], epilogi;
    clearscreen();
    printf("Parakalo vale to onoma xristi: ");
    scanf("%s", account);
    if (strcmp(account, ipalilos_username) == 0){
        for (i=0; i<3; i++){
            if (askpass(0) == ipalilos_pass){
                printf("\nEisai sigouros oti thes na kleiseis to ATM?\nY\\N: ");
                scanf(" %c", &epilogi);
                if (epilogi == 'Y' || epilogi == 'y') shutdownatm();
                break;
            }
            if (i!=2) printf("\nO kodikos pou evales einai lathos. Exeis akoma %i prospathies\n", 2 - i);
            else printf("\nApetixes na valeis sosto kodiko!\n");
        }
    }
    else printf("O logariasmos aftos den iparxei!");
}

double database(int account, int mode, float newval){
    FILE *fl;
    double result;
    int i;
    if (fopen("database.txt", "r") == 0){
        fl = fopen("database.txt", "a");
        for (i=0; i<1000; i++){
            fprintf(fl, "%.2f\n", getfrand(100, 5000));
        }
        fprintf(fl, "%i\n%i\n%i\n", 50, 100, 100);
        fclose(fl);
    }
    if (mode == 1){
        account -= 4000;
        fl = fopen("database.txt", "r");
        for (i=0; i<account; i++){
            fscanf(fl, "%lf", &result);
        }
        fclose(fl);
        return result;
    }
    else if (mode == 2){
        FILE *temp;
        double line;
        account -= 4000;
        int a = (int)database(1, 3, 0), b = (int)database(2, 3, 0), c = (int)database(3, 3, 0);
        fl = fopen("database.txt", "r");
        temp = fopen("temp.txt", "w+");
        for (i=0; i<1000; i++){
            fscanf(fl, "%lf", &line);
            if (i + 1 == account) fprintf(temp, "%.2lf\n", newval);
            else fprintf(temp, "%.2lf\n", line);
        }
        fprintf(temp, "%i\n%i\n%i\n", a, b, c);
        fclose(fl);
        fclose(temp);
        fl = fopen("database.txt", "w+");
        temp = fopen("temp.txt", "r");
        for (i=0; i<1003; i++){
            fscanf(temp, "%lf", &line);
            fprintf(fl, "%.2f\n", line);
        }
        fclose(fl);
        fclose(temp);
        remove("temp.txt");
        return 0;
    }
    else if (mode == 3){
        float thirida;
        fl = fopen("database.txt", "r");
        for (i=0; i<1003; i++){
            fscanf(fl, "%f", &thirida);
            if (i == 1000 && account == 1) break;
            else if (i == 1001 && account == 2) break;
            else if (i == 1002 && account == 3) break;
        }
        fclose(fl);
        return thirida;
    }
    else{
        FILE *temp;
        double line;
        fl = fopen("database.txt", "r");
        temp = fopen("temp.txt", "w+");
        for (i=0; i<1003; i++){
            fscanf(fl, "%lf", &line);
            if (i == 1000 && account == 1) fprintf(temp, "%.2lf\n", newval);
            else if (i == 1001 && account == 2) fprintf(temp, "%.2lf\n", newval);
            else if (i == 1002 && account == 3) fprintf(temp, "%.2lf\n", newval);
            else fprintf(temp, "%.2lf\n", line);
        }
        fclose(fl);
        fclose(temp);
        fl = fopen("database.txt", "w+");
        temp = fopen("temp.txt", "r");
        for (i=0; i<1003; i++){
            fscanf(temp, "%lf", &line);
            fprintf(fl, "%.2f\n", line);
        }
        fclose(fl);
        fclose(temp);
        remove("temp.txt");
        return 0;
    }
}

int askpass(int account){
    if (account != 0) printf("Parakalo vale ton kodiko tou logariasmou %i: ____\b\b\b\b", account);
    else printf("Parakalo vale ton kodiko tou logariasmou ipalilou: ____\b\b\b\b");
    int code = 0, i;
    for (i=0; i<4; i++){
        int temp;
        temp = getch_();
        temp = temp - '0';
        if (i == 3) code += temp;
        else {code += temp; code *= 10;}
        printf("*");
    }
    getch_();
    printf("\n");
    return code;
}

int getrand(int start, int end){
    return (rand() % (end - start)) + start;
}

float getfrand(float start, float end){
    return ((((float)rand() / RAND_MAX) * (end - start + 1)) + start);
}

int flipnumber(int number){
    int newnumber=0;
	while (number>0){
		newnumber += number%10;
		newnumber *= 10;
		number /= 10;
	}
    return newnumber/10;
}

void shutdownatm(){
    running = 0;
    clearscreen();
    printf("SHUTTING DOWN ATM");
    sleep(1);
    clearscreen();
    printf("SHUTTING DOWN ATM.");
    sleep(1);
    clearscreen();
    printf("SHUTTING DOWN ATM..");
    sleep(1);
    clearscreen();
    printf("SHUTTING DOWN ATM...");
    sleep(1);
}