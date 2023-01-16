#include<iostream>
using namespace std;

int main(){
    char A[]="painter";
    char B[]="painting";
    int i;
    for(i=0;A[i]!='\0' && B[i]!='\0';i++)
    {
        if(A[i]!=B[i]){
            break;
        }
    }
    if(A[i]==B[i])cout<<"equal"<<endl;
    else if(A[i]<B[i]) cout<<"smaller"<<endl;
    else cout<<"greater"<<endl;
}