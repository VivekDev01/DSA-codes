#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;
};

class CircularLL{
        node * head;
    public:
        void create(int A[], int n);
        void display();
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

int main(){
    int A[]={2,6,9,15,20,17,7};
    CircularLL l;
    l.create(A,7);
    l.display();
}