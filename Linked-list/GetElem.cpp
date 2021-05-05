#include<iostream>
using namespace std;
//按顺序查找第i个结点
LNode *GetElem(LinkList L,int i)
{
    int j =1 ;
    LNode *p=L->next;
    if(i == 0)
        return L;
    if(i<1)
        return NULL;
    while (p && i<j)
    {
       p = p->next;
       j++;
    }
    return p;//返回的p指针指向i结点
    
}