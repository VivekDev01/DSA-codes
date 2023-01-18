#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node * next;
};

class DLL{
    node *first;
    public:
        void create(int A[], int n);
        void display();
        void insert(int pos, int x);
        int Delete(int pos);
        void reverse();
};

void DLL::create(int A[], int n)
{
    node *t,*last;
    first= new node;
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->prev=last;
        t->next=NULL;
        t->data=A[i];
        last->next=t;
        last=t;
    }
}

void DLL::display(){
    node *p=first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void DLL::insert(int pos, int x){
    node *t,*p;
    t=new node;
    t->data=x;
    t->prev=NULL;
    t->next=NULL;
        if(pos==0){ 
            if(first==NULL){
                first=t;
            }
            else{
                t->next=first;
                first->prev=t;
                first=t;
            }
        }
        else{
            p=first;
            for(int i=0;i<pos-1;i++){
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            if(p->next){
                p->next->prev=t;
            }
            p->next=t;
        }
}

int DLL::Delete(int pos){
    int x;
    node *p=first;
    if(pos<1 || pos>5){
        return -1;
    }
    if(first==NULL){
        return -1;
    }
    if(pos==1){
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        x=p->data;
        delete p;
    }
    else{
        p=first;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        delete p;
    }
    return x;
}

void DLL::reverse(){
    node *p,*temp;
    p=first;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}

int main(){
    DLL l;
    int A[5]={2,5,9,15,49};
    l.create(A,5);
    l.display();
    cout<<endl;
    
    // l.insert(4,100);

    // cout<<l.Delete(1)<<endl;

    l.reverse();
    l.display();
}