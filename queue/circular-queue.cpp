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
    front=0;
    rear=0;
    Q= new int[size];
}

void Queue::display(){
    if(front==rear){
        cout<<"Queue is empty";
    }
    else{
        int f=(front+1) % size;
        while(f!=(rear+1)%size){
            cout<<Q[f]<<" ";
            f=(f+1)%size;
        }
    }
}

void Queue::enqueue(int x){
    if((rear+1)%size==front){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        front=(front+1)%size;
        x= Q[front];        
    }
    return x;
}

int main(){
    Queue q;
    q.create(5);

    q.enqueue(100);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display();

    cout<<endl<<q.dequeue()<<endl;
    q.enqueue(20);
    q.display();

    cout<<endl<<q.dequeue()<<endl;
    q.enqueue(222);
    q.display();
}