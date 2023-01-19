#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    int * s;

    void create(int sz);
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
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

int Stack::pop(){
    int x=-1;
    if(Top==-1){
        cout<<"Stack Underflow";
    }
    else{
        x=s[Top];
        Top--;
    }
    return x;
}

int Stack::peek(int pos){
    int x=-1;
    if(Top+1-pos<0){
        return x;
    }
    else{
        x= s[Top+1-pos];
    }
    return x;
}

int Stack::stackTop(){
    if(Top==-1){
        return -1;
    }
    else{
        return s[Top];
    }
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

int main(){
    Stack st;
    st.create(5);
    st.push(3);    
    st.push(5);    
    st.push(7);    
    st.push(9);    
    st.push(11);    
    // cout<<st.stackTop();
    // cout<<st.peek(3);
    // cout<<st.isFull()<<endl;
    // cout<<st.isEmpty()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.stackTop();
    
}