#ifndef element_h
#define element_h

#include <stdio.h>
#include "stack.h"

// Element
typedef struct Element
{
    Stack *states;
    char *str;
    size_t str_len;
} Element;

// Functions
Element* element_init();
Element* element_init_with_components(const char *str, size_t str_len, struct Stack *st);
void element_set_with_compontents(Element* e, const char *str, size_t str_len, Stack *st);
void element_dump(const struct Element* self);
void element_free(struct Element* self);

#endif /*element_h*/
