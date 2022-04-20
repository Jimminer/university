#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataStructures.h"
#include "dataStructuresVars.h"

int currentStop = 0;
int passengerID = 0;
int notServed = 0;
int highOn = 0;
int highOnStop = 0;
int highGettingOff = 0;
int highGettingOffStop = 0;
int avgDist = 0;

void init(LList*, PQueue*);
void nextStop(LList*, PQueue*, Queue*, Stack*);

int main(){
    int i;
    LList *busStops = createLList();
    PQueue *passengers = createPQueue(0);
    Queue *gettingOn = createQueue(85);
    Stack *gettingOff = createStack(85);

    srand(4502);
    init(busStops, passengers);

    while (currentStop<30){
        nextStop(busStops, passengers, gettingOn, gettingOff);
    }

    LLData lldata, lldata2, lldata3;
    lldata = peekLList(busStops, highOnStop);
    lldata2 = peekLList(busStops, highOnStop+1);
    lldata3 = peekLList(busStops, highGettingOffStop);
    printf("\nPlirofories dromologiou:\n1. Eksipiretithikan sinolika %i atoma\n2. %i atoma den eksipiretithikan\n3. Metaksi ton staseon %i - %i to leoforeio eixe %i epivates\n4. Sti stasi %i katevikan %i atoma\n5. Mesos oros aposastis metrimenos se staseis: %f", passengerID, notServed, lldata.number, lldata2.number, highOn, lldata3.number, highGettingOff, (float)avgDist/(float)passengerID);
    return 0;
}

void init(LList *busStops, PQueue *passengers){
    int i;
    LLData lldata;
    PQData pqdata;

    lldata.number = 1; lldata.codenum = 13011; strcpy(lldata.name, "T.S. K.T.E.L.");
    addLList(busStops, -1, lldata);
    lldata.number = 2; lldata.codenum = 13013; strcpy(lldata.name, "GEFIRA");
    addLList(busStops, -1, lldata);
    lldata.number = 3; lldata.codenum = 1435; strcpy(lldata.name, "XARTOPOIIA");
    addLList(busStops, -1, lldata);
    lldata.number = 4; lldata.codenum = 1437; strcpy(lldata.name, "GIPEDO THERMAIKOU");
    addLList(busStops, -1, lldata);
    lldata.number = 5; lldata.codenum = 1283; strcpy(lldata.name, "BIRSODEPSEIO");
    addLList(busStops, -1, lldata);
    lldata.number = 6; lldata.codenum = 1281; strcpy(lldata.name, "SFAGEIA");
    addLList(busStops, -1, lldata);
    lldata.number = 7; lldata.codenum = 1279; strcpy(lldata.name, "FIX");
    addLList(busStops, -1, lldata);
    lldata.number = 8; lldata.codenum = 1323; strcpy(lldata.name, "KTIRIA PER/REIAS KEN/KIS MAK/NIAS");
    addLList(busStops, -1, lldata);
    lldata.number = 9; lldata.codenum = 1325; strcpy(lldata.name, "MEGARA");
    addLList(busStops, -1, lldata);
    lldata.number = 10; lldata.codenum = 1327; strcpy(lldata.name, "KENTRO DIERXOMENON");
    addLList(busStops, -1, lldata);
    lldata.number = 11; lldata.codenum = 1330; strcpy(lldata.name, "NEA DIKASTIRIA");
    addLList(busStops, -1, lldata);
    lldata.number = 12; lldata.codenum = 1307; strcpy(lldata.name, "KOLOMVOU");
    addLList(busStops, -1, lldata);
    lldata.number = 13; lldata.codenum = 1459; strcpy(lldata.name, "ANTIGONIDON");
    addLList(busStops, -1, lldata);
    lldata.number = 14; lldata.codenum = 1043; strcpy(lldata.name, "PLATEIA ARISTOTELOUS");
    addLList(busStops, -1, lldata);
    lldata.number = 15; lldata.codenum = 1046; strcpy(lldata.name, "MITROPOLITOU GENNADIOU");
    addLList(busStops, -1, lldata);
    lldata.number = 16; lldata.codenum = 1048; strcpy(lldata.name, "AGIAS SOFIAS");
    addLList(busStops, -1, lldata);
    lldata.number = 17; lldata.codenum = 1049; strcpy(lldata.name, "IASONIDOU");
    addLList(busStops, -1, lldata);
    lldata.number = 18; lldata.codenum = 1052; strcpy(lldata.name, "KAMARA");
    addLList(busStops, -1, lldata);
    lldata.number = 19; lldata.codenum = 1139; strcpy(lldata.name, "A.X.E.P.A.");
    addLList(busStops, -1, lldata);
    lldata.number = 20; lldata.codenum = 1135; strcpy(lldata.name, "AGIA FOTEINI-PAN/MIO MAK/NIAS");
    addLList(busStops, -1, lldata);
    lldata.number = 21; lldata.codenum = 1123; strcpy(lldata.name, "STR/GEIO-MOUSEIO BIZ. POL.");
    addLList(busStops, -1, lldata);
    lldata.number = 22; lldata.codenum = 1124; strcpy(lldata.name, "EYZONON-GALLIKO INS/TO");
    addLList(busStops, -1, lldata);
    lldata.number = 23; lldata.codenum = 1175; strcpy(lldata.name, "THEAGENEIO");
    addLList(busStops, -1, lldata);
    lldata.number = 24; lldata.codenum = 1178; strcpy(lldata.name, "KIVELEIA");
    addLList(busStops, -1, lldata);
    lldata.number = 25; lldata.codenum = 1180; strcpy(lldata.name, "IPPOKRATEIO");
    addLList(busStops, -1, lldata);
    lldata.number = 26; lldata.codenum = 1191; strcpy(lldata.name, "DIMITRIOU MITROPOULOU");
    addLList(busStops, -1, lldata);
    lldata.number = 27; lldata.codenum = 1267; strcpy(lldata.name, "MPOTSARI");
    addLList(busStops, -1, lldata);
    lldata.number = 28; lldata.codenum = 1410; strcpy(lldata.name, "BRISAKI");
    addLList(busStops, -1, lldata);
    lldata.number = 29; lldata.codenum = 1408; strcpy(lldata.name, "25HS MARTIOU");
    addLList(busStops, -1, lldata);
    lldata.number = 30; lldata.codenum = 1407; strcpy(lldata.name, "T.S. BOULGARI");
    addLList(busStops, -1, lldata);

    currentStop = 1;
    int randPassengers = rand() % 15;
    for (i=0; i<randPassengers; i++){
        passengerID++;
        int stop = rand() % 29 + 2;
        pqdata.start = currentStop; pqdata.stop = stop; pqdata.pID = passengerID;
        addPQueue(passengers, stop, pqdata);
    }
    lldata = peekLList(busStops, currentStop-1);
    printf("Trexon stasi: %i - %s\n%i epivates epivivastikan\n0 epivates apovivastikan\n0 epivates den eksipiretithikan\nTo leoforeio exei sinolika %i epivates.\n\n", lldata.number, lldata.name, randPassengers, passengerID);
}

void nextStop(LList *busStops, PQueue *passengers, Queue *gettingOn, Stack *gettingOff){
    int i = 0, gotOff = 0, randPassengers;
    LLData lldata;
    PQData pqdata;
    QueueData queuedata;
    StackData stackdata;

    currentStop++;
    
    for (i=0; i<getSizePQueue(passengers); i++){
        pqdata = peekPQueue(passengers);
        if (pqdata.stop == currentStop){
            avgDist += pqdata.stop - pqdata.start;
            stackdata.start = pqdata.start; stackdata.stop = pqdata.stop;
            addStack(gettingOff, stackdata);
        }
        else break;
    }

    for (i=0; i<getSizeStack(gettingOff); i++){
        removePQueue(passengers);
    }
    
    if (currentStop != 30){
        randPassengers = rand() % 7;
        for (i=0; i<randPassengers; i++){
            queuedata.key = i;
            addQueue(gettingOn, queuedata);
        }

        for (i=0; i<randPassengers; i++){
            if (getSizePQueue(passengers) >= 85) break;
            removeQueue(gettingOn);
            passengerID++;
            int stop = rand() % (30-currentStop) + currentStop+1;
            pqdata.start = currentStop; pqdata.stop = stop; pqdata.pID = passengerID;
            addPQueue(passengers, stop, pqdata);
        }
    }

    lldata = peekLList(busStops, currentStop-1);
    printf("Trexon stasi: %i - %s\n%i epivates epivivastikan\n%i epivates apovivastikan\n%i epivates den eksipiretithikan\nTo leoforeio exei sinolika %i epivates.\n\n", lldata.number, lldata.name, randPassengers-getSizeQueue(gettingOn), getSizeStack(gettingOff), getSizeQueue(gettingOn), getSizePQueue(passengers));

    randPassengers = 0;
    notServed += getSizeQueue(gettingOn);

    if (highOn<getSizePQueue(passengers)){
        highOn = getSizePQueue(passengers);
        highOnStop = currentStop - 1;
    }

    if (highGettingOff<getSizeStack(gettingOff)){
        highGettingOff = getSizeStack(gettingOff);
        highGettingOffStop = currentStop - 1;
    }

    emptyQueue(gettingOn);
    emptyStack(gettingOff);
}
