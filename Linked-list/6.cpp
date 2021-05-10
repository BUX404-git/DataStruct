/**
 * 	有一个带头节点的单链表L,设计一个算法使其元素递增有序
 * 
 * 思路:采用直接插入排序的思想
 * 
 **/ 

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