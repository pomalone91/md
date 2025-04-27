#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"
#include "element.h"
#include "element_list.h"
#include "doc.h"

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

    Stack *stack_of_states = stack_init();
    size_t doc_len = strlen(str);

    Doc *d = malloc(sizeof(Doc));

    // Build doc string
    d->str = malloc(sizeof(char) * doc_len);
    strcpy(d->str, str);

    // d->element = malloc(sizeof(Element));
    d->element_list = element_list_init();
        //d->element_list->element->states = stack_of_states;
    
    d->element_count = 0;

    // Start scanning for symbols
    int i = 0;
    int j = 0;
    int syb_len = 0;    // 0 for paragraphs, 1 for #, 2 for ## etc.

    while (str[i] != '\0')
    {
        // Handle paragraphs
        if (!is_special_char(str[i]) && stack_of_states->top < 0) {
            stack_push(stack_of_states, P);
            syb_len = 0;

            // Scan ahead
            j = i + 1;
            while (str[j] != '\0')
            {
                if (str[j] == '\n')
                    break;
                
                j++;
            }
            if (i - j == 0)
                break;
            char* el_str = calloc(j - i + 1, sizeof(char));
            
            // Copy from where i is to where j found the end. Offset by the symbol length so we don't copy #s and such into the string. 
            strncpy(el_str, str + i + syb_len, j - i);
            el_str[j - i + 1] = '\0';
            //int h = 0;
            // This loop is to check what chars are actually going into the string 
            //while (h < j - i + 1) {
            //    char c = el_str[h];
            //    c ? printf("%c ", c) : printf("\\0 ");
            //    h++;
            //}
            // Initialize element
            // Need to capture an array of states in the element since you could have nested states
            // We need to copy the actual values so that they persist for just that element since the parent or child elements will have different stacks.
            Element *e = element_init_with_components(el_str, strlen(el_str), stack_of_states);
            // TODO - why does this reset the stack when I use this function?
            element_list_append(d->element_list, *e);
            d->element_count++;

            // Reset indices and continue loop. i now points past the end of that last element
            i = j++;
            j = 0;
            syb_len = 0;
            stack_pop(stack_of_states);
            free(el_str);
        } 
        i++;
    }

    return d;
}

Element* doc_get_first_element(Doc* self) {
    return self->element_list->element;
}

void doc_free(Doc* self) {
    element_list_free(self->element_list);
    self->element_list = NULL;

    self->element_count = 0;

    free(self->str);
    self->str = NULL;

    free(self);
    self = NULL;
}
