/**
 * ���һ���ݹ��㷨,ɾ������ͷ���ĵ�����L������ֵΪX�Ľ��
 * 
 * ˼·:���ݺ�������,��ƺ���f(L->next,x) ��ɾ��x
 *      ��ֹ����:f(L,x) <=> �����κ���     ��LΪ�ձ�
 *      �ݹ�����:f(L->next,x) <=> ɾ��*L���;f(L->next,x); ��L->data == x
 *      f(L,x) <=> f(L->next,x);
 * */

void Del_X_3(LinkList &L,ElemType x){
	//�ݹ�ʵ���ڵ�����L��ɾ��ֵΪx�Ľ��
	LNode *p;
	if(L == NULL)
		return;
	if(L->data == x){
		p=L;
		L=L->next;
		free(p);
		Del_X_3(L,x);
	}
	else
		Del_X_3(L->next,x); 
}
