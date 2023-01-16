#include<bits/stdc++.h>
using namespace std;

class matrix{
    private:
        int n;
        int *A;
    public:
    matrix(){
        n=2;
        A= new int[2];
    }
    matrix(int n){
        this->n=n;
        A= new int[n];
    }
    void setElement(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~matrix(){
        delete []A;
    }
};

void matrix::setElement(int i, int j, int x)
{
    if(i==j && i<=n){
        A[i-1]=x;
    }
}

int matrix::get(int i, int j){
    if(i==j){
        return A[i-1];
    }
    else{
        return 0;
    }
}

void matrix::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<A[i]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}


int main(){
    matrix m(4);
    m.setElement(1,1,10);
    m.setElement(1,1,10);
    m.setElement(1,2,20);
    m.setElement(2,2,30);
    m.setElement(3,3,40);
    m.setElement(4,4,50);
    m.setElement(5,5,60);
    m.setElement(6,6,70);
    m.setElement(7,7,80);

    cout<<m.get(1,1)<<endl;
    cout<<m.get(1,2)<<endl;
    cout<<m.get(2,2)<<endl;
    cout<<m.get(3,3)<<endl;
    cout<<m.get(4,4)<<endl;
    cout<<m.get(5,5)<<endl;
    cout<<m.get(6,6)<<endl;
    cout<<m.get(7,7)<<endl;

    m.Display();
}