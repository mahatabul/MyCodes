#include<iostream>
using namespace std;


void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={12,44,1,3,89,69,2};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    printarray(arr,size);

    cout<<"\n";

    for(int i=0;i<size-1;i++){
        for( int j=0;j<size-i-1;j++){

            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }

        }
    }
    printarray(arr,size);
    return 0;

 }