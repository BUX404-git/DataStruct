
LNode *Del_X(Linklist &L,int x){

    LNode  *p = L->next,*pre = L;

    while (p != NULL)
    {
        if (p != NULL && p->data == x)
        {
        LNode *r=nullptr;
        r=p;
        free(r);
        p = p->next;
        pre = p;
        }
        else 
            p = p -> next;

    }
    
   
    


}