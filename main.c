#include "doc.h"
#include "element_list.h"

int main (int argc, char *argv[] ) {
    char* str = "#Paragraph 1!\nParagraph 2\0";

    Doc *d = doc_init(str);
    
    element_list_dump(d->element_list);

    //Stack *s = stack_init();
    //stack_push(s, P);
    //stack_push(s, H1);

    //// s->dump_states(s);

    //char* str = "E1";
    //Element *e1 = element_init_with_components(str, strlen(str), s);

    //stack_push(s, BOLD);

    //char* str2 = "E2";
    //Element *e2 = element_init_with_components(str2, strlen(str2), s);

    //// element_dump(e1);
    //// element_dump(e2);

    //ElementList *el = element_list_init();
    //element_list_append(el, *e1);
    //element_list_append(el, *e2);

    //element_list_dump(el);

    //stack_free(s);
    //element_free(e1);
    //element_free(e2);
    //element_list_free(el);
}
