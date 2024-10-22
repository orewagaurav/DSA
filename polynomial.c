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

struct node1{
	int coef;
    int power;
    struct node *next;
}*start = NULL;

void insert1(int co,int po){
    struct node *ptr,*tmp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coef=co;
    ptr->power=po;
    ptr->next=NULL;
    if(head==NULL || po > head->power){
    ptr->next=head;
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

void insert2(int co,int po){
    struct node1 *ptr,*tmp;
    ptr = (struct node1 *)malloc(sizeof(struct node1));
    ptr->coef=co;
    ptr->power=po;
    ptr->next=NULL;
    if(start==NULL || po > start->power){
    ptr->next=start;
    start=ptr;
    }
    else{
        tmp=start;
        while(tmp->next!=NULL && tmp->next->power >po){
            tmp=tmp->next;
        }
        ptr->next=tmp->next;
        tmp->next=ptr;
    }
}
void display1(){
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
void display2(){
    struct node1 *tmp;
    tmp =start;
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
void display3(){
    struct node1 *tmp1;
    struct node *tmp;
    tmp1 =start;
    tmp=head;
    if(tmp==NULL)
    return;
    else{
        while(tmp!=NULL){
            tmp->coef=tmp->coef+tmp1->coef;
            //tmp->power=tmp->power+tmp1->power;
            tmp=tmp->next;
            tmp1=tmp1->next;
        }
    }
}
void display4(){
    struct node *tmp;
    tmp=head;
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
        insert1(co,po);
    }
    printf("Enter no. of ele in 2nd poly: ");
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&co,&po);
        insert2(co,po);
    }
    display1();
    display2();
    display3();
    display4();
}