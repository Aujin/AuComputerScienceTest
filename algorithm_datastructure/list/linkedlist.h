//
// Created by JXR on 2023/6/1.
//

#ifndef AUCOMPUTERSCIENCETEST_LINKEDLIST_H
#define AUCOMPUTERSCIENCETEST_LINKEDLIST_H

#include "..\..\common.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

/*
 * 初始化表
 */
bool InitLinkedList(LinkedList *);

/*
 * 求表长
 */
int LinkedListLength(LinkedList);

/*
 * 按值查找操作
 */
LNode *LinkedListLocateElem(LinkedList, ElemType);

/*
 * 按位查找操作
 */
LNode *LinkedListGetElem(LinkedList, int);

/*
 * 头插法插入操作
 */
bool LinkedList_HeadInsert(LinkedList, ElemType);

/*
 * 尾插法插入操作
 */
bool LinkedList_TailInsert(LinkedList, ElemType);

/*
 * 插入操作
 */
bool LinkedList_Insert(LinkedList, int, ElemType);

/*
 * 删除操作
 */
bool LinkedListDelete(LinkedList, int, ElemType *);

/*
 * 输出操作
 */
bool PrintLinkedList(LinkedList);

/*
 * 判空操作
 */
bool LinkedListEmpty(LinkedList);

/*
 * 销毁操作
 */
bool DestroyLinkedList(LinkedList);

/*
 * 测试链表
 */
bool TestLinkedList();

#endif //AUCOMPUTERSCIENCETEST_LINKEDLIST_H
