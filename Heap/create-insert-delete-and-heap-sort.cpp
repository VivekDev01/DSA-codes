#include<bits/stdc++.h>
using namespace std;

void insertHeap(int A[], int n){
    int i=n;
    int temp=A[n];

    while(i>1 && temp > A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void CreateHeap(int A[], int size){
    int i;
    for(i=2;i<=size;i++){
        insertHeap(A, i);
    }
}

void DeleteHeap(int A[], int size){
    int x= A[1];
    A[1]=A[size];
    int i=1;
    int j=2*i;
    int temp;
    while(j<size-1){
        if(A[j+1] > A[j]){
            j=j+1;
        }
        if(A[i] < A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i=j;
            j=2*i;
        }
        else{
            break;
        }
    }
    A[size]=x;
}

void HeapSort(int A[], int size){
    CreateHeap(A, size);
    for(int i=0;i<size;i++){
        DeleteHeap(A, size-i);
    }
}

void DisplayHeap(int A[], int size){
    for(int i=1; i<=size; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[]={0, 10, 20, 30, 25, 5, 40, 35};
    // HeapSort(A, 7);

    // insertHeap(A, 2);
    // insertHeap(A, 3);
    // insertHeap(A, 4);
    // insertHeap(A, 5);

    // CreateHeap(A,7);
    // DeleteHeap(A,7);
    // DeleteHeap(A,6);

    HeapSort(A,7);
    DisplayHeap(A,7);
}