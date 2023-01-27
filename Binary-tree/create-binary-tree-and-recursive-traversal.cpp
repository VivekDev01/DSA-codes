#include<bits/stdc++.h>
using namespace std;

//Binary tree
class tnode{
    public:
    tnode * lchild;
    int data;
    tnode * rchild;
};

class tree{
    public:
    tnode * root;
    tree(){
        root=NULL;
    }
    void create();
    void preOrder(tnode *p);
    void inOrder(tnode *p);
    void postOrder(tnode *p);
    int height(tnode *p);
    int count(tnode *p);
};

//Queue
class qnode{
    public:
    tnode * data;
    qnode * next;
};

class Queue{
    qnode * front;
    qnode * rear;
    public:
        Queue(){
            front=NULL;
            rear=NULL;
        }
        void enqueue(tnode * x);
        tnode * dequeue();
        void display();
        bool isEmpty();
};

void Queue::enqueue(tnode * x){
    qnode *t= new qnode;
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

tnode * Queue::dequeue(){
    tnode * x=NULL;
    if(front==NULL){
        cout<<"Queue is empty";
    }
    else{
        qnode *p= front;
        front= front->next;
        x=p->data;
        delete p;
    }
    return x;
}

bool Queue::isEmpty(){
    if(front==NULL){
        return true;
    }
    else{
        return false;
    }
}

// void Queue::display(){
//     if(front==NULL){
//         cout<<"Queue is empty";
//     }
//     else{
//         qnode *p= front;
//         while(p!=NULL){
//             cout<<p->data<<" ";
//             p=p->next;
//         }
//     }
//     cout<<endl;
// }

// queue created
//Now create binary tree

void tree::create(){
    tnode *t=NULL, *p=NULL;
    int x;
    Queue q;
    cout<<"Enter root node: ";
    cin>>x;
    root = new tnode;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p=q.dequeue();
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t= new tnode;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t= new tnode;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        } 
    }
}

//inorder traversal
void tree::inOrder(tnode * p){
    if(p){
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}

void tree::preOrder(tnode *p){
    if(p){
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void tree::postOrder(tnode *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

int tree::count(tnode *p){
    int x,y;
    if(p!=NULL){
        x= count(p->lchild);
        y =count(p->rchild);
        return x+y+1;
    }
    return 0;
}

//this height function returns +1 height ie level no.
int tree::height(tnode *p){
    int x,y;
    if(p!=NULL){
        x= height(p->lchild);
        y= height(p->rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
}

int main(){
    tree t;
    t.create();
    // tnode * x= new tnode;
    // Queue q;
    // q.enqueue(x);
    // cout<<q.isEmpty()<<endl;
    // cout<<q.dequeue()<<endl;
    // q.display();
    t.inOrder(t.root);
    cout<<endl;
    t.preOrder(t.root);
    cout<<endl;
    t.postOrder(t.root);
    cout<<endl<<t.count(t.root)<<endl;
    cout<<t.height(t.root);
}