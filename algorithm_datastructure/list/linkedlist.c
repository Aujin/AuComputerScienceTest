//
// Created by JXR on 2023/6/1.
//
#include "linkedlist.h"

bool InitList(LinkedList *L) {
    (*L)=(LNode*)malloc(sizeof(LNode));
    (*L)->data=0;
    (*L)->next=NULL;
}

int Length(LinkedList L) {
    int i = 0;
    LNode *p=L;
    while (p->next){
        p=p->next;
        i++;
    }
    return i;
}

int LocateElem(LinkedList L, ElemType e) {
    if (!L.length) return 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i;
    }
    return 0;
}

LNode GetElem(LinkedList L, int i) {
    if (i < 1 || i > L.length) return 0;
    return L.data[i - 1];
}

bool List_HeadInsert(LinkedList *L, ElemType e) {
    if (i < 1 || i > L->length + 1) return false;
    if (L->length >= L->MaxSize) return false;
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(LinkedList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->data[L->length] = 0;
    L->length--;
    return true;
}

bool PrintList(LinkedList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    return true;
}

bool Empty(LinkedList L) {
    if (!L.length) return true;
    return false;
}=

bool DestroyList(SeqList *L) {
    free(L->data);
    L->length = 0;
    return true;
}

bool TestLinkedList() {
    LinkedList test;
    InitList(&test);
    if (Empty(test)) printf("empty\n");
    else printf("not empty\n");
    for (int i = 0; i < 30; i++) {
        ListInsert(&test, i + 1, i * i);
    }
    printf("%d\n", Length(test));
    if (Empty(test)) printf("empty\n");
    else printf("not empty\n");
    printf("%d\n", LocateElem(test, 400));
    printf("%d\n", GetElem(test, 20));
    int E;
    ListDelete(&test, 3, &E);
    printf("%d\n", E);
    PrintList(test);
    DestroyList(&test);
    return true;
}

