/**
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 * 
 * 思路：首先按顺序不断取下两个顺序表表头较小的节点存入新的顺序表。
 *      然后看哪个表还有剩余，将剩下的部分加到新的顺序表后面。
 *   
 * */

bool Merge(SqList A,SqList B,SqList &C){
    if(A.length + B.length > C.length)
        return false;
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length){
        if(A.data[i] < B.data[j])
            C.data[k++]=A.data[i++];
        else 
            C.data[k++]=B.data[j++];
    }
    while(i<A.length)
        C.data[k++]=A.data[i++];
    while(j<B.length)
        C.data[k++]=B.data[j++]
    C.length = k;
    return true;
}
