#include<iostream>
using namespace std;
int max,min;
int comparisons = 0;
int checkForDivided(int *arr,int low,int high){
     ::comparisons++;
    return (arr[low]>arr[high])?arr[high]:arr[low];
}
void divideThisArray(int *arr,int low,int high){
//    cout<<"Low : "<<low<<"\tHigh : "<<high<<endl;
    int mid = (high-low)/2 + low;
//    cout<<"Mid : "<<mid<<endl;
    if(high==low){
        if(::max<arr[high])::max = arr[high];
        if(::min>arr[high])::min = arr[high];
     	::comparisons+=2;
        return;
    }
    if(high==low+1){
//        cout<<"gotcha 2 elements\n";
        int Max;
        int Low = checkForDivided(arr,low,high);
        Low == arr[low] ? Max = arr[high] : Max = arr[low];
        if(::max<Max)::max = Max;
        if(::min>Low)::min = Low;
 	    ::comparisons++;
        return;
    }
    divideThisArray(arr,low,mid);
    divideThisArray(arr,mid+1,high);
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Element #"<<i+1<<" : ";
        cin>>arr[i];
    }
    ::max = arr[0];
    ::min = arr[0];
    divideThisArray(arr,1,n-1);
    cout<<"Max : "<<::max<<endl;
    cout<<"Min : "<<::min<<endl;
    cout<<"After "<<::comparisons<<" comparisons\n";
    return 0;
}
/*
8
12 -8 41 45 60 19 9 51
0  1  2  3  4  5  6  7
low                 high
mid = 3
*/
