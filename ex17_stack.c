/* ex17_stack.c
   This is a short program that implements and demonstrates
   a linked list implementaiton of a stack data structure.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *next;
  int data;
};

struct Stack {
  struct Node *top;
};


struct Stack* Stack_new () {
  struct Stack *stack = malloc(sizeof(struct Stack));
  stack->top = NULL;
  return stack;
}


int Stack_isEmpty (struct Stack *stack) {
  return (stack->top == NULL);
}


void Stack_push (struct Stack *stack, int value) {
  struct Node *node = malloc(sizeof(struct Node));

  node->data = value;
  node->next = stack->top;
  stack->top = node;
}


int Stack_pop (struct Stack *stack) {
  int value = 0;
  struct Node *temp;

  value = stack->top->data;
  temp = stack->top;
  stack->top = stack->top->next;
  free(temp);

  return value;
}


void Stack_delete (struct Stack *stack) {
  while (!Stack_isEmpty(stack)) {
    Stack_pop(stack);
  }
  
  free(stack);
}



int main (int argc, char** argv) {
  struct Stack *theStack;
  
  theStack = Stack_new();
  
  printf("\nPushing 0 through 9 on to the stack.\n");
  int i = 0;
  for (i = 0; i < 10; i++) {
    Stack_push(theStack, i);
  }
  
  printf("\nPopping the values from the stack.\n");
  int value = 0;
  while (!Stack_isEmpty(theStack)) {
    value = Stack_pop(theStack);
    printf("Value: %d\n", value);
  }
  
  Stack_delete(theStack);
  
  return 0;
}
