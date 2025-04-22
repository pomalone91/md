#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Initialize a new stack
struct Stack* stack_init() {
    struct Stack *s = malloc(sizeof(Stack));
    s->size = 2;
    s->top = -1;
    s->states = malloc(sizeof(State) * 2);

    return s;
}

void stack_push(struct Stack* self, State st) {
    // Increment the top of the stack
    self->top++;

    // If we're at the top of the stack we need to realloc
    if (self->size == self->top)
    {
        self->size *= 2;
        self->states = realloc(self->states, sizeof(State) * self->size);
    }

    

    // Push onto the top of the stack
    *(self->states + self->top) = st;
}

State stack_pop(struct Stack* self) {
    if (self->top < 0)
    {
        return 9999;
    }
    
    // Get the state at the top of the stack.
    State st = *(self->states + self->top);

    // If the top of the stack is below half of the allocated memory we should reallocate
    if (self->size < (self->top / 2))
    {
        self->size /= 2;
        self->states = realloc(self->states, sizeof(State) * self->size);
    }
    self->top--;

    return st;
}

State stack_peek(struct Stack* self) {
    State st = *(self->states + self->top);
    return st;
}

void stack_free(struct Stack* self) {
    self->size = 0;
    self->top = 0;

    // Free each state in array
    for (size_t i = 0; i < self->size; i++)
    {
        free(self->states + i);
    }
    
    // Free the pointer to the array
    free(self->states);
}

void stack_dump_states(Stack* self) {
    for (int i = 0; i <= self->top; i++)
    {
        State st = *(self->states+i);
        printf("%d\n", st);
    }
}



