#include<iostream>
using namespace std;
void print(int n,int e,int **edge,int *visited){
    cout<<e<<" ";
    visited[e] = 1;
    for(int i=0;i<n;i++){
        if(i==e)
            continue;
        if(edge[e][i]==1){
            if(visited[i] == 1)
                continue;
            print(n,i,edge,visited);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++)
            edge[i][j] = 0;
    }
    int v1,v2;
    for(int i=0;i<e;i++){
        cin>>v1>>v2;
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }
    int *visited = new int[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    print(n,0,edge,visited);
    return 0;

}
