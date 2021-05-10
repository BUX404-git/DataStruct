/**
 * 两个整数序列A=a1,a2,a3,...,an和B=b1,b2,b3,...,bn，已经存入两个单链表中
 * 设计一个算法,判断序列B是否是序列A的连续子序列
 * 
 * 
 * 思路:操作从两个链表的第一个结点开始 ,若data相等,则后移指针;
 * 若对应数据不等,则A链表从上次开始结点的后继结点开始比较,B链表仍从第一个结点开始比较
 * 直到B链表到尾表示匹配成功.A链表到尾而B链表未到尾则表示失败
 * */

bool Pattern(LinkList &A,LinkList &B){
	LNode *p=A->next,*pre=p;//p为工作指针,pre记录每次比较的A链表的开始结点
	LNode *q=B->next;//q是B的工作指针

	while(p && q){
		if(p->data == q->data){//结点值相同
			p=p->next;
			q=q->next;
		}
		else{
			pre=pre->next;
			p=pre;//A链表新的开始比较结点
			q=B;
		}
	}
	if(q==nullptr)
		return 1;
	else 	
		return 0;
}