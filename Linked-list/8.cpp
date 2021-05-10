/**
 * 给定两个单链表,编写算法找出两个链表的公共节点
 * 
 * 思路:因为链表的性质,一个next只能指向一个结点,
 *      所以找到第一个公共结点之后的所有节点都是公共结点,类似于Y
 *      但是公共结点之前的链表长度不一致,如果两个链表都是从头开始遍历
 *      则并不能保证能同时达到公共结点,但是如果能知道链表长度相差k个结点
 *      我们就可以先遍历较长链表k个结点,再同时遍历,直至找到第一个公共结点
 *      所以先求出链表长度,得到差值k
 *      再一起遍历,求公共结点
 * 
 * */

LinkList Search_1st_Common(LinkList L1,LinkList L2){
	int len1 = getlength(L1), len2 = getlength(L2);
	
	LinkList longlist,shortlist;
	int dist;//定义差值

	if(len1 > len2){//将longlist指向较长链表的实际结点
		longlist = L1->next;shortlist = L2->next;
		dist = len1 - len2;
	}
	else{
		longlist = L2->next;shortlist = L1->next;
		dist = len2 - len1;
	}

	while(dist--)
		longlist = longlist->next;//先将长链表遍历到第dist个结点,然后同步
	
	while(longlist != nullptr){//开始同步遍历
		if(longlist == shortlist)
			return longlist;
		else{
			longlist=longlist->next;
			shortlist=shortlist->next;
		}
		return nullptr;
	}
	
}