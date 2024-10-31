#include <stdio.h>
int main(){
    int arr[]={78,23,0,87,69};
    // int n =(sizeof(arr))/sizeof(arr[0]);
    for(int i=0;i<5;i++){
        int smallIdex = i;
        for(int j=i+1;j<5;j++){
            if(arr[j]<arr[smallIdex]){
                int tmp = arr[j];
                arr[j]=arr[smallIdex];
                arr[smallIdex]=tmp;
            }
        }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }


    }
}