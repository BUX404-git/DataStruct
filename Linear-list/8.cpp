/**
 * 在一维数组中A[m+n]中依次存放两个顺序表[a1,a2,a3,a4...,b1,b2,b3...]
 * 要求将数组中的两个顺序表互换[b1,b2,b3...,a1,a2,a3,a4...]
 * 
 * 思路：先将整个数组倒置，然后将前n个数倒置，再将后m个数倒置
 * 
 * */

SqList Reverse_01(SqList &L){

    int n,m;
    cout<<"请输入m的数值：";
    cin>>m;
    cout<<endl;
    cout<<"请输入n的数值：";
    cin>>n;
    cout<<endl;
    int temp;
    for(int i=0;i<L.length/2;i++){//将整个顺序表倒置
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }

    for(int j = 0;j< n/2;j++){//将前n个元素倒置
        temp = L.data[j];
        L.data[j] = L.data[n-j-1];
        L.data[n-j-1] = temp;
    }
    for(int k = 0;k< (L.length-n)/2;k++){//将后m个元素倒置
        temp = L.data[k+n];
        L.data[k+n] = L.data[L.length-k-1];
        L.data[L.length-k-1] = temp;
    }
    return  L;
}

// typedef int Datatype;
// void Revserse(Datatype A[],int left,int right,int arraySize){
//     //逆转（aleft,aleft+1,aleft+2...,aright)为(aright,aright-1,...aleft)
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