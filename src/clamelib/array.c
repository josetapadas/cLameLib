#include <clamelib/array.h>

Array * createArray(size_t initial_size) {
  Array * result_array = malloc(sizeof(Array));

  result_array->size = initial_size;
  result_array->elements = calloc(initial_size, sizeof(void*));
  result_array->length = (int) initial_size;

  return result_array;
}

void deleteArray(Array * array) {
  if(array) {
    if(array->elements) {
      free(array->elements);
    }
    free(array);
  }
}