#include<bits/stdc++.h>
using namespace std;
struct Job{
    int deadline,profit,index;
};
bool sortByMaxProfit(Job a,Job b){
    return a.profit>b.profit;
}
int main(){
    int n;
    cout<<"Number of Jobs : ";
    cin>>n;
    Job *arr = new Job[n];
    int maxDead = 0;
    for(int i=0;i<n;i++){
        cout<<"Job "<<i+1<<" : Profit -> ";
        cin>>arr[i].profit;
        cout<<"Job "<<i+1<<" : Deadline -> ";
        cin>>arr[i].deadline;
        arr[i].index = i+1;
        if(maxDead<arr[i].deadline)
            maxDead = arr[i].deadline;
    }
    sort(arr,arr+n,sortByMaxProfit);
    int time = 1;
    int index = 0;
    int profit = 0;
    for(int i=0;i<n;i++)
        cout<<"J"<<arr[i].index<<"\t"<<arr[i].profit<<"\t"<<arr[i].deadline<<endl;
    cout<<"Job"<<"\t"<<"Profit"<<"\t"<<"Deadline"<<endl;
    while(time<=maxDead){
        if(arr[index].deadline>=time){
            cout<<"J"<<arr[index].index<<"\t"<<arr[index].profit<<"\t"<<arr[index].deadline<<endl;
            profit += arr[index].profit;
            time++;
        }
        index++;
    }
    cout<<"Max Profit : "<<profit;
    return 0;
}
/*
Job         J1  J2  J3  J4  J5
Deadline    2   1   3   2   1
Profit      60  100 20  40  20
*/