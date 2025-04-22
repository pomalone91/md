#include <stdlib.h>
#include "element_list.h"
#include "element.h"

// Initialize a new array
struct ElementList* element_list_init() {
    ElementList *el = malloc(sizeof(ElementList));
    el->size = 2;
    el->count = 0;
    el->element = malloc(sizeof(ElementList) * 2);
    return el;
}

// Appcount a new element to array
void element_list_append(struct ElementList* self, Element e) {
    // If count is same as size we need to double the allocated memory.
    if (self->count == self->size)
    {
        self->size *= 2;
        self->element = realloc(self->element, sizeof(Element) * self->size);
    }

    // Appcount to the count of the array
    *(self->element + self->count) = e;
    self->count++;
}

void element_list_dump(const struct ElementList* self) {
    for (int i = 0; i < self->count; i++)
    {
        element_dump(self->element + i);
    }
}

void element_list_free(struct ElementList* self) {
    if (self->element != NULL)
    {
        element_free(self->element);
    }
    self->count = 0;
    self->size = 0;
    free(self);
}