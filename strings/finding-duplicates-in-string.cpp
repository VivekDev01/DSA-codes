#include<bits/stdc++.h>
using namespace std;

//by comparing the elements of string
void duplicates1(char A[]){
    int i;
    for(i=0; A[i]!='\0';i++){
        int count=1;
        for(int j=i+1;A[j]!='\0';j++){
            if(A[i]!=-1){
                if(A[i]==A[j]){
                    count++;
                    A[j]=-1;
                }
            }
        }
        if(count>1){    
            cout<<A[i]<<" is appeared "<<count<<" times"<<endl;
        }
    }
}

//by using hash table
void duplicates2(char A[]){
    char H[26]={0};
    for(int i=0;A[i]!='\0';i++){
        H[A[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(H[i]>1){
            cout<< (char)(i+'a') << " appeared " << (int) H[i] << " times"<< endl; 
        }
    }
}

int main(){
    char A[]="paintingt";
    char B[]="vandanachailly";
    duplicates1(A);
    duplicates2(B);
}

