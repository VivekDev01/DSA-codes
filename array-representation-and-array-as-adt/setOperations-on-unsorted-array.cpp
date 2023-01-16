#include<iostream>
using namespace std;

int * Union(int A[],int m, int B[], int n){
    int * C=new int[m+n];
    int i=0, j=0, k=0;
    for(i,k;i<m;i++,k++){
        C[k]=A[i];
    }
    for(j;j<n;j++){
        int l=0;
        for(l;l<=k;l++){
            if(B[j]==C[l]){
                break;
            }
        }
        if(l>k){
            C[k]=B[j];
            k++;
        }

    }
    return C;
}

void Intersection(int A[],int m, int B[], int n){
    int * c=new int[5];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i]==B[j]){
                c[k]=A[i];
                k++;
            }
        }
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
}

void setDifference(int A[],int m, int B[], int n){
    int * c=new int[5];
    int k=0;
    for(int i=0;i<m;i++){
        int j=0;
        for(j;j<n;j++){
            if(A[i]==B[j]){
                break;
            }
        }
        if(j>=n){
            c[k]=A[i];
            k++;
        }
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
}

int main(){
    int A[5]={10,5,4,7,8};
    int B[5]={6,9,5,12,4};

    // int *c= Union(A,5,B,5);
    // for(int i=0;i<10;i++){
    //     cout<<*(c+i)<<" ";
    // }

    // Intersection(A,5,B,5);

    setDifference(A,5,B,5);
}