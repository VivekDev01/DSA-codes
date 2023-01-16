#include<bits/stdc++.h>
using namespace std;

class Element{
    public: 
    int i;
    int j;
    int x;
};

class sparse{
    private:
    int m;
    int n;
    int num;
    Element * e;
    public:
    void create();
    void Display();
    // sparse * add(sparse t);
    sparse operator+(sparse t);
};

void sparse::create(){
    int i;
    cout<<"Enter dimensions m x n: "<<endl;
    cin>>m>>n;
    cout<<"Enter the number of non zero elements: "<<endl;
    cin>>num;
    e=new Element[num];
    cout<<"Enter the [rowno. colno. elementvalue]: ";
    for(i=0;i<num;i++){
        cin>>e[i].i>>e[i].j>>e[i].x;
    }
}

void sparse::Display(){
    int i,j,k=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(i==e[k].i && j==e[k].j){
                cout<<e[k++].x<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

}

// sparse * sparse::add(sparse t){
    sparse sparse::operator+(sparse t){
    int i=0,j=0,k=0;
    sparse *sum, sunya;
    if(m!=t.m || n!=t.n){
        sunya.m=0;
        sunya.n=0;
        sunya.num=0;
        return sunya;
    }    
    sum = new sparse; //Important line , dont forget it
    sum->m=this->m;
    sum->n=n;
    sum->e= new Element[this->num + t.num];

    while(i<this->num || j<t.num){
        if(e[i].i > t.e[j].i){
            sum->e[k++]=t.e[j++];
        }
        else if(e[i].i < t.e[j].i){
            sum->e[k++]=e[i++];
        }
        else if(e[i].j > t.e[j].j){
            sum->e[k++]=t.e[j++];
        }
        else if(e[i].j < t.e[j].j){
            sum->e[k++]=e[i++];
        }
        else{
            sum->e[k]=e[i++];
            sum->e[k++].x+=t.e[j++].x;
        }
    }
  
    return *sum;
}

int main(){
    sparse s1, s2;
    // sparse *s3;
    sparse s3;
    s1.create();
    s1.Display();
    s2.create();
    s2.Display();
    // s3=s1.add(s2);
    s3= s1 + s2;
    cout<<endl<<endl;
    s3.Display();
}