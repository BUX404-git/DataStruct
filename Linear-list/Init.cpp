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


//创建线性表
SqList CreateList(SqList &L){
    L.length=0;
	int length;
    cout<<"请输入线性表的长度：";
    cin>>length;

    for(int i=0;i<length;i++){
        cout<<"请输入第"<<i+1<<"个元素:";
        ElemType x;
        cin>>x;
        L.data[i]=x;
        L.length++;
    }
    return L;
}

//输出线性表
void OutPut(SqList L){
	 cout<<"线性表中的元素为：";
    for(int i = 0 ; i < L.length ;i++){
       cout<<" "<<L.data[i];
    }
    cout<<endl;
}

//插入操作:在x位置插入数值e
SqList ListInsert(SqList &L){
    int x,e;
    cout<<"请输入你要插入的数：";
    cin>>e;
    cout<<"请输入你要插入的位置：";
    cin>>x;
    //判断输入的位置是否有效
    if( x > L.length+1 || x< 1){
        cout<<"该位置不可插入"<<endl;
        return L;
    }
    if(L.length >= MaxSize){
        cout<<"当前存储空间已满，不能插入"<<endl;
        return L;
    }
    for(int i=L.length; i >= x; i--)
        L.data[i] = L.data[i-1];
    L.data[x-1] = e;
    L.length++;

    return L;

}

//删除第i的位置的元素
SqList Del_x(SqList &L){
    int x;
    cout<<"请输入要删除的数的位置：";
    cin>>x;
    if(x > L.length || x<1){
        cout<<"输入错误"<<endl;
        return L;
    }
    for(int i=x-1;i<L.length;i++)
        L.data[i] = L.data[i+1];
    L.length--;
    return L;
}

//按值查找:查找值为x的第一个元素，并输出其位置
void Locate_x(SqList &L){
    int x;
    cout<<"请输入要查找的数：";
    cin>>x;

    int j;//标记x的位置
    for(int i= 0;i<L.length;i++){

        if(L.data[i] ==  x){
             j = i+1;
             break;
        }
           
    }
    cout<<"该值的位置是："<<j<<endl;
}

//1
SqList Del_Min(SqList &L){
    int x= L.data[0];
    int locate = 0,i;

    if(L.length == 0){
        cout<<"错误error"<<endl;
        return L;
    }

    for ( i = 1 ; i < L.length; i++){//从第二个开始比较
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
    
    ElemType temp;//辅助变量。暂存

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
    cout<<"请输入要删除的元素的值：";
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
    cout<<"请输入要删除的元素的值：";
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
    cout<<"请输入起始值：";
    cin>>s;
    cout<<endl;
    cout<<"请输入结束值：";
    cin>>t;
    cout<<endl;
    int i,j;
    if (s>=t || L.length == 0)
         return L;
    
    for ( i = 0;i<L.length && L.data[i]<s; i++);//寻找值大于等于s的第一个元素

    if (i>=L.length)
        return L;//所有元素均小于s，返回
    
    for(j=i;j<L.length && L.data[j]<=t;j++);//寻找值大于t的第一个元素
    
    for(;j<L.length;i++,j++)
        L.data[i] = L.data[j];//前移，填补被删元素位置
    L.length=i;
    return L; 
    
}

//5
SqList Del_s_t_R(SqList &L){
    int s,t;
    cout<<"请输入起始值：";
    cin>>s;
    cout<<endl;
    cout<<"请输入结束值：";
    cin>>t;
    cout<<endl;
    int i,k=0;
    if (L.length==0 || s>t)
        return L;       //线性表为空或s，t不合法，返回
    for ( i = 0; i < L.length; i++){
        if(L.data[i] >= s && L.data[i] < t )
            k++;
        else 
            L.data[i-k] = L.data[i];//当前元素前移k个位置
    }
    L.length-=k;//长度减小L.length=L.length-k;
    return L;   
}
    
//6
SqList Del_Same(SqList &L){
    if (L.length==0)
        return L;

    int i,j;
    for ( i = 0,j=1; j < L.length; j++)//插入排序的思想
        if(L.data[i] != L.data[j]){//判断上一个与下一个是否相等
            i++;
            L.data[i]=L.data[j];//若不同则插入到前面非重复有序表的最后
        }
    L.length=i+1;
    return L;
}

//7
SqList Merge(SqList A,SqList B,SqList &L){
    if(A.length + B.length > L.length)
        return L;
    int i=0,j=0,k=0;
    while( i<A.length && j<B.length){//循环两两比较,选出最小值
        if(A.data[i] < B.data[j])
            L.data[k++] = A.data[i++];
        else    
            L.data[k++] = B.data[j++];
    }
    //还剩一个灭有比较完的顺序表，把它剩下的部分加入到C表后面；
    while(i < A.length)
            L.data[k++] = A.data[i++];
    while(j < B.length)
            L.data[k++] = B.data[j++];
    L.length = k;//最后一次循环中k++；
    return L;
}

//8
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

    //在x位置插入数值e
    //ListInsert(L);

    //删除x位置的数
    //Del_x(L);

    //取的数值为x元素的位置
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
    //需要注释最上面的CreateList(L);OutPut(L);
    // SqList A,B;
    // cout<<"===初始化A表==="<<endl;
    // CreateList(A);
    // cout<<"===初始化B表==="<<endl;
    // CreateList(B);
    // Merge(A,B,L);
    // cout<<"合并后的L表为：";
    
    //8
    // Reverse_01(L);
    
    //9


    OutPut(L);

    return 0;
}