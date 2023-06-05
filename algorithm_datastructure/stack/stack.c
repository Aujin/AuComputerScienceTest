//
// Created by JXR on 2023/6/4.
//
#include "stack.h"

bool InitStack(SqStack *S) {
    S->top = -1;
    return true;
}

bool StackEmpty(SqStack S) {
    return (S.top == -1);
}

bool StackFull(SqStack S) {
    return (S.top == MaxSize - 1);
}

int StackLength(SqStack S) {
    return (S.top + 1);
}

bool StackPush(SqStack *S, ElemType x) {
    if (S->top == MaxSize - 1)return false;
    S->top++;
    S->data[S->top] = x;
    return true;
}

bool StackPop(SqStack *S, ElemType *x) {
    if (S->top == -1)return false;
    *x = S->data[S->top];
    S->top--;
    return true;
}

bool StackGetTop(SqStack S, ElemType *x) {
    if (S.top == -1)return false;
    *x = S.data[S.top];
    return true;
}

bool DestroyStack(SqStack *S) {
    S->top = -1;
    return true;
}

bool TestStack() {
    SqStack test;
    InitStack(&test);
    if (StackEmpty(test)) printf("empty\n");
    else printf("not empty\n");
    for (int i = 0; i < 30; i++) {
        StackPush(&test, i * i);
    }
    printf("%d\n", StackLength(test));
    if (StackFull(test)) printf("full\n");
    else printf("not full\n");
    ElemType n;
    StackGetTop(test, &n);
    printf("%d\n", n);
    while (!StackEmpty(test)) {
        StackPop(&test, &n);
        printf("%d ", n);
    }
    printf("\n");
    DestroyStack(&test);
    return true;
}
