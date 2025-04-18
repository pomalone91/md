#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "stack.h"

// Initialize a new stack
struct Stack stack_init() {
    struct Stack s = {2, -1, malloc(sizeof(State) * 2)};
    // s.stack_size = 2;
    // s.stack_top = -1;
    // s.stack_states = malloc(sizeof(State) * 2);

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

    // Free each state in array
    for (size_t i = 0; i < s->stack_size; i++)
    {
        free(s->stack_states + i);
    }
    
    // Free the pointer to the array
    free(s->stack_states);
}

void stack_dump_states(Stack *s) {
    for (int i = 0; i < s->stack_top; i++)
    {
        State st = *(s->stack_states+i);
        printf("%d\n", st);
    }
}