//Implementation of Queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *head = NULL;
Node *tail = NULL;
void Enqueue(int val){ //insert at tail
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode -> data = val;
	newnode -> next = NULL;
	if(head == NULL && tail == NULL){
		head = newnode;
		tail = newnode;
	}
	else {
		tail->next = newnode;
		tail = newnode;
	}
}
void dequeue(){ //delete at head
	if(head == NULL && tail == NULL){
		printf("No node to be deleted\n");
	}
	else if(head==tail){
		Node *temp = head;
		head = NULL;
		free(temp);
	}
	else {
		Node *temp = head;
		head=head->next;
		free(temp);
	}	
}
void  display(){
	if(head == NULL){
		printf("No node to display\n");
	}
	else{
		Node *temp = head;
		while(temp != NULL){
			printf("%d ",temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}
int main(){
	int ch;
	while(1){
		printf("Enter\n1.Enqueue\n2.Dequeue\n3.Display\nAny other\n");
		scanf("%d",&ch);
		if(ch==1){
			int val;
			printf("Enter the number to be inserted: ");
			scanf("%d",&val);
			Enqueue(val);
		}
		else if (ch==2){
			dequeue();
		}
		else if(ch==3){
			display();
		}
		else
		{
			break;
		}
	}
}
