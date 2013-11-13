#include <clamelib/array.h>
#include <stdio.h>

int main() {
	Array * array = createArray(4);

  setArrayElement(array, 0, "item 1");
  setArrayElement(array, 1, "item 2");
  setArrayElement(array, 2, "item 3");
  setArrayElement(array, 3, "item 4");

  arrayForEach(array, array_element) {
    printf("- Array element: %s\n", array_element);
  }

  deleteArray(array);

	return 0;
}
