
int dc(Linklist L,int n){
    int i;
    char s[n/2];
    LNode *p=L->next;

    for(i=0;i<n/2;i++){
        s[i]=p->data;
        p=p->next;
    }
    i--;
    if(n/2==1)
        p=p->next;
    
    while(p!=nullptr && p->data == s[i]){
        p=p->next
        i--;
    }

    if(i == -1)
        return 1;
    else 
        return 0;
}