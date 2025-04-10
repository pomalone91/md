#include <stdio.h>
#include <stdlib.h>
#include "element.h"

// Initialize new element
Element* element_init(const char *s) {
    // Figure out where the element starts
    // Note what type it is
    // Figure out where it ends (\n for now but we'll have to add new logic for different types of elements later)
    int i = 0;
    Element *e = malloc(sizeof(Element));

    int symbol_position = 0;
    int heading_level = 0;
    int pound_offset = 0;
    // Try to find #s and figure out how many there are.
    while (*(s+i) != '\n' || *(s+i) != '\0')
    {
        if (*(s+i) == '#')
        {
            int j = i + 1;
            while (*(s+j) == '#')
            {
                pound_offset++;
                j++;
            }
            heading_level = 1 + pound_offset;
            symbol_position = i;

            break;
        }
        i++;
    }
    if (heading_level > 0)
    {
        e->state = H1;
    }

    // Find the \n or \0 for the end of the string so we can get the length of this part of it. 
    int end = 0;
    while (s[end] != '\n' || s[end] != '\0')
    {
        end++;
    }
    
    printf("%i\n", heading_level);
    printf("s[%i]: %c\n", i, s[i]);
    printf("s[%i+%i]: %c\n", i, pound_offset,  s[i + pound_offset]);
    printf("%u\n", e->state);
    

}
