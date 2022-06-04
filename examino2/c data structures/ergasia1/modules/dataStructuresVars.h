#ifndef DATA_STRUCTURES_VARS_H
#define DATA_STRUCTURES_VARS_H

/* STACK (STIVA) */

struct StackData{
    int start;
    int stop;
};

typedef struct StackData StackData;

/* QUEUE (OURA) */

struct QueueData{
    // Passenger Queue
    int key;
};

typedef struct QueueData QueueData;

/* PRIORITY QUEUE (OURA PROTERAIOTITAS) */

struct PQData{
    int start;
    int stop;
    int pID;
};

typedef struct PQData PQData;

/* LINKED LIST (SINDEDEMENI LISTA) */

struct LLData{
    // Bus Stops
    int number;
    int codenum;
    char name[40];
};

typedef struct LLData LLData;

#endif