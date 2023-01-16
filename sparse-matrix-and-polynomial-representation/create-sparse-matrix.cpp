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

int main(){
    sparse s;
    s.create();
    s.Display();
}