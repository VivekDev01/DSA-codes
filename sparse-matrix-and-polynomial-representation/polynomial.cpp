#include<bits/stdc++.h>
using namespace std;

class term{
    public:
    int coeff;
    int exp;
};

class poly{
    int n; // no. of terms
    term *t;
    public:
    void create();
    int value(int x);
    poly * add(poly p);
    void display();
};

void poly::create(){
    cout<<"Enter no. of non zero elements: "<<endl;
    cin>>n;
    t=new term[n];
    cout<<"Enter polynomial terms[coeff exp]: "<<endl;
    for(int i=0; i<n; i++){
        cin>>t[i].coeff>>t[i].exp;
    }
}

int poly::value(int x){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+ t[i].coeff * pow(x, t[i].exp);
    }
    return sum;
}

poly * poly::add(poly p){
    poly *sum;
    sum=new poly;
    sum->t= new term[n+p.n];
    int i=0, j=0, k=0;
    while(i<n && j<p.n){
        if(t[i].exp > p.t[j].exp){
            sum->t[k++]=t[i++];
        }
        else if(t[i].exp < p.t[j].exp){
            sum->t[k++]=p.t[j++];
        }
        else{
            sum->t[k].exp=t[i].exp;
            sum->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
        }
    }
    for(;i<n;i++){
        sum->t[k++]=t[i];
    }
    for(;j<p.n;j++){
        sum->t[k++]=p.t[j];
    }
    sum->n=k;
    return sum;
}

void poly::display(){
    int i=0;
    for(i;i<n;i++){
        cout<<t[i].coeff<<"x^"<<t[i].exp;
        if(i<n-1){
            cout<<"+";
        }
    }
}


int main(){
    poly p1, p2,*p;
    p1.create();
    p1.display();
    cout<<endl;

    p2.create();
    p2.display();
    cout<<endl;

    cout<<p1.value(2)<<endl;
    cout<<p2.value(3)<<endl;

    p=p1.add(p2);
    p->display();
    cout<<p->value(1)<<endl;
}