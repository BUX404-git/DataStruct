/**
 * �Ա�д�㷨�ڴ�ͷ���ĵ�����L�У�ɾ��һ����Сֵ���ĸ�Ч�㷨��������Сֵ�����Ψһ�ģ�
 * 
 * ˼·:��������ڵ�*p��ǰ�����*pre��������Сֵ���*mip����Сֵ��ǰ���ڵ�*premip
 *       һ�߱���һ�߱Ƚ�.
 * */

LinkList Delete_Min(LinkList &L){
		LNode *p=L->next,*pre=L;
		LNode *minp=p,*preminp=pre;
		while(p != nullptr){//��������
			if(p->data < minp->data){//��minpָ��ָ����С�ڵ�
				minp = p;
				preminp = pre;
			}
				pre=p;//��������
				p=p->next;
			
		}
		preminp->next=minp->next;
		free(minp);
		return L;
	}