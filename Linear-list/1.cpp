/**
 * ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾԪ�ص�ֵ��
 * �ճ���λ�������һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
 * 
 * ˼·�������һ��Ԫ��ֵ��С��int x = L.data[0];
 *       Ȼ����һ��x���бȽϴ�С��С�����£�����¼��λ�á�
 *       ����������λ�õ�ֵ==���һ��Ԫ�ص�ֵ��
 *       length--;
 * 
 * */

bool Del_Min(SqList &L,ElemType &value){
    int locate;
    value= L.data[0];

    if(L.length == 0)
        return false;
    

    for(int i = 1;i<L.length;i++)
        if( L.data[i] < value){
            value = L.data[i];
            locate = i;
        }

    L.date[locate] = L.date[L.length-1];
    L.length--;
    return true;
    
}

