#include<bits/stdc++.h>
using namespace std;

class matrix{
    private:
        int n;
        int *A;
    public:
    matrix(){
        n=2;
        A= new int[n*(n+1)/2];
    }
    matrix(int n){
        this->n=n;
        A= new int[n*(n+1)/2];
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
    if(i>=j && i<=n && j<=n){
        A[n*(j-1) - (j-2)*(j-1)/2 + i-j]=x;
    }
}

int matrix::get(int i, int j){
    if(i>=j){
       return A[n*(j-1) - (j-2)*(j-1)/2 + i-j];
    }
    else{
        return 0;
    }
}

void matrix::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
                cout<<A[n*(j-1) - (j-2)*(j-1)/2 + i-j]<<"     ";
            }
            else{
                cout<<0<<"      ";
            }
        }
        cout<<endl;
    }
}


int main(){
    matrix m(3);
    m.setElement(1,1,10);
    m.setElement(2,1,15);
    m.setElement(3,1,20);
    m.setElement(2,2,30);
    m.setElement(3,2,40);
    m.setElement(3,3,50);
    m.setElement(5,5,60);
    m.setElement(6,6,70);
    m.setElement(7,7,80);

    cout<<m.get(1,1)<<endl;
    cout<<m.get(1,2)<<endl;
    cout<<m.get(2,2)<<endl;
    cout<<m.get(3,3)<<endl;
    cout<<m.get(4,4)<<endl;

    cout<<endl<<endl;

    m.Display();
}