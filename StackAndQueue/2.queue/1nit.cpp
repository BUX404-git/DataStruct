#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int ElemType;

#define MAXSIZE 50

typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;



