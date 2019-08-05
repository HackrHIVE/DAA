#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int max=0;
    int min=INT_MAX;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max<arr[i])
            max = arr[i];
        if(min<arr[i])
        	min = arr[i];
    }   
    int bucket[max+1] = {0};
    for(int i=0;i<n;i++){
        bucket[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        if(bucket[i]!=0){
            while(bucket[i]!=0){
                cout<<i<<" ";
                bucket[i]--;
            }
        }
    }
    return 0;
}
