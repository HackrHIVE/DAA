#include<iostream>
#include<queue>
using namespace std;
void print(int n,int e,int **edge){
    queue <int> pending;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    	visited[i] = false;
    
    pending.push(e);
    visited[e] = true;
    while(!pending.empty()){
    	int current = pending.front();
    	pending.pop();
    	cout<<current<<" ";
    	for(int i=0;i<n;i++){
    		if(edge[current][i]==1 && !visited[i]){
    			pending.push(i);
    			visited[i] = true;
			}
		}
	}
	delete []visited;
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
    print(n,0,edge);

    return 0;
}