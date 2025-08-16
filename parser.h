#include "tokenizator.h"


int pos = 0;


Token get_token() {
    return tokens[pos];
}


void eat(TokenType type) {
    if (tokens[pos].type == type) {
        pos++;
    } else {
        printf("Parsing error\n");
        exit(1);
    }
}


int parse_factor();

int parse_term() {
    int result = parse_factor();
    while (get_token().type == TOKEN_MUL || get_token().type == TOKEN_DIV) {
        Token op = get_token();
        eat(op.type);
        int rhs = parse_factor();
        if (op.type == TOKEN_MUL) result *= rhs;
        else result /= rhs;
    }
    return result;
}

int parse_expr() {
    int result = parse_term();
    while (get_token().type == TOKEN_PLUS || get_token().type == TOKEN_MINUS) {
        Token op = get_token();
        eat(op.type);
        int rhs = parse_term();
        if (op.type == TOKEN_PLUS) result += rhs;
        else result -= rhs;
    }
    return result;
}

int parse_factor() {
    Token tok = get_token();
    if (tok.type == TOKEN_NUMBER) {
        eat(TOKEN_NUMBER);
        return tok.value;
    } else if (tok.type == TOKEN_LPAREN) {
        eat(TOKEN_LPAREN);
        int result = parse_expr();
        eat(TOKEN_RPAREN);
        return result;
    }
    printf("Error\n");
    exit(1);
}