/**
 * 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
 * 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
 * 
 * 思路：假设第一个元素值最小，int x = L.data[0];
 *       然后逐一与x进行比较大小，小的留下，并记录该位置。
 *       遍历完后，令该位置的值==最后一个元素的值。
 *       length--;
 * 
 * */

bool Del_Min(SqList &L,ElemType &value){
    int locate;
    value= L.data[0];

    if(L.length == 0)
        return false;
    

    for(int i = 1;i<L.length;i++)
        if( L.data[i] < value){
            value = L.data[i];
            locate = i;
        }

    L.date[locate] = L.date[L.length-1];
    L.length--;
    return true;
    
}

