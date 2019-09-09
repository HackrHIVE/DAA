#include<bits/stdc++.h>
using namespace std;
struct Knapsack{
    int profit;
    int weight;
    float ratio;
};
bool compareByRatio(Knapsack a,Knapsack b){
    return a.ratio>b.ratio;
}
bool compareByProfit(Knapsack a,Knapsack b){
    return a.profit>b.profit;
}
bool compareByWeight(Knapsack a,Knapsack b){
    return a.weight<b.weight;
}
float calculateTotalProfit(int maxWeight,Knapsack *arr,int n){
    float totalProfit = 0.0f;
    int index = 0;
    int weightNow = maxWeight;
    while(weightNow>0){
        if(index==n)
        break;

        if(weightNow<arr[index].weight){
            float proportionate = weightNow/(float)arr[index].weight;
            totalProfit += (float)proportionate*arr[index].profit;
            weightNow = 0;
            index++;
            continue;
        }

        totalProfit += arr[index].profit;
        weightNow -= arr[index].weight;
        index++;
    }
    return totalProfit;
}
int main(){
    int n;
    cout<<"Enter number of Items available : ";
    cin>>n;
    /*
    3
    23 16
    15 10
    24 18 
    20
    */
    /*
    6
    45 50
    60 50
    35 20
    23 16
    15 10
    24 18 
    35
    */
    /*
    3
    21 19 
    25 18
    19 16
    20
    */
    Knapsack *arr = new Knapsack[n];
    Knapsack *obj = new Knapsack[n];
    for(int i=0;i<n;i++){
        cout<<"For Item #"<<i+1<<endl;
        cout<<"Profit : ";
        cin>>arr[i].profit;
        cout<<"Weight : ";
        cin>>arr[i].weight;
        arr[i].ratio = arr[i].profit/(float) arr[i].weight;
        obj[i] = arr[i];
    }
    int maxWeight;
    cout<<"Max weight allowed for Knapsack : ";
    cin>>maxWeight;
    //By Profit
    sort(arr,arr+n,compareByProfit);
    cout<<"After selecting items by Profit : "<<calculateTotalProfit(maxWeight,arr,n)<<endl;
    //By Weight
    sort(arr,arr+n,compareByWeight);
    cout<<"After selecting items by Weight : "<<calculateTotalProfit(maxWeight,arr,n)<<endl;
    //By ProfitByWeightRatio
    sort(arr,arr+n,compareByRatio);
    cout<<"After selecting items by Profit/weight Ratio : "<<calculateTotalProfit(maxWeight,arr,n)<<endl;
    //By Hit and Trial
    cout<<"After selecting items by Hit & Trial : "<<calculateTotalProfit(maxWeight,obj,n)<<endl;
}
