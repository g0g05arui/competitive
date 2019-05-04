struct node{
    node *st,*dr;
    int val;
}*bst;

node * find(int val,node * nod){
    if(nod==NULL)
        return NULL;
    if(nod->val==val)
        return nod;
    if(val>nod->val)
        return find(val,nod->dr);
    return find(val,nod->st);
}
node* newNode(int data)
{
    node* temp = new node;

    temp->val = data;

    temp->st = NULL;
    temp->dr = NULL;

    return temp;
}
node* insert(node* root, int val)
{
    node* newnode = newNode(val);
    node* x = root;
    node* y = NULL;
    while (x != NULL) {
        y = x;
        if (val < x->val)
            x = x->st;
        else
            x = x->dr;
    }

    if (y == NULL)
        y = newnode;
    else if (val < y->val)
        y->st = newnode;
    else
        y->dr = newnode;
    return y;
}

node * minb(node *start){
    while(start->st!=NULL)
        start=start->st;
    return start;
}

node * erase(int val,node *&nod){
    if(nod==NULL)
        return nod;
    if(val<nod->val)
        nod->st=erase(val,nod->st);
    else
        if(val>nod->val)
            nod->dr=erase(val,nod->dr);
        else{
            if(nod->st==NULL){
                node * tmp=nod->dr;
                delete nod;
                return tmp;
            }
            if(nod->dr==NULL){
                node * tmp=nod->st;
                delete nod;
                return tmp;
            }
            node *tmp=minb(nod->dr);
            nod->val=tmp->val;
            nod->dr=erase(tmp->val,nod->dr);
        }
    return nod;
}
