#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    char * s;

    void create(int sz);
    void push(char x);
    void pop();
    bool isEmpty();
    bool isFull();;
};

void Stack::create(int sz){
    size=sz;
    Top=-1;
    s=new char[sz];
}

void Stack::push(char x){
    if(Top==size-1){
        cout<<"Stack Overflow";
    }
    else{
        Top++;
        s[Top]=x;
    }
}

void Stack::pop(){
    Top--;
}


bool Stack::isEmpty(){
    if(Top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isFull(){
    if(Top==size-1) 
        return true;
    else
        return false;
}

bool isBalance(char exp[]){
    Stack st;
    st.create(strlen(exp));
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            st.push(exp[i]);
        }
        else if(exp[i]==')'){
            if(st.isEmpty()){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    return st.isEmpty()? true:false;
}

int main(){
    char exp[]= "((a+b)*(c-d))";    
    cout<<isBalance(exp);
    
}