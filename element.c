#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "element.h"
#include "stack.h"

bool is_special_char(char c) {
    bool special;
    switch (c)
    {
    case '#':
        special = true;
        break;
    case '\n':
        special = true;
        break;
    case '*':
        special = true;
        break;
    case '[':
        special = true;
        break;
    case ']':
        special = true;
        break;
    case '(':
        special = true;
        break;
    case ')':
        special = true;
        break;
    case '_':
        special = true;
    default:
        special = false;
        break;
    }
    return special;
}

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

    for (int i = 0; i < st->stack_top; i++)
    {
        stack_push(&e->states, *(st->stack_states + i));
    }

    return e;
}
