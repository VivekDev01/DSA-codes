#include<iostream>
using namespace std;

int main(){
    char name[]={'V','I','V','E','K','\0'};
    cout<<"BEFORE- "<<name<<endl;
    int i;
    for(i=0;name[i]!='\0';i++){
        name[i]=name[i]+32;
    }
    cout<<"AFTER- "<<name<<endl;

    //toggling the case
    char A[]="wElCOmE";
    cout<<"BEFORE- "<<A<<endl;
    for(i=0;A[i]!='\0';i++){
        if(A[i]>=65 && A[i]<=90){
            A[i]+=32;
        }
        else if(A[i]>=97 && A[i]<=122){
            A[i]-=32;
        }
    }
    cout<<"AFTER- "<<A<<endl;
}