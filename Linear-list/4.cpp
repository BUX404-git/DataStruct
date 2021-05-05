/**
 * 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
 * 
 * 思路：因为是有序的，所以先找到第一个>=s的元素，再找到第一个>t的元素，
 *       
 *       然后，将这一段元素删除，只需将后面的元素前移;
 * 
 * */

bool Del_s_t(SqList &L,ElemType s,ElemType t){

    int i,j;
    if (s>=t || L.length == 0)
         return false;
    
    for ( i = 0;i<L.length && L.data[i]<s; i++);//寻找值大于等于s的第一个元素

    if (i>=L.length)
        return false;//所有元素均小于s，返回
    
    for(j=i;j<L.length && L.data[j]<=t;j++);//寻找值大于t的第一个元素
    
    for(;j<L.length;i++,j++)
        L.data[i] = L.data[j];//前移，填补被删元素位置
    L.length=i;
    return true; 
    
}