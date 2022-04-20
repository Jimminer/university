#ifndef DATA_STRUCTURES_VARS_H
#define DATA_STRUCTURES_VARS_H

/* STACK (STIVA) */

struct StackData{
    int number;
};

typedef struct StackData StackData;

/* QUEUE (OURA) */

struct QueueData{
    int number;
};

typedef struct QueueData QueueData;

/* PRIORITY QUEUE (OURA PROTERAIOTITAS) */

struct PQData{
    int size;
    float money;
};

typedef struct PQData PQData;

/* LINKED LIST (SINDEDEMENI LISTA) */

struct LLData{
    int key;
};

typedef struct LLData LLData;

#endif