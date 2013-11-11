#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <clamelib/object.h>

struct PersonStructure {
  Object prototype;
  int age;
  int (*getAge)(void * self);
};

typedef struct PersonStructure Person;

int initPerson(void * self, ...);
int _getAge(void * self);

int initPerson(void * self, ...) {
  Person * this = self;

  this->age = 23;
  this->getAge = _getAge;

  return 1;
}

Object PersonPrototype = {
  .init = initPerson
};

int _getAge(void * self) {
  Person * this = self;

  if(this->age) {
    return this->age;
  } else {
    return -1;
  }
}

int main() {
  Person * jose = NEW(Person, "An average portuguese person.");

  printf("This Person object is described by:\n"); jose->prototype.describe(jose);
  printf("\nThis Person's age is: %d\n", jose->getAge(jose));

  return 0;
}