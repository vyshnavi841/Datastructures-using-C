#include <stdio.h>
#include <stdlib.h>

int *q;
int front, capacity;
int rear;
int size;

void enqueue(int val) {
    if (size == capacity) {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % capacity;
    q[rear] = val;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is deleted\n", q[front]);
    front = (front + 1) % capacity;
    size--;
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", q[(front + i) % capacity]);
    }
    printf("\n");
}

int get_size() {
    return size;
}

int main() {
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    q = (int *)malloc(sizeof(int) * capacity); // dynamic array
    size = 0;
    front = 0;
    rear = -1; // Correct initialization of rear

    int ch;
    while (1) {
        printf("Enter\n1. Enqueue\n2. Dequeue\n3. Display\n4. Size\nAny other number to exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            int val;
            printf("Enter a value to be inserted: ");
            scanf("%d", &val);
            enqueue(val);
        }
        else if (ch == 2) {
            dequeue();
        }
        else if (ch == 3) {
            display();
        }
        else if (ch == 4) {
            printf("Size = %d\n", get_size());
        }
        else {
            break;
        }
    }

    // Free the allocated memory
    free(q);

    return 0;
}

