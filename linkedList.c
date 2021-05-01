#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatkul;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    nilaiMatkul kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen* prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L){
    int hasil = 0;
    if(L.first != NULL){
        // List tidak kosong
        elemen* tunjuk;

        // Inisialisasi
        tunjuk = L.first;
        
        while(tunjuk != NULL){
            // Proses
            hasil++;
            tunjuk = tunjuk -> next;
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
    //6 5 4 1 2 3
    // L first = 5
    // 6
    elemen* baru;
    baru = (elemen*) malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);
    if((*L).first == NULL){
        baru->next = NULL;
    }
    else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, char nim[], char nama[], char nilai[], list *L){
    // 6 5 4 1 2 3
    // 6 5 4 7 1 2 3
    elemen *baru;
    baru = (elemen*) malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);
    if(prev->next == NULL){
        baru->next = NULL;
    }
    else{
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addLast(char nim[], char nama[], char nilai[], list *L){
    if((*L).first == NULL){
        // Jika list adalah list kosong
        addFirst(nim, nama, nilai, L);
    }
    else{
        // JIka list tidak kosong
        // Mencari elemen terakhir list
        // 8 6 5 4 7 9 1 2 3 10
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            // Iterasi
            prev = prev->next;
        }
        addAfter(prev, nim, nama, nilai, L);
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
        // Jika list bukan list kosong
        // 1 2 3 4
        // .first =  nul
        elemen* hapus = (*L).first;
        if(countElement(*L) == 1){
            (*L).first = NULL;
        }
        else{
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* prev, list *L){
    elemen* hapus = prev->next;
    // 1 2 3 4
    // hapus = 3
    if(hapus != NULL){
        if(hapus->next == NULL){
            prev->next = NULL;
        }
        else{
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delLast(list *L){
    if((*L).first != NULL){
        // Jika list tidak kosong
        if(countElement(*L) == 1){
            // List terdiri dari 1 elemen
            delFirst(L);
        }
        else{
            // Mencari elemen terakhir list
            // 1 2 3 4
            elemen* last = (*L).first;
            elemen* prev;
            while(last->next != NULL){
                // Iterasi
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    if(countElement(*L) != 0){
        int i;
        for(i = countElement(*L); i >= 1; i--){
            // Proses menghapus elemen list
            delLast(L);
        }
    }
}

void printElement(list L){
    if(L.first != NULL){
        // Jika list tidak kosong
        // Inisialisasi
        elemen* tunjuk = L.first;
        
        int i = 1;
       
        while(tunjuk != NULL){
            // Proses
            printf("Elemen ke : %d\n", i);
            printf("NIM   : %s\n", tunjuk->kontainer.nim);
            printf("Nama  : %s\n", tunjuk->kontainer.nama);
            printf("Nilai : %s\n", tunjuk->kontainer.nilai);
            printf("-------------------------------\n");
            // Iterasi
            tunjuk = tunjuk->next;
            i++;
        }
    }
    else{
        // Jika list kosong
        printf("List Kosong\n");
    }
}

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