#include<bits/stdc++.h>
using namespace std;
struct vec{
	queue<int> st;
};
int main(){
    int n;
    cin>>n;
    int max=0;
    vec *arrVec = new vec[n];
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max<arr[i])
            max = arr[i];
    }   
    vec *bucket = new vec[max+1];
    for(int i=0;i<n;i++){
    	bucket[arr[i]].st.push(arr[i]);
    }
    for(int i=1;i<=max;i++){
        if(!bucket[i].st.empty()){
            while(!bucket[i].st.empty()){
                cout<<bucket[i].st.front()<<" ";
                bucket[i].st.pop();
            }
        }
    }
    return 0;
}
