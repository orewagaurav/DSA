#include <stdio.h>
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j= 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i= 0;i<n;i++){
      
      printf("%d ",arr[i]);
    }
    printf("\n"); 

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i= 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    
}