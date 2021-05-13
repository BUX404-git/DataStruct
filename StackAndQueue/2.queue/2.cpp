/**
 * Q是一个队列,S是一个空栈,实现将队列中的元素逆置的算法
 * 
 * 算法思想:出队列,入栈,出栈,进队列
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
        x=DeQueue(Q);//出队列
        Push(S,x);//入栈
    }

    while(!StackEmpty(S)){
        Pop(S,x);//出栈
        EnQueue(Q,x);//入队列
    }
}



