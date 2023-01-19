#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;
};

class Stack{
    node * top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    bool isEmpty();
    bool isFull();
};

void Stack::push(int x){
    node * t=new node;
    if(t==NULL){
        cout<<"Stack Overflow";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    if(top==NULL){
        cout<<"Stack Underflow";
        return -1;
    }
    else{
        node * p=top;
        top=top->next;
        int x= p->data;
        delete p;
        return x;
    }
}

int Stack::peek(int pos){
    int x=-1;
    node *p=top;
    for(int i=0;p && i<pos-1;i++){
        p=p->next;
    }
    if(p){
        x=p->data;
    }
    else{
        x=-1;
    }
    return x;
}

int Stack::stackTop(){
    if(top==NULL){
        return -1;
    }
    else{
        return top->data;
    }
}

bool Stack::isEmpty(){
    return top? false:true;
}

bool Stack::isFull(){
    node *t= new node;
    bool r= t?true:false;
    delete t;
    return r;
}

int main(){
    Stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    // cout<<s.stackTop()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.isFull()<<endl;
    // cout<<s.peek(3)<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
}