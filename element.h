#ifndef element_h
#define element_h

#include <stdio.h>

// Element Types
typedef enum {
    H1,
    H2,
    H3
} State;

// Element
typedef struct Element
{
    char *s;
    struct Element *elements;  // Pointer to the first sub element in this one.
    int ec;         // Count of sub elements
    State state;
} Element;

// Functions
Element* element_init(const char *s);
Element* element_get_first_sub_element(Element *e);
void element_free(Element *e);

#endif /*element_h*/
