#include<bits/stdc++.h>
using namespace std;

class matrix{
    private:
        int n;
        int *A;
    public:
    matrix(){
        n=2;
        A= new int[n*n];
    }
    matrix(int n){
        this->n=n;
        A= new int[n*n];
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
        A[(i*(i-1))/2 + (j-1)]=x;
    }
}

int matrix::get(int i, int j){
    if(i>=j){
       return A[(i*(i-1))/2 + (j-1)];
    }
    else{
        return A[j*(j-1)/2 + (i-1)];
    }
}

void matrix::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
                cout<<A[(i*(i-1))/2 + (j-1)]<<"     ";
            }
            else{
                cout<<A[j*(j-1)/2 + (i-1)]<<"      ";
            }
        }
        cout<<endl;
    }
}


int main(){
    matrix m(3);
    m.setElement(1,1,10);
    m.setElement(2,1,15);
    m.setElement(3,1,100);
    m.setElement(2,2,30);
    m.setElement(3,2,1);
    m.setElement(3,3,50);

    cout<<m.get(3,1);

    cout<<endl<<endl;

    m.Display();
}