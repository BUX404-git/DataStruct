/**
 * ��һά������A[m+n]�����δ������˳���[a1,a2,a3,a4...,b1,b2,b3...]
 * Ҫ�������е�����˳�����[b1,b2,b3...,a1,a2,a3,a4...]
 * 
 * ˼·���Ƚ��������鵹�ã�Ȼ��ǰn�������ã��ٽ���m��������
 * 
 * */

SqList Reverse_01(SqList &L){

    int n,m;
    cout<<"������m����ֵ��";
    cin>>m;
    cout<<endl;
    cout<<"������n����ֵ��";
    cin>>n;
    cout<<endl;
    int temp;
    for(int i=0;i<L.length/2;i++){//������˳�����
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }

    for(int j = 0;j< n/2;j++){//��ǰn��Ԫ�ص���
        temp = L.data[j];
        L.data[j] = L.data[n-j-1];
        L.data[n-j-1] = temp;
    }
    for(int k = 0;k< (L.length-n)/2;k++){//����m��Ԫ�ص���
        temp = L.data[k+n];
        L.data[k+n] = L.data[L.length-k-1];
        L.data[L.length-k-1] = temp;
    }
    return  L;
}

// typedef int Datatype;
// void Revserse(Datatype A[],int left,int right,int arraySize){
//     //��ת��aleft,aleft+1,aleft+2...,aright)Ϊ(aright,aright-1,...aleft)
//     if(left>=right || right>=arraySize)
//         return;
//     int mid = (left+right)/2;
//     for(int i=0;i<=mid-left;i++){
//         Datatype temp = A[right-i];
//         A[left+i] = A[right-i];
//         A[right-i] = temp;
//     }
// }

// void Exchange(DataType A[],int m,int n,int arraySize){
//     Revserse(A,0,m+n-1,arraySize);
//     Revserse(A,0,n-1,arraySize);
//     Revserse(A,n,m+n-1,arraySize);
// }