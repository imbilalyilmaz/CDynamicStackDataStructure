#include <stdio.h>
#include <malloc.h>

struct Stack{
    int data;
    struct Stack* next;
};

struct Stack* createStack(int data) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = data;
    stack->next = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return !stack;
}

void push(struct Stack** stack, int data) {
    struct Stack* newNode = createStack(data);
    newNode->next = *stack;
    *stack = newNode;
}
void pop(struct Stack** stack) {
    if(isEmpty(*stack)) {
        printf("Stack is empty");
        return;
    }
    struct  Stack* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

void writeStack(struct Stack* stack) {
    if(stack==NULL) {
        printf("Stack is not defined");
        return;
    }
    while(stack) {
        printf("%d ",stack->data);
        stack = stack->next;
    }
}

void destroyStack(struct Stack** stack) {
    struct Stack* temp;
    while(*stack !=NULL) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

int main() {
    struct Stack* stack = createStack(5);
    push(&stack,4);
    push(&stack,3);
    push(&stack,2);
    push(&stack,1);
    writeStack(stack);
    printf("\n");
    pop(&stack);
    writeStack(stack);
    printf("\n");
    destroyStack(&stack);
    writeStack(stack);


    return 0;
}
