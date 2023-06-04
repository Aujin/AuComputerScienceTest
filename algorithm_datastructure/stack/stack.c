//
// Created by JXR on 2023/6/4.
//
#include "stack.h"

bool InitStack(SqStack *);

bool StackEmpty(SqStack);

bool Push(SqStack *,ElemType);

bool Pop(SqStack *,ElemType*);

bool GetTop(SqStack ,ElemType*);

bool DestroyStack(SqStack*);

bool TestStack();
