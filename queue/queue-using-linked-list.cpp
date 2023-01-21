#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;
};

class Queue{
    node * front;
    node * rear;
    public:
        Queue(){
            front=NULL;
            rear=NULL;
        }
        void enqueue(int x);
        int dequeue();
        void display();
};

void Queue::enqueue(int x){
    node *t= new node;
    if(t==NULL){
        cout<<"Queue is full";
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==NULL){
        cout<<"Queue is empty";
    }
    else{
        node *p= front;
        front= front->next;
        x=p->data;
        delete p;
    }
    return x;
}

void Queue::display(){
    if(front==NULL){
        cout<<"Queue is empty";
    }
    else{
        node *p= front;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
    cout<<endl;
}

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout<<q.dequeue()<<endl;
    q.enqueue(50);
    q.display();
}