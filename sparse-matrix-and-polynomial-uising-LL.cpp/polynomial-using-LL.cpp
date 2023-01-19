#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int coeff;
    int exp;
    node * next;
};

double evaluate(node *p, int x){
    double sum=0.0;
    node *q=p;
    while(q!=NULL){
        sum+= q->coeff* pow(x, q->exp);
        q=q->next;
    }
    return sum;
}

int main(){
    int n;
    node *t, *p=NULL, *last;
    cout<<"Enter no. of terms: ";
    cin>>n;
    cout<<"Enter "<<n<<" coeff-exp pair: ";
    last=p;
    for(int i=0;i<n;i++){
        t=new node;
        cin>>t->coeff;
        cin>>t->exp;
        t->next=NULL;
        if(last==NULL){
            last=t;
            p=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
    //linked list created

    cout<<endl;
    cout<<evaluate(p, 1);
}
