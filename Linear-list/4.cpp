/**
 * ������˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��s<t��������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
 * 
 * ˼·����Ϊ������ģ��������ҵ���һ��>=s��Ԫ�أ����ҵ���һ��>t��Ԫ�أ�
 *       
 *       Ȼ�󣬽���һ��Ԫ��ɾ����ֻ�轫�����Ԫ��ǰ��;
 * 
 * */

bool Del_s_t(SqList &L,ElemType s,ElemType t){

    int i,j;
    if (s>=t || L.length == 0)
         return false;
    
    for ( i = 0;i<L.length && L.data[i]<s; i++);//Ѱ��ֵ���ڵ���s�ĵ�һ��Ԫ��

    if (i>=L.length)
        return false;//����Ԫ�ؾ�С��s������
    
    for(j=i;j<L.length && L.data[j]<=t;j++);//Ѱ��ֵ����t�ĵ�һ��Ԫ��
    
    for(;j<L.length;i++,j++)
        L.data[i] = L.data[j];//ǰ�ƣ����ɾԪ��λ��
    L.length=i;
    return true; 
    
}