/**
 * 对长度为n的顺序表L，编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素
 *              （如果遍历顺序表，则每删一次，后面的元素就要都往前移动一位）
 * 思路：1.用k记录顺序表L中不等于x的元素个数（即需要保存的元素个数），边扫描边统计k，最后修改L的长度。
 *       2.用k记录顺序表L中等于x的元素个数，边扫描边统计k，并将不等于x的元素向前移动k个位置，最后修改L的长度。
 * */

void del_x_1(SqList &L,ElemType x){
    int k = 0;//记录值不等于x的元素个数
    for (int  i = 0; i < L.length; i++){
        if(L.data[i] != x){
            L.data[k] = L.data[i];
            K++         //不等于x的元素增1
        }
    }
    L.length = k;   //顺序表L的长度等于k
    
}

void del_x_2(SqList &L,ElemType x){
    int k=0,i=0;    //k记录值等于x的元素个数
    while(i<L.length){
        if(L.data[i] == x)
            k++;
        else    
            L.data[i-k]=L.data[i];//当前元素向前移k个位置
        i++;
    }
    L.length=L.length-k;//顺序表L的长度递减
}