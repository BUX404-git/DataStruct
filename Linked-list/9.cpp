/**
 * ����һ������ͷ���ĵ�����,��headΪͷָ��.
 * ��д���㷨:��������������������и��ڵ������Ԫ��,
 * ���ͷŽ����ռ�Ĵ洢�ռ�(Ҫ��:������������Ϊ�����ռ�)
 * 
 * ˼·:��������б���,��ÿ�α������ҳ������������СֵԪ��,
 *      ������ͷŽ����ռ�ռ�;�ڲ��Ҵ�СֵԪ��,������Ƿ�ռ�,
 *      �����ȥ֪������Ϊ��,����ͷ�ͷ���Ĵ洢�ռ�
 * 
 * */


void Min_Delete(LinkList &head){
	cout<<"����ɾ����С���:";
	while(head->next != nullptr){
		LNode *pre = head;
		LNode *p=pre->next;
		while(p->next != nullptr){
			if(p->next->data < pre->next->data)
				pre = p;//preָ��ָ����Сֵ����ǰ���ڵ�
			p=p->next;//��������
		}
		cout<<pre->next->data<<" ";//�����Сֵ��������
		LNode *u = pre->next;//�����ͷ�ָ��u
		pre->next = u->next;
		free(u);
	}
	cout<<endl;
	free(head);//���ͷָ���ͷ�
}