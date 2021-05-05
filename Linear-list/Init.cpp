#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

#define MaxSize 50
typedef int ElemType;


typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;


//�������Ա�
SqList CreateList(SqList &L){
    L.length=0;
	int length;
    cout<<"���������Ա�ĳ��ȣ�";
    cin>>length;

    for(int i=0;i<length;i++){
        cout<<"�������"<<i+1<<"��Ԫ��:";
        ElemType x;
        cin>>x;
        L.data[i]=x;
        L.length++;
    }
    return L;
}

//������Ա�
void OutPut(SqList L){
	 cout<<"���Ա��е�Ԫ��Ϊ��";
    for(int i = 0 ; i < L.length ;i++){
       cout<<" "<<L.data[i];
    }
    cout<<endl;
}

//�������:��xλ�ò�����ֵe
SqList ListInsert(SqList &L){
    int x,e;
    cout<<"��������Ҫ���������";
    cin>>e;
    cout<<"��������Ҫ�����λ�ã�";
    cin>>x;
    //�ж������λ���Ƿ���Ч
    if( x > L.length+1 || x< 1){
        cout<<"��λ�ò��ɲ���"<<endl;
        return L;
    }
    if(L.length >= MaxSize){
        cout<<"��ǰ�洢�ռ����������ܲ���"<<endl;
        return L;
    }
    for(int i=L.length; i >= x; i--)
        L.data[i] = L.data[i-1];
    L.data[x-1] = e;
    L.length++;

    return L;

}

//ɾ����i��λ�õ�Ԫ��
SqList Del_x(SqList &L){
    int x;
    cout<<"������Ҫɾ��������λ�ã�";
    cin>>x;
    if(x > L.length || x<1){
        cout<<"�������"<<endl;
        return L;
    }
    for(int i=x-1;i<L.length;i++)
        L.data[i] = L.data[i+1];
    L.length--;
    return L;
}

//��ֵ����:����ֵΪx�ĵ�һ��Ԫ�أ��������λ��
void Locate_x(SqList &L){
    int x;
    cout<<"������Ҫ���ҵ�����";
    cin>>x;

    int j;//���x��λ��
    for(int i= 0;i<L.length;i++){

        if(L.data[i] ==  x){
             j = i+1;
             break;
        }
           
    }
    cout<<"��ֵ��λ���ǣ�"<<j<<endl;
}

//1
SqList Del_Min(SqList &L){
    int x= L.data[0];
    int locate = 0,i;

    if(L.length == 0){
        cout<<"����error"<<endl;
        return L;
    }

    for ( i = 1 ; i < L.length; i++){//�ӵڶ�����ʼ�Ƚ�
        if (L.data[i] < x){
            x = L.data[i];
            locate = i;
        }
        
    }

    L.data[locate] = L.data[L.length-1];
    L.length--;
    return L;
    
}

//2
SqList Reverse_2(SqList &L){
    
    ElemType temp;//�����������ݴ�

    for (int i = 0; i < L.length/2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
        
    }

    return L;
    
}

//3
SqList del_x_1(SqList &L){
    int x;
    cout<<"������Ҫɾ����Ԫ�ص�ֵ��";
    cin>>x;
    cout<<endl;
    int k=0;
    for (int i = 0; i < L.length; i++)
        if(L.data[i] != x){
            L.data[k] = L.data[i];
            k++;
        }

    L.length = k;
    return L;
    
}
SqList del_x_2(SqList &L){
    int x;
    cout<<"������Ҫɾ����Ԫ�ص�ֵ��";
    cin>>x;
    cout<<endl;
    int k = 0,i =0;
    while(i<L.length){
        if(L.data[i] == x)
            k++;
        else    
            L.data[i-k] = L.data[i];
        i++;
    }
    L.length = L.length-k;
     
     return L;
}

//4
SqList Del_s_t_L(SqList &L){
    int s,t;
    cout<<"��������ʼֵ��";
    cin>>s;
    cout<<endl;
    cout<<"���������ֵ��";
    cin>>t;
    cout<<endl;
    int i,j;
    if (s>=t || L.length == 0)
         return L;
    
    for ( i = 0;i<L.length && L.data[i]<s; i++);//Ѱ��ֵ���ڵ���s�ĵ�һ��Ԫ��

    if (i>=L.length)
        return L;//����Ԫ�ؾ�С��s������
    
    for(j=i;j<L.length && L.data[j]<=t;j++);//Ѱ��ֵ����t�ĵ�һ��Ԫ��
    
    for(;j<L.length;i++,j++)
        L.data[i] = L.data[j];//ǰ�ƣ����ɾԪ��λ��
    L.length=i;
    return L; 
    
}

//5
SqList Del_s_t_R(SqList &L){
    int s,t;
    cout<<"��������ʼֵ��";
    cin>>s;
    cout<<endl;
    cout<<"���������ֵ��";
    cin>>t;
    cout<<endl;
    int i,k=0;
    if (L.length==0 || s>t)
        return L;       //���Ա�Ϊ�ջ�s��t���Ϸ�������
    for ( i = 0; i < L.length; i++){
        if(L.data[i] >= s && L.data[i] < t )
            k++;
        else 
            L.data[i-k] = L.data[i];//��ǰԪ��ǰ��k��λ��
    }
    L.length-=k;//���ȼ�СL.length=L.length-k;
    return L;   
}
    
//6
SqList Del_Same(SqList &L){
    if (L.length==0)
        return L;

    int i,j;
    for ( i = 0,j=1; j < L.length; j++)//���������˼��
        if(L.data[i] != L.data[j]){//�ж���һ������һ���Ƿ����
            i++;
            L.data[i]=L.data[j];//����ͬ����뵽ǰ����ظ����������
        }
    L.length=i+1;
    return L;
}

//7
SqList Merge(SqList A,SqList B,SqList &L){
    if(A.length + B.length > L.length)
        return L;
    int i=0,j=0,k=0;
    while( i<A.length && j<B.length){//ѭ�������Ƚ�,ѡ����Сֵ
        if(A.data[i] < B.data[j])
            L.data[k++] = A.data[i++];
        else    
            L.data[k++] = B.data[j++];
    }
    //��ʣһ�����бȽ����˳�������ʣ�µĲ��ּ��뵽C����棻
    while(i < A.length)
            L.data[k++] = A.data[i++];
    while(j < B.length)
            L.data[k++] = B.data[j++];
    L.length = k;//���һ��ѭ����k++��
    return L;
}

//8
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

//9
SqList SearchExchangeInsert(ElemType A[],ElemType x){
    int low =0,high = n-1;mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==x) break;
        else if(A[mid] < x ) low = mid+1;
        else high = mid-1;
    }
    if(A[mid] == x && mid!=n-1){
        int t = A[mid]; A[mid] = A[mid+1]; A[mid+1] = t;
    }
    if(low > high){
        for( i = n-1;i>high;i--) A[i-1]=A[i];
        A[i+1] = x;
    }
}


int main(){
    SqList L;
    CreateList(L);
    OutPut(L);

    //��xλ�ò�����ֵe
    //ListInsert(L);

    //ɾ��xλ�õ���
    //Del_x(L);

    //ȡ����ֵΪxԪ�ص�λ��
    //Locate_x(L);

    //1
    // Del_Min(L);

    //2
    // Reverse(L);

    //3
    // del_x_1(L);
    // del_x_2(L);

    //4
    // Del_s_t_L(L);

    //5
    // Del_s_t_R(L);

    //6
    // Del_Same(L);

    //7
    //��Ҫע���������CreateList(L);OutPut(L);
    // SqList A,B;
    // cout<<"===��ʼ��A��==="<<endl;
    // CreateList(A);
    // cout<<"===��ʼ��B��==="<<endl;
    // CreateList(B);
    // Merge(A,B,L);
    // cout<<"�ϲ����L��Ϊ��";
    
    //8
    // Reverse_01(L);
    
    //9


    OutPut(L);

    return 0;
}