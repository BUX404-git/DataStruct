/**
 * 试编写算法在带头结点的单链表L中，删除一个最小值结点的高效算法（假设最小值结点是唯一的）
 * 
 * 思路:定义遍历节点*p、前驱结点*pre、保存最小值结点*mip，最小值的前驱节点*premip
 *       一边遍历一边比较.
 * */

LinkList Delete_Min(LinkList &L){
		LNode *p=L->next,*pre=L;
		LNode *minp=p,*preminp=pre;
		while(p != nullptr){//遍历链表
			if(p->data < minp->data){//将minp指针指向最小节点
				minp = p;
				preminp = pre;
			}
				pre=p;//继续遍历
				p=p->next;
			
		}
		preminp->next=minp->next;
		free(minp);
		return L;
	}