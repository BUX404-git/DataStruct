/**
 * 	��һ����ͷ�ڵ�ĵ�����L,���һ���㷨ʹ��Ԫ�ص�������
 * 
 * ˼·:����ֱ�Ӳ��������˼��
 * 
 **/ 

 LinkList Sort(LinkList &L){
	LNode *p=L->next,*r=p->next,*pre;//����ָ��*r,����ָ��*p,ǰ��ָ��*pre ������*p�Ƚ�
	p->next=nullptr;
	p=r;
	while(p != nullptr){
		r=p->next;
		pre = L;//ÿ��ѭ����ͷ��㿪ʼ�Ƚ�
		if(pre->next != nullptr && pre->next->data < p->data)//�Ƚ�pre�ĺ�һ������ֵ��ֱ����β
			pre=pre->next;

		p->next = pre->next;//�Ƚ����,���ý����뵽pre�ĺ���
		pre->next = p;

		p=r;//ָ����һ�����
	}
	return L;
 }