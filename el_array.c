#include <stdlib.h>
#include "el_array.h"
#include "element.h"

// Initialize a new array
ElArray el_array_init() {
    ElArray ea = {2, 0, malloc(sizeof(ElArray) * 2)};
    return ea;
}

// Append a new element to array
void el_array_append(ElArray *ea, Element e) {
    // If end is same as size we need to double the allocated memory.
    if (ea->end == ea->size)
    {
        ea->size *= 2;
        ea->element = realloc(ea->element, sizeof(Element) * ea->size);
    }

    // Append to the end of the array
    *(ea->element + ea->end) = e;
    ea->end++;
}

void el_array_free(ElArray *ea) {
    element_free(ea->element);
    ea->end = 0;
    ea->size = 0;
    free(ea);
}