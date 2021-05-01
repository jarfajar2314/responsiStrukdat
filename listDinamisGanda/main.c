#include "header.h"
int main(){
    list L;
    createList(&L);
    printElement(L);
    printf("==============\n");
    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L);
    addLast("3", "Orang_3", "A", &L);
    addLast("4", "Orang_4", "A", &L);
    addLast("5", "Orang_5", "A", &L);
    addLast("6", "Orang_6", "A", &L);
    addLast("7", "Orang_7", "A", &L);
    addLast("8", "Orang_8", "A", &L);
    addLast("9", "Orang_9", "A", &L);
    addLast("10", "Orang_10", "A", &L);
    addLast("11", "Orang_11", "A", &L);
    printElement(L);
    printf("==============\n");
    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);
    printf("==============\n");

    return 0;
}