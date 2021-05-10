/**
 * 假设有两个按元素值递增次序排列的线性表,均以单链表形式存储.
 * 请编写将这两个单链表归并为一个按元素值递减次序排列的单链表
 * 并要求利用原来两个单链表的结点存放归并后的单链表
 * 
 * 思路: 先将L1链表置空,作为结果链表,定义*p1,*p2工作指针分别指向L1,L2的开始结点
 *      比较结点的值,同时后移工作指针.因为要递减排序,所以使用头插法.
 *      最后可能还有一个链表没有遍历完,用if语句判断一下,将剩余的链表的结点用头插法插入结果链表中
 * 
 * */

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


