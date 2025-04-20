// Stack of states to help with parsing

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "element.h"
#include "el_array.h"

// Stack struct
typedef struct Stack
{
    int stack_size;       // How much space has been allocated to this stack.
    int stack_top;      // How much has been used.
    enum State *stack_states;   // Array of states
} Stack;

// Functions
struct Stack* stack_init();
void stack_push(Stack *s, enum State st);
enum State stack_pop(Stack *s);
enum State stack_peek(Stack *s);
void stack_free(Stack *s);
void stack_dump_states(Stack *s);

#endif /*stack_h*/