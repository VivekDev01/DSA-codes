#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

int hashfn(int a){
    return a%10;
}

void InsertIntoHashtable(node **H, int A[], int n){
    int i, hash;
    node *t;
    for(i=0;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        
        hash=hashfn(A[i]);
        if(H[hash]==NULL){
            H[hash]=t;
        }else if(H[hash]->data > t->data){
            node *q= H[hash];
            H[hash]=t;
            t->next=q;
        }
        else{
            node *p=H[hash];
            while(p->next && p->next->data < t->data){
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
    }
}

node * search(node **H, int key){
    int hash= hashfn(key);
    if(H[hash]==NULL){
        return NULL;
    }
    else{
        node *p=H[hash];
        while(p && p->data < key ){
            p=p->next;
        }
        if(p->data==key){
            return p;
        }
        else{
            return NULL;
        }
    }
}

void displayHashTable(node **H){
    for(int i=0;i<10;i++){
        if(H[i]==NULL){
            cout<<"Null"<<endl;
        }
        else{
            node *p=H[i];
            while(p){
                cout<<p->data<<" -> ";
                p=p->next;
            }
            cout<<endl;
        }
    }
}

int main(){
    int A[]={10, 5, 255, 36, 47, 89, 100};
    node **H= new node*[10];
    for(int i=0;i<10;i++){
        H[i]=NULL;
    }
    InsertIntoHashtable(H, A, 7);
    displayHashTable(H);
    cout<<search(H, 36);
}