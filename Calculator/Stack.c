#include "stack.h"
#include <stdio.h>

void initialize(Stack *ps)
{
    ps->top = 0;
}

int isFull(Stack *ps)
{
    return ps->top == MAX_SIZE;
}

int isEmpty(Stack *ps) {
    return ps->top == 0;
}

void push(Stack *ps, StackEntry e)
{
    if (!isFull(ps)) {
        ps->arr[ps->top++] = e;
        printf("%d pushed into stack\n", e);
    } else {
        printf("Stack is full\n");
    }
}

void pop(Stack *ps, StackEntry *e)
{
    if (!isEmpty(ps)) {
        *e = ps->arr[--ps->top];
        printf("%d Popped from stack\n", *e);
    } else {
        printf("Stack is empty\n");
    }


}

void clearStack(Stack *ps) {
    ps->top = 0;
}
