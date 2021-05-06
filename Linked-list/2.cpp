/**
 * 在带头节点的单链表L中,删除所有值为x的结点,
 * 并释放其空间,假设值为x的结点不唯一,试编写算法以实现上述操作
 * 
 * 思路: 定义p指针遍历链表;
 *      定义q指针指向遍历指针的前继结点,目的是释放值为x的结点
 * */

void Del_X_1(LinkList &L,ElemType x){
    LNode *p=L->next,*pre=L,*q;//定义遍历指针和前继指针和释放指针
    while(p != nullptr){
        if(p->data == x){
            q=p;//释放指针指向该结点
            p=p->next;
            pre->next=p;
            free(q);
        }
        else{
            pre = p;
            p=p->next;
        }
    }
}

void Del_X_2(LinkList &L,ElemType x){//使用尾插法删除值为x的结点
    LNode *p=L->next,*r=L,*q;
    L->next = nullptr;//将头结点设为空,只需要把不等于x的结点加入到新链表中
    while(p != nullptr){
        if(p->data != x){
            r->next = p;
            r=p;
            p=p->next;
        }
        else{
            q=p;
            p=p->next;
            free(q);
        }
    }
}
