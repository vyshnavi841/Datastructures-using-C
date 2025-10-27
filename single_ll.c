#include<stdio.h>
#include<stdlib.h>

// Self-referential structure 
struct node {
    int data;
    struct node *next; // Pointer to node
};

// Alias name
typedef struct node Node;
Node *head = NULL;

void insert_at_head(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    if(head == NULL){	//if there are no nodes alread
		head = newNode;
	}
	else{
		newNode -> next = head;
		head = newNode;
	}
}

void insert_at_tail(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_at_head() {
    if (head == NULL) {
        printf("Linked list is empty. Deletion is not possible\n");
    } else {
        Node *temp = head; // Node to be deleted
        head = head->next; // Move head to the next node
        free(temp); // Deallocate memory for the deleted node
    }
}

void delete_at_tail() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else if (head->next == NULL) {
        Node *delNode = head;
        head = NULL;
        free(delNode);
    } else {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        free(delNode);
    }
}

void delete_at_position(int position) {
	int i;
    if (head == NULL) {
        printf("Linked list is empty. Deletion is not possible\n");
        return;
    }
    if (position == 0) {
        delete_at_head();
        return;
    }

    Node *temp = head;
    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

void display() {
    if (head == NULL) {
        printf("No nodes to display\n");
    } else {
        Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    // Infinite loop
    while (1) {
        printf("Enter\n1. Insert at head\n2. Insert at tail\n3. Display\n4. Deletion at head\n5. Deletion at tail\n6. Deletion at position\nAny other number to exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            int val;
            printf("Enter a value for the node to be inserted: ");
            scanf("%d", &val);
            insert_at_head(val);
        } else if (ch == 2) {
            int val;
            printf("Enter a value for the node to be inserted: ");
            scanf("%d", &val);
            insert_at_tail(val);
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            delete_at_head();
        } else if (ch == 5) {
            delete_at_tail();
        } else if (ch == 6) {
            int pos;
            printf("Enter the position for deletion: ");
            scanf("%d", &pos);
            delete_at_position(pos);
        } else {
            printf("Thank You for the testing. ADIEU!!\n");
            break;
        }
    }
    return 0;
}

