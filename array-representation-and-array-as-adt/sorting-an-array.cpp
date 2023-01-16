#include<iostream>
using namespace std;

//check if array is sorted
bool isSorted(int A[], int length){
    for(int i=0;i<length-1;i++){
        if(A[i+1]<A[i]){
            return false;
        }
    }
    return true;
}

void insertInSortedArray(int A[], int length, int x){
    int i=length-1;
    while(A[i]>x){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;

    for(int j=0;j<length+1;j++){
        cout<< A[j]<<" ";
    }
}

void negativeNumberOnLeft(int A[], int length){
    int i=0, j=length-1;
    while(i<j){
        while(A[i]<0){
            i++;
        }
        while(A[j]>=0){
            j--;
        }

        if(i<j){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        i++;
        j--;   
    }

    for(int j=0;j<length;j++){
        cout<< A[j]<<" ";
    }
}

int main(){
    int A[10]={2,-8,10,12,-15};
    // cout<<isSorted(A,5);
    // insertInSortedArray(A,5,11);
    negativeNumberOnLeft(A,5);
}
