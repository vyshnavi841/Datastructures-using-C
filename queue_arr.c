#include <stdio.h>

int q[100];
int front = 0;
int rear = 0;
int size;

void enqueue(int val) {
    // Insertion --> full condition
    if (rear - front == size) {
        printf("Queue is full\n");
        return;
    }
    q[rear] = val;
    rear++;
}

void dequeue() {
    // Deletion --> empty condition
    if (front == rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is removed\n", q[front]);
    front++;
}
void display() {
    int i;
    if (front == rear) {
        printf("Queue is empty\n");
        return;
    }
    for (i = front; i < rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int get_front() {
    if (front == rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[front];
}

int get_rear() {
    if (front == rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[rear - 1];  // Adjusted to get the actual rear element
}

int is_empty() {
    return front == rear;
}

int get_size() {
    return rear - front;
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    int ch;
    while (1) {
        printf("Enter\n1. Enqueue\n2. Dequeue\n3. Display\n4. Get front\n5. Get rear\n6. Is empty\n7. Get size\nAny other to exit.\n");
        scanf("%d", &ch);
        if (ch == 1) {
            int val;
            printf("Enter the value to be enqueued: ");
            scanf("%d", &val);
            enqueue(val);
        } else if (ch == 2) {
            dequeue();
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            printf("Front = %d\n", get_front());
        } else if (ch == 5) {
            printf("Rear = %d\n", get_rear());
        } else if (ch == 6) {
            if (is_empty()) {
                printf("Queue is empty\n");
            } else {
                printf("Queue is not empty\n");
            }
        } else if (ch == 7) {
            printf("Size = %d\n", get_size());
        } else {
            break;
        }
    }
}

