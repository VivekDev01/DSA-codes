#include<iostream>
using namespace std;

struct array{
    int size;
    int *A;
    int length;
};

void Display(struct array arr){
    cout<<"Array is: ";
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void Append(struct array &arr,int x){
    if(arr.length<arr.size){
        arr.A[arr.length]=x;
        arr.length++;
    }
}

void Insert(struct array &arr, int index, int x){
    if(index>0 && index<=arr.length){
        if(arr.length<arr.size){
            for(int i=arr.length;i>index;i--){
                arr.A[i]=arr.A[i-1];
            }
            arr.A[index]=x;
            arr.length++;
        }
    }
}

void Delete(struct array &arr, int index){
    if(index>0 && index<arr.length){
        int x=arr.A[index];
        for(int i=index;i<arr.length-1;i++){
            arr.A[i]=arr.A[i+1];
        }
        arr.length--;
    }
}

//Normal linear search
int linearSearch(struct array arr, int key){
    for(int i=0;i<arr.length;i++){
        if(key==arr.A[i]){
            return i;
        }
    }
    return -1;
}

//Improving Linear Search: 1. Transposition
// int linearSearch(struct array arr, int key){
//     for(int i=0;i<arr.length;i++){
//         if(key==arr.A[i]){
//             swap(arr.A[i], arr.A[i-1]);
//             return i;
//         }
//     }
//     return -1;
// }

//Improving Linear Search: 2. Move to front (move to head)
// int linearSearch(struct array arr, int key){
//     for(int i=0;i<arr.length;i++){
//         if(key==arr.A[i]){
//             swap(arr.A[i], arr.A[0]);
//             return i;
//         }
//     }
//     return -1;
// }

// void swap(int &a, int &b){
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
// }

//Binary Search using recursion
int BinarySearch(struct array arr, int l, int h, int key){
    if(l<=h){
        int mid= (l+h)/2;
        if(arr.A[mid]==key){
            return mid;
        }
        else if(key>arr.A[mid]){
            return BinarySearch(arr, mid+1, h, key);
        }
        else{
            return BinarySearch(arr, l, mid-1, key);
        }
    }
    return -1;
}

//Binary Search using loop
// int BinarySearch(struct array arr, int l, int h, int key)
// {
//     while(l<=h){
//         int mid=(l+h)/2;
//         if(key==arr.A[mid]){
//             return mid;
//         }
//         else if(key>arr.A[mid]){
//             l=mid+1;
//         }
//         else{
//             h=mid-1;
//         }
//     }
//     return -1;
// }

int get(struct array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    else{
        return -1;
    }
}
//O(1)

void set(struct array arr, int index, int x)
{
    if(index>=0 && index<arr.length){
        arr.A[index]= x;
    }
}
//O(1)

int max(struct array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}
//O(n)

int min(struct array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}
//O(n)

//sum using loop
// int sum(struct array arr){
//     int total=0;
//     for(int i=0;i<arr.length;i++){
//         total=total+arr.A[i];
//     }
//     return total;
// }
//O(n)

//sum using recursion
int sum(int A[], int n){
    if(n<0){
        return 0;
    }
    else{
        return sum(A,n-1)+A[n];
    }
}

double avg(struct array arr){
    return double(sum(arr.A, arr.length-1))/(arr.length);
}

//Reverse an array using an Auxilliary array
// void Reverse(struct array &arr){
//     int B[arr.length];
//     for(int i=arr.length-1, j=0;i>=0;i--,j++){
//         B[j]=arr.A[i];
//     }
//     for(int i=0;i<arr.length;i++){
//         arr.A[i]=B[i];
//     }
// }
//O(n)

//using swapping
void Reverse(struct array &arr){
    for(int i=arr.length-1, j=0;i>j;i--,j++){
        int temp= arr.A[i];
        arr.A[i]=arr.A[j];
        arr.A[j]=temp;
    }
}

void leftShift(struct array &arr){
    for(int i=0;i<arr.length-1;i++){
        arr.A[i]=arr.A[i+1];
    }
    arr.length--;
}

void leftRotate(struct array &arr){
    int x=arr.A[0];
    for(int i=0;i<arr.length-1;i++){
        arr.A[i]=arr.A[i+1];
    }
    arr.A[arr.length-1]=x;
}

void rightRotate(struct array &arr){
    int x=arr.A[arr.length-1];
    for(int i=arr.length-1;i>0;i--){
        arr.A[i]=arr.A[i-1];
    }
    arr.A[0]=x;
}


int main(){
    struct array arr;

    int x;

    // int n;
    // cout<<"Enter the size of array: "<<endl;
    // cin>>arr.size;
    arr.size=10;
    arr.A=new int[arr.size];
    arr.length=0;

    // cout<<"Enter length of the array: ";
    // cin>>n;
    // cout<<"enter "<<n<<" elements of the array: ";
    // for(int i=0;i<n;i++){
    //     cin>>arr.A[i];
    // }
    // arr.length=n;

    arr.A[0]=1;
    arr.A[1]=2;
    arr.A[2]=10;
    arr.A[3]=8;
    arr.A[4]=5;
    arr.length=5;
    while(1){
    cout<<endl<<"Menu"<<endl;
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
            Append(arr, x);
            break;
        case 2:
             Insert(arr, 3, 0);
             break;
        case 3:   
            Delete(arr, 3);
            break;
        case 4:    
            cout<<linearSearch(arr, 5)<<endl;
            break;
        case 5:
            cout<<BinarySearch(arr, 0, arr.length-1,5);
            break;
        case 6:
            cout<<get(arr, 10);
            break;
        case 7: 
            set(arr, 2, 10);
            break;
        case 8:
            cout<<max(arr);
            break;
        case 9:
            cout<<min(arr);
            break;
        case 10:
            cout<<sum(arr.A, arr.length-1);
            break;
        case 11:
            cout<<avg(arr);
            break;
        case 12:
            Reverse(arr);
            break;
        case 13:
            leftShift(arr);
            break;
        case 14:
            leftRotate(arr);
            break;
        case 15:
            rightRotate(arr);
            break;
        case 16:
            Display(arr);
            break;
    }
    }

    
}