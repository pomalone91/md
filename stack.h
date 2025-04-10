// Stack of states to help with parsing

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "element.h"

// Stack struct
typedef struct Stack
{
    int stack_size;       // How much space has been allocated to this stack.
    int stack_top;      // How much has been used.
    State *stack_states;   // Array of states
} Stack;

// Functions
struct Stack stack_init();
void stack_push(Stack *s, State st);
State stack_pop(Stack *s);
State stack_peek(Stack *s);
void stack_free(Stack *s);


#endif /*stack_h*/