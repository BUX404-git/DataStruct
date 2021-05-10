/**
 * 设C={a1,b1,a2,b2,...,an,bn}为线性表,
 * 采用带头结点的hchc单链表存放,设计一个就地算法,
 * 将其拆分为两个线性表,使得A={a1,a2,a3,...,an}
 *                        B={bn,...,b3,b2,b1}
 * 
 * 思路:与第十题思路相似,不同的是,这里的B表采用头插法.
 * 
 * */

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