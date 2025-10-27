#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *head=NULL;
Node *tail=NULL;
 int size=0;
void enqueue(int val){
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
    size++;
}

void display() {
    if(head==NULL){
        printf("no nodes to display\n");
    } else{
        Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void dequeue() {
     if(head == NULL && tail==NULL) {
       printf("LL is empty deletion not possible");   
    }
    else if(head==tail) {
        head=NULL;
        tail=NULL;
        size--;
    }
    else {
      Node *temp=head;
      head = head->next;
      free(temp);
      size--;
    }
}
int main(){
    int ch;
    while(1){
    printf("Enter\n1.enqueue\n2.dequeue\n3.display\n4.Size\n5.Display front\n6.Display rear\n");
    scanf("%d",&ch);
    if(ch==1){
        int val;
        printf("Enter a value to be inserted:");
        scanf("%d",&val);
        enqueue(val);
    } 
    else if(ch==2){
        dequeue();
    }
    else if(ch==3){
        display();
    }
    else if(ch==4) {
        printf("Size = %d\n",size);
    }
    else if(ch==5) {
        printf("%d\n",*head);
    }
    else if(ch==6) {
         printf("%d\n",*tail);
    }
}
}
