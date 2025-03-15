#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    int d;
    int s=x;
    int sum =0;
    while(x>0){
        d =x%10;
        sum=sum*10+d;
        x=x/10;
        
    }
    if(s==sum){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    if(isPalindrome(-121)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
