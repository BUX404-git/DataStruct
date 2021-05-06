/**
 * 设L为带头结点的单链表,编写算法实现从尾到头反向输出每个结点的值
 * 
 * 思路:1.使用头插法
 *      2.递归
 * 
 * */

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

void R_Ignore_Head(LinkList L){
    if(L != nullptr) R_Print_2(L->next);
}