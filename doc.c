#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doc.h"
#include "element.h"
#include "stack.h"
#include <string.h>

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


Doc* doc_init(char *str) {
    Doc *d = malloc(sizeof(Doc));
    d->element = malloc(sizeof(Element));
    Stack *stack = malloc(sizeof(Stack));
    *stack = stack_init();
    size_t doc_len = strlen(str);

    d->str = malloc(sizeof(char) * doc_len);
    strcpy(d->str, str);

    d->ec = 0;

    // Start scanning for symbols
    int i = 0;
    int j = 0;
    int syb_len = 0;    // 0 for paragraphs, 1 for #, 2 for ## etc.
    bool found_end = false;

    while (str[i] != '\0' || !found_end)
    {
        // Handle paragraphs
        if (!is_special_char(str[i]) && stack->stack_top < 0) {
            stack_push(stack, P);
            syb_len = 0;

            // Scan ahead
            j = i + 1;
            while (!is_special_char(str[i]))
            {
                j++;
            }

            char* el_str = malloc(sizeof(char) * (doc_len - j));
            
            // Copy from where i is to where j found the end. Offset by the symbol length so we don't copy #s and such into the string. 
            strncpy(el_str, str + i + syb_len, j - i);
            // Initialize element
            // Need to capture an array of states in the element since you could have nested states
            // TODO - change it so elements have an array of stacks and the init copies the passed stack to that element. 
            // We need to copy the actual values so that they persist for just that element since the parent or child elements will have different stacks.
            Element *e = element_init(el_str, strlen(el_str), stack);

            // TODO - Add element to array of elements. I need to create "element_array"
            if (d->ec == 0)
            {
                d->element = e;
                d->ec++;
            }
            

            
            

        } 
    }
}

Doc* doc_get_first_element(Doc *d) {

}

void doc_free(Doc *d) {

}