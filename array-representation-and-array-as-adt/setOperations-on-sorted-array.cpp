//same as merging ie using 3 variables i,j,k
#include<iostream>
using namespace std;

void Union(int A[], int m, int B[], int n){
    int *c=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<B[j]){
            c[k++]=A[i++];
        }
        else if(A[i]>B[j]){
            c[k++]=B[j++];
        }
        else{
            c[k++]=A[i++];
            j++;
        }
    }
    for(;i<m;i++){
        c[k++]=A[i];
    }
    for(;j<n;j++){
        c[k++]=B[j];
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
}

void Intersection(int A[], int m, int B[], int n){
    int *c=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<B[j]){
            i++;
        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            c[k++]=A[i++];
            j++;
        }
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
}

void setDifference(int A[], int m, int B[], int n){
    int *c=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]>B[j]){
            j++;
        }
        else if(A[i]<B[j]){
            c[k++]=A[i++];
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<m;i++){
        c[k++]=A[i];
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
}

int main(){
    int A[5]={3,4,5,6,10};
    int B[5]={2,4,5,7,12};
    // Union(A,5,B,5);
    // Intersection(A,5,B,5);
    setDifference(A,5,B,5);
}