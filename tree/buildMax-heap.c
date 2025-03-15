#include <stdio.h>

void maxHeapify(int arr[],int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int largest;
    // if(left<=sizeof(arr)/sizeof(arr[0]))
    if(left<n && left>arr[i])
        largest =left;
    else{
        largest=i;
    }
    if(right<n && right>arr[largest])
        largest = right;
    if(largest!=i){
        int tmp;
        tmp =arr[i];
        arr[i]=arr[largest];
        arr[largest]=tmp;
        maxHeapify(arr,n,largest);
    }
}

void buildMaxHeap(int arr[],int n){
    for(int i =n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr, n);

    printf("Max Heap: ");
    printArray(arr, n);

    return 0;
}
