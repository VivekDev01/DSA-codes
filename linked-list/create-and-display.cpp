#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;

    void create(int A[], int n);
    void display();
    void recursiveDisplay(node * p);
    int count();
    int Rcount(node * p);
    int sum();
    int Rsum(node * p);
    int max();
    int Rmax(node * p);
    int min();
    int Rmin(node * p);
    node * search(int key);
    node * Rsearch(node * p, int key);
    node * move_to_head_search(int key);
    void Insert(int pos, int key);
    void InsertLast(int key);
    void InsertINTOsorted(int key);
    int Delete(int pos);
    bool isSorted();
    void removeDuplicates();
    void reverseElements();
    void reverseLinks();
    void Rreverse(node *p, node *q);
}*first=NULL;

// node * first=NULL;

void node::create(int A[], int n){
    node *t, *last;
    first= new node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    int i;
    for(i=1; i<n;i++){
        t= new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void node::display(){
    node * t;
    t=first;
    while(t!=NULL){
        cout<<t->data<<endl;
        t=t->next;
    }
}

void node::recursiveDisplay(node * p){
    if(p==NULL){
        return;
    }
    else{
        recursiveDisplay(p->next);
        cout<<p->data<<endl;
    }
}

int node::count(){
    node * p= first;
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int node::Rcount(node * p){
    if(p==NULL){
        return 0;
    }
    else {
        return Rcount(p->next)+1;
    }
}

int node::sum(){
    node *p=first;
    int sum=0;
    while(p){
        sum=sum + p->data;
        p=p->next;
    }
    return sum;
}

int node::Rsum(node * p){
    if(p==0){
        return 0;
    }
    else{
        return Rsum(p->next) + p->data;
    }
}

int node::max(){
    node *p= first;
    int m= INT_MIN;
    while(p){
        if(p->data > m){
            m= p->data;
        }
        p=p->next;
    }
    return m;
}

int node::Rmax(node * p){
    int x=0;
    if(p==NULL){
        return INT_MIN;
    }
    else{
        x=Rmax(p->next);
        return x > p->data ? x : p->data;
    }
}

int node::min(){
    int m=INT_MAX;
    node * p= first;
    while(p){
        if(p->data < m){
            m= p->data;
        }
        p= p->next;
    }
    return m;
}

int node::Rmin(node * p){
    int x=0;
    if(p==NULL){
        return INT_MAX;
    }
    x= Rmin(p->next);
    return x < p->data ? x : p->data ;
}

node * node::search(int key){
    node *p = first;
    while(p){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

node * node::Rsearch(node * p, int key){
    if(p==NULL){
        return NULL;
    }
    if(key == p->data){
        return p;
    }
    return Rsearch(p->next, key);
}

node * node::move_to_head_search(int key){
    node * p= first;
    node * q =NULL;
    while(p){
        if(key==p->data){
            q->next = p->next;
            p->next= first;
            first= p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void node::Insert(int pos , int key){
    node *t, *p;
    t= new node;
    t->data = key;
    if(pos==0){
        t->next= first;
        first = t;
    }
    else if(pos>0){
        p=first;
        for(int i=0; i<pos-1 && p; i++){
            p=p->next;
        }
        if(p){
            t->next= p->next;
            p->next=t;
        }  
    }
}

void node::InsertLast(int key){
    node *t, *last;
    last= search(17); // Imporatant because we haven't defined last earlier
    t=new node;
    t->data = key;
    t->next= NULL;
    if(first==NULL){
        first = last =t;
    }
    else{
        last->next=t;
        last=t;
    }
}

void node::InsertINTOsorted(int key){
    node *p=first;
    node *q = NULL;
    node * t= new node;
    t-> data=key;
    t->next=NULL;
    
    if(p==NULL){
        first = t;
    }
    else{ 
        // while((p->data < key) && p){ 
        /* above line is not able to provide right result. BUT WHY ???? 
        BECAUSE first of all you have to check primary condition such that p exists or not,
        if p is NULL then there is no meaning of checking p's data */
        while(p && (p->data < key)){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next= first;
            first = t;
        }
        else{
            t->next= q->next;
            q->next= t;
        }
    }
}

int node::Delete(int pos){
    node * p, *q;
    int x=0;
    p=first;
    q=NULL;
    if(pos<1 || pos>count()){
        return -1;
    }
    if(pos==1){
        first= first->next;
        x= p->data;
        delete p;
    }
    else{
        for(int i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x= p->data;
            delete p;
        } 
    }
    return x;
}

bool node::isSorted(){
    node *p=first;
    int x= INT_MIN;
    while(p!=NULL){
        if(p->data < x){
            return false;
        }
        x= p->data;
        p= p->next;
    }
    return true;
}

void node::removeDuplicates(){
    node *p= first;
    node *q= p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void node::reverseElements(){
    node * p=first;
    int A[5],i=0;
    while(p!=NULL){
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p!=NULL){
        p->data=A[i];
        p=p->next;
        i--;
    }
}

void node::reverseLinks(){
    node *p=first, *q=NULL, *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void node::Rreverse(node *q, node *p){
    if(p!=NULL){
        Rreverse(p, p->next);
        p->next=q;
    }
    else{
        first = q;
    }
}

int main(){
    int A[5]={3, 8, 10, 15, 19};
    first->create(A,5);
    first->display();
    cout<<endl<<endl;
    // first->recursiveDisplay(first)<<endl;

    // cout<<first->count()<<endl;
    // cout<<first->Rcount(first)<<endl;
    // cout<<first->sum()<<endl;
    // cout<<first->Rsum(first)<<endl;
    // cout<<first->max()<<endl;
    // cout<<first->Rmax(first)<<endl;
    // cout<<first->min()<<endl;
    // cout<<first->Rmin(first)<<endl;

    // cout<<first->search(15)<<endl;
    // cout<<first->Rsearch(first, 15)<<endl;
    // cout<<first->move_to_head_search(15)<<endl;
    // first->display();

    // first->Insert(4 , 22);
    // first->display();

    // first->InsertLast(100);

    // first->InsertINTOsorted(2);
    // first->InsertINTOsorted(8);
    // first->InsertINTOsorted(13);
    // first->InsertINTOsorted(16);
    // first->InsertINTOsorted(20);

    // cout<<first->Delete(9)<<endl<<endl;

    // cout<<first->isSorted()<<endl;

    // first->removeDuplicates();

    // first->reverseElements();
    // first->reverseLinks();
    // first->Rreverse(NULL, first);
    
    first->display(); 
}