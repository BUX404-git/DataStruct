/**
 * ������������A=a1,a2,a3,...,an��B=b1,b2,b3,...,bn���Ѿ�����������������
 * ���һ���㷨,�ж�����B�Ƿ�������A������������
 * 
 * 
 * ˼·:��������������ĵ�һ����㿪ʼ ,��data���,�����ָ��;
 * ����Ӧ���ݲ���,��A������ϴο�ʼ���ĺ�̽�㿪ʼ�Ƚ�,B�����Դӵ�һ����㿪ʼ�Ƚ�
 * ֱ��B����β��ʾƥ��ɹ�.A����β��B����δ��β���ʾʧ��
 * */

bool Pattern(LinkList &A,LinkList &B){
	LNode *p=A->next,*pre=p;//pΪ����ָ��,pre��¼ÿ�αȽϵ�A����Ŀ�ʼ���
	LNode *q=B->next;//q��B�Ĺ���ָ��

	while(p && q){
		if(p->data == q->data){//���ֵ��ͬ
			p=p->next;
			q=q->next;
		}
		else{
			pre=pre->next;
			p=pre;//A�����µĿ�ʼ�ȽϽ��
			q=B;
		}
	}
	if(q==nullptr)
		return 1;
	else 	
		return 0;
}