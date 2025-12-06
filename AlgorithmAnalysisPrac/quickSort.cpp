#include<iostream>
#include<vector>
using namespace std;

int partition(int low,int high, vector<int>&arr){

    int pi = arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<=pi){
        i++;
        swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(int low,int high, vector<int>&arr){
    if(low<high){
        int pivot = partition(low,high,arr);

        quicksort(low,pivot-1,arr);
        quicksort(pivot+1,high,arr);
    }
}
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it:arr) cin>>it;

    cout<<"\nBefore Sort:\n";
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<"\nAfter Sort:\n";
    quicksort(0,n-1,arr);
    for(auto it:arr){
        cout<<it<<" ";
    }

    return 0;
    
}