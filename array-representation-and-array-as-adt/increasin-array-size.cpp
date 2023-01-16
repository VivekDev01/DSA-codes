#include<iostream>
using namespace std;

int main(){
    int *p=new int[5];
    p[0]=11;
    p[1]=12;
    p[2]=23;
    p[3]=54;
    p[4]=68;
//   for(int i=0; i<10;i++){
//         cout<<p[i]<<" ";
//     }
    
    int *q=new int[10];
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    q[5]=100;
    
    delete []p;
    p=q;
    q=NULL;
   
    for(int i=0; i<10;i++){
        cout<<p[i]<<" ";
    }
}