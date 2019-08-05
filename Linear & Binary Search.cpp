#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;
void linSearch(int *arr,int n,int el){
	bool found = false;
	for(int i=0;i<n;i++){
		if(arr[i]==el){
			found = true;
			cout<<"Found "<<el<<" at index "<<i<<endl;
			break;
		}
	}
	if(!found){
		cout<<el<<" not found in array."<<endl;
	}
}
bool binSearch(int *arr,int low,int high,int el){
	if(low<=high){
		int mid = (high+low)/2;
		if(arr[mid]==el){
			cout<<"Found "<<el<<" at index "<<mid<<endl;
			return true;
		}
		else if(arr[mid]>el){
			return binSearch(arr,low,mid-1,el);
		}
		return binSearch(arr,mid+1,high,el);
	}
	return false;
}
int main(){
	int n;
	cout<<"Enter number of elements : ";
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i] = i+1;
	}
	int el;
	cout<<"Enter element to search : ";
	cin>>el;
	cout<<"Searching Linearly\n";
	clock_t curTime = clock();
	linSearch(arr,n,el);
	cout<<"AFTER "<<(double)clock()-curTime/CLOCKS_PER_SEC<<" microSeconds"<<endl;
	cout<<"Binary Search called.\n";
	sort(arr,arr+n);
	curTime = clock();
	if(!binSearch(arr,0,n-1,el)){
		cout<<el<<" not found in array.";
	}
	cout<<"AFTER "<<(double)clock()-curTime/CLOCKS_PER_SEC<<" microSeconds"<<endl;
	return 0;
}
