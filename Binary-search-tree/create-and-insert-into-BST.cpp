#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *lchild;
    int data;
    node * rchild;
};

class tree{
    public:
    node * root;
    tree(){
        root=NULL;
    }
    void Insert(int key);
    node * RInsert(node *p, int key);
    void display(node *p); //  Inorder
    node * search(int key); //Iterative approach
    node * Rsearch(node *p, int key);
    node * Delete(node *p, int key);
    node * Inpre(node *p);
    node * Insuc(node *p);
    int Height(node *p);
};

//Iterative approach
void tree::Insert(int key){
    node *t, *q;

    t=new node;
    t->data=key;
    t->lchild=t->rchild=NULL;

    if(root==NULL){
        root=t;
    }
    node *p=root;

    while(p!=NULL){
        q=p;
        if(key == p->data){
            return;
        }
        else if(key < p->data){
            p=p->lchild;
        }
        else if(key > p->data){
            p=p->rchild;
        }
    }
    if(key < q->data){
        q->lchild=t;
    }else{
        q->rchild=t;
    } 
}


//Recursive approach
node * tree::RInsert(node * p, int key){
    node * t;
    if(p==NULL){
        t=new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else if(key < p->data){
        p->lchild= RInsert(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild= RInsert(p->rchild, key);
    }
    return p;
}

//Inorder display
void tree::display(node *p){
    if(p){
        display(p->lchild);
        cout<<p->data<<" ";
        display(p->rchild);
    }
}

node * tree::search(int key){
    node *p=root;
    while(p!=NULL){
        if(key==p->data)
            return p;
        if(key < p->data)
            p=p->lchild;
        else if(key > p->data)
            p=p->rchild;
    }
    return NULL;
}

node * tree::Rsearch(node *p, int key){
    if(p==NULL){
        return NULL;
    }
    else if(key == p->data){
        return p;
    }
    else if(key <p->data){
        return Rsearch(p->lchild, key);
    }
    else{
        return Rsearch(p->rchild, key);
    }
}

/*************************************************************************************/
//Delete a node from BST

node * tree::Delete(node *p, int key){
    node *q;
    if(p==NULL){
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root){
            return NULL;
        }
        delete p;
        return NULL;
    }
    if(key < p->data){
        p->lchild= Delete(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }
    else{
        if(Height(p->lchild) < Height(p->rchild)){
            q= Insuc(p->rchild);
            p->data = q->data;
            p->rchild= Delete(p->rchild, q->data); 
        }
        else{
            q= Inpre(p->lchild);
            p->data=q->data;
            p->lchild= Delete(p->lchild, q->data);
        }
    }
    return p;
}

int tree::Height(node *p){
    int x, y;
    if(p==NULL){
        return 0;
    }
    x= Height(p->lchild);
    y= Height(p->rchild);
    return x>y?x+1:y+1;
}

node * tree::Inpre(node *p){
    while(p && p->rchild!=NULL){
        p=p->rchild;
    }
    return p;
}

node * tree::Insuc(node *p){
    while(p && p->lchild!=NULL){
        p=p->lchild;
    }
    return p;
}

int main(){
    tree t;
    t.Insert(10);
    t.root= t.RInsert(t.root, 20);
    t.root= t.RInsert(t.root, 30);
    t.Insert(5);
    t.Insert(15);
    t.Insert(40);
    t.display(t.root);
    cout<<endl;
    cout<<t.search(20)<<endl;
    cout<<t.Rsearch(t.root, 20)<<endl;
    t.root= t.Delete(t.root, 10);
    t.display(t.root);
}

