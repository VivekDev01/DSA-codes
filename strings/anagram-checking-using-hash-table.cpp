#include<bits/stdc++.h>
using namespace std;

int main(){
    char A[]="decimal";
    char B[]="medical";
    int i, H[26]={0};
    for(i=0;A[i]!='\0';i++){
        H[A[i]-'a']+=1;
    }
    for(i=0;B[i]!='\0';i++){
        H[B[i]-'a']-=1;
        if(H[B[i]-'a']<0){
            cout<<"not anagram"<<endl;
            break;
        }
    }
    for(i=0;i<26;i++){
        if(H[i]!=0){
            break;
        }
    }   
    if(i>25){
        cout<<"anagram"<<endl;
    } 
    else{
        cout<<"not anagram"<<endl;
    }
}