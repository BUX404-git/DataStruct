#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


LinkList CreatLinkListTail(LinkList &L)//β�巨���µĽ����ں���
{   
    int length;   
    cout<<"�����������ȣ� ";
    cin>>length;
    
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    
    LNode *s,*r=L;

    for(int i = 0;i < length;i++)
    {
        s = (LinkList)malloc(sizeof(LNode));
        cout << "�����" << i+1 <<"��Ԫ�أ�";
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
    cout << "�˵�����Ϊ��";
    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}

//ɾ������ֵΪx�Ľ��

LinkList Del_X(LinkList &L)
{	int x;
	cout<<"������Ҫɾ��������";
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
 
 
//����L������β��ͷ��� ��ʹ��ͷ�巨�������� 
LinkList Inversion(LinkList &L)
{
	LNode *p = L->next;
 	LNode *q;
	L->next = NULL;
	while(p != NULL)
	{
		q = p->next;//�ݴ�p�ĺ�̽��
		p->next = L ->next;
		L->next =p;
		p=q;
	 } 
	 return L;
 } 
 
 //����L������β��ͷ��� ��ʹ�õݹ�
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



	//ɾ��ΪXֵ�Ľ�� 
	//Del_X(L);
	//OutPut(L);
   
   
	//����L���� 
 	// Inversion(L);
 	// Recursion(L);
	// OutPut(L);



  return 0;
   
}