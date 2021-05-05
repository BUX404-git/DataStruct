/**
 * 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
 * 
 * 
 * 思路：扫描顺序表L的前半部分元素，对于元素L.data[i](0<=i<L.length/2),
 *       将其与后半部分的对应元素L.data[L.length-i-1]进行交换。
 * 
 * */

void Reverse(SqList &L){
    int temp;

    for (int i = 0; i < L.length/2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
    
}


