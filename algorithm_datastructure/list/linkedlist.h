//
// Created by JXR on 2023/6/1.
//

#ifndef AUCOMPUTERSCIENCETEST_LINKEDLIST_H
#define AUCOMPUTERSCIENCETEST_LINKEDLIST_H

#include "stdbool.h"
#include <malloc.h>
#include "..\..\common.h"

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkedList;

/*
 * 初始化表
 */
bool InitList(LinkedList *);

/*
 * 求表长
 */
int Length(LinkedList);

/*
 * 按值查找操作
 */
int LocateElem(LinkedList, ElemType);

/*
 * 按位查找操作
 */
LNode GetElem(LinkedList, int);

/*
 * 头插法插入操作
 */
bool List_HeadInsert(LinkedList *, ElemType);

/*
 * 尾插法插入操作
 */
bool List_TailInsert(LinkedList *, ElemType);

/*
 * 删除操作
 */
bool ListDelete(LinkedList *, int, ElemType *);

/*
 * 输出操作
 */
bool PrintList(LinkedList);

/*
 * 判空操作
 */
bool Empty(LinkedList);

/*
 * 销毁操作
 */
bool DestroyList(LinkedList *);

/*
 * 测试链表
 */
bool TestLinkedList();

#endif //AUCOMPUTERSCIENCETEST_LINKEDLIST_H
