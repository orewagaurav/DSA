#include <stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d",&k);
    i = 0,j=n-1;
    int flag=0,index,position;
    while(i<=j){
        int mid= (i+j)/2;
        if(arr[mid]==k){
            flag=1;
            position=mid+1;
            index=mid;
            break;
        }
        else if(arr[mid]<k){
            i = mid+1;
        }
        else if(arr[mid]>k){
            j= mid-1;
        }
    }
    if(flag==1){
        printf("Number found at position %d and at index %d\n",position,index);
    }
    else{
        printf("Not found the given number!\n");
    }
}