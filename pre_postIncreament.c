#include <stdio.h>
int main() {
    int a =5;
    int b = 5;
    int c = a++;//first use then increase
    int d = ++b;//first increase then use
    printf("%d\n",c);
    printf("%d\n",d);
    return 0;
}