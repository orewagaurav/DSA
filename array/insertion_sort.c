#include <stdio.h>
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j =i-1;
        while(key<arr[j]&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key; 
    }
}
int main(){
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elementsL: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        if(i<n-1)
        printf("%d ",arr[i]);
        else
        printf("%d",arr[i]);
    }
     printf("\n");
}