/**
 * 设在一个带表头结点的单链表中所有元素节点的数据值无序
 * 试编写一个函数,删除表中所有介于给定的两个值之间的元素
 * 
 * 思路:遍历链表,if判断是否要删除,定义前驱节点,遍历结点,释放结点
 * 
 * */

LinkList RangeDelete(LinkList &L){
	ElemType x;
	cout<<"请输入起始的值:";
	cin>>x;
	cout<<endl;
	ElemType y;
	cout<<"请输入结束的值:";
	cin>>y;
	cout<<endl;

	LNode *p=L->next,*pre=L,*q;//遍历结点p,前驱节点pre,释放指针q

	while(p != nullptr){
		if(p->data > x && p->data < y){
			q=p;
			p=p->next;
			pre->next=p;//删除值介于x和y之间的结点
			free(q);
		}
		else{
			pre=p;
			p=p->next;//继续遍历
		}
	}
	return L;
 }