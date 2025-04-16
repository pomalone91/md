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
    Algorithm Outline
    1. Scan to find first special character
        2. Get state and push it onto stack.
        3. Do another loop to scan a head for next special character.
            - If it's \n or \0 end. Add an element to the array.
    If we hit \n or \0 end.


*/
Element* element_init(const char *str, State st) {
    // Figure out where the element starts
    // Note what type it is
    // Figure out where it ends (\n for now but we'll have to add new logic for different types of elements later)
    Element *e = malloc(sizeof(Element));
    Stack *stack = malloc(sizeof(Stack));
    *stack = stack_init();
    int i = 0;
    int j = 0;  // Use this when we're looking for **, ##, ### and so on.
    int symbol_start = 0;
    int symbol_end = 0;
    int symbol_length = 0;  // # has length 1. ## length 2.
    bool found_end = false;
    
    // Scan through string
    while (str[i] != '\0' || !found_end)
    {
        // If the first char is not a special char, we're in a paragraph.
        if (!is_special_char(str[i]) && stack->stack_top < 0)
        {
            symbol_start = i;
            stack_push(stack, P);
        } else if (is_special_char(str[i])) {
            if (str[i] == '#')
            {
                stack_push(stack, H1);
            } else if (str[i] == '*') {
                stack_push(stack, BOLD);
            }

            symbol_start = i;
            symbol_length = 1;
            
            // Scan ahead for next symbol
            j = i + 1;
            while (!is_special_char(str[i]))
            {
                j++;
            }
            
        }
        
        // printf("%c is style %d\n", str[i], stack_peek(stack));
        i++;
    }

    stack_free(stack);

    return e;
}
