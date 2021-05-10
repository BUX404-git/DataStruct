/**
 * ��C={a1,b1,a2,b2,...,an,bn}Ϊ���Ա�,
 * ���ô�ͷ����hchc��������,���һ���͵��㷨,
 * ������Ϊ�������Ա�,ʹ��A={a1,a2,a3,...,an}
 *                        B={bn,...,b3,b2,b1}
 * 
 * ˼·:���ʮ��˼·����,��ͬ����,�����B�����ͷ�巨.
 * 
 * */

LinkList DisCreate_2(LinkList &A){
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = nullptr;//����B���ͷ���

	LNode *p=A->next;//���幤��ָ��*p

	A->next = nullptr;//��A���ÿ�

	LNode *ra = A,*rb = B;//����A��ı�βָ��*ra,��B���ͷָ��*rb

	LNode *r;//����*r�����ֹ���ָ��*p�ĺ�̽��

	int i = 0;
	while(p != nullptr){
		i++;
		r = p->next;//�����̽��
		if( i%2 == 0){//ʹ��ͷ�巨��{b1,b2,b3,...,bn}����
			p->next = rb->next;
			rb->next = p;
		}
		else{
			ra->next = p;//��10��һ��,��{a1,a2,a3,...,an}�������β
			ra = p;
		}
		p=r;//����ָ���������
	}
	ra->next = nullptr;//���A��β�ÿ�
	return B;
}