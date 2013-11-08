#include <clamelib/list.h>
#include <stdio.h>

int main() {
  char * item1 = "data node #1";
  char * item2 = "data node #2";
  char * item3 = "data node #3";

  List * sample_list = newList();

  printf("- On the beginning, sample_list size is %d.\n", getListSize(sample_list));

  pushListNode(sample_list, item1);
  pushListNode(sample_list, item2);
  pushListNode(sample_list, item3);

  printf("- After pushing, sample_list size is %d.\n", getListSize(sample_list));

  printf("- Poping a item with value: {%s}.\n", popListNode(sample_list));
  printf("- Poping another item with value: {%s}.\n", popListNode(sample_list));

  printf("- After the pops, sample_list size is %d.\n", getListSize(sample_list));

  return 0;
}