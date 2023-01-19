#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    char * s;

    void create(int sz);
    void push(char x);
    char pop();
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

char Stack::pop(){
    char x= s[Top];
    Top--;
    return x;
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
        if(exp[i]=='(' ||  exp[i]=='{' || exp[i]=='['){
            st.push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(st.isEmpty()){
                return false;
            }
            else{
                char x= st.pop();
                if(exp[i]==')' && x!='('){
                    return false;
                }
                else if(exp[i]=='}' && x!='{'){
                    return false;
                }
                else if(exp[i]==']' && x!='['){
                    return false;
                }
            }
        }
    }
    return st.isEmpty()? true:false;
}

int main(){
    char exp[]= "[{(a+b)*(c-d)}/e]";    
    cout<<isBalance(exp);
    
}