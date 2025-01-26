#ifndef DATA_STRUCTURES_VARS_H
#define DATA_STRUCTURES_VARS_H

/* STACK (STIVA) */

struct StackData{
    int valid;
};

typedef struct StackData StackData;

/* QUEUE (OURA) */

struct QueueData{
    int valid;
};

typedef struct QueueData QueueData;

/* PRIORITY QUEUE (OURA PROTERAIOTITAS) */

struct PQData{
    int valid;
};

typedef struct PQData PQData;

/* LINKED LIST (SINDEDEMENI LISTA) */

struct LLData{
    int valid;
    int from;
    int to;
    int weight;
};

typedef struct LLData LLData;

/* BINARY TREE (DIADIKO DENTRO) */

struct BTData{
    int valid;
};

typedef struct BTData BTData;

/* GRAPH (GRAFOS) */

struct GRData{
    int valid;
};

typedef struct GRData GRData;


/* HASHING TABLE (KATAKERMATISMOS) */

struct HTData{
    int valid;
};

typedef struct HTData HTData;

#endif