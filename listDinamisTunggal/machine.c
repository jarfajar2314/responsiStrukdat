#include "header.h"

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