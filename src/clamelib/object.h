#ifndef _object_h_
#define _object_h_

#include <stddef.h>

typedef struct {
	char * description;
	int (*init)(void * self, ...);
	void (*describe)(void * self);
	void (*delete)(void * self);
} Object;

int initObject(void * self, ...);
void describeObject(void * self);
void deleteObject(void * self);

void * newObject(size_t size, Object prototype, char * description);

#define NEW(O, D) newObject(sizeof(O), O##Prototype, D)

#endif