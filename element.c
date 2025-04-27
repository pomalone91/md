#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "element.h"
#include "stack.h"

#define BASE_STR_SIZE 10

// Initialize new element
/*
    This doesn't actually really need an algorithm. It only needs to do two things.
    1. Store the string that makes up the element.
    2. Copy the states passed to it from the document.
        - States should be copied by value, not just the pointer so that they don't get changed by mistake.
*/

Element* element_init() {
    Element *e = malloc(sizeof(Element));
    e->states = stack_init();
    e->str = malloc(sizeof(char) * BASE_STR_SIZE);

    return e;
}

Element* element_init_with_components(const char *str, size_t str_len, Stack *st) {
    Element *e = malloc(sizeof(Element));

    // Copy the passed string to this elements string attribute
    e->str = malloc(sizeof(char) * str_len);
    strcpy(e->str,str);

    // Do stack stuff.
    e->states = stack_init();
    for (int i = 0; i <= st->top; i++)
    {
        stack_push(e->states, *(st->states + i));
    }

    return e;
}

void element_dump(const struct Element* self) {
    printf("%s\n", self->str);
    stack_dump_states(self->states);
}

void element_free(Element* self) {
    if (self->states != NULL)
    {
        stack_free(self->states);
        self->states = NULL;
    }
    
    if (self->str != NULL)
    {
        free(self->str);
        self->str = NULL;
    }
    
    free(self);
    self = NULL;
}
