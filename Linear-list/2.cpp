/**
 * ���һ����Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
 * 
 * 
 * ˼·��ɨ��˳���L��ǰ�벿��Ԫ�أ�����Ԫ��L.data[i](0<=i<L.length/2),
 *       �������벿�ֵĶ�ӦԪ��L.data[L.length-i-1]���н�����
 * 
 * */

void Reverse(SqList &L){
    int temp;

    for (int i = 0; i < L.length/2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
    
}


