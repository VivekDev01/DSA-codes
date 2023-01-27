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
    void preOrder();
    void inOrder();
    void postOrder();
    void levelOrder();
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

//Stack 
class Stack{
    public:
    int size;
    int Top;
    tnode * *s;

    void create(int sz);
    void push(tnode * x);
    tnode * pop();
    bool isEmpty();
};

void Stack::create(int sz){
    size=sz;
    Top=-1;
    s=new tnode * [sz];
}

void Stack::push(tnode * x){
    if(Top==size-1){
        cout<<"Stack Overflow";
    }
    else{
        Top++;
        s[Top]=x;
    }
}

tnode * Stack::pop(){
    tnode *x=NULL;
    if(Top==-1){
        cout<<"Stack Underflow";
    }
    else{
        x=s[Top];
        Top--;
    }
    return x;
}

bool Stack::isEmpty(){
    if(Top==-1){
        return true;
    }
    else{
        return false;
    }
}
//stack completed

//NOW Iterative traversal
void tree::inOrder(){
    tnode *t=root;
    Stack st;
    st.create(10);
    while(t!=NULL || !st.isEmpty()){
        if(t!=NULL){
            st.push(t);
            t=t->lchild;
        }
        else{
            t=st.pop();
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
}

void tree::preOrder(){
    tnode *t=root;
    Stack st;
    st.create(10);
    while(t!=NULL || !st.isEmpty()){
        if(t!=NULL){
            cout<<t->data<<" ";
            st.push(t);
            t=t->lchild;
        }
        else{
            t=st.pop();
            t=t->rchild;
        }
    }
}

/* post order became a little dificult because, I want to store -ve addres into the tnode type of stack,
but i am unable */

// void tree::postOrder(){
//     tnode *t=root;
//     Stack st;
//     tnode *temp;
//     st.create(10);
//     while(t!=NULL || !st.isEmpty()){
//         if(t!=NULL){
//             st.push(t);
//             t=t->lchild;
//         }
//         else{
//             temp=st.pop();
//             if(temp>0){
//                 st.push(-temp);
//                 t= temp->rchild;
//             }
//             else{
//                 cout<<t->data<<" ";
//                 t=NULL;
//             }
//         }
//     }
// }

void tree::levelOrder(){
    tnode *p= root;
    Queue q;
    cout<<p->data<<" ";
    q.enqueue(p);
    while(!q.isEmpty()){
        p=q.dequeue();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.enqueue(p->rchild);
        }
    }
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
    t.inOrder();
    cout<<endl;
    t.preOrder();
    cout<<endl;
    // t.postOrder();
    t.levelOrder();
}