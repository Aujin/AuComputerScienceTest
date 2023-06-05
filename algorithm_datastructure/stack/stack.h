//
// Created by JXR on 2023/6/4.
//

#ifndef AUCOMPUTERSCIENCETEST_STACK_H
#define AUCOMPUTERSCIENCETEST_STACK_H

#include "../../common.h"

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

/*
 * 初始化空栈
 */
bool InitStack(SqStack *);

/*
 * 判断栈空
 */
bool StackEmpty(SqStack);

/*
 * 判断栈满
 */
bool StackFull(SqStack);

/*
 * 求栈长
 */
int StackLength(SqStack);

/*
 * 进栈
 */
bool StackPush(SqStack *, ElemType);

/*
 * 出栈
 */
bool StackPop(SqStack *, ElemType *);

/*
 * 读栈顶元素
 */
bool StackGetTop(SqStack, ElemType *);

/*
 * 销毁栈
 */
bool DestroyStack(SqStack *);

/*
 * 测试栈
 */
bool TestStack();

#endif //AUCOMPUTERSCIENCETEST_STACK_H
