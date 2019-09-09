#include<iostream>
#include<time.h>
#include<queue>
using namespace std;
void printBFS(int n,int e,int **edge){
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
void printDFS(int n,int e,int **edge,int *visited){
    cout<<e<<" ";
    visited[e] = 1;
    for(int i=0;i<n;i++){
        if(i==e)
            continue;
        if(edge[e][i]==1){
            if(visited[i] == 1)
                continue;
            printDFS(n,i,edge,visited);
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
    cout<<"BFS Traversal Started : "<<endl;
    clock_t curTime = clock();
    printBFS(n,0,edge);
    cout<<"Done after "<<((double)clock()-curTime)/CLOCKS_PER_SEC<<" seconds\n";
    cout<<"DFS Traversal Started : "<<endl;
    curTime = clock();
    printDFS(n,0,edge,visited);
    cout<<"Done after "<<((double)clock()-curTime)/CLOCKS_PER_SEC<<" seconds\n";
    return 0;
}