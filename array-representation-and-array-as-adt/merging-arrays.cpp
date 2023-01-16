#include<iostream>
using namespace std;

int * mergeArrays(int A[],int m, int B[], int n){
    int * C;
    C= new int[m+n];
    int i=0, j=0, k=0;
    while(i<m && j<n){
        if(A[i]<B[j]){
            C[k++]=A[i++];
        }
        else{
            C[k++]=B[j++];
        }
    }

    for(;i<m;i++){
        C[k++]=A[i];
    }

    for(;j<n;j++){
        C[k++]=B[j];
    }

    return C;
    // for(int l=0;l<m+n;l++){
    //     cout<<C[l]<<" ";
    // }
}

int main(){
    int A[5]={2,5,7,10,11};
    int B[5]={1,8,9,11,12};
    int *C;
    C=mergeArrays(A,5,B,5);
    for(int i=0;i<10;i++){
        cout<<*(C+i)<<" ";
    }
}