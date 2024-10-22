#include <stdio.h>
#include <stdlib.h>

// Test case 1
// 3	
// 5 2	
// -3 1	
// 1 0	
// 3	
// 2 3	
// 4 1	
// -7 0	
// 5x^2·+·-3x^1·+·1x^0⏎	
// 2x^3·+·4x^1·+·-7x^0⏎	
// 2x^3·+·5x^2·+·1x^1·+·-6x^0
struct node{
	int coef;
    int power;
    struct node *next;
}*head = NULL;

void insert(int co,int po){
    struct node *ptr,*tmp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coef=co;
    ptr->power=po;
    ptr->next=NULL;
    if(head==NULL || po > head->power){
    ptr->next=head;//check
    head=ptr;
    }
    else{
        tmp=head;
        while(tmp->next!=NULL && tmp->next->power >po){
            tmp=tmp->next;
        }
        ptr->next=tmp->next;
        tmp->next=ptr;
    }
}
void display(){
    struct node *tmp;
    tmp =head;
    if(tmp==NULL)
    return;
    else{
        while(tmp->next!=NULL){
            printf("%dx^%d + ",tmp->coef,tmp->power);
            tmp=tmp->next;
        }
        printf("%dx^%d\n",tmp->coef,tmp->power);
    }
}
int main(){
    int n,k;
    int po,co;
    printf("Enter the no. of elem: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&co,&po);
        insert(co,po);
    }
    printf("Enter no. of ele in 2nd poly: ");
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&co,&po);
        insert(co,po);
    }
    display();
}