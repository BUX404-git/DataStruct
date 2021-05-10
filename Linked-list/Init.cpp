#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;

//������
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//˫����
typedef struct DNode{
	ElemType data;
	struct DNode *next,*prior;
}DNode,*DLinklist;



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

//β�巨���µĽ����ں���,��ͷ���   
LinkList CreatLinkListTail_NoheadNode(LinkList &L){
    int length;   
    cout<<"�����������ȣ� ";
    cin>>length;
    
    L = (LinkList)malloc(sizeof(LNode));
    
}

void OutPut(LinkList L){
    LinkList temp = L;
    cout << "�˵�����Ϊ��";
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
void R_Print_2(LinkList &L){//�ݹ� ͷ��㲻Ϊ�գ����һ�������ͷ�ڵ�dataû������
	//��β��ͷ���L����
	if(L->next != nullptr)
		R_Print_2(L->next);
	if(L != nullptr)
		cout<<L->data<<" ";
}

//4
LinkList Delete_Min(LinkList &L){
		LNode *p=L->next,*pre=L;
		LNode *minp=p,*preminp=pre;
		while(p != nullptr){//��������
			if(p->data < minp->data){//��minpָ��ָ����С�ڵ�
				minp = p;
				preminp = pre;
			}
				pre=p;//��������
				p=p->next;
			
		}
		preminp->next=minp->next;
		free(minp);
		return L;
	}

//5
LinkList Inverse_1(LinkList &L){//ʹ��ͷ�巨��������
	LNode *p=L->next,*r;//�������ָ��r�Ͱ���ָ��p
	L->next = nullptr;//��ͷ���ָ��
	while(r != nullptr){
		r=p->next;
		p->next = L->next;
		L->next=p;
		p=r;
	}
	return L;
} 
LinkList Inverse_2(LinkList &L){//����ͷ�巨
		LNode *pre,*p=L->next,*r=L->next->next;//r�������̽ڵ�
		p->next=nullptr;
		while(r != nullptr){
			pre = p;
			p=r;
			r=r->next;
			p->next = pre;//ָ�뷴ת
		}
		L->next = p;
		return L;
	}
LinkList Recursion(LinkList &L){//����L������β��ͷ��� ��ʹ�õݹ�
 	if(L->next!=NULL)
 		Recursion(L->next);
 	if(L!=NULL)
 		cout<<L->data;
		 return L;
 	 }
 
 //6
LinkList Sort(LinkList &L){
	LNode *p=L->next,*r=p->next,*pre;//����ָ��*r,����ָ��*p,ǰ��ָ��*pre ������*p�Ƚ�
	p->next=nullptr;
	p=r;
	while(p != nullptr){
		r=p->next;
		pre = L;//ÿ��ѭ����ͷ��㿪ʼ�Ƚ�
		if(pre->next != nullptr && pre->next->data < p->data)//�Ƚ�pre�ĺ�һ������ֵ��ֱ����β
			pre=pre->next;

		p->next = pre->next;//�Ƚ����,���ý����뵽pre�ĺ���
		pre->next = p;

		p=r;//ָ����һ�����
	}
	return L;
 }

 //7
LinkList RangeDelete(LinkList &L){
	ElemType x;
	cout<<"��������ʼ��ֵ:";
	cin>>x;
	cout<<endl;
	ElemType y;
	cout<<"�����������ֵ:";
	cin>>y;
	cout<<endl;

	LNode *p=L->next,*pre=L,*q;//�������p,ǰ���ڵ�pre,�ͷ�ָ��q

	while(p != nullptr){
		if(p->data > x && p->data < y){
			q=p;
			p=p->next;
			pre->next=p;//ɾ��ֵ����x��y֮��Ľ��
			free(q);
		}
		else{
			pre=p;
			p=p->next;//��������
		}
	}
	return L;
 }

//8
LinkList Search_1st_Common(LinkList L1,LinkList L2){
	int len1 = getlength(L1), len2 = getlength(L2);
	
	LinkList longlist,shortlist;
	int dist;//�����ֵ

	if(len1 > len2){//��longlistָ��ϳ������ʵ�ʽ��
		longlist = L1->next;shortlist = L2->next;
		dist = len1 - len2;
	}
	else{
		longlist = L2->next;shortlist = L1->next;
		dist = len2 - len1;
	}

	while(dist--)
		longlist = longlist->next;//�Ƚ��������������dist�����,Ȼ��ͬ��
	
	while(longlist != nullptr){//��ʼͬ������
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
	cout<<"����ɾ����С���:";
	while(head->next != nullptr){
		LNode *pre = head;
		LNode *p=pre->next;
		while(p->next != nullptr){
			if(p->next->data < pre->next->data)
				pre = p;//preָ��ָ����Сֵ����ǰ���ڵ�
			p=p->next;//��������
		}
		cout<<pre->next->data<<" ";//�����Сֵ��������
		LNode *u = pre->next;//�����ͷ�ָ��u
		pre->next = u->next;
		free(u);
	}
	cout<<endl;
	free(head);//���ͷָ���ͷ�
}

//10
LinkList DisCreate_1(LinkList &A){
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = nullptr;//����B����ı�ͷ���
	LNode *ra = A,*rb = B;//ra��rb�ֱ�ָ�򽫴�����A���B���β���
	LNode *p = A->next;
	A->next = nullptr;//�ÿ��µ�A��
	int i = 0;
	while(p != nullptr){
		i++;
		if( i%2 == 0 ){
			rb->next = p;//��B��β�����½��
			rb=p;
		}
		else{
			ra->next = p;//��A��β�����½��
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
	B->next = nullptr;//����B���ͷ���

	LNode *p=A->next;//���幤��ָ��*p

	A->next = nullptr;//��A���ÿ�

	LNode *ra = A,*rb = B;//����A��ı�βָ��*ra,��B���ͷָ��*rb

	LNode *r;//����*r�����ֹ���ָ��*p�ĺ�̽��

	int i = 0;
	while(p != nullptr){
		i++;
		r = p->next;//�����̽��
		if( i%2 == 0){//ʹ��ͷ�巨��{b1,b2,b3,...,bn}����
			p->next = rb->next;
			rb->next = p;
		}
		else{
			ra->next = p;//��10��һ��,��{a1,a2,a3,...,an}�������β
			ra = p;
		}
		p=r;//����ָ���������
	}
	ra->next = nullptr;//���A��β�ÿ�
	return B;
}

//12
LinkList Del_Same(LinkList &L){
	LNode *p=L->next,*q;//���幤��ָ��*pɨ������,���ָ��*q�����ж��Ƿ����
	while(p->next != nullptr){
		q=p->next;//ÿ��ѭ��*q����*p�ĺ�̽��

		if(p->data == q->data){//������,��ɾ��q���
			p->next = q->next;
			free(q);
		}
		else
			p=p->next;//����������ɨ��
	}
	return L;
}

//13
LinkList MergeList(LinkList &L1,LinkList &L2){

	LNode *r,*p1=L1->next,*p2=L2->next;//p1,p2�ֱ�ΪL1,L2�Ĺ���ָ��
	L1->next=nullptr;//L1��Ϊ��������ͷָ��,�Ƚ���������ÿ�

	while(p1 && p2)
		if(p1->data<=p2->data){//ͷ�巨
			r=p1->next;//r�ݴ��̽��ָ��
			p1->next=L1->next;
			L1->next=p1;
			p1=r;
		}
		else{//���뵽L1���������
		r=p2->next;
		p2->next=L1->next;
		L1->next=p2;
		p2=r;
		}

	if(p1)//�ж��ĸ�����û�б�����,��p2ָ��ָ�������
		p2=p1;
	
	while(p2){//��ͷ�巨��������ʣ��Ľ��
		r=p2->next;
		p2->next=L1->next;
		L1->next=p2;
		p2=r;
	}
	free(L2);//�ͷ�L2ͷ���

	return L1;//���ؽ������
}

//14
LinkList Get_Common(LinkList A,LinkList B){
	LNode *p=A->next,*q=B->next,*r,*s;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	r=C;

	while( p!=nullptr && q!=nullptr){
		if(p->data < q->data)//ֵ��С��������
			p=p->next;
		else if(q->data < p->data)
			q=q->next;
		else{
			s=(LinkList)malloc(sizeof(LNode));//�����½��
			s->data=p->data;//��AB��ͬ����ֵ��ֵ���½��
			r->next=s;//β�巨���½�����C����
			r=s;
			p=p->next;//��A�ͱ�B�������ɨ��
			q=q->next;
		}
	}
	r->next=nullptr;
	return C;
}

//15
LinkList Union(LinkList &la,LinkList &lb){
	LNode *pa=la->next,*pb=lb->next;//���ù���ָ��
	LNode *pc=la,*u;//������кϲ�����ǰ��ָ����ͷ�ָ��*u

	while(pa && pb){
		if(pa->data==pb->data){
			pc->next=pa;//A�н�����ӵ��������
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;//B�н���ͷ�
			free(u);
		}
		else if(pa->data<pb->data){//��A��ǰ���С��B�е�ǰ�ڵ�ֵ
			u=pa;
			pa=pa->next;//����ָ��
			free(u);//�ͷ�A�е�ǰ���
		}
		else{				//��B�е�ǰ���С��A�е�ǰ����ֵ
			u=pb;
			pb=pb->next;	//����ָ��
			free(u);		//�ͷ�B�е�ǰ���
		}
	}
	while(pa){//B�ѱ�����,Aδ��
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){//A�ѱ�����,Bδ��
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=nullptr;//������βָ��Ϊ��,��Ϊʹ�õ�ʹβ�巨
	free(lb);
	return la;
}

//16
bool Pattern(LinkList &A,LinkList &B){
	LNode *p=A->next,*pre=p;//pΪ����ָ��,pre��¼ÿ�αȽϵ�A����Ŀ�ʼ���
	LNode *q=B->next;//q��B�Ĺ���ָ��

	while(p && q){
		if(p->data == q->data){//���ֵ��ͬ
			p=p->next;
			q=q->next;
		}
		else{
			pre=pre->next;
			p=pre;//A�����µĿ�ʼ�ȽϽ��
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
	//���㷨����ͷɨ��ѭ��˫����,���ж��Ƿ�Գ�
	DNode *p=L->next,*q=L->prior;//��ͷ����ָ��
	while(p != q && q->next != p)//����Ϊż��ʱ,��ѭ����q����pʱ����������Ϊ����ʱ,��ѭ����q����һ���ڵ����pʱ,ѭ������
		if(p->data == q->data){//��ָ�Ľ��ֵ��ͬ������Ƚ�
			p=p->next;
			q=q->prior
		}
		else//����һ�����Գ�ʱ,ѭ������
			return 0;
	return 1;
}

//18
LinkList	Link(LinkList &h1,LinkList &h2){//����ѭ��������
	//��ѭ������h2���ӵ�ѭ������h1֮��,ʹ֮�Ա���ѭ���������ʽ
	LNode *p,*q;//�ֱ�ָ�����������β�ڵ�
	p=h1;
	while(p->next != h1)//Ѱ��h1��β���
		p=p->next;
	q=h2;
	while(q->next != h2)//Ѱ��h2��β���
		q=q->next;
	p->next=h2;//��h2���ӵ�h1֮��
	q->next=h1;//��h2��β���ָ��h1
	return h1;
}

//19
void Del_All(LinkList &L){//ѭ��������
	//���㷨ʵ��ÿ��ɾ��ѭ������������СֵԪ��,ֱ������Ϊ��
	LNode *p,*pre,*minp,*minpre;//����ָ��͹���ָ��ǰ��,��Сֵ������ǰ��
	while(L->next!=L){//����,ѭ��
		p=L->next;pre=L;
		minp=p;minpre=pre;
		while(p!=L){
			if(p->data < minp->data){
				minp=p;
				minpre=pre;
			}
			pre=p;//������һ�����
			p=p->next;
		}
		cout<<minp->data<<" "<<endl;//ÿ��ѭ�������һ�ε���С���ֵ
		minpre->next=minp->next;//ɾ����Сֵ���
		free(minp);//�ͷſռ�
	}
	free(L);//�ͷ�ͷ���
}

//20





int main(){
    // LinkList L = NULL;
    // L = CreatLinkListTail(L);//��ʼ������
    // OutPut(L);

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

    //4
	// Delete_Min(L);
	
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
    // L1 = CreatLinkListTail(L1);//��ʼ������
	// OutPut(L1);
    // LinkList L2 = NULL;
    // L2 = CreatLinkListTail(L2);//��ʼ������
	// OutPut(L2);
	// LinkList q = MergeList(L1,L2);
	// OutPut(q);
	
	//14
	// LinkList L1 = NULL;
    // L1 = CreatLinkListTail(L1);//��ʼ������
	// OutPut(L1);
    // LinkList L2 = NULL;
    // L2 = CreatLinkListTail(L2);//��ʼ������
	// OutPut(L2);
	// LinkList q = Get_Common(L1,L2);
	// OutPut(q);

	//15
	// LinkList L1 = NULL;
    // L1 = CreatLinkListTail(L1);//��ʼ������
	// OutPut(L1);
    // LinkList L2 = NULL;
    // L2 = CreatLinkListTail(L2);//��ʼ������
	// OutPut(L2);
	// cout<<"���кϲ�����:"<<endl;
	// LinkList q = Union(L1,L2);
	// OutPut(q);

	// OutPut(L);

	system ("pause");
    return 0;
}