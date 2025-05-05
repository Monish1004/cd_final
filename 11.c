#include <stdio.h>
#include <stdlib.h>

#define max 10

int top = -1;
int stack[max];

void push() {
    if (top >= max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    int x;
    printf("Enter the value: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("%d inserted into the stack\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    int popped = stack[top--];
    printf("%d popped from the stack\n", popped);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    char op;
    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your option: ");
        scanf(" %c", &op); 

        switch(op) {
            case '1': push(); break;
            case '2': pop(); break;
            case '3': display(); break;
            case '4': printf("Exiting...\n"); break;
            default : printf("Enter a valid option\n");
        }
    } while(op != '4');

    return 0;
}
