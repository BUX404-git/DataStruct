#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//β�巨���µĽ����ں���   
LinkList CreatLinkListTail(LinkList &L){
    int length;   
    cout<<"�����������ȣ� ";
    cin>>length;
    
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    
    LNode *s,*r=L;

    for(int i = 0;i < length;i++){
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

void OutPut(LinkList L){
    LinkList temp = L;
    cout << "�˵�����Ϊ��";
    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}

//����Ų��ҽ���ֵ
LNode *GetElem(LinkList L){
	ElemType x;
	cout<<"���������:";
	cin>>x;
	cout<<endl;
	if(x < 1 || x == 0)
		return L;
	LNode *p = L->next;
	while(x>1){
		p=p->next;
		x--;
	}
	cout<<p->data<<endl;
	return p;
}

//��ֵ���ұ���
LNode *LocateElem(LinkList L){
	ElemType x;
	cout<<"������Ҫ���ҵı����ֵ:";
	cin>>x;
	cout<<endl;
	LNode *p = L->next;
	while(p != NULL && p->data != x)
		p=p->next;
	cout<<"���ҵ���"<<p->data;

	return p;

}

//���������
LinkList InsertLNode(LinkList &L){
	ElemType i;
	cout<<"������Ҫ�����λ��:";
	cin>>i;
	cout<<endl;
	ElemType x;
	cout<<"������Ҫ�����ֵ:";
	cin>>x;
	cout<<endl;
	LNode *p = L->next;
	if(i == 0 || i < 1)//���Ҫ�����λ�ô���,�򷵻�ԭ����
		return L;

	for(int j = 1;j<i-1;j++)//�ҵ�Ҫ�����λ�õ�ǰ�̽��
		p=p->next;
	
	LNode *q = (LNode*)malloc(sizeof(LNode));//�½�������
	q->data = x;//��ֵx���ý��

	q->next=p->next;//������
	p->next = q;
	return L;

}

//ɾ��������
LinkList DeleteLNode(LinkList &L){
	ElemType x;
	cout<<"������Ҫɾ���Ľ���λ��:";
	cin>>x;
	LNode *p = L->next;
	for(int j = 1;j < x-1;j++)//�ҵ��ý���ǰ�̽��
		p=p->next;
	LNode *q = p->next;//�ͷŸýڵ�
	
	p->next = p->next->next;
	free(q);
	
	return L;
	
}

//ɾ������ֵΪx�Ľ��
LinkList Del_X(LinkList &L){	
	int x;
	cout<<"������Ҫɾ��������";
	cin>>x;
	LNode *p = L->next;
	LNode *pre =L,*q;
	while( p != NULL){
		if(p->data == x){	
			q=p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else {
			pre = p;
			p=p->next;
		}
	}
	return L;
 } 
 
//1
void Del_X_3(LinkList &L,ElemType x){
	//�ݹ�ʵ���ڵ�����L��ɾ��ֵΪx�Ľ��
	LNode *p;
	if(L == NULL)
		return;
	if(L->data == x){
		p=L;
		L=L->next;
		free(p);
		Del_X_3(L,x);
	}
	else
		Del_X_3(L->next,x); 
}

//2
LinkList Del_X_1(LinkList &L){

	ElemType x;
	cout<<"������Ҫɾ���Ľ���ֵ:";
	cin>>x;
	cout<<endl;
	LNode *p = L->next,*pre=L,*q;//�������ָ���ǰ��ָ����ͷ�ָ��
	while( p != nullptr){
		if(p->data != x){
			pre=p;
			p=p->next;
		}
		else{
			q=p;//�ͷ�ָ��ָ��ý��
			p=p->next;
			pre->next=p;
			free(q);
		}
	}
	return L;
}

LinkList Del_X_2(LinkList &L){//ʹ��β�巨ɾ��ֵΪx�Ľ��
	ElemType x;
	cout<<"������Ҫɾ���Ľ���ֵ:";
	cin>>x;
	cout<<endl;
	LNode *p=L->next,*r=L,*q;
	L->next = nullptr;//��ͷ�����Ϊ��,ֻ��Ҫ�Ѳ�����x�Ľ����뵽��������
	while(p != nullptr){
		if(p->data == x){
			q=p;
			p=p->next;
			free(q);
		}
		else{
			r->next = p;
			r=p;
			p=p->next;
		}
	}
	r->next=nullptr;
	return L;
}

//3
LinkList R_Print_1(LinkList &L){//ʹ��ͷ�巨,��������
	LNode *p = L->next,*q;//�������ָ��p�ͺ��ָ��q
	L->next = nullptr;//
	while(p != nullptr){//q=p->next,p=qʹÿ��ѭ��������q��p��ָ��ͬһ�����,����ѭ������
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
	return L;
}
void R_Print_2(LinkList &L){//�ݹ�
	//��β��ͷ���L����
	if(L ->next =nullptr)
		R_Print_2(L->next);
	if(L != nullptr)
		cout<<L->data<<" ";
}







//����L������β��ͷ��� ��ʹ��ͷ�巨�������� 
LinkList Inversion(LinkList &L){
	LNode *p = L->next;
 	LNode *q;
	L->next = NULL;
	while(p != NULL){
		q = p->next;//�ݴ�p�ĺ�̽��
		p->next = L ->next;
		L->next =p;
		p=q;
	 } 
	 return L;
 } 
 
 //����L������β��ͷ��� ��ʹ�õݹ�
 LinkList Recursion(LinkList &L){
 	if(L->next!=NULL)
 		Recursion(L->next);
 	if(L!=NULL)
 		cout<<L->data;
		 return L;
 	
  } 
 
 

int main(){
    LinkList L = NULL;
    L = CreatLinkListTail(L);//��ʼ������
    OutPut(L);


	//������Ϊx�Ľ���ֵ
	// GetElem(L);

	//��ֵ���ұ���
	// LocateElem(L);

	//ɾ��ΪXֵ�Ľ�� 
	//Del_X(L);

	//���������
	// InsertLNode(L);

	//ɾ��������
	// DeleteLNode(L);

	//1
	// Del_X_3(L,3);

	//2
	// Del_X_1(L);
	// Del_X_2(L);

	//3
	// R_Print_1(L);
	// R_Print_2(L);
   
	//����L���� 
 	// Inversion(L);
 	// Recursion(L);

	OutPut(L);

	system ("pause");
    return 0;
   
}