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
    e->str_len = sizeof(char) * BASE_STR_SIZE;

    return e;
}

Element* element_init_with_components(const char *str, size_t str_len, Stack *st) {
    Element *e = malloc(sizeof(Element));

    

    // Copy the passed string to this elements string attribute
    e->str_len = str_len;
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

// For setting up elements that have already been allocated
void element_set_with_compontents(Element* e, const char *str, size_t str_len, Stack *st) {
    e->str = malloc(sizeof(char) * str_len);
    strcpy(e->str, str);


    if (e->states == NULL) 
        if((e->states = realloc(e->states, sizeof(Stack))) == NULL) {
            printf("Error reallocating states of an element in element_list\n");
            return;
        }
    e->states = stack_init();

    // Copy the stack
    for (int i = 0; i <= st->top; i++)
    {
        stack_push(e->states, *(st->states + i));
    }
}

void element_dump(const struct Element* self) {
    printf("%s\n", self->str);
    stack_dump_states(self->states);
}

void element_free(Element* self) {
    if (self->states)
    {
        stack_free(self->states);
        self->states = NULL;
    }
    
    if (self->str)
    {
        free(self->str);
        self->str = NULL;
    }
    
    if (self) {
        free(self);
        self = NULL;
    }
}
