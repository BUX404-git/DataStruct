/**
 * 已知两个链表A和B分别表示两个集合,其元素递增排列.
 * 编制函数,求A与B的交集,并存放于A链表中
 * 
 * 思路:采用归并的思想，设置两个工作指针pa和pb，
 *      对两个链表进行归并扫描，只有同时出现在两集合中的元素，
 *      才链接到结果表中且仅保留一个，其他的结点全部释放
 *      当一个链表遍历完毕后，释放另一个表中剩下的全部结点
 * */

LinkList Union(LinkList &la,LinkList &lb){
	LNode *pa=la->next,*pb=lb->next;//设置工作指针
	LNode *pc=la,*u;//结果表中合并结点的前驱指针和释放指针*u

	while(pa && pb){
		if(pa->data==pb->data){
			pc->next=pa;//A中结点链接到结果表中
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;//B中结点释放
			free(u);
		}
		else if(pa->data<pb->data){//若A当前结点小于B中当前节点值
			u=pa;
			pa=pa->next;//后移指针
			free(u);//释放A中当前结点
		}
		else{				//若B中当前结点小于A中当前结点的值
			u=pb;
			pb=pb->next;	//后移指针
			free(u);		//释放B中当前结点
		}
	}
	while(pa){//B已遍历完,A未完
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){//A已遍历完,B未完
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=nullptr;//置链表尾指针为空,因为使用的使尾插法
	free(lb);
	return la;
}