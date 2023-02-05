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
        bool isEmpty();
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

bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    else
        return false;
}
//Queue completed

//breadth first search
void BFS(int A[][7],int n,int i){ //i is starting vertex
    int u;
    Queue q;
    q.create(10);
    int visited[n]={0};
    cout<<i<<" ";
    q.enqueue(i);
    visited[i]=1;
    while(!q.isEmpty()){
        u=q.dequeue();
        for(int v=0;v<n;v++){
            if(A[u][v]!=0 && visited[v]==0){
                cout<<v<<" ";
                q.enqueue(v);
                visited[v]=1;
            }
        }
    }
}

int main(){
    int A[7][7]={{0,1,1,1,0,0,0},
                {1,0,1,0,0,0,0},
                {1,1,0,1,1,0,0},
                {1,0,1,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
BFS(A,7,1);
}