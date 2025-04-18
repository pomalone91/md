#include <stdio.h>
#include "element.h"
#include "doc.h"
#include "stack.h"
#include "el_array.h"

int main (int argc, char *argv[] ) {
    char* str = "#This is a markdown string *woohoo*!\nHere is another paragraph\n";

    Doc *d = doc_init(str);

    for (int i = 0; i < d->ec; i++)
    {   
        Element *e = doc_get_first_element(d);
        stack_dump_states(&e->states);
    }
    
}