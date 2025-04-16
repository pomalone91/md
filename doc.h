#ifndef doc_h
#define doc_h

#include <stdio.h>
#include <element.h>

// Types
typedef struct Doc {
    char *str;
    Element *element;   // Pointer to first element in the doc
    int ec; // Number of elements
} Doc;

// Functions
Doc* doc_init(char *str);
Doc* doc_get_first_element(Doc *d);
void doc_free(Doc *d);

#endif /*doc_h*/