#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int col;
    int val;
    node * next;
};

int main(){
    int m=5, n=6;
    node *A[m]={NULL};
    node *t,*last;
    for(int i=0;i<m;i++){
        int k;
        last=A[i];
        cout<<"row "<<i<<" has values: ";
        cin>>k;
        cout<<"Enter "<<k<<" col values pairs: ";
        for(int j=0;j<k;j++){
            t=new node;
            cin>>t->col;
            cin>>t->val;
            t->next=NULL;

            if(last==NULL){
                last=t;
                A[i]=t;
            }
            else{
                last->next=t;
                last=t;
            }
        }
        cout<<endl;
    }
    // array created

    // now display the sparse matrix using created array
    for(int i=0;i<m;i++){
        node *p=A[i];
        for(int j=0;j<n;j++){
            if(p && j==p->col){
                cout<<p->val<<" ";
                p=p->next;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}