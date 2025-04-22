#include <stdio.h>
#include "element.h"
// #include "doc.h"
#include "stack.h"
#include "element_list.h"

int main (int argc, char *argv[] ) {
    // char* str = "#This is a markdown string *woohoo*!\nHere is another paragraph\0";

    // Doc *d = doc_init(str);

    // for (int i = 0; i < d->ec; i++)
    // {   
    //     Element *e = doc_get_first_element(d);
    //     stack_dump_states(&e->states);
    // }

    Stack *s = stack_init();
    stack_push(s, P);
    stack_push(s, H1);

    // s->dump_states(s);

    char* str = "This is a string";
    Element *e1 = element_init(str, strlen(str), s);

    stack_push(s, BOLD);

    char* str2 = "Another string";
    Element *e2 = element_init(str, strlen(str2), s);

    // element_dump(e1);
    // element_dump(e2);

    ElementList *el = element_list_init();
    element_list_append(el, *e1);
    element_list_append(el, *e2);

    element_list_dump(el);

    stack_free(s);
    element_free(e1);
    element_free(e2);
    element_list_free(el);
}