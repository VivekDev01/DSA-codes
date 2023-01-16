#include<iostream>
using namespace std;

int main(){
    char name[]={'v','i','v','e','k','\0'};
    // cout<<name;
    int i;
    for(i=0;name[i]!='\0';i++);
    cout<<"length of string= "<<i;

}