#include<stdio.h>

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={44,22,6,1,23};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    printarray(arr,size);

    printf("\n");

    for(int i=0;i<size-1;i++){
        int minIDX = i;

        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIDX]){
                minIDX=j;
            }
        }
        int temp = arr[minIDX];
        arr[minIDX]=arr[i];
        arr[i]=temp;
    }

    printarray(arr,size);

    return 0;


}

