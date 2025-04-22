#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "element.h"
#include "stack.h"

// Initialize new element
/*
    This doesn't actually really need an algorithm. It only needs to do two things.
    1. Store the string that makes up the element.
    2. Copy the states passed to it from the document.
        - States should be copied by value, not just the pointer so that they don't get changed by mistake.
*/
Element* element_init(const char *str, size_t str_len, Stack *st) {
    Element *e = malloc(sizeof(Element));

    // Copy the passed string to this elements string attribute
    e->str = malloc(sizeof(char) * str_len);
    strcpy(e->str,str);

    // Do stack stuff.
    e->states = stack_init();
    for (int i = 0; i < st->top; i++)
    {
        stack_push(e->states, *(st->states + i));
    }

    return e;
}

void element_dump(const struct Element* self) {
    printf("%s\n", self->str);
    stack_dump_states(self->states);
}

void element_free(Element *e) {
    stack_free(e->states);
    free(e);
}