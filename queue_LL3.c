#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;
Node *tail = NULL;
int size = 0;

void enqueue(int val) { //adding an element at the end
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void dequeue() {		//removing the first element
    if (head == NULL) {
        printf("LL is empty, deletion not possible\n");
    } else if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
        size--;
    } else {
        Node *temp = head;
        head = head->next;
        free(temp);
        size--;
    }
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

int get_front() {
    if (head != NULL) {
        return head->data;
    } else {
        printf("Queue is empty\n");
        return -1; // Indicating that the queue is empty
    }
}

int get_rear() {
    if (tail != NULL) {
        return tail->data;
    } else {
        printf("Queue is empty\n");
        return -1; // Indicating that the queue is empty
    }
}

int if_empty() {
    return size == 0;
}

int get_size() {
    return size;
}

int main() {
    int ch;
    while (1) {
        printf("Enter\n1. Enqueue\n2. Dequeue\n3. Display\n4. Size\n5. Display front\n6. Display rear\n7. Check if empty\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                {
                    int val;
                    printf("Enter a value to be inserted: ");
                    scanf("%d", &val);
                    enqueue(val);
                    break;
                }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Size = %d\n", get_size());
                break;
            case 5:
                printf("Front = %d\n", get_front());
                break;
            case 6:
                printf("Rear = %d\n", get_rear());
                break;
            case 7:
                if (if_empty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

