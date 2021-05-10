/**
 * 将一个带头结点的单链表A分解为两个带头结点的单链表A和B,
 * 使得A表中含有原表中序号为奇数的元素,而B表中含有原表中序号为偶数的元素,
 * 且保持相对顺序不变.
 * 
 * 思路:for循环遍历链表,if语句判断序号奇偶.
 * 
 * */

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



