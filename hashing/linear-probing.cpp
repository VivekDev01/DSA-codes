#include<bits/stdc++.h>
using namespace std;

int Hashfn(int key){
    return key%10;
}

// int modifiedHashfn(int key, int prob){
//     return (Hashfn(key) + Hashfn(prob)) % 10;
// }

void linearProbing(int HT[], int A[], int n){
    int i;
    for(i=0;i<n;i++){
        if(HT[Hashfn(A[i])]==-1){
            HT[Hashfn(A[i])]=A[i];
        }
        else{
            int j=Hashfn(A[i]);
            while(HT[j]!=-1){
                j=(j+1)%10;
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
    int A[]={12,15,3,41,25,63,8,52};
    int HT[10];
    for(int i=0;i<10;i++){
        HT[i]=-1;
    }
    linearProbing(HT, A, 8);
    display(HT);
    cout<<search(HT, 52);
}