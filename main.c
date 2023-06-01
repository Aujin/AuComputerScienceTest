
#include "stdio.h"
#include "algorithm_datastructure/list/seqlist.h"

int main() {
    SeqList test;
    InitList(&test);
    if(Empty(test)) printf("empty\n");
    else printf("not empty\n");
    for(int i=0;i < 30;i++){
        ListInsert(&test,i+1,i*i);
    }
    printf("%d\n", Length(test));
    if(Empty(test)) printf("empty\n");
    else printf("not empty\n");
    printf("%d\n", LocateElem(test,400));
    printf("%d\n", GetElem(test,20));
    int E;
    ListDelete(&test,3,&E);
    printf("%d\n",E);
    PrintList(test);
    DestroyList(&test);
}
