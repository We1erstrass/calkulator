#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define MAX_TOKENS 100

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPAREN,  // (
    TOKEN_RPAREN,  // )
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    int value;  
} Token;


Token tokens[MAX_TOKENS];
int token_count = 0;

void tokenize(const char *expr) {
    token_count = 0;
    while (*expr) {
        if (isspace(*expr)) {
            expr++;
            continue;
        }
        if (isdigit(*expr)) {
            int val = 0;
            while (isdigit(*expr)) {
                val = val * 10 + (*expr - '0');
                expr++;
            }
            tokens[token_count++] = (Token){TOKEN_NUMBER, val};
            continue;
        }
        switch (*expr) {
            case '+': tokens[token_count++] = (Token){TOKEN_PLUS, 0}; break;
            case '-': tokens[token_count++] = (Token){TOKEN_MINUS, 0}; break;
            case '*': tokens[token_count++] = (Token){TOKEN_MUL, 0}; break;
            case '/': tokens[token_count++] = (Token){TOKEN_DIV, 0}; break;
            case '(': tokens[token_count++] = (Token){TOKEN_LPAREN, 0}; break;
            case ')': tokens[token_count++] = (Token){TOKEN_RPAREN, 0}; break;
            default:
                printf("Error '%c'\n", *expr);
                exit(1);
        }
        expr++;
    }
    tokens[token_count++] = (Token){TOKEN_END, 0}; 
}
