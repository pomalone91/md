#ifndef el_array_h
#define el_array_h

#include <stdio.h>
#include "element.h"

// ElementArray
typedef struct ElArray {
    int size;   // How many elements the array can hold
    int end;    // How many are actually in the array.
    Element *element;
} ElArray;

ElArray el_array_init();
void el_array_append(ElArray *ea, Element e);
void el_array_free(ElArray *ea);


#endif /*el_array*/