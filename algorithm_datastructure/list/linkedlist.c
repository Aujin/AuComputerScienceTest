//
// Created by JXR on 2023/6/1.
//
#include "linkedlist.h"

bool InitLinkedList(LinkedList *L) {
    (*L) = (LNode *) malloc(sizeof(LNode));
    (*L)->data = 0;
    (*L)->next = NULL;
    return true;
}

int LinkedListLength(LinkedList L) {
    int i = 0;
    LNode *p = L->next;
    while (p) {
        p = p->next;
        i++;
    }
    return i;
}

LNode *LinkedListLocateElem(LinkedList L, ElemType e) {
    LNode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    };
    return p;
}

LNode *LinkedListGetElem(LinkedList L, int i) {
    if (i < 1) return NULL;
    int j = 1;
    LNode *p = L->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

bool LinkedList_HeadInsert(LinkedList L, ElemType e) {
    LNode *s;
    s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

bool LinkedList_TailInsert(LinkedList L, ElemType e) {
    LNode *p = L;
    while (p->next) {
        p = p->next;
    }
    LNode *s;
    s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    p->next = s;
    return true;
}

bool LinkedList_Insert(LinkedList L, int i, ElemType e) {
    LNode *p = LinkedListGetElem(L, i - 1);
    if (!p) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    return true;
}

bool LinkedListDelete(LinkedList L, int i, ElemType *e) {
    LNode *p = LinkedListGetElem(L, i - 1);
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
}

bool PrintLinkedList(LinkedList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    return true;
}

bool LinkedListEmpty(LinkedList L) {
    if (L->next) return false;
    else return true;
}

bool DestroyLinkedList(LinkedList L) {
    LNode *p;
    while (LinkedListEmpty(L)) {
        p = L->next;
        while (p->next) {
            p = p->next;
        }
        free(p);
    }
    free(L);
    return true;
}

bool TestLinkedList() {
    LinkedList test;
    InitLinkedList(&test);
    if (LinkedListEmpty(test)) printf("empty\n");
    else printf("not empty\n");
    for (int i = 0; i < 30; i++) {
        LinkedList_HeadInsert(test, i * i);
    }
    printf("%d\n", LinkedListLength(test));
    if (LinkedListEmpty(test)) printf("empty\n");
    else printf("not empty\n");
    printf("%d\n", LinkedListLocateElem(test, 400));
    printf("%d\n", LinkedListGetElem(test, 20));
    int E;
    LinkedListDelete(test, 3, &E);
    printf("%d\n", E);
    PrintLinkedList(test);
    DestroyLinkedList(test);
    return true;
}

