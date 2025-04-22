#ifndef element_list_h
#define element_list_h

#include <stdio.h>
#include "element.h"

// ElementArray
typedef struct ElementList {
    int size;   // How many elements the array can hold
    int count;    // How many are actually in the array.
    struct Element* element;
} ElementList;

struct ElementList* element_list_init();
void element_list_append(struct ElementList* self, struct Element e);
void element_list_dump(const struct ElementList* self);
void element_list_free(ElementList* self);


#endif /*el_array*/