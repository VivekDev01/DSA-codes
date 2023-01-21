#include<bits/stdc++.h>
using namespace std;

class Queue{
    int size;
    int front; //index pointer
    int rear;
    int * Q;
    public:
        void create(int sz);
        void display();
        void enqueue(int x);
        int dequeue();
};

void Queue::create(int sz){
    size=sz;
    front=-1;
    rear=-1;
    Q= new int[size];
}

void Queue::display(){
    if(front==rear){
        cout<<"Queue is empty";
    }
    else{
        int f=front+1;
        while(f!=rear+1){
            cout<<Q[f]<<" ";
            f++;
        }
    }
}

void Queue::enqueue(int x){
    if(rear==size-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        front++;
        x= Q[front];        
    }
    return x;
}

int main(){
    Queue q;
    q.create(7);
    q.enqueue(100);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
    cout<<endl<<q.dequeue()<<endl;
    q.display();
}