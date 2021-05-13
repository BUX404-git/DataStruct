#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

#define elemtp int
#define maxsize 100

typedef struct{
    elemtp stack[maxsize];
    int top[2]; 
}stk;

stk s;//ȫ�ֱ���

//��ջ����
int push(int i,elemtp x){
    //��ջ����.iΪջ��,i=0��ʾ��ߵ�s1ջ,i=1��ʾ�ұߵ�s2ջ,x����ջԪ��
    //��ջ�ɹ�����1,���򷵻�0

    if(i<0 || i>1){
        cout<<"ջ���������!"<<endl;
        return 0;
    }

    if(s.top[1]-s.top[0]==1){
        cout<<"ջ����!"<<endl;
        return 0;
    }

    switch (i)
    {
    case 0:
        s.stack[++s.top[0]]=x;
        return 1;
        break;
    case 1:
        s.stack[--s.top[1]]=x;
        return 1;
    }
}

//��ջ����
elemtp pop(int i){
    //��ջ�㷨,i����ջ��,i=0ʱΪs1ջ,i=2ʱΪs2ջ
    //��ջ�ɹ�������ջԪ��,���򷵻�-1
    if(i<0 || i>1)
        return -1;
    switch (i){

        case 0:
            if(s.top[0]==-1){    
            cout<<"ջ��."<<endl;
            return -1;
            }
            else{
            return s.stack[s.top[0]--];
            }

        case 1:
            if(s.top[1]==maxsize){    
            cout<<"ջ��."<<endl;
            return -1;
            }
            else{
            return s.stack[s.top[1]--];
            }
    }       
}


