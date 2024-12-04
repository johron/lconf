#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TK_IDENTIFIER,
    TK_STRING,
    TK_NUMBER,
    TK_OPERATOR,
    TK_PUNCTUATION,
    TK_ERROR,
    TK_EOF,
} TokenType;

typedef struct {
    TokenType type;
    char value[256];
} Token;

Token get_next_token(const char **input);
void lex(const char *input);

#endif // LEXER_H