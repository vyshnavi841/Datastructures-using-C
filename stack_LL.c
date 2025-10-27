//Implementation of singly linked kist
#include<stdio.h>
#include<stdlib.h>
// self referential structure
struct node{
	int data;
	struct node *next;//pointer to node
};
//alias name
typedef struct node Node;
//taking head as a global  variable
Node *head=NULL;
int size;
int top=-1;
void PUSH(int val){
	if(top==size-1){
		printf("Stack is full\n");
		return;
	}
	//creating a newNode
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=val;
	newNode->next=NULL;
	if(head==NULL){  //if there are no nodes already
		head = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
	top++;
}
void POP(){
	if(head==NULL)
	{
		printf("Stack is empty.Deletion is not possible: \n");
		return;
	}
		Node *temp=head; // to be deleted node
		printf("%d is popped out of the stack.",head->data);
		head=head->next;
		free(temp); //deallocate the memory for node1
		top--;
}
void display (){
	if(head == NULL){
		printf("stack is empty\n");
	}
	else{
		Node *temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->next ;
		}
		printf("\n");
	}
}
int main()
{
	printf("Enter size of stack:");
	scanf("%d",&size);
	int ch;
	//Infinite loop
	while(1){
		printf("Enter \n1.PUSH\n2.POP\n3.Display\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch==1){
			//implement  insert at head
			int val;
			printf("Enter a Value for the node to be inserted: ");
			scanf("%d",&val);
			PUSH(val);//function  call
		}
		else if(ch==2){
			//implement delete at head
			POP();
		}
		else if(ch==3){
			//implement display
			display();
		}
		else
		{	
			printf("Thank You for the testing.ADIEU!!\n");
			break;
		}
	}
}
