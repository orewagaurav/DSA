#include <stdio.h>
void selection_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int small = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[small]){
                int tmp = arr[j];
                arr[j]=arr[small];
                arr[small]=tmp;
            }
        }
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
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        if(i<n-1)
        printf("%d ",arr[i]);
        else
        printf("%d",arr[i]);
    }
     printf("\n");
}