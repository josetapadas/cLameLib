#include <clamelib/list.h>

List * newList() {
  return calloc( 1, sizeof(List) );
}

void deleteList(List * list) {
  ListNode * cursor = NULL;
  ListNode * element = NULL;

  for( element = cursor = list->first_node ; cursor != NULL; element = cursor = cursor->next_node ) {
    free( element );
  }

  free(list);
}

void pushListNode(List * list, void * data) {
  ListNode * new_node = calloc( 1, sizeof(ListNode) );

  new_node->data = data;

  if ( list->first_node == NULL ) {
    list->first_node = new_node;
    list->last_node = new_node;
  } else {
    new_node->next_node = list->first_node;
    list->first_node->previous_node = new_node;
    list->first_node = new_node;    
  }

  list->size++;
}

void * popListNode(List * list) {
  ListNode * popped_node = list->first_node;

  if( popped_node != NULL ) {
    if( list->first_node == list->last_node ) {
      list->first_node = NULL;
      list->last_node = NULL;
    } else if( list->first_node == popped_node ) {
      list->first_node = popped_node->next_node;
      list->first_node->previous_node = NULL;      
    } else if( list->last_node == popped_node ) {
      list->first_node = NULL;
      list->last_node = NULL;
    } else {
      ListNode * previous;
      ListNode * next;

      previous = popped_node->previous_node;
      next = popped_node->next_node;

      previous->next_node = next;
      next->previous_node = previous;
    }

    void * result = popped_node->data;

    free(popped_node);

    list->size--;

    return result;
  }

  return NULL;
}