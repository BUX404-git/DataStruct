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

//��ʼ��ջ
void InitStack(SqStack &S){
    S.top=-1;
}

//��ջ��
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else    
        return false;
}

//��ջ
bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1)//ջ��,������ջ
        return false;
    S.data[++S.top]=x;//ָ���ȼ�1,����ջ
    return true;
}

//��ջ
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1)//ջ��,����
        return false;
    x=S.data[S.top--];//�ȳ�ջ��ָ���ټ�1
    return true;
}

//��ջ��Ԫ��
bool GetTop(SqStack S,ElemType &x){
    if(S.top==-1)//ջ��,����
        return false;
    x=S.data[S.top];//x��¼ջ��Ԫ��
        return true;
}

//��ջ
void CreateStack(SqStack &s){
	int x;//��ջ��ʱ���ȡ����ֵ
	int data[MaxSize];//��һ������Ķ�����Ҫ��Ϊ��ʹ��PrintStack������ʱ��ʹ�õ�
	int n, m, i;
	InitStack(s);
	cout<<"������Ԫ�ظ���:";
	cin>>n;        
	cout<<endl;

	for (i = 0; i < n; i++){	
		cout<<"��������ջ�ĵ�"<<i+1<<"��Ԫ�ص�ֵ:";
		cin>>m;
		Push(s, m);
	}
	
	cout<<"��ջ��Ԫ��:";
	for (i = 0; i < n; i++){
		Pop(s,x);
		cout<<x<<" ";
	}
	cout<<endl;
	
	GetTop(s,x);
	cout<<"��ʱ��ջ��Ԫ�ض�ȡ��Ϊ:"<<x<<endl;
}

//�ж���������Ƿ�Ϸ�
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
			if(k>j) {cout<<"�Ƿ�����"<<endl; system ("pause");}
		}
	i++;
	}
	if(j != k){
		cout<<"�Ƿ�����"<<endl;
		return false;
	}
	else{
		cout<<"���кϷ�."<<endl;
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

