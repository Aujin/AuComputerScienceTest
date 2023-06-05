//
// Created by JXR on 2023/6/1.
//
#include "seqlist.h"

bool InitSeqList(SeqList *L) {
    L->length = 0;
    return true;
}

int SeqListLength(SeqList L) {
    return L.length;
}

int SeqListLocateElem(SeqList L, ElemType e) {
    if (!L.length) return 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i;
    }
    return 0;
}

ElemType SeqListGetElem(SeqList L, int i) {
    if (i < 1 || i > L.length) return 0;
    return L.data[i - 1];
}

bool SeqListInsert(SeqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return false;
    if (L->length >= MaxSize) return false;
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool SeqListDelete(SeqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->data[L->length] = 0;
    L->length--;
    return true;
}

bool PrintSeqList(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    return true;
}

bool SeqListEmpty(SeqList L) {
    if (!L.length) return true;
    return false;
}

bool DestroySeqList(SeqList *L) {
    free(L->data);
    L->length = 0;
    return true;
}

bool TestSeqList() {
    SeqList test;
    InitSeqList(&test);
    if (SeqListEmpty(test)) printf("empty\n");
    else printf("not empty\n");
    for (int i = 0; i < 30; i++) {
        SeqListInsert(&test, i + 1, i * i);
    }
    printf("%d\n", SeqListLength(test));
    if (SeqListEmpty(test)) printf("empty\n");
    else printf("not empty\n");
    printf("%d\n", SeqListLocateElem(test, 400));
    printf("%d\n", SeqListGetElem(test, 20));
    int E;
    SeqListDelete(&test, 3, &E);
    printf("%d\n", E);
    PrintSeqList(test);
    DestroySeqList(&test);
    return true;
}