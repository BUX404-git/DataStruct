/**
 * 设计一个递归算法,删除不带头结点的单链表L中所有值为X的结点
 * 
 * 思路:根据函数功能,设计函数f(L->next,x) 来删除x
 *      终止条件:f(L,x) <=> 不做任何事     若L为空表
 *      递归条件:f(L->next,x) <=> 删除*L结点;f(L->next,x); 若L->data == x
 *      f(L,x) <=> f(L->next,x);
 * */

void Del_X_3(LinkList &L,ElemType x){
	//递归实现在单链表L中删除值为x的结点
	LNode *p;
	if(L == NULL)
		return;
	if(L->data == x){
		p=L;
		L=L->next;
		free(p);
		Del_X_3(L,x);
	}
	else
		Del_X_3(L->next,x); 
}
