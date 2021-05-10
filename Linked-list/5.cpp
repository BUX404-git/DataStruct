/**
 * 编写算法将带头结点的单链表就地逆置,所谓 "就地" 是指辅助空间复杂度为O(1)
 * 
 * 思路:头插法和递归
 * 
 * */

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
 		cout<<L->data;//头节点的data域为空,最后一次输出的时候为 地址值
		 return L;
 	
   }