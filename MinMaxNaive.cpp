#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Element #"<<i+1<<" : ";
        cin>>arr[i];
    }
    int comparisons = 0;
    int min = arr[0],max = arr[0];
    for(int i=1;i<n;i++){
        comparisons+=2;
        if(arr[i]>max)
            max = arr[i];
        if(min>arr[i])
            min = arr[i];
    }
    cout<<"Min : "<<min<<"\tMax : "<<max<<" after "<<comparisons<<" comparisons"<<endl;
    return 0;
}
