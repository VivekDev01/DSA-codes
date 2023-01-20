#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    char * s;

    void create(int sz);
    void push(char x);
    char stackTop();
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

char Stack::stackTop(){
    if(Top==-1){
        return -1;
    }
    else{
        return s[Top];
    }
}

char Stack::pop(){
    char x='\0';
    if(Top==-1){
        cout<<"stack underflow";
    }
    x=s[Top];
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

 bool isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')'){
        return false;
    }
    else{
        return true;
    }
 }

 int InStackPrece(char x){
    if(x=='+' || x=='-'){
        return 2;
    }
    else if(x=='*' || x=='/'){
        return 4;
    }
    else if(x=='^'){
        return 5;
    }
    else if(x=='('){
        return 0;
    }
    else{
        return 0;
    }
 }

  int OutStackPrece(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 3;
    }
    else if(x=='^'){
        return 6;
    }
    else if(x=='('){
        return 7;
    }
    else{
        return 0;
    }
 }

char * converter(char * infix){
    Stack st;
    st.create(strlen(infix));
    char * postfix= new char[strlen(infix)+1]; // one extra for NULL character
    int i=0, j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(infix[i]==')' && st.stackTop()=='('){
                    st.pop();
                    i++;
                }
            else{
                if(OutStackPrece(infix[i]) > InStackPrece(st.stackTop())){
                    st.push(infix[i++]);
                }
                else{
                    postfix[j++]=st.pop();
                }
            }   
        }
    }
    while(!(st.isEmpty())){
        postfix[j++]=st.pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char exp[]= "((a+b)*c)-d^e^f";   
    cout<<converter(exp); 
    
}