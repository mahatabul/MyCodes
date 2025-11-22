#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int start,int mid, int end){
    
    int n1 = mid-start+1;
    int n2 = end-mid;

    int left[n1],right[n2];

    for(int i=0;i<n1;i++)left[i]=arr[start+i];

    for(int i=0;i<n2;i++)right[i]=arr[mid+1+i];

    int i=0,j=0,k=start;

    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        } else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }

    


}
void mergeSort(int arr[],int start,int end){
    if(start<end){
        int mid = (start + end)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);

    }
    


}
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
    mergeSort(arr,0,size-1);
    printarray(arr,size);
    return 0;
}