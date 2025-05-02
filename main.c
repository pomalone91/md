#include "doc.h"
#include "element_list.h"

int main (int argc, char *argv[] ) {
    char* str = "#Paragraph 1!\nParagraph 2\n#And yet another paragraph! The third one, even! Wow!\0";

    Doc *d = doc_init(str);
    
    element_list_dump(d->element_list);
    doc_free(d);
/**********************************************************/
    //Stack *s = stack_init();
    //stack_push(s, P);
    //stack_push(s, H1);

    //// s->dump_states(s);

    //char* str = "E1";
    //Element *e1 = element_init_with_components(str, strlen(str), s);

    //stack_push(s, BOLD);

    //char* str2 = "E2";
    //Element *e2 = element_init_with_components(str2, strlen(str2), s);

    //char* str3 = "E3";
    //Element *e3 = element_init_with_components(str3, strlen(str3), s);

    //char* str4 = "E4";
    //Element *e4 = element_init_with_components(str3, strlen(str3), s);

    //char* str5 = "E5";
    //Element *e5 = element_init_with_components(str3, strlen(str3), s);

    //char* str6 = "E6";
    //Element *e6 = element_init_with_components(str3, strlen(str3), s);

    //// element_dump(e1);
    //// element_dump(e2);

    //ElementList *el = element_list_init();
    //element_list_append(el, *e1);
    //element_list_append(el, *e2);
    //element_list_append(el, *e3);
    //element_list_append(el, *e4);
    //element_list_append(el, *e5);
    //element_list_append(el, *e6);

    //element_list_dump(el);

    //stack_free(s);
    //element_free(e1);
    //element_free(e2);
    //element_free(e3);
    //element_free(e4);
    //element_free(e5);
    //element_free(e6);
    //element_list_free(el);
/**********************************************************/
    // Stack *s = stack_init();
    // stack_push(s, BOLD);
    // char *str = "test string";
    // Element *e = element_init_with_components(str, strlen(str), s);

    // element_dump(e);

    // e = realloc(e, sizeof(Element) * 2);


    // stack_push(s, URL);
    // char *str2 = "test string 2";
    // *(e + 1) = *element_init_with_components(str2, strlen(str2), s);

    // element_dump(e + 1);

    // stack_free(s);
    // element_free(e);

    return 0;
}
