/**
 * �ڴ�ͷ�ڵ�ĵ�����L��,ɾ������ֵΪx�Ľ��,
 * ���ͷ���ռ�,����ֵΪx�Ľ�㲻Ψһ,�Ա�д�㷨��ʵ����������
 * 
 * ˼·: ����pָ���������;
 *      ����qָ��ָ�����ָ���ǰ�̽��,Ŀ�����ͷ�ֵΪx�Ľ��
 * */

void Del_X_1(LinkList &L,ElemType x){
    LNode *p=L->next,*pre=L,*q;//�������ָ���ǰ��ָ����ͷ�ָ��
    while(p != nullptr){
        if(p->data == x){
            q=p;//�ͷ�ָ��ָ��ý��
            p=p->next;
            pre->next=p;
            free(q);
        }
        else{
            pre = p;
            p=p->next;
        }
    }
}

void Del_X_2(LinkList &L,ElemType x){//ʹ��β�巨ɾ��ֵΪx�Ľ��
    LNode *p=L->next,*r=L,*q;
    L->next = nullptr;//��ͷ�����Ϊ��,ֻ��Ҫ�Ѳ�����x�Ľ����뵽��������
    while(p != nullptr){
        if(p->data != x){
            r->next = p;
            r=p;
            p=p->next;
        }
        else{
            q=p;
            p=p->next;
            free(q);
        }
    }
}
