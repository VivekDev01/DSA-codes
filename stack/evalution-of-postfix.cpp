#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    int * s;

    void create(int sz);
    void push(int x);
    int stackTop();
    int pop();
    bool isEmpty();
    bool isFull();;
};

void Stack::create(int sz){
    size=sz;
    Top=-1;
    s=new int[sz];
}

void Stack::push(int x){
    if(Top==size-1){
        cout<<"Stack Overflow";
    }
    else{
        Top++;
        s[Top]=x;
    }
}

int Stack::stackTop(){
    if(Top==-1){
        return -1;
    }
    else{
        return s[Top];
    }
}

int Stack::pop(){
    char x=-1;
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

int evaluate(char *postfix){
    Stack st;
    st.create(strlen(postfix));
    int x1,x2,r;
    for(int i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            st.push(postfix[i]-'0');
        }
        else{
            x2=st.pop();
            x1=st.pop();
            switch(postfix[i]){
                case '+':
                    r=x1 + x2;
                    st.push(r);
                    break;
                case '-':
                    r=x1-x2;
                    st.push(r);
                    break;    
                case '*':
                    r=x1*x2;
                    st.push(r);
                    break;     
                case '/':
                    r=x1/x2;
                    st.push(r);
                    break; 
            }
        }
    }
    return st.pop();
}

int main(){
    char postfix[]= "35*62/+4-";   
    int x= evaluate(postfix);
    cout<<x;
}