/**
 * 利用两个栈S1，S2来模拟一个队列，已知栈的4个运算定于如下：
 * Push(S,x);//元素x入栈S
 * Pop(S,x);//S出栈并将出栈的值赋给x
 * StackEmpty(S);//判断栈是否为空
 * StackOverflow(S);//判断栈是否满
 * 如何利用栈的运算来实现该队列的3个运算:
 * Enqueue;//将元素x入队
 * Dequeue;//出队,并将出队元素存储在x中
 * QueueEmpty;//判断队列是否为空
 * 
 * 算法思想:1.对S2的出栈操作用作出队,若S2为空,则先将S1中的所有元素送入S2.
 *          2.对S1的入栈操作用作入队,若S1满,必须保证S2栈为空,才能将S1的元素压入S2中
 * 
 * */

int Enqueue(Stack &S1,Stack &S2,int e){
    if(!StackOverflow(S1)){//当S1不满时,压入数据
        Push(S1,e);
        return 1;
    }
    if(StackOverflow(S1) && !StackEmpty(S2)){//当S1栈满且S2不为空时,队列已满
        cout<<"队列已满"<<endl;
        return 0;
    }
    if(StackOverflow(S1) && StackEmpty(S2)){//当S1栈满,S2栈空时,将S1的元素全部出栈,压入S2中,再将e压入S1中
        whiel(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    }
    Push(S1,e);
    return 1;
}

int Dequeue(Stack S1,Stack S2,int x){
    if(!StackEmpty(S2)){//S2不为空,则出栈
        Pop(S2,x);
        return 1;
    }
    else if(StackEmpty(S1)){//S2为空,S1也为空时,队列为空
        cout<<"队列为空!"<<enld;
        return 0;
    }
    else {//当S1不为空,S2为空时,将S1内的元素出栈,压入S2中
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    Pop(S2,x);
    }
}

int QueueEmpty(Stack S1,Stack S2){
    if(StackEmpty(S1) && StackEmpty(S2)){//当S1和S2都栈空时,队列为空
        return 1;
    }
    else 
        return 0;

}




