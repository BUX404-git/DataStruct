/**
 * 从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，
 * 若s或t不合理或顺序表为空，则显示出错误信息，并退出运行。
 * 
 * 思路：从前往后扫描顺序表L;用k记录下元素值在s到t之间元素的个数（初始时k=0）。
 *      对于当前扫描的元素，若其值不在s到t之间，则前移k个位置：否则执行k++。
 *      由于这样每个不在s到t之间的元素仅移动了一次
 * */

bool Del_s_t(SqList &L,ElemType s,ElemType t){
    int i,k=0;

    if(L.length == 0 || s>=t)
        return false;       //线性表为空或s、t不合法返回
    for(i=0; i<L.length ;i++){
        if(L.data[i] >=s && L.data[i]<=t)
            k++;
        else    
            L.data[i-k] = L.data[i];//让i位置的元素向前移动k个单位
    }
    L.length-=k;
    return true;
}

