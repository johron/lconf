#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "../hdr/util.h"
#include "../hdr/lexer.h"

int main() {
    char *code = read_file("test.craig");
    if (!code) {
        return 1;
    }
    lex(code);
    return 0;
}