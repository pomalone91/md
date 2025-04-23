#ifndef doc_h
#define doc_h

#include <stdio.h>
#include "element.h"
#include "element_list.h"

// Types
typedef struct Doc {
    char *str;
    ElementList* element_list;   // Pointer to first element in the doc
    int element_count; // Number of elements
} Doc;

// Functions
Doc* doc_init(char *str);
Element* doc_get_first_element(Doc* self);
void doc_free(Doc* self);

#endif /*doc_h*/