/**
 * ��������������,��д�㷨�ҳ���������Ĺ����ڵ�
 * 
 * ˼·:��Ϊ���������,һ��nextֻ��ָ��һ�����,
 *      �����ҵ���һ���������֮������нڵ㶼�ǹ������,������Y
 *      ���ǹ������֮ǰ�������Ȳ�һ��,������������Ǵ�ͷ��ʼ����
 *      �򲢲��ܱ�֤��ͬʱ�ﵽ�������,���������֪�����������k�����
 *      ���ǾͿ����ȱ����ϳ�����k�����,��ͬʱ����,ֱ���ҵ���һ���������
 *      ���������������,�õ���ֵk
 *      ��һ�����,�󹫹����
 * 
 * */

LinkList Search_1st_Common(LinkList L1,LinkList L2){
	int len1 = getlength(L1), len2 = getlength(L2);
	
	LinkList longlist,shortlist;
	int dist;//�����ֵ

	if(len1 > len2){//��longlistָ��ϳ������ʵ�ʽ��
		longlist = L1->next;shortlist = L2->next;
		dist = len1 - len2;
	}
	else{
		longlist = L2->next;shortlist = L1->next;
		dist = len2 - len1;
	}

	while(dist--)
		longlist = longlist->next;//�Ƚ��������������dist�����,Ȼ��ͬ��
	
	while(longlist != nullptr){//��ʼͬ������
		if(longlist == shortlist)
			return longlist;
		else{
			longlist=longlist->next;
			shortlist=shortlist->next;
		}
		return nullptr;
	}
	
}