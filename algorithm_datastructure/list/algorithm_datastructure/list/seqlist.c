#include "seqlist.h"

bool InitList(SeqList *L) {
    L->data = 0;
    L->data = (ElemType *) malloc(sizeof(ElemType) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
    if (L->data) {
        return true;
    } else {
        return false;
    }
}

int Length(SeqList L) {
    return L.length;
}

int LocateElem(SeqList L, ElemType e) {
    if (!L.length) return 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i;
    }
    return 0;
}

ElemType GetElem(SeqList L, int i) {
    if (i < 1 || i > L.length) return 0;
    return L.data[i - 1];
}

bool ListInsert(SeqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return false;
    if (L->length >= L->MaxSize) return false;
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(SeqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->data[L->length] = 0;
    L->length--;
    return true;
}

bool PrintList(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    return true;
}

bool Empty(SeqList L) {
    if (!L.length) return true;
    return false;
}


bool DestroyList(SeqList *L) {
    free(L->data);
    L->length = 0;
    return true;
}