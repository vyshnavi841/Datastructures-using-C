#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *head = NULL;
void insert_at_head(int val){
	//creating a newNode
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = newNode;
	if(head == NULL){
		head = newNode;
	} 
	else{
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
		head = newNode;
	}
}
void insert_at_tail(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = newNode;
	if(head == NULL){
		head = newNode;
	}
	else{
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
	}
}
void Delete_at_head(){
	if(head == NULL){
		printf("Linked list is empty, Deletion is not possible");
	}else if(head->next == head){
		Node * delnode = head;
		head = NULL;
		free(delnode);
	}else{
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		Node *delnode = head;
		head = head->next;
		temp->next = head;
		free(delnode);
	}
}
void Delete_at_tail() {
    if (head == NULL) {
        printf("Linked list is empty, Deletion is not possible\n");
        return;
    } else if (head->next == head) { // Single node case
        Node *delnode = head;
        head = NULL;
        free(delnode);
        return;
    } else {
        Node *temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node *tobedeleted = temp->next;
        temp->next = head;
        free(tobedeleted);
    }
}

void display() {
    if (head == NULL) {
        printf("No nodes to display\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void display_n_nodes(){
	int i,n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	Node *temp = head;
	if(head == NULL){
		printf("Linked List is empty.\n");
		return;
	}
	for(i=0;i<n;i++){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(){
	int ch;
	//infinite loop
	while(1){
	printf("Enter \n1.Insert at head\n2.Insert at tail\n3.Display\n4.Deletion_n_nodes\n5.delete at head\n6.delete at tail\nAny other to exit\n");	
		scanf("%d",&ch);
		if(ch==1){
			//insert at head
			int val;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d",&val);
			insert_at_head(val);  //function call	
		}
		else if(ch==2){
			//implement insert at tail
			int val;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d",&val);
			insert_at_tail(val);
		}
		else if(ch==3){
			//implement display
			display();
		}
		else if(ch==4){
			//implement delete at head
			display_n_nodes(); 
		}
		else if (ch==5){
			Delete_at_head();
		}
		else if(ch==6){
			Delete_at_tail();
		}
		else{
			printf("Thank you!\n");
			break;
		}
	
	}
}
