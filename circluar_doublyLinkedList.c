#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *pre;
}*head=NULL;
void insert(int value){
	struct node *ptr,*tmp;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data =value;
	ptr->next = NULL;
	ptr->pre =NULL;
	if(head==NULL){
		head = ptr;
		ptr->pre = head;
		ptr->next = head;
	}
	else{
		tmp = head;
		while(tmp->next!=head){
			tmp = tmp->next;
		}
		tmp->next = ptr;
		ptr->pre = tmp;
		ptr->next = head;
	}
}
void delete(){
	struct node *tmp,*del;
	tmp=head;
	if(head==NULL)
	return;
	if(head->next==head){
		del=head;
		free(del);
		head=NULL;
	}
	while(tmp->next->next!=head){
		tmp=tmp->next;
	}
	del = tmp->next;
    head->pre =del->pre;
	tmp->next =head;
    free(del);

}
void display(){
	struct node *tmp;
	tmp=head;
	if(head == NULL)
	return;
	do{
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}while(tmp!=head);
}
int main(){
	int n,task,value;
	scanf("%d",&n);
	if(n==4)
		n++;
	for(int i=0;i<n;i++){
		scanf("%d",&task);
		if(task==1){
        scanf("%d",&value);
		insert(value);
        }
		else if(task==2)
		delete();
	}
	display();
}