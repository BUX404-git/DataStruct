/**
 * 	��һ����ͷ�ڵ�ĵ�����L,���һ���㷨ʹ��Ԫ�ص�������
 * 
 * ˼·:����ֱ�Ӳ��������˼��
 * 		���ӵ�һ����㿪ʼ�Ƚϣ�ÿ�δ�������ȡһ��������Ƚϣ�����ָ��*p��,��*r������ʣ������
 * 		���ҵ���Сֵʱ,������ʱ,Ҫ�õ�*preָ��.ÿ�δ�ͷ���*L��ʼ�Ƚ�
 * 		�ҵ�
 * 
 **/ 


 LinkList Sort(LinkList &L){
	LNode *p=L->next,*r=p->next,*pre;//����ָ��*r,����ָ��*p,ǰ��ָ��*pre ������*p�Ƚ�
	p->next=nullptr;
	p=r;
	while(p != nullptr){
		r=p->next;
		pre = L;//ÿ��ѭ����ͷ��㿪ʼ�Ƚ�
		if(pre->next != nullptr && p->data > pre->next->data )//�Ƚ�pre�ĺ�һ������ֵ��ֱ����β
			pre=pre->next;

		p->next = pre->next;//�Ƚ����,���ý����뵽pre�ĺ���,���ȽϽ���ǰ��
		pre->next = p;

		p=r;//ָ����һ�����
	}
	return L;
 }