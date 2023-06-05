//
// Created by JXR on 2023/6/4.
//

#include "queue.h"

bool InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return true;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool QueueFull(SqQueue Q) {
    return Q.front == (Q.rear + 1) % MaxSize;
}

int QueueLength(SqQueue Q) {
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

bool EnQueue(SqQueue *Q, ElemType x) {
    if (QueueFull(*Q))return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue *Q, ElemType *x) {
    if (QueueEmpty(*Q))return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}

bool QueueGetHead(SqQueue Q, ElemType *x) {
    if (QueueEmpty(Q))return false;
    *x = Q.data[Q.front];
    return true;
}

bool DestroyQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return true;
}

bool TestQueue() {
    SqQueue test;
    InitQueue(&test);
    if (QueueEmpty(test)) printf("empty\n");
    else printf("not empty\n");
    for (int i = 0; i < 30; i++) {
        EnQueue(&test, i * i);
    }
    printf("%d\n", QueueLength(test));
    if (QueueFull(test)) printf("full\n");
    else printf("not full\n");
    ElemType n;
    QueueGetHead(test, &n);
    printf("%d\n", n);
    while (!QueueEmpty(test)) {
        DeQueue(&test, &n);
        printf("%d ", n);
    }
    printf("\n");
    DestroyQueue(&test);
    return true;
}
