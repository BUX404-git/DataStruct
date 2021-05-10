/**
 * 设有一个带头结点的循环单链表,其结点值均为正整数.
 * 设计一个算法,反复找出单链表中结点值最小的结点并输出,然后将该结点从中删除
 * 直到单链表空为止,再删除表头结点
 * 
 * 思路:对于循环单链表L,在不空时循环:
 *      每循环一次查找一个最小结点(由minp指向最小值结点,minpre指向其前驱节点)并删除它.最后是否头结点
 * */

void Del_All(LinkList &L){//循环单链表
	//本算法实现每次删除循环单链表中最小值元素,直到链表为空
	LNode *p,*pre,*minp,*minpre;//工作指针和工作指针前驱,最小值结点和其前驱
	while(L->next!=L){//表不空,循环
		p=L->next;pre=L;
		minp=p;minpre=pre;
		while(p!=L){
			if(p->data < minp->data){
				minp=p;
				minpre=pre;
			}
			pre=p;//查找下一个结点
			p=p->next;
		}
		cout<<minp->data<<" "<<endl;//每次循环输出这一次的最小结点值
		minpre->next=minp->next;//删除最小值结点
		free(minp);//释放空间
	}
	free(L);//释放头结点
}