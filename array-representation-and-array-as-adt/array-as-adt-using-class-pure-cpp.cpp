#include<iostream>
using namespace std;

template <class T>
class array{
    private:
        int size;
        T *A;
    public:
        int length;
        array(){
            size=10;
            length=0;
            A=new T[10];
        }
        array(int sz){
            size=sz;
            length=0;
            A=new T[10];
        }
        ~array(){
            delete []A;
        }
        void Display();
        void Append(T x);
        void Insert(int index, T x);
        void Delete(int index);
        T linearSearch(T key);
        T BinarySearch(int l, int h, T key);
        T get(int index);
        void set(int index, T x);
        T max();
        T min();
        T sum();
        double avg();
        void Reverse();
        void leftShift();
        void leftRotate();
        void rightRotate();
};

template <class T>
void array<T>::Display(){
    cout<<"Array is: ";
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template <class T>
void array<T>::Append(T x){
    if(length<size){
        A[length]=x;
        length++;
    }
}

template <class T>
void array<T>::Insert(int index, T x){
    if(index>0 && index<=length){
        if(length<size){
            for(int i=length;i>index;i--){
                A[i]=A[i-1];
            }
            A[index]=x;
            length++;
        }
    }
}

template <class T>
void array<T>:: Delete(int index){
    if(index>0 && index<length){
        int x=A[index];
        for(int i=index;i<length-1;i++){
            A[i]=A[i+1];
        }
        length--;
    }
}

//Normal linear search
template <class T>
T array<T>::linearSearch(T key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            return i;
        }
    }
    return -1;
}

//Improving Linear Search: 1. Transposition
// template <class T>
// T array<T>::linearSearch(T key){
//     for(int i=0;i<length;i++){
//         if(key==A[i]){
//             swap(A[i], A[i-1]);
//             return i;
//         }
//     }
//     return -1;
// }

//Improving Linear Search: 2. Move to front (move to head)
// template <class T>
// T array<T>::linearSearch(T key){
//     for(int i=0;i<length;i++){
//         if(key==A[i]){
//             swap(A[i], A[0]);
//             return i;
//         }
//     }
//     return -1;
// }

// template <class T>
// void array<T>::swap(T &a, T &b){
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
// }

//Binary Search using recursion
template <class T>
T array<T>::BinarySearch(int l, int h, T key){
    if(l<=h){
        int mid= (l+h)/2;
        if(A[mid]==key){
            return mid;
        }
        else if(key>A[mid]){
            return BinarySearch(mid+1, h, key);
        }
        else{
            return BinarySearch(l, mid-1, key);
        }
    }
    return -1;
}

//Binary Search using loop
// template <class T>
// T array<T>::BinarySearch(int l, int h, int key)
// {
//     while(l<=h){
//         int mid=(l+h)/2;
//         if(key==A[mid]){
//             return mid;
//         }
//         else if(key>A[mid]){
//             l=mid+1;
//         }
//         else{
//             h=mid-1;
//         }
//     }
//     return -1;
// }

template <class T>
T array<T>::get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    else{
        return -1;
    }
}
//O(1)

template <class T>
void array<T>::set(int index, T x)
{
    if(index>=0 && index<length){
        A[index]= x;
    }
}
//O(1)

template <class T>
T array<T>::max(){
    int max=A[0];
    for(int i=1;i<length;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}
//O(n)

template <class T>
T array<T>::min(){
    int min=A[0];
    for(int i=1;i<length;i++){
        if(A[i]<min){
            min=A[i];
        }
    }
    return min;
}
//O(n)

//sum using loop
template <class T>
T array<T>::sum(){
    int total=0;
    for(int i=0;i<length;i++){
        total=total+A[i];
    }
    return total;
}
//O(n)

//sum using recursion
// T array<T>::sum(int A[], int n){
//     if(n<0){
//         return 0;
//     }
//     else{
//         return sum(A,n-1)+A[n];
//     }
// }

template <class T>
double array<T>::avg(){
    return double(sum()/length);
}

//Reverse an array using an Auxilliary array
// void array::Reverse(){
//     int B[length];
//     for(int i=length-1, j=0;i>=0;i--,j++){
//         B[j]=A[i];
//     }
//     for(int i=0;i<length;i++){
//         A[i]=B[i];
//     }
// }
//O(n)

//using swapping
template <class T>
void array<T>::Reverse(){
    for(int i=length-1, j=0;i>j;i--,j++){
        int temp= A[i];
        A[i]=A[j];
        A[j]=temp;
    }
}

template <class T>
void array<T>::leftShift(){
    for(int i=0;i<length-1;i++){
        A[i]=A[i+1];
    }
    length--;
}

template <class T>
void array<T>::leftRotate(){
    int x=A[0];
    for(int i=0;i<length-1;i++){
        A[i]=A[i+1];
    }
    A[length-1]=x;
}

template <class T>
void array<T>::rightRotate(){
    int x=A[length-1];
    for(int i=length-1;i>0;i--){
        A[i]=A[i-1];
    }
    A[0]=x;
}


int main(){

    int sz,x;
    cout<<"enter the size of the array: "<<endl;
    cin>>sz;

    // array<float> arr(sz);
    array<int> arr(sz);

    while(1){
    cout<<endl<<endl<<"Menu"<<endl;
    cout<<"1. Apend"<<endl;
    cout<<"2. Insert"<<endl;
    cout<<"3. Delete "<<endl;
    cout<<"4. Linear Search "<<endl;
    cout<<"5. Binary Search "<<endl;
    cout<<"6. get "<<endl;
    cout<<"7. set "<<endl;
    cout<<"8. max "<<endl;
    cout<<"9. min "<<endl;
    cout<<"10. sum "<<endl;
    cout<<"11. avg "<<endl;
    cout<<"12. reverse "<<endl;
    cout<<"13. left shift "<<endl;
    cout<<"14. left rotate "<<endl;
    cout<<"15. right rotate "<<endl;
    cout<<"16. Display "<<endl<<endl;
    cout<<"Choose an operation: "<<endl;
    int n;
    cin>>n;
    switch(n){
        case 1: 
            cout<<"Enter a number: ";
            cin>>x;
            arr.Append(x);
            break;
        case 2:
             arr.Insert(3, 0);
             break;
        case 3:   
            arr.Delete(3);
            break;
        case 4:    
            cout<<arr.linearSearch(5)<<endl;
            break;
        case 5:
            cout<<arr.BinarySearch(0, arr.length-1,5);
            break;
        case 6:
            cout<<arr.get(10);
            break;
        case 7: 
            arr.set(2, 10);
            break;
        case 8:
            cout<<arr.max();
            break;
        case 9:
            cout<<arr.min();
            break;
        case 10:
            cout<<arr.sum();
            break;
        case 11:
            cout<<arr.avg();
            break;
        case 12:
            arr.Reverse();
            break;
        case 13:
            arr.leftShift();
            break;
        case 14:
            arr.leftRotate();
            break;
        case 15:
            arr.rightRotate();
            break;
        case 16:
            arr.Display();
            break;
    }
    }
}