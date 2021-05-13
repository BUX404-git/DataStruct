/**
 * 若希望循环队列中的元素都能得到利用，则需要设置一个标志域tag，
 * 并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的队列状态是
 *“空”还是“满”。试编写与此结构相应的入队和出对算法
 * 
 * 算法思想: 队空条件:Q.front==Q.rear && Q.tag==0
 *          队满条件Q.front==Q.rear && Q.tag==1
 *          进队操作:Q.data[Q.rear]=x;Q.rear=(Q.rear+1)%MAXSIZE;Q.tag=1
 *          出队操作:x=Q.data[Q.front],Q.front=(Q.front+1)%MAXSIZE;Q.tag=0;
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
}SqQueue;

//入队算法
int EnQueue1(SqQueue &Q,ElemType x){
    if(Q.rear==Q.front && Q.tag==1)
        return 0;
    Q.data[Q.rear]=x;Q.rear=(Q.rear+1)%MAXSIZE;Q.tag=1;
    return 1;
}

//出队算法
int DeQueue1(SqQueue &Q,ElemType x){
    if(Q.rear==Q.front && Q.tag==0)
        return 0;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    Q.tag=0;
}




