/**
 * ����һ������ͷ���ĵ�����������Ԫ�ؽڵ������ֵ����
 * �Ա�дһ������,ɾ���������н��ڸ���������ֵ֮���Ԫ��
 * 
 * ˼·:��������,if�ж��Ƿ�Ҫɾ��,����ǰ���ڵ�,�������,�ͷŽ��
 * 
 * */

LinkList RangeDelete(LinkList &L){
	ElemType x;
	cout<<"��������ʼ��ֵ:";
	cin>>x;
	cout<<endl;
	ElemType y;
	cout<<"�����������ֵ:";
	cin>>y;
	cout<<endl;

	LNode *p=L->next,*pre=L,*q;//�������p,ǰ���ڵ�pre,�ͷ�ָ��q

	while(p != nullptr){
		if(p->data > x && p->data < y){
			q=p;
			p=p->next;
			pre->next=p;//ɾ��ֵ����x��y֮��Ľ��
			free(q);
		}
		else{
			pre=p;
			p=p->next;//��������
		}
	}
	return L;
 }