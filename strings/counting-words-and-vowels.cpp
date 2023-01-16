#include<iostream>
using namespace std;

int main(){
    char A[]="How are you";
    // cout<<name;
    int i, vcount=0, ccount=0, words=0;
    for(i=0;A[i]!='\0';i++){
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o'|| A[i]=='u' || A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U'){
            vcount++;
        }
        else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122)){
            ccount++;
        }

        if(A[i]==' ' && A[i-1]!=' '){
            words++;
        }
    }
    cout<<"no. of vowels= "<<vcount<<endl;
    cout<<"no. of consonents= "<<ccount<<endl;
    cout<<"no. of words= "<<words+1<<endl;

}