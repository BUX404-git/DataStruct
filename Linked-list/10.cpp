/**
 * ��һ����ͷ���ĵ�����A�ֽ�Ϊ������ͷ���ĵ�����A��B,
 * ʹ��A���к���ԭ�������Ϊ������Ԫ��,��B���к���ԭ�������Ϊż����Ԫ��,
 * �ұ������˳�򲻱�.
 * 
 * ˼·:forѭ����������,if����ж������ż.
 * 
 * */

LinkList DisCreate_1(LinkList &A){

	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = nullptr;//����B����ı�ͷ���

	LNode *ra = A,*rb = B;//ra��rb�ֱ�ָ�򽫴�����A���B���β���

	LNode *p = A->next;
	A->next = nullptr;//�ÿ��µ�A��

	int i = 0;
	while(p != nullptr){
		i++;
		if( i%2 == 0 ){
			rb->next = p;//��B��β�����½��
			rb=p;
		}
		else{
			ra->next = p;//��A��β�����½��
			ra = p;
		}
		p=p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}



