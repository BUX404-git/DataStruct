#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;

//单链表
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//双链表
typedef struct DNode{
	ElemType data;
	struct DNode *next,*prior;
}DNode,*DLinklist;



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

//尾插法，新的结点接在后面,无头结点   
LinkList CreatLinkListTail_NoheadNode(LinkList &L){
    int length;   
    cout<<"请输入链表长度： ";
    cin>>length;
    
    L = (LinkList)malloc(sizeof(LNode));
    
}

void OutPut(LinkList L){
    LinkList temp = L;
    cout << "此单链表为：";
    while(temp->next != NULL){
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << endl;
}

void OutPut_NoLNode(LinkList L){
	LNode *p=L;
	while(p != nullptr){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int getlength(LinkList L){
	LNode *p=L->next;
	int i = 0;
	while(p != nullptr){
		i++;
		p=p->next;
	}
	return i;
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
void R_Print_2(LinkList &L){//递归 头结点不为空，最后一个输出的头节点data没有设置
	//从尾到头输出L链表
	if(L->next != nullptr)
		R_Print_2(L->next);
	if(L != nullptr)
		cout<<L->data<<" ";
}

//4
LinkList Delete_Min(LinkList &L){
		LNode *pre = L;
		LNode *p=pre->next;
		while(p->next != nullptr){
			if(p->next->data < pre->next->data)
				pre = p;//pre指针指向最小值结点的前驱节点
			p=p->next;//继续遍历
		}
		cout<<pre->next->data<<" ";//输出最小值结点的数据
		LNode *u;
		u=pre->next;
				pre->next = u->next;

		free(u);
		return L;
	}

//5
LinkList Inverse_1(LinkList &L){//使用头插法逆置链表
	LNode *p=L->next,*r;//定义遍历指针r和搬运指针p
	L->next = nullptr;//将头结点指空
	while(r != nullptr){
		r=p->next;
		p->next = L->next;
		L->next=p;
		p=r;
	}
	return L;
} 
LinkList Inverse_2(LinkList &L){//类似头插法
		LNode *pre,*p=L->next,*r=L->next->next;//r来保存后继节点
		p->next=nullptr;
		while(r != nullptr){
			pre = p;
			p=r;
			r=r->next;
			p->next = pre;//指针反转
		}
		L->next = p;
		return L;
	}
LinkList Recursion(LinkList &L){//反置L链表，从尾到头输出 ，使用递归
 	if(L->next!=NULL)
 		Recursion(L->next);
 	if(L!=NULL)
 		cout<<L->data;
		 return L;
 	 }
 
 //6
LinkList Sort(LinkList &L){
	LNode *p=L->next,*r=p->next,*pre;//遍历指针*r,搬运指针*p,前驱指针*pre 用来与*p比较
	p->next=nullptr;
	p=r;
	while(p != nullptr){
		r=p->next;
		pre = L;//每次循环从头结点开始比较
		if(pre->next != nullptr && pre->next->data < p->data)//比较pre的后一个结点的值，直到表尾
			pre=pre->next;

		p->next = pre->next;//比较完成,将该结点插入到pre的后面
		pre->next = p;

		p=r;//指向下一个结点
	}
	return L;
 }

 //7
LinkList RangeDelete(LinkList &L){
	ElemType x;
	cout<<"请输入起始的值:";
	cin>>x;
	cout<<endl;
	ElemType y;
	cout<<"请输入结束的值:";
	cin>>y;
	cout<<endl;

	LNode *p=L->next,*pre=L,*q;//遍历结点p,前驱节点pre,释放指针q

	while(p != nullptr){
		if(p->data > x && p->data < y){
			q=p;
			p=p->next;
			pre->next=p;//删除值介于x和y之间的结点
			free(q);
		}
		else{
			pre=p;
			p=p->next;//继续遍历
		}
	}
	return L;
 }

//8
LinkList Search_1st_Common(LinkList L1,LinkList L2){
	int len1 = getlength(L1), len2 = getlength(L2);
	
	LinkList longlist,shortlist;
	int dist;//定义差值

	if(len1 > len2){//将longlist指向较长链表的实际结点
		longlist = L1->next;shortlist = L2->next;
		dist = len1 - len2;
	}
	else{
		longlist = L2->next;shortlist = L1->next;
		dist = len2 - len1;
	}

	while(dist--)
		longlist = longlist->next;//先将长链表遍历到第dist个结点,然后同步
	
	while(longlist != nullptr){//开始同步遍历
		if(longlist == shortlist)
			return longlist;
		else{
			longlist=longlist->next;
			shortlist=shortlist->next;
		}
		return nullptr;
	}	
}
	
//9
void Min_Delete(LinkList &head){
	cout<<"依次删除最小结点:";
	while(head->next != nullptr){
		LNode *pre = head;
		LNode *p=pre->next;
		while(p->next != nullptr){
			if(p->next->data < pre->next->data)
				pre = p;//pre指针指向最小值结点的前驱节点
			p=p->next;//继续遍历
		}
		cout<<pre->next->data<<" ";//输出最小值结点的数据
		LNode *u = pre->next;//定义释放指针u
		pre->next = u->next;
		free(u);
	}
	cout<<endl;
	free(head);//最后将头指针释放
}

//10
LinkList DisCreate_1(LinkList &A){
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = nullptr;//定义B链表的表头结点
	LNode *ra = A,*rb = B;//ra和rb分别指向将创建的A表和B表的尾结点
	LNode *p = A->next;
	A->next = nullptr;//置空新的A表
	int i = 0;
	while(p != nullptr){
		i++;
		if( i%2 == 0 ){
			rb->next = p;//在B表尾插入新结点
			rb=p;
		}
		else{
			ra->next = p;//在A表尾插入新结点
			ra = p;
		}
		p=p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}

//11
LinkList DisCreate_2(LinkList &A){
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = nullptr;//建立B表的头结点

	LNode *p=A->next;//定义工作指针*p

	A->next = nullptr;//将A表置空

	LNode *ra = A,*rb = B;//定义A表的表尾指针*ra,和B表的头指针*rb

	LNode *r;//定义*r来保持工作指针*p的后继结点

	int i = 0;
	while(p != nullptr){
		i++;
		r = p->next;//保存后继结点
		if( i%2 == 0){//使用头插法将{b1,b2,b3,...,bn}倒置
			p->next = rb->next;
			rb->next = p;
		}
		else{
			ra->next = p;//与10题一样,将{a1,a2,a3,...,an}结点插入表尾
			ra = p;
		}
		p=r;//工作指针继续遍历
	}
	ra->next = nullptr;//最后将A表尾置空
	return B;
}

//12
LinkList Del_Same(LinkList &L){
	LNode *p=L->next,*q;//定义工作指针*p扫描链表,后继指针*q用来判断是否相等
	while(p->next != nullptr){
		q=p->next;//每次循环*q都是*p的后继结点

		if(p->data == q->data){//如果相等,则删除q结点
			p->next = q->next;
			free(q);
		}
		else
			p=p->next;//不相等则继续扫描
	}
	return L;
}

//13
LinkList MergeList(LinkList &L1,LinkList &L2){

	LNode *r,*p1=L1->next,*p2=L2->next;//p1,p2分别为L1,L2的工作指针
	L1->next=nullptr;//L1作为结果链表的头指针,先将结果链表置空

	while(p1 && p2)
		if(p1->data<=p2->data){//头插法
			r=p1->next;//r暂存后继结点指针
			p1->next=L1->next;
			L1->next=p1;
			p1=r;
		}
		else{//插入到L1结果链表中
		r=p2->next;
		p2->next=L1->next;
		L1->next=p2;
		p2=r;
		}

	if(p1)//判断哪个链表还没有遍历完,将p2指针指向该链表
		p2=p1;
	
	while(p2){//用头插法继续插入剩余的结点
		r=p2->next;
		p2->next=L1->next;
		L1->next=p2;
		p2=r;
	}
	free(L2);//释放L2头结点

	return L1;//返回结果链表
}

//14
LinkList Get_Common(LinkList A,LinkList B){
	LNode *p=A->next,*q=B->next,*r,*s;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	r=C;

	while( p!=nullptr && q!=nullptr){
		if(p->data < q->data)//值较小的往后移
			p=p->next;
		else if(q->data < p->data)
			q=q->next;
		else{
			s=(LinkList)malloc(sizeof(LNode));//创建新结点
			s->data=p->data;//将AB共同结点的值赋值给新结点
			r->next=s;//尾插法将新结点插入C表中
			r=s;
			p=p->next;//表A和表B继续向后扫描
			q=q->next;
		}
	}
	r->next=nullptr;
	return C;
}

//15
LinkList Union(LinkList &la,LinkList &lb){
	LNode *pa=la->next,*pb=lb->next;//设置工作指针
	LNode *pc=la,*u;//结果表中合并结点的前驱指针和释放指针*u

	while(pa && pb){
		if(pa->data==pb->data){
			pc->next=pa;//A中结点链接到结果表中
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;//B中结点释放
			free(u);
		}
		else if(pa->data<pb->data){//若A当前结点小于B中当前节点值
			u=pa;
			pa=pa->next;//后移指针
			free(u);//释放A中当前结点
		}
		else{				//若B中当前结点小于A中当前结点的值
			u=pb;
			pb=pb->next;	//后移指针
			free(u);		//释放B中当前结点
		}
	}
	while(pa){//B已遍历完,A未完
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){//A已遍历完,B未完
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=nullptr;//置链表尾指针为空,因为使用的使尾插法
	free(lb);
	return la;
}

//16
bool Pattern(LinkList &A,LinkList &B){
	LNode *p=A->next,*pre=p;//p为工作指针,pre记录每次比较的A链表的开始结点
	LNode *q=B->next;//q是B的工作指针

	while(p && q){
		if(p->data == q->data){//结点值相同
			p=p->next;
			q=q->next;
		}
		else{
			pre=pre->next;
			p=pre;//A链表新的开始比较结点
			q=B;
		}
	}
	if(q==nullptr)
		return 1;
	else 	
		return 0;
}

//17
int Sysmmetry(DLinklist L){
	//本算法从两头扫描循环双链表,以判断是否对称
	DNode *p=L->next,*q=L->prior;//两头工作指针
	while(p != q && q->next != p)//链表为偶数时,当循环到q等于p时结束或链表为奇数时,当循环到q的下一个节点等于p时,循环结束
		if(p->data == q->data){//所指的结点值相同则继续比较
			p=p->next;
			q=q->prior;
		}
		else//当有一个不对称时,循环结束
			return 0;
	return 1;
}

//18
LinkList	Link(LinkList &h1,LinkList &h2){//两个循环单链表
	//将循环链表h2链接到循环链表h1之后,使之仍保持循环链表的形式
	LNode *p,*q;//分别指向两个链表的尾节点
	p=h1;
	while(p->next != h1)//寻找h1的尾结点
		p=p->next;
	q=h2;
	while(q->next != h2)//寻找h2的尾结点
		q=q->next;
	p->next=h2;//将h2链接到h1之后
	q->next=h1;//令h2的尾结点指向h1
	return h1;
}

//19
void Del_All(LinkList &L){//循环单链表
	//本算法实现每次删除循环单链表中最小值元素,直到链表为空
	LNode *p,*pre,*minp,*minpre;//工作指针和工作指针前驱,最小值结点和其前驱
	while(L->next!=L){//表不空,循环
		p=L->next;pre=L;
		minp=p;minpre=pre;
		while(p!=L){
			if(p->data < minp->data){
				minp=p;
				minpre=pre;
			}
			pre=p;//查找下一个结点
			p=p->next;
		}
		cout<<minp->data<<" "<<endl;//每次循环输出这一次的最小结点值
		minpre->next=minp->next;//删除最小值结点
		free(minp);//释放空间
	}
	free(L);//释放头结点
}

//20





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

    //4
	Delete_Min(L);
	
	//5
	// Inversion_1(L);
	// Inverse_2(L);

	//6
	// Sort(L);

	//7
	// RangeDelete(L);
	
	//8
	// L3 = Search_1st_Common(L1,L2);
	// OutPut_NoLNode(L3);

	//9
	// Min_Delete(L);

	//10
	// LinkList q = DisCreate_1(L);
	// OutPut(L);
	// OutPut(q);
	// OutPut(L);

	//11
	// LinkList q = DisCreate_2(L);
	// OutPut(L);
	// OutPut(q);

	//12
	// Del_Same(L);

	//13
	// LinkList L1 = NULL;
    // L1 = CreatLinkListTail(L1);//初始化链表
	// OutPut(L1);
    // LinkList L2 = NULL;
    // L2 = CreatLinkListTail(L2);//初始化链表
	// OutPut(L2);
	// LinkList q = MergeList(L1,L2);
	// OutPut(q);
	
	//14
	// LinkList L1 = NULL;
    // L1 = CreatLinkListTail(L1);//初始化链表
	// OutPut(L1);
    // LinkList L2 = NULL;
    // L2 = CreatLinkListTail(L2);//初始化链表
	// OutPut(L2);
	// LinkList q = Get_Common(L1,L2);
	// OutPut(q);

	//15
	// LinkList L1 = NULL;
    // L1 = CreatLinkListTail(L1);//初始化链表
	// OutPut(L1);
    // LinkList L2 = NULL;
    // L2 = CreatLinkListTail(L2);//初始化链表
	// OutPut(L2);
	// cout<<"进行合并操作:"<<endl;
	// LinkList q = Union(L1,L2);
	// OutPut(q);

	OutPut(L);

	system ("pause");
    return 0;
}