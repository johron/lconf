#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../hdr/lexer.h"

Token get_next_token(const char **input) {
    const char *cur = *input;

    while (isspace(*cur)) cur++;

    if (*cur == '\0') {
        *input = cur;
        return (Token){TK_EOF, ""};
    }

    Token token;

    if (*cur == '"') {
        cur++;
        char buffer[256];
        int length = 0;

        while (*cur && *cur != '"') {
            buffer[length++] = *cur++;
        }

        if (*cur == '"') {
            cur++;
            buffer[length] = '\0';
            token.type = TK_STRING;
            strcpy(token.value, buffer);
        } else {
            token.type = TK_ERROR;
            strcpy(token.value, "Unterminated string literal");
        }
    } else if (isalpha(*cur)) {
        char buffer[256];
        int length = 0;

        while (isalnum(*cur) || *cur == '_') {
            buffer[length++] = *cur++;
        }
        buffer[length] = '\0';

        token.type = TK_IDENTIFIER;
        strcpy(token.value, buffer);
    } else if (isdigit(*cur)) {
        char buffer[256];
        int length = 0;

        while (isdigit(*cur)) {
            buffer[length++] = *cur++;
        }
        buffer[length] = '\0';

        token.type = TK_NUMBER;
        strcpy(token.value, buffer);
    } else if (*cur == '=') {
        token.type = TK_OPERATOR;
        token.value[0] = *cur++;
        token.value[1] = '\0';
    } else if (*cur == ',' || *cur == '[' || *cur == ']' || *cur == '{' || *cur == '}') {
        token.type = TK_PUNCTUATION;
        token.value[0] = *cur++;
        token.value[1] = '\0';
    } else {
        token.type = TK_ERROR;
        token.value[0] = *cur++;
        token.value[1] = '\0';
    }

    *input = cur;
    return token;
}

void lex(const char *input) {
    while (*input) {
        Token token = get_next_token(&input);
        if (token.type == TK_EOF) break;
        if (token.type == TK_ERROR) {
            printf("Error: value='%s'\n", token.value);
            break;
        } else {
            printf("Token: type=%d, value='%s'\n", token.type, token.value);
        }
    }
}