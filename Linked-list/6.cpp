/**
 * 	有一个带头节点的单链表L,设计一个算法使其元素递增有序
 * 
 * 思路:采用直接插入排序的思想
 * 		将从第一个结点开始比较，每次从链表中取一个结点来比较（工作指针*p）,用*r来保存剩下链表
 * 		当找到最小值时,插入结点时,要用到*pre指针.每次从头结点*L开始比较
 * 		找到
 * 
 **/ 


 LinkList Sort(LinkList &L){
	LNode *p=L->next,*r=p->next,*pre;//遍历指针*r,搬运指针*p,前驱指针*pre 用来与*p比较
	p->next=nullptr;
	p=r;
	while(p != nullptr){
		r=p->next;
		pre = L;//每次循环从头结点开始比较
		if(pre->next != nullptr && p->data > pre->next->data )//比较pre的后一个结点的值，直到表尾
			pre=pre->next;

		p->next = pre->next;//比较完成,将该结点插入到pre的后面,即比较结点的前面
		pre->next = p;

		p=r;//指向下一个结点
	}
	return L;
 }