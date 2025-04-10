#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "stack.h"

// Initialize a new stack
struct Stack stack_init() {
    struct Stack s;
    s.stack_size = 2;
    s.stack_top = -1;
    s.stack_states = malloc(sizeof(State) * 2);

    return s;
}

void stack_push(struct Stack *s, State st) {
    // Increment the top of the stack
    s->stack_top++;

    // If we're at the top of the stack we need to realloc
    if (s->stack_size == s->stack_top)
    {
        s->stack_size *= 2;
        s->stack_states = realloc(s->stack_states, sizeof(State) * s->stack_size);
    }

    

    // Push onto the top of the stack
    *(s->stack_states + s->stack_top) = st;
}

State stack_pop(struct Stack *s) {
    if (s->stack_top < 0)
    {
        return 9999;
    }
    
    // Get the state at the top of the stack.
    printf("Where is it popping: %i\n", s->stack_top);
    State st = *(s->stack_states + s->stack_top);

    // If the top of the stack is below half of the allocated memory we should reallocate
    if (s->stack_size < (s->stack_top / 2))
    {
        s->stack_size /= 2;
        s->stack_states = realloc(s->stack_states, sizeof(State) * s->stack_size);
    }
    s->stack_top--;

    return st;
}

State stack_peek(Stack *s) {
    State st = *(s->stack_states + s->stack_top);
    return st;
}

void stack_free(struct Stack *s) {
    s->stack_size = 0;
    s->stack_top = 0;
    free(s->stack_states);
}