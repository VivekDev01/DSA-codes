#include<iostream>
using namespace std;

bool validate(char A[]){
    int i;
    for(i=0;A[i]!='\0';i++){
        if(!(A[i]>=65 && A[i]<=90) && !(A[i]>=97 && A[i]<=122) && !(A[i]>=48 && A[i]<=57)){
            return false;
        }
    }
    return true;
}

int main(){
    char A[]="vivek123";
    char B[]="vivek@123";
    if(validate(A)){
        cout<<"A is valid"<<endl;
    }
    else{
        cout<<"A is invalid"<<endl;
    }

     if(validate(B)){
        cout<<"B is valid"<<endl;
    }
    else{
        cout<<"B is invalid"<<endl;
    }

}