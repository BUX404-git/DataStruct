/**
 * 设头指针为L的带有表头结点的非循环双向链表,其每个节点中除有pred(前驱指针)
 * data(数据)和next(后继指针)域外,还有一个访问频度域freq.
 * 在链表被启用前,其值均初始化为0.每当在链表中进行一次Locate(L,x)运算时,
 * 令元素值为x结点中freq域的值增1,并使此链表中结点保持按访问频度非增(递减)的顺序排列
 * 同时最近访问的结点排在频度相同的结点前面,以便使频繁访问的结点总是靠近表头.
 * 试编写符合尚需要求的Locate(L,x)运算的算法.该运算为函数过程,返回找到结点的地址,类型为指针型
 * 
 * 算法思想:首先在双向链表中查找数据值为x的结点,查到后,将结点从链表上摘下
 *      然后顺着结点的前驱链查找该结点的插入位置
 *      (频度递减,且排在同频度的第一个,即向前找到第一个比它的频度大的结点,插入位置为该结点之后)
 *      并插入到该位置
 * */
typedef struct DNode{
	int data;
	struct DNode *next,*pred,*freq;
}DNode,*DLinklist;

DLinklist Locate(DLinklist &L,int x){

	DNode *p=L->next,*q;
	while(p&&p->data!=x)
		p=p->next;
	if(!p){
		cout<<"不存在值为x的结点"<<endl;
		exit(0);
	}
	else{
		p->freq++;
		if(p->next!=nullptr)	p->next->pred=p->pred;
		p->pred->next=p->next;
		q=p->pred;
		while(q!=L&&q->freq<=p->freq)
			q=q->pred;
		p->next=q->next;
		q->next->pred=p;
		p->pred=q;
		q->next=p;
	}
	return p;
}