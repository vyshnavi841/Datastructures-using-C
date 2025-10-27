//implementing doubly linked list
#include<stdio.h>
#include<stdlib.h>
//self-referential structure
struct node{
	int data;
	struct node *prev;
	struct node *next; //pointer to node
};
//alias code
typedef struct node Node;
Node *head = NULL;
Node *tail = NULL;
void insert_at_head(int val){
	//creating a newNode
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = val;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	if(head == NULL && tail == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode -> next = head;
		head -> prev = newNode;
		head = newNode;
	}
}
void insert_at_tail(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = val;
	newNode -> next = NULL;
	newNode -> prev = NULL;
	if(head == NULL && tail ==NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
void insert_at_position(int val,int position){
	int i;
	Node *temp = head;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = val;
	for(i=0;i<position-1;i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next=newNode;
}
void delete_at_head(){
	if(head == NULL &&tail == NULL){
		printf("Linked List is empty.");
	}
	else if(head == tail){
		Node *tobedeleted = head;
		head = NULL;
		tail = NULL;
		free(tobedeleted);
	}
	else{
		Node *temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}
void delete_at_tail(){
	if(head == NULL && tail == NULL){
		printf("Linked List is empty");
	}
	else if(head == tail){
		Node *tobedeleted = head;
		head = NULL;
		tail = NULL;
		free(tobedeleted);
	}
	else{
		Node *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	}
}

void display_from_left(){
	if(head == NULL && tail == NULL){
		printf("No Nodes to display");
	}
	else{
		Node *temp = head;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}
void display_from_right(){
		if(head == NULL && tail == NULL){
		printf("No Nodes to display");
	}
	else{
		Node *temp = tail;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->prev;
		}
	}
}
int main(){
	int ch;
	//infinite loop
	while(1){
		printf("Enter \n1.Insert at head\n2.Insert at tail\n3.Insert at any position\n4.Delete at head\n5.Delete at tail\n6.Display forward\n7.Display backward\n");	
		scanf("%d",&ch);
		if(ch==1){
			int val;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d",&val);
			//implement insert at head
			insert_at_head(val);  //function call
		}
		else if(ch == 2){
			int val;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d",&val);
			insert_at_tail(val);
		}
		else if(ch == 3){
			int val,position;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d",&val);
			printf("Enter the position:");
			scanf("%d",&position);
			insert_at_position(val,position);
		}
		else if(ch == 4){
			delete_at_head();
		}
		else if(ch == 5){
			delete_at_tail();
		}
		else if(ch == 6){
			display_from_left();
		}
		else if (ch == 7){
			display_from_right();
		}
		else{
			printf("Thank you!\n");
		}
	}
}
	

