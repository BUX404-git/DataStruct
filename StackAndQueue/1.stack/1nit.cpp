#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;

#define MaxSize 50

typedef struct{
    ElemType data[MaxSize];
    int top; 
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top=-1;
}

//判栈空
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else    
        return false;
}

//进栈
bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1)//栈满,不能入栈
        return false;
    S.data[++S.top]=x;//指针先加1,再入栈
    return true;
}

//出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1)//栈空,报错
        return false;
    x=S.data[S.top--];//先出栈，指针再减1
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,ElemType &x){
    if(S.top==-1)//栈空,报错
        return false;
    x=S.data[S.top];//x记录栈顶元素
        return true;
}

//建栈
void CreateStack(SqStack &s){
	int x;//出栈的时候读取到的值
	int data[MaxSize];//这一个数组的定义主要是为了使用PrintStack函数的时候使用的
	int n, m, i;
	InitStack(s);
	cout<<"请输入元素个数:";
	cin>>n;        
	cout<<endl;

	for (i = 0; i < n; i++){	
		cout<<"请输入入栈的第"<<i+1<<"个元素的值:";
		cin>>m;
		Push(s, m);
	}
	
	cout<<"出栈的元素:";
	for (i = 0; i < n; i++){
		Pop(s,x);
		cout<<x<<" ";
	}
	cout<<endl;
	
	GetTop(s,x);
	cout<<"此时的栈顶元素读取到为:"<<x<<endl;
}

//判断输出序列是否合法
bool Judge(char A[]){
	int i=0;
	int j=0,k=0;
	while(A[i] != '\0'){
		switch (A[i]){
		case 'I':
			j++;
			break;
		case 'O':
			k++;
			if(k>j) {cout<<"非法序列"<<endl; system ("pause");}
		}
	i++;
	}
	if(j != k){
		cout<<"非法序列"<<endl;
		return false;
	}
	else{
		cout<<"序列合法."<<endl;
		return true;
	}
}

int main(){
	SqStack s;
	CreateStack(s);

	// 3
	// char a[]={'I','O','I','I','O','I','O','O'};
	// Judge(a);

	system ("pause");
    return 0;
}

