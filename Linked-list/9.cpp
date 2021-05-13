/**
 * 给定一个带表头结点的单链表,设head为头指针.
 * 试写出算法:按递增次序输出单链表中各节点的数据元素,
 * 并释放结点所占的存储空间(要求:不适用数组作为辅助空间)
 * 
 * 思路:对链表进行遍历,在每次遍历中找出整个链表的最小值元素,
 *      输出并释放结点所占空间;在查找次小值元素,输出并释放空间,
 *      如此下去知道链表为空,最后释放头结点的存储空间
 * 		两个while循环,一个if判断,
 * 		第一个循环的作用时找到剩下链表中的最小值结点,然后释放,直到链表为空.
 * 		第二个循环的作用是遍历剩下链表,标记最小值结点.
 * 		if语句判断,记录最小结点,第二个循环结束时释放该结点
 * 		
 * 		用p作为工作指针,pre作为比较指针和前驱指针
 * 
 * */


void Min_Delete(LinkList &head){
	cout<<"依次删除最小结点:";
	while(head->next != nullptr){
		LNode *pre = head;
		LNode *p=pre->next;
		while(p->next != nullptr){
			if(p->next->data < pre->next->data)
				pre = p;//pre指针指向最小值结点的前驱节点
			p=p->next;//继续遍历
		}
		cout<<pre->next->data<<" ";//输出最小值结点的数据
		LNode *u = pre->next;//定义释放指针u
		pre->next = u->next;
		free(u);
	}
	cout<<endl;
	free(head);//最后将头指针释放
}