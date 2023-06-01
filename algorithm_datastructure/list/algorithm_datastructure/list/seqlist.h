#ifndef AU_SEQ_LIST
#define AU_SEQ_LIST

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define InitSize 100

typedef int ElemType;           //数据类型

typedef struct {
    ElemType *data;             //动态分配数组的指针
    int MaxSize;                //数组最大容量
    int length;                 //数组当前个数
} SeqList;

/*
 * 初始化表
 */
bool InitList(SeqList *);

/*
 * 求表长
 */
int Length(SeqList);

/*
 * 按值查找操作
 */
int LocateElem(SeqList, ElemType);

/*
 * 按位查找操作
 */
ElemType GetElem(SeqList, int);

/*
 * 插入操作
 */
bool ListInsert(SeqList *, int, ElemType);

/*
 * 删除操作
 */
bool ListDelete(SeqList *, int, ElemType *);

/*
 * 输出操作
 */
bool PrintList(SeqList);

/*
 * 判空操作
 */
bool Empty(SeqList);

/*
 * 销毁操作
 */
bool DestroyList(SeqList *);

#endif