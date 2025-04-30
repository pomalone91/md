#include <stdlib.h>
#include "element_list.h"
#include "element.h"

// Initialize a new array
struct ElementList* element_list_init() {
    ElementList *el = malloc(sizeof(ElementList));
    el->size = 1;
    el->count = 0;
    //el->element = malloc(sizeof(Element) * 2);
    el->element = element_init();
    return el;
}

// Append a new element to array
void element_list_append(struct ElementList* self, Element e) {
    // If count is same as size we need to double the allocated memory.
    if (self->count == self->size)
    {
        self->size *= 2;
        int temp_size = self->size;
        size_t allocation_size = sizeof(Element) * temp_size;
        Element *realloced_element = realloc(self->element, 4096);
        self->element = realloced_element;
    }

    // Append to the end of the array
    (self->element + self->count)->str = malloc(sizeof(char));
    strcpy((self->element + self->count)->str, e.str);
    if ((self->element + self->count)->states == NULL) 
        (self->element + self->count)->states = realloc((self->element + self->count)->states, sizeof(Stack));
    (self->element + self->count)->states = stack_init();

    // Copy the stack
    for (int i = 0; i <= e.states->top; i++)
    {
        stack_push((self->element + self->count)->states, *(e.states->states + i));
    }

    self->count++;
}

void element_list_dump(const struct ElementList* self) {
    for (int i = 0; i < self->count; i++)
    {
        element_dump(self->element + i);
    }
}

void element_list_free(struct ElementList* self) {
    if (self->element)
    {
        element_free(self->element);
        self->element = NULL;
    }
    self->count = 0;
    self->size = 0;
    free(self);
    self = NULL;
}
