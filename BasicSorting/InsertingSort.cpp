#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;


//≤Â»Î≈≈–Ú
void InsertSort(int *a,int length){

    int i,j;
    for(j=1;j<length;j++){
        int key = a[j];//‘›¥Êa[j]µƒ÷µ
        i = j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }

}


void OutPut(int a[]){
    for (int i = 0; i < 10; i++){
		cout <<a[i]<<" ";
	}
	cout << endl;
}


int main(){
    int a[10] = {2,1,4,5,3,8,7,9,0,6};
    OutPut(a);
    int length = 10;
    InsertSort(a,10);
    OutPut(a);
    system ("pause");
    return 0;

}