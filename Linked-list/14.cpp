/**
 * ��A��B������������(��ͷ���),����Ԫ�ص�������.
 * ���һ���㷨��A��B�Ĺ���Ԫ�ز���������C,Ҫ���ƻ�A B�Ľ��
 * 
 * ˼·:��Ϊ���������ǵ���,�ɴӵ�һ��Ԫ�����αȽ�A B�����Ԫ��,��Ԫ��ֵ����,
 * ��ֵС��ָ��������,�����,�򴴽�һ��ֵ�������ڵ��Ԫ��ֵ���½��,
 * ʹ��β�巨�����µ�������,����ԭ��ָ�����һλ,֪������һ�������������β
 * 
 * */


LinkList Get_Common(LinkList A,LinkList B){
	LNode *p=A->next,*q=B->next,*r,*s;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	r=C;

	while( p!=nullptr && q!=nullptr){
		if(p->data < q->data)//ֵ��С��������
			p=p->next;
		else if(q->data < p->data)
			q=q->next;
		else{
			s=(LinkList)malloc(sizeof(LNode));//�����½��
			s->data=p->data;//��AB��ͬ����ֵ��ֵ���½��
			r->next=s;//β�巨���½�����C����
			r=s;
			p=p->next;//��A�ͱ�B�������ɨ��
			q=q->next;
		}
	}
	r->next=nullptr;
	return C;
}




}