#ifndef clamelib_Stack_h
#define clamelib_Stack_h

#include <stdlib.h>

struct StackNode;

typedef struct StackNode {
  struct StackNode * previous_node;
  struct StackNode * next_node;
  void * data;
} StackNode;

typedef struct Stack {
  int size;
  StackNode * first_node;
  StackNode * last_node;
} Stack;

Stack * newStack();
void deleteStack(Stack * stack);

void pushStackNode(Stack * stack, void * data);
void * popStackNode(Stack * stack);

#define getStackSize(S) ((S)->size)
#endif
