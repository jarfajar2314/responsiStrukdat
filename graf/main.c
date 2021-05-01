#include "header.h"
int main(){
    graph G;

    createEmpty(&G);
    addSimpul('A', &G);
    addSimpul('B', &G);
    addSimpul('C', &G);
    addSimpul('D', &G);
    addSimpul('E', &G);
    addSimpul('F', &G);

    simpul *begin = findSimpul('A', G);
    simpul *end = findSimpul('B', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }

    begin = findSimpul('B', G);
    end = findSimpul('D', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }

    end = findSimpul('E', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 7);
    }

    begin = findSimpul('C', G);
    end = findSimpul('A', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }

    begin = findSimpul('D', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 8);
    }

    end = findSimpul('C', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }

    begin = findSimpul('E', G);
    end = findSimpul('D', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 4);
    }

    end = findSimpul('F', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 4);
    }

    begin = findSimpul('F', G);
    end = findSimpul('D', G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 2);
    }

    printf("=================\n");
    printGraph(G);
    printf("\n=================\n");

    begin = findSimpul('A', G);
    if(begin != NULL){
        delJalur('B', begin);
    }

    printf("=================\n");
    printf("setelah dihapus\n");
    printGraph(G);
    printf("\n=================\n");

    return 0;
}