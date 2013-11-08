#ifndef clamelib_List_h
#define clamelib_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
  struct ListNode * previous_node;
  struct ListNode * next_node;
  void * data;
} ListNode;

typedef struct List {
  int size;
  ListNode * first_node;
  ListNode * last_node;
} List;

List * newList();
void deleteList(List * list);

void pushListNode(List * list, void * data);
void * popListNode(List * list);

#define getListSize(L) ((L)->size)
#define getFirstListNode(L) ((L)->first_node != NULL ? (L)->first_node->data : NULL)
#define getLastListNode(L) ((L)->last_node != NULL ? (L)->last_node->data : NULL)
#define hasNextListNode(N) ((N)->next_node != NULL ? 1 : 0)
#endif
