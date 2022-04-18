#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

int running = 1;
char ipalilos_username[] = "GKOUMAS";
int ipalilos_pass = 4502;
int currentdate[3];
int thirides[3] = {200, 400, 400};

struct accdata{
    unsigned short account;
    unsigned short pin;
    char surname[28];
    char name[28];
    float money;
};
typedef struct accdata accdata;

struct transdata{
    float money;
    char type[3];
    unsigned short account;
    char day;
    char month;
    char year;
};
typedef struct transdata transdata;

struct dates{
    int d1;
    int m1;
    int y1;
    int d2;
    int m2;
    int y2;
};
typedef struct dates dates;

int mainpage();
void enimerosi();
void metafora();
void analipsi();
void katathesi();
void pliromes();
void allagipin();
void ipalilos1();
void ipalilos2();
void ipalilos3();
accdata accfinder(unsigned short);
transdata *transfinder(unsigned short);
void transadder(transdata);
void changemoney(int, float);
void changepin(int, int);
int dailywdramount(unsigned short);
int askpass();
int datecompare(dates);
void finddate();
void shutdownatm();

int main(){
    finddate();
    srand(time(NULL));
    for(;;){
        if (running != 1) {
            printf("\n");
            system("pause");
            break;
        }
        switch(mainpage()){
            case 1: {enimerosi(); getch(); break;}
            case 2: {metafora(); getch(); break;}
            case 3: {analipsi(); getch(); break;}
            case 4: {katathesi(); getch(); break;}
            case 5: {pliromes(); getch(); break;}
            case 6: {allagipin(); getch(); break;}
            case 101: {ipalilos1(); getch(); break;}
            case 102: {ipalilos2(); getch(); break;}
            case 103: {ipalilos3(); break;}
            case 0: {getch(); break;}
        }
    }
    return 0;
}

int mainpage(){
    int selection;
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n\t\t\t\t1. ENIMEROSI\t\t\t\t4. KATATHESI\n\n\t\t\t\t2. METAFORA\t\t\t\t5. PLIROMES\n\n\t\t\t\t3. ANALIPSI\t\t\t\t6. ALLAGI PIN\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO DIALEKSE MIA EPILOGI: ");
    scanf("%i", &selection);
    if ((selection >= 1 && selection <= 6) || (selection >= 101 && selection <= 103)) return selection;
    else {printf("\n\t\t\t\tH EPILOGH AFTI DEN IPARXEI!"); return 0;}
}

void enimerosi(){
    int input = 0, input2 = 0, i;
    accdata account, emptyacc = {0, 0, "", "", 0};
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ARITHMO TOU LOGARIASMOU SOU: ____\b\b\b\b");
    scanf("%i", &input);
    account = accfinder(input);
    if (account.account == input){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %i: ", account.account);
            if (askpass() == account.pin){
                printf("\n\t\t\t\t1. IPOLIPO 2. TELEFTAIES KINISEIS 3. LEPTOMERIES LOGARIASMOU\n\n\t\t\t\tPARAKALO EPILEKSE TO EIDOS ENIMEROSIS (1-3): ");
                scanf("%i", &input2);
                if (input2 == 1){
                    printf("\n\t\t\t\tO LOGARIASMOS %i EXEI: %.1f$", account.account, account.money);
                    break;
                }
                else if (input2 == 2){
                    transdata *transactions = transfinder(account.account);
                    int i;
                    printf("\n\t\t\t\tOI TELEFTAIES 4 KINISEIS TOU LOGARIASMOU %i EINAI:\n", account.account);
                    for (i=0; i<4; i++){
                        if (transactions[i].money != 0){
                            printf("\t\t\t\t%i/%i/%i %s %s%.1f\n", transactions[i].day, transactions[i].month, transactions[i].year, transactions[i].type, transactions[i].money > 0 ? "+" : "", transactions[i].money);
                        }
                    }
                    break;
                }
                else if (input2 == 3){
                    printf("\n\t\t\t\tTA STOIXEIA TOU LOGARIASMOU %i EINAI:\n\t\t\t\tEPONIMO: %s\n\t\t\t\tONOMA: %s\n\t\t\t\tIPOLIPO: %.1f$", account.account, account.surname, account.name, account.money);
                    break;
                }
                else{
                    printf("\n\t\t\t\tI EPILOGI AFTI DEN IPARXEI!");
                    break;
                }
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
    account = emptyacc;
}

void metafora(){
    int input = 0, input2 = 0, i;
    float money;
    accdata sender, receiver, emptyacc = {0, 0, "", "", 0};
    transdata trans, emptytrans = {0, "", 0, 0, 0, 0};
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ARITHMO TOU LOGARIASMOU SOU: ____\b\b\b\b");
    scanf("%i", &input);
    sender = accfinder(input);
    if (sender.account == input){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %i: ", sender.account);
            if (askpass() == sender.pin){
                printf("\n\t\t\t\tO LOGARIASMOS %i EXEI: %.1f$", sender.account, sender.money);
                printf("\n\n\t\t\t\tDIALEKSE TON PARALIPTI: ____\b\b\b\b");
                scanf("%i", &input2);
                receiver = accfinder(input2);
                if (receiver.account == input2){
                    if (sender.account != receiver.account){
                        printf("\n\t\t\t\tTA STOIXEIA TOU LOGARIASMOU %i EINAI:\n\t\t\t\tEPONIMO: %s\n\t\t\t\tONOMA: %s", receiver.account, receiver.surname, receiver.name);
                        printf("\n\n\t\t\t\tDIALEKSE TO POSO METAFORAS: ");
                        scanf("%f", &money);
                        if (money <= sender.money){
                            if (money > 0){
                                changemoney(sender.account, sender.money - money);
                                changemoney(receiver.account, receiver.money + money);
                                trans.money = -money;
                                strcpy(trans.type, "TRN");
                                trans.account = sender.account;
                                trans.day = currentdate[0];
                                trans.month = currentdate[1];
                                trans.year = currentdate[2] % 100;
                                transadder(trans);
                                trans.money = money;
                                trans.account = receiver.account;
                                transadder(trans);
                                printf("\n\t\t\t\tH METAFORA OLOKLIROTHIKE!");
                            }
                            else printf("\n\t\t\t\tTO POSO PREPEI NA KSEPERNAEI TA 0$!");
                        }
                        else printf("\n\t\t\t\tO LOGARIASMOS %i DEN EXEI ARKETA XRHMATA GIA AFTI TIN METAFORA!", sender.account);
                    }
                    else printf("\n\t\t\t\tDEN GINETAI NA METAFEREIS XRHMATA STON EAFTO SOU!");
                }
                else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
    sender = emptyacc;
    receiver = emptyacc;
    trans = emptytrans;
}

void analipsi(){
    int input = 0, i, temp[3] = {0, 0, 0};
    float money;
    accdata account, emptyacc = {0, 0, "", "", 0};
    transdata trans, emptytrans = {0, "", 0, 0, 0, 0};
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ARITHMO TOU LOGARIASMOU SOU: ____\b\b\b\b");
    scanf("%i", &input);
    account = accfinder(input);
    if (account.account == input){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %i: ", account.account);
            if (askpass() == account.pin){
                printf("\n\t\t\t\tO LOGARIASMOS %i EXEI: %.1f$", account.account, account.money);
                printf("\n\n\t\t\t\tDIALEKSE TO POSO ANALIPSIS: ");
                scanf("%f", &money);
                if (money <= account.money){
                    if (money > 0){
                        while((temp[0]+1)*20 <= money && (temp[0]+1) <= thirides[0]){
                            temp[0]+=1;
                        }
                        while((temp[1]+1)*10 <= (money - temp[0]*20) && (temp[1]+1) <= thirides[1]){
                            temp[1]+=1;
                        }
                        while((temp[2]+1)*5 <= (money - temp[0]*20 - temp[1]*10) && (temp[2]+1) <= thirides[2]){
                            temp[2]+=1;
                        }
                        if (money == temp[0]*20 + temp[1]*10 + temp[2]*5){
                            if (dailywdramount(account.account) + money <= 600){
                                thirides[0] -= temp[0];
                                thirides[1] -= temp[1];
                                thirides[2] -= temp[2];
                                changemoney(account.account, account.money - money);
                                trans.money = -money;
                                strcpy(trans.type, "WDR");
                                trans.account = account.account;
                                trans.day = currentdate[0];
                                trans.month = currentdate[1];
                                trans.year = currentdate[2] % 100;
                                transadder(trans);
                                printf("\n\t\t\t\tH ANALIPSI OLOKLIROTHIKE!");
                            }
                            else printf("\n\t\t\t\tDEN MPOREIS NA KSEPERASEIS TO IMERISIO POSO ANALIPSIS (600$)!\n\t\t\t\tTO SIMERINO POSO ANALIPSIS SOU EINAI: %i", dailywdramount(account.account));
                        }
                        else printf("\n\t\t\t\tTO ATM DEN MPOREI NA OLOKLIROSEI AFTI TIN ANALIPSI!");
                    }
                    else printf("\n\t\t\t\tTO POSO PREPEI NA KSEPERNAEI TA 0$!");
                }
                else printf("\n\t\t\t\tO LOGARIASMOS %i DEN EXEI ARKETA XRHMATA GIA AFTI TIN ANALIPSI!", account.account);
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
    account = emptyacc;
    trans = emptytrans;
}

void katathesi(){
    int input = 0, temp[3] = {0, 0, 0};
    accdata account, emptyacc = {0, 0, "", "", 0};
    transdata trans, emptytrans = {0, "", 0, 0, 0, 0};
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ARITHMO TOU LOGARIASMOU SOU: ____\b\b\b\b");
    scanf("%i", &input);
    account = accfinder(input);
    if (account.account == input){
        printf("\n\n\t\t\t\tDIALEKSE TON ARITHMO TON XARTONOMISMATON POU THA KATATHESEIS:\n\n\t\t\t\t20$: ");
        scanf("%i", &temp[0]);
        if (temp[0] < 0) temp[0] = 0;
        printf("\t\t\t\t10$: ");
        scanf("%i", &temp[1]);
        if (temp[1] < 0) temp[1] = 0;
        printf("\t\t\t\t5$: ");
        scanf("%i", &temp[2]);
        if (temp[2] < 0) temp[2] = 0;
        if ((temp[0]*20 + temp[1]*10 + temp[2]*5) > 0){
            thirides[0] += temp[0];
            thirides[1] += temp[1];
            thirides[2] += temp[2];
            changemoney(account.account, account.money + (temp[0]*20 + temp[1]*10 + temp[2]*5));
            trans.money = (temp[0]*20 + temp[1]*10 + temp[2]*5);
            strcpy(trans.type, "DEP");
            trans.account = account.account;
            trans.day = currentdate[0];
            trans.month = currentdate[1];
            trans.year = currentdate[2] % 100;
            transadder(trans);
            printf("\n\t\t\t\tH KATATHESI OLOKLIROTHIKE!");
        }
        else printf("\n\t\t\t\tTO POSO PREPEI NA KSEPERNAEI TA 0$!");
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
    account = emptyacc;
    trans = emptytrans;
}

void pliromes(){
    int input = 0, input2 = 0, i;
    float money;
    accdata account, emptyacc = {0, 0, "", "", 0};
    transdata trans, emptytrans = {0, "", 0, 0, 0, 0};
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ARITHMO TOU LOGARIASMOU SOU: ____\b\b\b\b");
    scanf("%i", &input);
    account = accfinder(input);
    if (account.account == input){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %i: ", account.account);
            if (askpass() == account.pin){
                printf("\n\t\t\t\t1. ENOIKIO 2. LOGARIASMOI (p.x. DEH, IDREFSI)\n\n\t\t\t\tPARAKALO EPILEKSE TO EIDOS PLIROMIS (1-2): ");
                scanf("%i", &input2);
                if (input2 == 1){
                    strcpy(trans.type, "RNT");
                }
                else if (input2 == 2){
                    strcpy(trans.type, "EXP");
                }
                else{
                    printf("\n\t\t\t\tI EPILOGI AFTI DEN IPARXEI!");
                    break;
                }
                printf("\n\t\t\t\tO LOGARIASMOS %i EXEI: %.1f$", account.account, account.money);
                printf("\n\n\t\t\t\tVALE TO POSO TIS PLIROMIS: ");
                scanf("%f", &money);
                if (money <= account.money){
                    if (money > 0){
                        changemoney(account.account, account.money - money);
                        trans.money = -money;
                        trans.account = account.account;
                        trans.day = currentdate[0];
                        trans.month = currentdate[1];
                        trans.year = currentdate[2] % 100;
                        transadder(trans);
                        printf("\n\t\t\t\tH PLIROMI OLOKLIROTHIKE!");
                    }
                    else printf("\n\t\t\t\tTO POSO PREPEI NA KSEPERNAEI TA 0$!");
                }
                else printf("\n\t\t\t\tO LOGARIASMOS %i DEN EXEI ARKETA XRHMATA GIA AFTI TIN PLIROMI!", account.account);
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
    account = emptyacc;
    trans = emptytrans;
}

void allagipin(){
    int input = 0, input2 = 0, i;
    accdata account, emptyacc = {0, 0, "", "", 0};
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ARITHMO TOU LOGARIASMOU SOU: ____\b\b\b\b");
    scanf("%i", &input);
    account = accfinder(input);
    if (account.account == input){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %i: ", account.account);
            if (askpass() == account.pin){
                printf("\n\t\t\t\tPARAKALO VALE TO NEO PIN: ");
                input2 = askpass();
                printf("\n\t\t\t\tEPIVEVAIOSE TO NEO PIN: ");
                if (askpass() == input2){
                    changepin(account.account, input2);
                    printf("\n\t\t\t\tTO PIN SOU ALLAKSE ME EPITIXIA!");
                }
                else printf("\n\t\t\t\tAPETIXES NA EPIVEVAIOSEIS TO PIN!");
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
    account = emptyacc;
    input2 = 0;
}

void ipalilos1(){
    int i;
    char account[28];
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ONOMA TOU LOGARIASMOU SOU: ");
    scanf("%s", account);
    if (strcmp(account, ipalilos_username) == 0){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %s: ", account);
            if (askpass() == ipalilos_pass){
                printf("\n\t\t\t\tOI THIRIDES TOU ATM EINAI:\n\t\t\t\t20$: %i -> %i$\n\t\t\t\t10$: %i -> %i$\n\t\t\t\t5$: %i -> %i$\n\t\t\t\tSINOLO THIRIDON: %i$", thirides[0], thirides[0]*20, thirides[1], thirides[1]*10, thirides[2], thirides[2]*5, thirides[0]*20 + thirides[1]*10 + thirides[2]*5);
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
}

void ipalilos2(){
    int i;
    char account[28];
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ONOMA TOU LOGARIASMOU SOU: ");
    scanf("%s", account);
    if (strcmp(account, ipalilos_username) == 0){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %s: ", account);
            if (askpass() == ipalilos_pass){
                if ((thirides[0]*20 + thirides[1]*10 + thirides[2]*5) <= 4000){
                    thirides[0] += 100;
                    thirides[1] += 250;
                    thirides[2] += 500;
                    printf("\n\t\t\t\tPARAKALO PERIMENE");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf("\n\n\t\t\t\tH TROFODOSIA OLOKLIROTHIKE!");
                }
                else printf("\n\t\t\t\tH TROFODOSIA APETIXE!\n\t\t\t\tGIA NA TROFODOTISEIS TO ATM PREPEI NA EXEI LIGOTERA APO 4000$!\n\t\t\t\tTO ATM TORA EXEI: %i$", thirides[0]*20 + thirides[1]*10 + thirides[2]*5);
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
}

void ipalilos3(){
    int i;
    char account[28], epilogi;
    system("cls");
    printf("\t\t\t\t  PEIRAMATIKO ATM TMHMATOS PLIROFORIKIS - %i/%i/%i\n\t\t\t\t_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n", currentdate[0], currentdate[1], currentdate[2]);
    printf("\t\t\t\tPARAKALO VALE TON ONOMA TOU LOGARIASMOU SOU: ");
    scanf("%s", account);
    if (strcmp(account, ipalilos_username) == 0){
        for (i=0; i<3; i++){
            printf("\n\t\t\t\tPARAKALO VALE TON KODIKO TOU LOGARIASMOU %s: ", account);
            if (askpass() == ipalilos_pass){
                printf("\n\t\t\t\tEISAI SIGOUROS OTI THES NA APENERGOPOIHSEIS TO ATM?\n\t\t\t\t(Y/N): ");
                scanf(" %c", &epilogi);
                if (epilogi == 'Y' || epilogi == 'y') shutdownatm();
                else getch();
                break;
            }
            if (i!=2) printf("\n\t\t\t\tO KODIKOS POU EVALES EINAI LATHOS! EXEIS AKOMA %i PROSPATHIES\n", 2 - i);
            else printf("\n\t\t\t\tAPETIXES NA VALEIS SOSTO KODIKO!\n");
        }
    }
    else printf("\n\t\t\t\tO LOGARIASMOS AFTOS DEN IPARXEI!");
}

accdata accfinder(unsigned short account){
    FILE *file;
    accdata output, emptyacc = {0, 0, "", "", 0};
    int found = 0;
    if ((file = fopen("accounts", "rb")) != NULL){
        while (fread(&output.account, sizeof(output.account), 1, file) > 0){
            fread(&output.pin, sizeof(output.pin), 1, file);
            fread(&output.surname, sizeof(output.surname), 1, file);
            fread(&output.name, sizeof(output.name), 1, file);
            fread(&output.money, sizeof(output.money), 1, file);
            if (output.account == account){
                found = 1;
                break;
            }
        }
        fclose(file);
        if (found == 0){
            output.account = 0;
        }
        return output;
    }
    else {
        system("cls");
        printf("TO ARXEIO \"accounts\" DEN VRETHIKE!\n");
        system("pause");
        exit(1);
    }
}

transdata *transfinder(unsigned short account){
    FILE *file;
    static transdata output[4], temp[4], final[4];
    transdata start, emptytrans = {0, "", 0, 0, 0, 0};
    dates data;
    int current = 0;
    if ((file = fopen("transactions", "rb")) != NULL){
        while (fread(&start.money, sizeof(start.money), 1, file) > 0){
            fread(&start.type, sizeof(start.type), 1, file);
            fseek(file, 1, SEEK_CUR);
            fread(&start.account, sizeof(start.account), 1, file);
            fread(&start.day, sizeof(start.day), 1, file);
            fread(&start.month, sizeof(start.month), 1, file);
            fread(&start.year, sizeof(start.year), 1, file);
            fseek(file, 3, SEEK_CUR);
            if (start.account == account){
                output[current].money = start.money;
                strcpy(output[current].type, start.type);
                output[current].account = start.account;
                output[current].day = start.day;
                output[current].month = start.month;
                output[current].year = start.year;
                if (current == 3){
                    current = 0;
                }
                else{
                    current += 1;
                }
            }
        }
        final[0] = output[0];
        data.d1 = final[0].day; data.m1 = final[0].month; data.y1 = final[0].year; data.d2 = output[1].day; data.m2 = output[1].month; data.y2 = output[1].year;
        if (datecompare(data) == 1){
            final[1] = output[1];
        }
        else{
            final[0] = output[1];
            final[1] = output[0];
        }

        data.d1 = final[1].day; data.m1 = final[1].month; data.y1 = final[1].year; data.d2 = output[2].day; data.m2 = output[2].month; data.y2 = output[2].year;
        if (datecompare(data) == 1){
            final[2] = output[2];
        }
        else{
            data.d1 = final[0].day; data.m1 = final[0].month; data.y1 = final[0].year; data.d2 = output[2].day; data.m2 = output[2].month; data.y2 = output[2].year;
            if (datecompare(data) == 1){
                temp[0] = final[1];
                final[1] = output[2];
                final[2] = temp[0];
            }
            else{
                temp[0] = final[0];
                final[0] = output[2];
                temp[1] = final[1];
                final[1] = temp[0];
                final[2] = temp[1];
            }
        }

        data.d1 = final[2].day; data.m1 = final[2].month; data.y1 = final[2].year; data.d2 = output[3].day; data.m2 = output[3].month; data.y2 = output[3].year;
        if (datecompare(data) == 1){
            final[3] = output[3];
        }
        else{
            data.d1 = final[1].day; data.m1 = final[1].month; data.y1 = final[1].year; data.d2 = output[3].day; data.m2 = output[3].month; data.y2 = output[3].year;
            if (datecompare(data) == 1){
                temp[0] = final[2];
                final[2] = output[3];
                final[3] = temp[0];
            }
            else{
                data.d1 = final[0].day; data.m1 = final[0].month; data.y1 = final[0].year; data.d2 = output[3].day; data.m2 = output[3].month; data.y2 = output[3].year;
                if (datecompare(data) == 1){
                    temp[0] = final[1];
                    final[1] = output[3];
                    temp[1] = final[2];
                    final[2] = temp[0];
                    final[3] = temp[1];

                }
                else{
                    temp[0] = final[0];
                    final[0] = output[3];
                    temp[1] = final[1];
                    final[1] = temp[0];
                    temp[2] = final[2];
                    final[2] = temp[1];
                    final[3] = temp[2];
                }
            }
        }
        fclose(file);
        return final;
    }
    else {
        system("cls");
        printf("TO ARXEIO \"transactions\" DEN VRETHIKE!\n");
        system("pause");
        exit(1);
    }
}

void transadder(transdata trans){
    FILE *file;
    if ((file = fopen("transactions", "rb+")) != NULL){
        char empty = 0;
        fseek(file, 0, SEEK_END);
        fwrite(&trans.money, sizeof(trans.money), 1, file);
        fwrite(&trans.type, sizeof(trans.type), 1, file);
        fwrite(&empty, sizeof(empty), 1, file);
        fwrite(&trans.account, sizeof(trans.account), 1, file);
        fwrite(&trans.day, sizeof(trans.day), 1, file);
        fwrite(&trans.month, sizeof(trans.month), 1, file);
        fwrite(&trans.year, sizeof(trans.year), 1, file);
        fwrite(&empty, sizeof(empty), 1, file);
        fwrite(&empty, sizeof(empty), 1, file);
        fwrite(&empty, sizeof(empty), 1, file);
        fclose(file);
    }
    else {
        system("cls");
        printf("TO ARXEIO \"transactions\" DEN VRETHIKE!\n");
        system("pause");
        exit(1);
    }
}

void changemoney(int account, float money){
    FILE *file;
    accdata temp;
    if ((file = fopen("accounts", "rb+")) != NULL){
        while (fread(&temp.account, sizeof(temp.account), 1, file) > 0){
            fread(&temp.pin, sizeof(temp.pin), 1, file);
            fread(&temp.surname, sizeof(temp.surname), 1, file);
            fread(&temp.name, sizeof(temp.name), 1, file);
            if (temp.account == account){
                fseek(file, 0, SEEK_CUR);
                fwrite(&money, sizeof(money), 1, file);
                break;
            }
            else{
                fread(&temp.money, sizeof(temp.money), 1, file);
            }
        }
        fclose(file);
    }
    else {
        system("cls");
        printf("TO ARXEIO \"accounts\" DEN VRETHIKE!\n");
        system("pause");
        exit(1);
    }
}

void changepin(int account, int pin){
    FILE *file;
    accdata temp;
    if ((file = fopen("accounts", "rb+")) != NULL){
        while (fread(&temp.account, sizeof(temp.account), 1, file) > 0){
            if (temp.account == account){
                fseek(file, 0, SEEK_CUR);
                fwrite(&pin, sizeof(pin), 1, file);
                break;
            }
            else{
                fread(&temp.pin, sizeof(temp.pin), 1, file);
                fread(&temp.surname, sizeof(temp.surname), 1, file);
                fread(&temp.name, sizeof(temp.name), 1, file);
                fread(&temp.money, sizeof(temp.money), 1, file);
            }
        }
        fclose(file);
    }
    else {
        system("cls");
        printf("TO ARXEIO \"accounts\" DEN VRETHIKE!\n");
        system("pause");
        exit(1);
    }
}

int dailywdramount(unsigned short account){
    FILE *file;
    transdata temp;
    int output = 0;
    if ((file = fopen("transactions", "rb")) != NULL){
        while (fread(&temp.money, sizeof(temp.money), 1, file) > 0){
            fread(&temp.type, sizeof(temp.type), 1, file);
            fseek(file, 1, SEEK_CUR);
            fread(&temp.account, sizeof(temp.account), 1, file);
            fread(&temp.day, sizeof(temp.day), 1, file);
            fread(&temp.month, sizeof(temp.month), 1, file);
            fread(&temp.year, sizeof(temp.year), 1, file);
            fseek(file, 3, SEEK_CUR);
            if (temp.account == account){
                if ((temp.day == currentdate[0]) && (temp.month == currentdate[1]) && (temp.year == currentdate[2] % 100) && (strcmp(temp.type, "WDR") == 0)){
                    output += (temp.money * -1);
                }
            }
        }
        return output;
    }
    else {
        system("cls");
        printf("TO ARXEIO \"transactions\" DEN VRETHIKE!\n");
        system("pause");
        exit(1);
    }
}

int askpass(){
    printf("____\b\b\b\b");
    int code = 0, temp, i;
    for (i=0; i<4; i++){
        int temp;
        temp = getch();
        temp = temp - '0';
        if (i == 3) code += temp;
        else {code += temp; code *= 10;}
        printf("*");
    }
    getch();
    printf("\n");
    return code;
}

int datecompare(dates data){
    if ((data.y1 > data.y2) || (data.y1 == data.y2 && data.m1 > data.m2) || (data.y1 == data.y2 && data.m1 == data.m2 && data.d1 > data.d2)){
        return 1;
    }
    return 2;
}

void finddate(){
    char input;
    time_t tm = time(NULL);
    struct tm stm = *localtime(&tm);
    currentdate[0] = stm.tm_mday;
    currentdate[1] = stm.tm_mon + 1;
    currentdate[2] = stm.tm_year + 1900;
    system("cls");
    printf("ENTOPISTIKE H IMEROMINIA TOU SISTIMATOS: %i/%i/%i\nTHELEIS NA TIN ALLAKSEIS?\n(Y/N): ", currentdate[0], currentdate[1], currentdate[2]);
    scanf(" %c", &input);
    if (input == 'Y' || input == 'y'){
        int temp[3] = {0, 0, 0};
        int done = 0;
        for(;;){
            if (done == 1) break;
            printf("\nVALE TIN NEA IMEROMINIA ME TI MORFI d/M/yyyy (p.x 1/10/2022): ");
            scanf("%i/%i/%i", &temp[0], &temp[1], &temp[2]);
            if ((temp[0] > 0) && (temp[1] > 0) && (temp[2] > 0)){
                printf("NEA IMEROMINIA: %i/%i/%i", temp[0], temp[1], temp[2]);
                done = 1;
                currentdate[0] = temp[0];
                currentdate[1] = temp[1];
                currentdate[2] = temp[2];
                getch();
            }
            else printf("\nH IMEROMINIA POU EVALES DEN EINAI EGKIRI!\n");
        }
    }
}

void shutdownatm(){
    running = 0;
    system("cls");
    printf("THE ATM IS SHUTTING DOWN");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
}