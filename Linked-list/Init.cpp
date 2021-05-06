#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//尾插法，新的结点接在后面   
LinkList CreatLinkListTail(LinkList &L){
    int length;   
    cout<<"请输入链表长度： ";
    cin>>length;
    
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    
    LNode *s,*r=L;

    for(int i = 0;i < length;i++){
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

void OutPut(LinkList L){
    LinkList temp = L;
    cout << "此单链表为：";
    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}

//按序号查找结点的值
LNode *GetElem(LinkList L){
	ElemType x;
	cout<<"请输入序号:";
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

//按值查找表结点
LNode *LocateElem(LinkList L){
	ElemType x;
	cout<<"请输入要查找的表结点的值:";
	cin>>x;
	cout<<endl;
	LNode *p = L->next;
	while(p != NULL && p->data != x)
		p=p->next;
	cout<<"已找到："<<p->data;

	return p;

}

//插入结点操作
LinkList InsertLNode(LinkList &L){
	ElemType i;
	cout<<"请输入要插入的位置:";
	cin>>i;
	cout<<endl;
	ElemType x;
	cout<<"请输入要插入的值:";
	cin>>x;
	cout<<endl;
	LNode *p = L->next;
	if(i == 0 || i < 1)//如果要插入的位置错误,则返回原链表
		return L;

	for(int j = 1;j<i-1;j++)//找到要插入的位置的前继结点
		p=p->next;
	
	LNode *q = (LNode*)malloc(sizeof(LNode));//新建结点插入
	q->data = x;//赋值x给该结点

	q->next=p->next;//插入结点
	p->next = q;
	return L;

}

//删除结点操作
LinkList DeleteLNode(LinkList &L){
	ElemType x;
	cout<<"请输入要删除的结点的位置:";
	cin>>x;
	LNode *p = L->next;
	for(int j = 1;j < x-1;j++)//找到该结点的前继结点
		p=p->next;
	LNode *q = p->next;//释放该节点
	
	p->next = p->next->next;
	free(q);
	
	return L;
	
}

//删除所有值为x的结点
LinkList Del_X(LinkList &L){	
	int x;
	cout<<"请输入要删除的数：";
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
	//递归实现在单链表L中删除值为x的结点
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
	cout<<"请输入要删除的结点的值:";
	cin>>x;
	cout<<endl;
	LNode *p = L->next,*pre=L,*q;//定义遍历指针和前继指针和释放指针
	while( p != nullptr){
		if(p->data != x){
			pre=p;
			p=p->next;
		}
		else{
			q=p;//释放指针指向该结点
			p=p->next;
			pre->next=p;
			free(q);
		}
	}
	return L;
}

LinkList Del_X_2(LinkList &L){//使用尾插法删除值为x的结点
	ElemType x;
	cout<<"请输入要删除的结点的值:";
	cin>>x;
	cout<<endl;
	LNode *p=L->next,*r=L,*q;
	L->next = nullptr;//将头结点设为空,只需要把不等于x的结点加入到新链表中
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
LinkList R_Print_1(LinkList &L){//使用头插法,逆置链表
	LNode *p = L->next,*q;//定义遍历指针p和后继指针q
	L->next = nullptr;//
	while(p != nullptr){//q=p->next,p=q使每次循环结束后q和p都指向同一个结点,便于循环遍历
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
	return L;
}
void R_Print_2(LinkList &L){//递归
	//从尾到头输出L链表
	if(L ->next =nullptr)
		R_Print_2(L->next);
	if(L != nullptr)
		cout<<L->data<<" ";
}







//反置L链表，从尾到头输出 ，使用头插法倒置链表 
LinkList Inversion(LinkList &L){
	LNode *p = L->next;
 	LNode *q;
	L->next = NULL;
	while(p != NULL){
		q = p->next;//暂存p的后继结点
		p->next = L ->next;
		L->next =p;
		p=q;
	 } 
	 return L;
 } 
 
 //反置L链表，从尾到头输出 ，使用递归
 LinkList Recursion(LinkList &L){
 	if(L->next!=NULL)
 		Recursion(L->next);
 	if(L!=NULL)
 		cout<<L->data;
		 return L;
 	
  } 
 
 

int main(){
    LinkList L = NULL;
    L = CreatLinkListTail(L);//初始化链表
    OutPut(L);


	//输出序号为x的结点的值
	// GetElem(L);

	//按值查找表结点
	// LocateElem(L);

	//删除为X值的结点 
	//Del_X(L);

	//插入结点操作
	// InsertLNode(L);

	//删除结点操作
	// DeleteLNode(L);

	//1
	// Del_X_3(L,3);

	//2
	// Del_X_1(L);
	// Del_X_2(L);

	//3
	// R_Print_1(L);
	// R_Print_2(L);
   
	//倒置L链表 
 	// Inversion(L);
 	// Recursion(L);

	OutPut(L);

	system ("pause");
    return 0;
   
}