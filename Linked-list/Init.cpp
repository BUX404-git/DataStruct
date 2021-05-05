#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


LinkList CreatLinkListTail(LinkList &L)//尾插法，新的结点接在后面
{   
    int length;   
    cout<<"请输入链表长度： ";
    cin>>length;
    
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    
    LNode *s,*r=L;

    for(int i = 0;i < length;i++)
    {
        s = (LinkList)malloc(sizeof(LNode));
        cout << "输入第" << i+1 <<"个元素：";
        ElemType x;
        cin >> x;
        s->data = x;
        r->next = s;
        r = s;
    }
    s->next = NULL;
    return L;
}

void OutPut(LinkList L)
{
    LinkList temp = L;
    cout << "此单链表为：";
    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}

//删除所有值为x的结点

LinkList Del_X(LinkList &L)
{	int x;
	cout<<"请输入要删除的数：";
	 cin>>x;
	LNode *p = L->next;
	LNode *pre =L,*q;
	while( p != NULL) 
	{
		if(p->data == x)
		{	q=p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else 
		{
			pre = p;
			p=p->next;
		}
	}
	return L;
 } 
 
 
//反置L链表，从尾到头输出 ，使用头插法倒置链表 
LinkList Inversion(LinkList &L)
{
	LNode *p = L->next;
 	LNode *q;
	L->next = NULL;
	while(p != NULL)
	{
		q = p->next;//暂存p的后继结点
		p->next = L ->next;
		L->next =p;
		p=q;
	 } 
	 return L;
 } 
 
 //反置L链表，从尾到头输出 ，使用递归
 LinkList Recursion(LinkList &L)
 {
 	if(L->next!=NULL)
 		Recursion(L->next);
 	if(L!=NULL)
 		cout<<L->data;
 	
  } 
 
 

int main(){
    LinkList L = NULL;
    L = CreatLinkListTail(L);
    OutPut(L);



	//删除为X值的结点 
	//Del_X(L);
	//OutPut(L);
   
   
	//倒置L链表 
 	// Inversion(L);
 	// Recursion(L);
	// OutPut(L);



  return 0;
   
}