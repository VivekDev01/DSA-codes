#include<bits/stdc++.h>
using namespace std;

int Hashfn(int key){
    return key%10;
}

// int modifiedHashfn(int key, int prob){
//     return (Hashfn(key) + Hashfn(prob)) % 10;
// }

void quadraticProbing(int HT[], int A[], int n){
    int i;
    for(i=0;i<n;i++){
        if(HT[Hashfn(A[i])]==-1){
            HT[Hashfn(A[i])]=A[i];
        }
        else{
            int j=Hashfn(A[i]);
            int c=0;
            while(HT[j]!=-1){
                j=Hashfn(A[i]);
                c++;
                j=(j+c*c)%10;
            }
            HT[j]=A[i];
        }
    }
}

void display(int HT[]){
    for(int i=0;i<10;i++){
        cout<<HT[i]<<endl;
    }
}

int search(int HT[], int key){
    for(int i=0;i<10;i++){
        if(HT[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int A[]={23,43,13,27};
    int HT[10];
    for(int i=0;i<10;i++){
        HT[i]=-1;
    }
    quadraticProbing(HT, A, 4);
    display(HT);
    cout<<search(HT, 43);
}