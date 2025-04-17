#ifndef element_h
#define element_h

#include <stdio.h>

#define STACK_SIZE 10

// Element Types
typedef enum {
    P,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    NL,
    BOLD,
    ITALIC,
    URL,
    IMG,
    ERROR = 9999
} State;

// Element
typedef struct Element
{
    int ec;         // Count of sub elements
    Stack states;
    struct Element *prev_el;
    struct Element *next_el;
    char *str;
} Element;

// Functions
Element* element_init(const char *str, size_t str_len, Stack *st);
Element* element_get_first_sub_element(Element *e);
void element_free(Element *e);

#endif /*element_h*/
