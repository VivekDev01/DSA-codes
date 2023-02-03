#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void display(int A[], int n){ // n is no. of elelments
    int i;
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void BubbleSort(int A[], int n){ 
    int flag=0;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j], A[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

void InsertionSort(int A[], int n){ //n is no. of elements
    int x, j;
    for(int i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void SelectionSort(int A[], int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        j=k=i;
        while(j<n){
            j++;
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(A[i], A[k]);
    }
}


//Quick sort
int partition(int A[], int l, int h){
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j){
            swap(A[i], A[j]);
        }
    }while(i<j);
    swap(A[l],A[j]);
    return j;
}
void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

//Mergesort
void Merge(int A[], int l, int mid, int h){
    int i,j,k;
    i=l;
    j=mid+1;
    k=l;
    int B[h+1];
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++){
        B[k++]=A[i];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(i=l;i<=h;i++){
        A[i]=B[i];
    }
}
//iterative virsion
void mergeSort(int A[], int n){
    int p, l, h, mid,i;
    for(p=2;p<=n;p=p*2){
        for(i=0;p+i-1<n;i=i+p){
            l=i;
            h=p+i-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n){
        Merge(A,0,p/2-1,n-1);
    }
}
//recursive virsion
void RmergeSort(int A[], int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        RmergeSort(A, l, mid);
        RmergeSort(A, mid+1, h);
        Merge(A, l, mid , h);
    }
}

//count sort
void CountSort(int A[], int n){
    int max=INT_MIN, i,j;
    for(i=0;i<=n;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    int *c= new int[max+1];
    for(i=0;i<max+1;i++){
        c[i]=0;
    }
    for(i=0;i<n;i++){
        c[A[i]]++;
    }
    i=0, j=0;
    while(i<=max){
        if(c[i]>0){
            A[j++]=i;
            c[i]--;
        }
        else{
            i++;
        }
    }
}

//shell sort
void shellSort(int A[], int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int j=gap;j<n;j++){
            int temp=A[j];
            int i=j-gap;
            while(i>=0 && temp<A[i]){
                A[i+gap]=A[i];i=i-gap;
            }
            A[i+gap]=temp;
        }
    }
}

int main(){
    // int A[]={10,7,25,3,14,5, INT_MAX};
    int A[]={10,7,25,3,14,5,50,58};
    display(A,8);
    // BubbleSort(A,6);
    // InsertionSort(A,6);
    // SelectionSort(A,6);
    // QuickSort(A,0,6);
    // mergeSort(A,8);
    // RmergeSort(A,0,8);
    // CountSort(A,8);
    shellSort(A,8);
    display(A,8);
}