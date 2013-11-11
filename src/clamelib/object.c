#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initObject(void * self, ...) {
  if(self) {
    return 1;
  } else {
    return 0;
  }
}

void describeObject(void * self) {
  Object * this = self;

  printf("%s\n", this->description);
}

void deleteObject(void * self) {
  Object * this = self;

  if( this ) {
    if( this->description ) {
      free(this->description);
    }

    free(this);
  }
}

void * newObject(size_t size, Object prototype, char * description) {
  
  // Use default Object methods if not defined
  if( prototype.init == NULL ) {
    prototype.init = initObject;
  }

  if( prototype.describe == NULL ) {
    prototype.describe = describeObject;
  }

  if( prototype.delete == NULL ) {
    prototype.delete = deleteObject;
  }

  // create one element and copy the prototype contents
  Object * new_element = calloc(1, size);
  *new_element = prototype;

  new_element->description = strdup(description);

  // the initialization function must return 1 to be successful
  if( new_element->init(new_element) != 1 ) {
    new_element->delete( new_element );
    return NULL;
  } else {
    return new_element;
  }
}


