#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main() {
    char expr[100];
    
    printf("write: ");
    fgets(expr, sizeof(expr), stdin);

    
    tokenize(expr);   
    pos = 0;          
    int result = parse_expr();  
    printf("Result: %d\n", result);

    
    return 0;
}


