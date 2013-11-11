#ifndef _clamelib_array_h
#define _clamelib_array_h

#include <stdlib.h>

struct Array;

typedef struct Array {
  void ** elements;
  size_t size;
  int length;
} Array;

Array * createArray(size_t initial_size);
void deleteArray(Array * array);

static inline void setArrayElement(Array * array, int position, void * element) {
  if(position < (int) array->size) {
    array->elements[position] = element;
  }
}

static inline void * getArrayElement(Array * array, int position) {
  if(position < (int) array->size) {
    return array->elements[position];
  }

  return NULL;
}
#endif
