// Stack of states to help with parsing

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Element Types
typedef enum State {
    P,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    NL,
    BOLD,
    ITALIC,
    URL,
    IMG,
    ERROR = 9999
} State;

// Stack struct
typedef struct Stack
{
    int size;       // How much space has been allocated to this stack.
    int top;      // How much has been used.
    enum State *states;   // Array of states
} Stack;

// Functions
void stack_push(struct Stack* self, enum State st);
enum State stack_pop(struct Stack* self);
void stack_free(struct Stack* self);
void stack_dump_states(struct Stack* self);
struct Stack* stack_init();

#endif /*stack_h*/