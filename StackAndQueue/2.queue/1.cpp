/**
 * ��ϣ��ѭ�������е�Ԫ�ض��ܵõ����ã�����Ҫ����һ����־��tag��
 * ����tag��ֵΪ0��1�����ֶ�ͷָ��front�Ͷ�βָ��rear��ͬʱ�Ķ���״̬��
 *���ա����ǡ��������Ա�д��˽ṹ��Ӧ����Ӻͳ����㷨
 * 
 * �㷨˼��: �ӿ�����:Q.front==Q.rear && Q.tag==0
 *          ��������Q.front==Q.rear && Q.tag==1
 *          ���Ӳ���:Q.data[Q.rear]=x;Q.rear=(Q.rear+1)%MAXSIZE;Q.tag=1
 *          ���Ӳ���:x=Q.data[Q.front],Q.front=(Q.front+1)%MAXSIZE;Q.tag=0;
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

//����㷨
int EnQueue1(SqQueue &Q,ElemType x){
    if(Q.rear==Q.front && Q.tag==1)
        return 0;
    Q.data[Q.rear]=x;Q.rear=(Q.rear+1)%MAXSIZE;Q.tag=1;
    return 1;
}

//�����㷨
int DeQueue1(SqQueue &Q,ElemType x){
    if(Q.rear==Q.front && Q.tag==0)
        return 0;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    Q.tag=0;
}




