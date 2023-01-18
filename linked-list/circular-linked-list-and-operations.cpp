#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;
};

class CircularLL{
    public:
        node * head;
        void create(int A[], int n);
        void display();
        void Rdisplay();
        void insert(int pos , int x);
        int Delete(int pos);
};

void CircularLL::create(int A[], int n){
    head = new node;
    head->data=A[0];
    head->next=NULL;
    node *t, *last;
    last=head;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=head;
}

void CircularLL::display(){
    node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }
    while(p!=head);
}

//******************************************************************************************
//Recursive function in a class without passing any argument, but by using static intiative
void CircularLL::Rdisplay(){
    static node *t=head;
    static int flag=0;
    if(t!=head || flag==0){
        flag=1;
        cout<<t->data<<" ";
        t=t->next;
        Rdisplay();
    }
    flag=0;
}

void CircularLL::insert(int pos , int x){
    node *t, *p;
    t=new node;
    t->data=x;
    if(pos==0){
        if(head==NULL){
            head=t;
            t->next=head;
        }
        else{
            p=head;
            t->next=head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            head=t;
        }
    }
    else{
        p=head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int CircularLL::Delete(int pos){
    node *p=head;
    int x=0;
    if(pos==1){
        if(head->next==p){
            x=head->data;
            delete head;
            head=NULL;
        }
        else{
            while(p->next!=head){
                p=p->next;
            }
            p->next=head->next;
            x=head->data;
            delete head;
            head=p->next;
        }
    }else{
        p=head;
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        node *q= p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main(){
    int A[]={2,6,9,15,20};
    CircularLL l;
    l.create(A,5);
    l.display();
    // l.Rdisplay();
    // l.insert(0, 100);
    cout<<endl;
    // l.display();
    // cout<<l.Delete(1)<<endl;
    l.display();
}