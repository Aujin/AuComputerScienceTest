//
// Created by JXR on 2023/6/4.
//

#ifndef AUCOMPUTERSCIENCETEST_QUEUE_H
#define AUCOMPUTERSCIENCETEST_QUEUE_H

#include "../../common.h"

typedef struct {
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

/*
 * 初始化队列
 */
bool InitQueue(SqQueue*);

/*
 * 判队列空
 */
bool QueueEmpty(SqQueue);

/*
 * 判队列满
 */
bool QueueFull(SqQueue);

/*
 * 求队列长
 */
int QueueLength(SqQueue);

/*
 * 入队
 */
bool EnQueue(SqQueue*,ElemType);

/*
 * 出队
 */
bool DeQueue(SqQueue*,ElemType*);

/*
 * 读队头元素
 */
bool GetHead(SqQueue,ElemType*);

/*
 * 销毁队列
 */
bool DestroyQueue(SqQueue *);

/*
 * 测试队列
 */
bool TestQueue();

#endif //AUCOMPUTERSCIENCETEST_QUEUE_H
