#include <clamelib/stack.h>

Stack * newStack() {
  return calloc( 1, sizeof(Stack) );
}

void deleteStack(Stack * stack) {
  StackNode * cursor = NULL;
  StackNode * element = NULL;

  for( element = cursor = stack->first_node ; cursor != NULL; element = cursor = cursor->next_node ) {
    free( element );
  }

  free(stack);
}

void pushStackNode(Stack * stack, void * data) {
  StackNode * new_node = calloc( 1, sizeof(StackNode) );

  new_node->data = data;

  if ( stack->first_node == NULL ) {
    stack->first_node = new_node;
    stack->last_node = new_node;
  } else {
    new_node->next_node = stack->first_node;
    stack->first_node->previous_node = new_node;
    stack->first_node = new_node;    
  }

  stack->size++;
}

void * popStackNode(Stack * stack) {
  StackNode * popped_node = stack->first_node;

  if( popped_node != NULL ) {
    if( stack->first_node == stack->last_node ) {
      stack->first_node = NULL;
      stack->last_node = NULL;
    } else if( stack->first_node == popped_node ) {
      stack->first_node = popped_node->next_node;
      stack->first_node->previous_node = NULL;      
    } else if( stack->last_node == popped_node ) {
      stack->first_node = NULL;
      stack->last_node = NULL;
    } else {
      StackNode * previous;
      StackNode * next;

      previous = popped_node->previous_node;
      next = popped_node->next_node;

      previous->next_node = next;
      next->previous_node = previous;
    }

    void * result = popped_node->data;

    free(popped_node);

    stack->size--;

    return result;
  }

  return NULL;
}