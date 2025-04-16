#include <stdio.h>
#include "element.h"
#include "doc.h"
#include "stack.h"

int main (int argc, char *argv[] ) {
    char* str = "#This is a markdown string *woohoo*!\nHere is another paragraph\n";

    Doc *d = doc_init(str);
}