/**
 * ��LΪ��ͷ���ĵ�����,��д�㷨ʵ�ִ�β��ͷ�������ÿ������ֵ
 * 
 * ˼·:1.ʹ��ͷ�巨
 *      2.�ݹ�
 * 
 * */

LinkList R_Print_1(LinkList &L){//ʹ��ͷ�巨,��������
	LNode *p = L->next,*q;//�������ָ��p�ͺ��ָ��q
	L->next = nullptr;//
	while(p != nullptr){//q=p->next,p=qʹÿ��ѭ��������q��p��ָ��ͬһ�����,����ѭ������
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
	return L;
}


void R_Print_2(LinkList &L){//�ݹ�
	//��β��ͷ���L����
	if(L ->next =nullptr)
		R_Print_2(L->next);
	if(L != nullptr)
		cout<<L->data<<" ";
}

void R_Ignore_Head(LinkList L){
    if(L != nullptr) R_Print_2(L->next);
}