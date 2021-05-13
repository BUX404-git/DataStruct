/**
 * ��������ջS1��S2��ģ��һ�����У���֪ջ��4�����㶨�����£�
 * Push(S,x);//Ԫ��x��ջS
 * Pop(S,x);//S��ջ������ջ��ֵ����x
 * StackEmpty(S);//�ж�ջ�Ƿ�Ϊ��
 * StackOverflow(S);//�ж�ջ�Ƿ���
 * �������ջ��������ʵ�ָö��е�3������:
 * Enqueue;//��Ԫ��x���
 * Dequeue;//����,��������Ԫ�ش洢��x��
 * QueueEmpty;//�ж϶����Ƿ�Ϊ��
 * 
 * �㷨˼��:1.��S2�ĳ�ջ������������,��S2Ϊ��,���Ƚ�S1�е�����Ԫ������S2.
 *          2.��S1����ջ�����������,��S1��,���뱣֤S2ջΪ��,���ܽ�S1��Ԫ��ѹ��S2��
 * 
 * */

int Enqueue(Stack &S1,Stack &S2,int e){
    if(!StackOverflow(S1)){//��S1����ʱ,ѹ������
        Push(S1,e);
        return 1;
    }
    if(StackOverflow(S1) && !StackEmpty(S2)){//��S1ջ����S2��Ϊ��ʱ,��������
        cout<<"��������"<<endl;
        return 0;
    }
    if(StackOverflow(S1) && StackEmpty(S2)){//��S1ջ��,S2ջ��ʱ,��S1��Ԫ��ȫ����ջ,ѹ��S2��,�ٽ�eѹ��S1��
        whiel(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    }
    Push(S1,e);
    return 1;
}

int Dequeue(Stack S1,Stack S2,int x){
    if(!StackEmpty(S2)){//S2��Ϊ��,���ջ
        Pop(S2,x);
        return 1;
    }
    else if(StackEmpty(S1)){//S2Ϊ��,S1ҲΪ��ʱ,����Ϊ��
        cout<<"����Ϊ��!"<<enld;
        return 0;
    }
    else {//��S1��Ϊ��,S2Ϊ��ʱ,��S1�ڵ�Ԫ�س�ջ,ѹ��S2��
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    Pop(S2,x);
    }
}

int QueueEmpty(Stack S1,Stack S2){
    if(StackEmpty(S1) && StackEmpty(S2)){//��S1��S2��ջ��ʱ,����Ϊ��
        return 1;
    }
    else 
        return 0;

}




