/**
 * ������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ����ͬ
 * 
 * ˼·����Ϊ������˳�����������ͬ��ֵһ����������λ���ϡ�
 *      ����˳�����
 *      �������ڲ��������˼�룬��ʼʱ����һ��Ԫ����Ϊ���ظ����������
 *      ֮�������жϺ����Ԫ���Ƿ���ǰ����ظ�����������һ��Ԫ����ͬ��
 *      ����ͬ�����������жϣ�����ͬ�������ǰ��ķ��ظ�����������
 *      ֱ���жϵ���βΪֹ��
 * 
 * */


bool Del_Same(SqList &L){
    if(L.length ==0)
        return false;
    int i,j;
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i] != L.data[j])
            L.data[++i] = L.data[j]
    }
    L.length = i-1;
    return true;
}
