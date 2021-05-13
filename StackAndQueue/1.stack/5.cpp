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

stk s;//全局变量

//入栈操作
int push(int i,elemtp x){
    //入栈操作.i为栈号,i=0表示左边的s1栈,i=1表示右边的s2栈,x是入栈元素
    //入栈成功返回1,否则返回0

    if(i<0 || i>1){
        cout<<"栈号输入错误!"<<endl;
        return 0;
    }

    if(s.top[1]-s.top[0]==1){
        cout<<"栈已满!"<<endl;
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

//退栈操作
elemtp pop(int i){
    //退栈算法,i代表栈号,i=0时为s1栈,i=2时为s2栈
    //退栈成功返回退栈元素,否则返回-1
    if(i<0 || i>1)
        return -1;
    switch (i){

        case 0:
            if(s.top[0]==-1){    
            cout<<"栈空."<<endl;
            return -1;
            }
            else{
            return s.stack[s.top[0]--];
            }

        case 1:
            if(s.top[1]==maxsize){    
            cout<<"栈空."<<endl;
            return -1;
            }
            else{
            return s.stack[s.top[1]--];
            }
    }       
}


