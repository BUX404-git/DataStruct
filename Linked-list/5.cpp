/**
 * ��д�㷨����ͷ���ĵ�����͵�����,��ν "�͵�" ��ָ�����ռ临�Ӷ�ΪO(1)
 * 
 * ˼·:ͷ�巨�͵ݹ�
 * 
 * */

LinkList Inverse_1(LinkList &L){//ʹ��ͷ�巨��������
	LNode *p=L->next,*r;//�������ָ��r�Ͱ���ָ��p
	L->next = nullptr;//��ͷ���ָ��
	while(r != nullptr){
		r=p->next;
		p->next = L->next;
		L->next=p;
		p=r;
	}
	return L;
} 
LinkList Inverse_2(LinkList &L){//����ͷ�巨
		LNode *pre,*p=L->next,*r=L->next->next;//r�������̽ڵ�
		p->next=nullptr;
		while(r != nullptr){
			pre = p;
			p=r;
			r=r->next;
			p->next = pre;//ָ�뷴ת
		}
		L->next = p;
		return L;
	}
LinkList Recursion(LinkList &L){//����L������β��ͷ��� ��ʹ�õݹ�
 	if(L->next!=NULL)
 		Recursion(L->next);
 	if(L!=NULL)
 		cout<<L->data;//ͷ�ڵ��data��Ϊ��,���һ�������ʱ��Ϊ ��ֵַ
		 return L;
 	
   }