//
// Created by JXR on 2023/6/1.
//

#ifndef AUCOMPUTERSCIENCETEST_SEQLIST_H
#define AUCOMPUTERSCIENCETEST_SEQLIST_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../../common.h"

typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

/*
 * 初始化表
 */
bool InitSeqList(SeqList *);

/*
 * 求表长
 */
int SeqListLength(SeqList);

/*
 * 按值查找操作
 */
int SeqListLocateElem(SeqList, ElemType);

/*
 * 按位查找操作
 */
ElemType SeqListGetElem(SeqList, int);

/*
 * 插入操作
 */
bool SeqListInsert(SeqList *, int, ElemType);

/*
 * 删除操作
 */
bool SeqListDelete(SeqList *, int, ElemType *);

/*
 * 输出操作
 */
bool PrintSeqList(SeqList);

/*
 * 判空操作
 */
bool SeqListEmpty(SeqList);

/*
 * 销毁操作
 */
bool DestroySeqList(SeqList *);

/*
 * 测试顺序表
 */
bool TestSeqList();

#endif //AUCOMPUTERSCIENCETEST_SEQLIST_H
