#include <stdio.h>
#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1; 
}

int isEmpty(Stack *s) {
    return s->top == -1; 
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } 
    else{
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow \n");
        return -1;
    }
    else {
        return s->arr[(s->top)--];
    }
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped element: %d\n", pop(&s)):
    printf("Popped element: %d\n", pop(&s));

    return 0;
}