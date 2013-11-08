#include <clamelib/stack.h>
#include <stdio.h>

int main() {
  char * item1 = "data node #1";
  char * item2 = "data node #2";
  char * item3 = "data node #3";

  Stack * sample_stack = newStack();

  printf("- On the beginning, sample_stack size is %d.\n", getStackSize(sample_stack));

  pushStackNode(sample_stack, item1);
  pushStackNode(sample_stack, item2);
  pushStackNode(sample_stack, item3);

  printf("- After pushing, sample_stack size is %d.\n", getStackSize(sample_stack));

  printf("- Poping a item with value: {%s}.\n", popStackNode(sample_stack));
  printf("- Poping another item with value: {%s}.\n", popStackNode(sample_stack));

  printf("- After the pops, sample_stack size is %d.\n", getStackSize(sample_stack));

  emptyStack(sample_stack);

  printf("- After emptying the stack, sample_stack size is %d.\n", getStackSize(sample_stack));

  deleteStack(sample_stack);

  return 0;
}