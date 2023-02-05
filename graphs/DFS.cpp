#include<bits/stdc++.h>
using namespace std;

//depth first search
void DFS(int A[][7],int n,int u){ //i is starting vertex
    static int visited[7]={0}; //********
    if(visited[u]==0){
        cout<<u<<" ";
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(A[u][v]==1 && visited[v]==0){
                DFS(A,n,v);
            }
        }
    }
}

int main(){
    int A[7][7]={{0,1,1,1,0,0,0},
                {1,0,1,0,0,0,0},
                {1,1,0,1,1,0,0},
                {1,0,1,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
DFS(A,7,1);
}