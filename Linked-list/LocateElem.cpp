#include<iostream>
using namespace std;
//按值查找
LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p;
    p = L->next;
    while(p != NULL && p->data != e)
        p=p->next;
    return p;
}

