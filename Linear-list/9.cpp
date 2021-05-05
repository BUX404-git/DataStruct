/**
 * 有一元素递增的线性表，要求设计一个算法，完成用 最少的时间在表中查找数值为x的元素，
 * 若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍然有序递增
 * 
 * 思路：折半查找
 * 
 * 
 * */

SqList SearchExchangeInsert(ElemType A[],ElemType x){
    int low =0,high = n-1;mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==x) break;
        else if(A[mid] < x ) low = mid+1;
        else high = mid-1;
    }
    if(A[mid] == x && mid!=n-1){
        int t = A[mid]; A[mid] = A[mid+1]; A[mid+1] = t;
    }
    if(low > high){
        for(int i = n-1;i>high;i--) A[i-1]=A[i];
        A[i+1] = x;
    }
}