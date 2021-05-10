/**
 * 设A和B是两个单链表(带头结点),其中元素递增有序.
 * 设计一个算法从A和B的公共元素产生单链表C,要求不破坏A B的结点
 * 
 * 思路:因为两个链表都是递增,可从第一个元素依次比较A B两表的元素,若元素值不等,
 * 则值小的指针往后移,若相等,则创建一个值等于两节点的元素值的新结点,
 * 使用尾插法插入新的链表中,并将原表指针后移一位,知道其中一个链表遍历到表尾
 * 
 * */


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




}