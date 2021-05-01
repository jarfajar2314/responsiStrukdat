#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
}simpul;

typedef struct jlr{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
}jalur;

typedef struct{
    simpul* first;
}graph;

void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *awal,simpul*tujuan,int beban);
void delJalur(char ctujuan, simpul *awal);
void delAll(simpul*awal);
void delSimpul(char c, graph *G);
void printGraph(graph G);
simpul* findSimpul(char c, graph G);