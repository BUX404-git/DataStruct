/**
 * ��֪��������A��B�ֱ��ʾ��������,��Ԫ�ص�������.
 * ���ƺ���,��A��B�Ľ���,�������A������
 * 
 * ˼·:���ù鲢��˼�룬������������ָ��pa��pb��
 *      ������������й鲢ɨ�裬ֻ��ͬʱ�������������е�Ԫ�أ�
 *      �����ӵ���������ҽ�����һ���������Ľ��ȫ���ͷ�
 *      ��һ�����������Ϻ��ͷ���һ������ʣ�µ�ȫ�����
 * */

LinkList Union(LinkList &la,LinkList &lb){
	LNode *pa=la->next,*pb=lb->next;//���ù���ָ��
	LNode *pc=la,*u;//������кϲ�����ǰ��ָ����ͷ�ָ��*u

	while(pa && pb){
		if(pa->data==pb->data){
			pc->next=pa;//A�н�����ӵ��������
			pc=pa;
			pa=pa->next;
			u=pb;
			pb=pb->next;//B�н���ͷ�
			free(u);
		}
		else if(pa->data<pb->data){//��A��ǰ���С��B�е�ǰ�ڵ�ֵ
			u=pa;
			pa=pa->next;//����ָ��
			free(u);//�ͷ�A�е�ǰ���
		}
		else{				//��B�е�ǰ���С��A�е�ǰ����ֵ
			u=pb;
			pb=pb->next;	//����ָ��
			free(u);		//�ͷ�B�е�ǰ���
		}
	}
	while(pa){//B�ѱ�����,Aδ��
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){//A�ѱ�����,Bδ��
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=nullptr;//������βָ��Ϊ��,��Ϊʹ�õ�ʹβ�巨
	free(lb);
	return la;
}