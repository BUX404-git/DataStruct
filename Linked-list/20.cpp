/**
 * ��ͷָ��ΪL�Ĵ��б�ͷ���ķ�ѭ��˫������,��ÿ���ڵ��г���pred(ǰ��ָ��)
 * data(����)��next(���ָ��)����,����һ������Ƶ����freq.
 * ����������ǰ,��ֵ����ʼ��Ϊ0.ÿ���������н���һ��Locate(L,x)����ʱ,
 * ��Ԫ��ֵΪx�����freq���ֵ��1,��ʹ�������н�㱣�ְ�����Ƶ�ȷ���(�ݼ�)��˳������
 * ͬʱ������ʵĽ������Ƶ����ͬ�Ľ��ǰ��,�Ա�ʹƵ�����ʵĽ�����ǿ�����ͷ.
 * �Ա�д��������Ҫ���Locate(L,x)������㷨.������Ϊ��������,�����ҵ����ĵ�ַ,����Ϊָ����
 * 
 * �㷨˼��:������˫�������в�������ֵΪx�Ľ��,�鵽��,������������ժ��
 *      Ȼ��˳�Ž���ǰ�������Ҹý��Ĳ���λ��
 *      (Ƶ�ȵݼ�,������ͬƵ�ȵĵ�һ��,����ǰ�ҵ���һ��������Ƶ�ȴ�Ľ��,����λ��Ϊ�ý��֮��)
 *      �����뵽��λ��
 * */
typedef struct DNode{
	int data;
	struct DNode *next,*pred,*freq;
}DNode,*DLinklist;

DLinklist Locate(DLinklist &L,int x){

	DNode *p=L->next,*q;
	while(p&&p->data!=x)
		p=p->next;
	if(!p){
		cout<<"������ֵΪx�Ľ��"<<endl;
		exit(0);
	}
	else{
		p->freq++;
		if(p->next!=nullptr)	p->next->pred=p->pred;
		p->pred->next=p->next;
		q=p->pred;
		while(q!=L&&q->freq<=p->freq)
			q=q->pred;
		p->next=q->next;
		q->next->pred=p;
		p->pred=q;
		q->next=p;
	}
	return p;
}