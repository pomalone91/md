#include <stdio.h>
#include "element.h"
#include "stack.h"
/*
    Outline of parsing algorithm
    1. Scan first char.
        - If it's a special md symbol put corresponding state on a stack
        - If it's not a special symbol put paragraph state on stack
    2. Scan until we find another special symbol
        - If it's \n or \0 end the scan
    3. Create an element struct with the first state and the string of chars that just had that state.
    4. Put the second inner state on the stack.
    5. Scan until we find another special symbol
        - If it's \n or \0 end scan
    6. Create another element struct with parent pointing to the element above it. 
        - State includes both the original state above it and the new one we're in. 
    7. When we hit the end of this state pop it off hte stack and go back above to the first one and finish that. 
    8. If we hit another inner state deal with it the same way. 
*/
int main (int argc, char *argv[] ) {
    Stack *s;
    *s = stack_init();
    stack_push(s, H1);
    printf("%d\n", stack_peek(s));
    stack_push(s, H2);
    printf("%d\n", stack_peek(s));
    stack_push(s, H2);
    printf("%d\n", stack_peek(s));
    stack_push(s, H3);
    printf("%d\n", stack_peek(s));
    stack_push(s, H3);
    printf("%d\n", stack_peek(s));
    stack_push(s, H3);
    printf("%d\n", stack_peek(s));
    // printf("%i\n", s->stack_size);
    // printf("%i\n", s->stack_top);

    // for (size_t i = 0; i < s->stack_size; i++)
    // {
    //     printf("%d\n", s->stack_states[i]);
    // }
    

    printf("Popping now\n");
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    
    stack_free(s);
}