#include<stdio.h>

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={12,44,1,3,89,69,2};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    printarray(arr,size);

    printf("\n");

    for(int i=1;i<size;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printarray(arr,size);
    return 0;
}