/**
 * Q��һ������,S��һ����ջ,ʵ�ֽ������е�Ԫ�����õ��㷨
 * 
 * �㷨˼��:������,��ջ,��ջ,������
 * 
 * */

#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;

#define MAXSIZE 50

typedef struct{
    ElemType data[MAXSIZE];
    int front,rear,tag;
}Queue;

typedef struct{
    ElemType data[MAXSIZE];
    int top; 
}Stack;


void Inverser(Stack &S,Queue &Q){
    while(!QueueEmpty(Q)){
        x=DeQueue(Q);//������
        Push(S,x);//��ջ
    }

    while(!StackEmpty(S)){
        Pop(S,x);//��ջ
        EnQueue(Q,x);//�����
    }
}



