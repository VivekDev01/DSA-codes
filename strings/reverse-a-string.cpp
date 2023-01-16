#include<iostream>
using namespace std;

int main(){
    char A[]="PYTHON";

    //medhode 1: using another string
    char B[7];
    int i;
    for(i=0;A[i]!='\0';i++);
    i=i-1;
    int j;
    for(j=0;i>=0;i--,j++){
        B[j]=A[i];
    }
    B[j]='\0';
    // cout<<B;

    //methode 2: using that array or string only
    int m,n;
    char t;
    for(m=0;A[m]!='\0';m++);
    m=m-1;
    n=0;
    for(m,n;n<m;m--,n++){
        t=A[m];
        A[m]=A[n];
        A[n]=t;
    }
    cout<<A;

}