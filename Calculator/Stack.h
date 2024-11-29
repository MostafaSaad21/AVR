#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100
#define StackEntry int

typedef struct {
    StackEntry arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *ps);
int isFull(Stack *ps);
int isEmpty(Stack *ps);
void push(Stack *ps, StackEntry e);
void pop(Stack *ps, StackEntry *e);
int StackSize(Stack *ps);
void clearStack(Stack *ps);

#endif
