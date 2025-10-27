#include <stdio.h>
int st[10000];
int size;
int top = -1;

void push(int ele) {
    // overflow
    if (top == size - 1) {
        printf("Stack is overflown / stack is full\n");
    } else {
        st[++top] = ele; // (or) top++; st[top] = ele;
    }
}

void pop() {
    // underflow
    if (top == -1) {
        printf("Stack is underflown / stack is empty\n");
    } else {
        printf("Deleted element is: %d\n", st[top]);
        top--;
    }
}

void display() {
    // underflow
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        int i;
        for (i = top; i >= 0; i--) {
            printf("%d ", st[i]);
        }
        printf("\n");
    }
}

void peak() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Peak element is: %d\n", st[top]);
    }
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == size - 1;
}

int main() {
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    int ch;
    while (1) {
        printf("Enter \n1. PUSH\n2. POP\n3. Display\n4. Peak\n5. Check if Empty\n6. Check if Full\nAny other to exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            // push operation
            int ele;
            printf("Enter an element to be pushed: ");
            scanf("%d", &ele);
            push(ele);
        } else if (ch == 2) {
            // pop
            pop();
        } else if (ch == 3) {
            // display
            display();
        } else if (ch == 4) {
            // peak
            peak();
        } else if (ch == 5) {
            // check if empty
            if (is_empty()) {
                printf("Stack is empty\n");
            } else {
                printf("Stack is not empty\n");
            }
        } else if (ch == 6) {
            // check if full
            if (is_full()) {
                printf("Stack is full\n");
            } else {
                printf("Stack is not full\n");
            }
        } else {
            break;
        }
    }
    return 0;
}

