#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"
#include <string.h>
// ((A*(B+D)/E)-F*(G+H/K))) -- 24

char* infix_to_postfix(int length, char *expression)
{
    char *postfix = malloc((length + 1)* sizeof(char));
    postfix[length] = '\0';
    int index = 0;

    int is_operator(char item) {
        if (item == '+' || item == '-' || item == '*' || item == '/' || item == '^') {
            return 1;
        } else {
            return 0;
        }
    }

    int precedence(char operator) {
        if (is_operator(operator) == 0) {
            return -1;
        } else {
            switch (operator) {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                case '^':
                    return 3;

                default:
                    return -1;
                
            }
        }
    }

    struct Stack *o_stack = create_stack(length);

    for(int i = 0; i < length; i++) {
        if (is_operator(expression[i]) == 0 && expression[i] != '(' && expression[i] != ')') {
            postfix[index++] = expression[i];
        } else if (is_empty(o_stack) == 1) {
            push(o_stack, expression[i]);
        } else if (expression[i] == '(') {
            push(o_stack, expression[i]);
        } else if (expression[i] == ')') {
            while (top(o_stack) != '(') {
                postfix[index++] = pop(o_stack);
            }
            pop(o_stack);
        } else if (is_operator(expression[i]) == 1) {
            if (is_empty(o_stack) == 1 || precedence(top(o_stack)) < precedence(expression[i])) {
                push(o_stack, expression[i]);
            } else if (precedence(top(o_stack)) > precedence(expression[i])) {
                while (top(o_stack) != '(' && is_empty(o_stack) == 0 && precedence(top(o_stack)) > precedence(expression[i])) {
                    postfix[index++] = pop(o_stack);
                }
            } else if (precedence(top(o_stack)) == precedence(expression[i]) && expression[i] == '^') {
                push(o_stack, expression[i]);
            } else {
                postfix[index++] = pop(o_stack);
                push(o_stack, expression[i]);
            }
        }
    }

    while (is_empty(o_stack) == 0) {
        postfix[index++] = pop(o_stack);
    }

    free_stack(o_stack);
    return postfix;

}

char* infix_to_prefix(int length, char *expression)
{
    int i,j;

    char *rev_exp = malloc((length + 1) * sizeof(char));
    rev_exp[length] = '\0';
    for (i = length - 1; i > -1; i--) {
        rev_exp[length -i - 1] = expression[i]; 
    }

    for (j = 0; j < length; j++) {
        if (rev_exp[j] == '(') {
            rev_exp[j] = ')';
        } else if (rev_exp[j] == ')') {
            rev_exp[j] = '(';
        }
    }

    char *rev_prefix = infix_to_postfix(length, rev_exp);

    char *prefix = malloc((length + 1) * sizeof(char));
    for (i = length - 1; i > -1; i--) {
        prefix[length - i - 1] = rev_prefix[i]; 
    }

    free(rev_prefix);
    free(rev_exp);

    return prefix;
}

int main() {

    int length;
    printf("Enter length: ");
    scanf("%d", &length);

    char *expression_string = malloc(sizeof(char) * (length + 1));
    printf("Enter expression: ");
    scanf("\n");
    scanf("%[^\n]%*c", expression_string);
    char *result = infix_to_prefix(length, expression_string);
    for (int i = 0; i < length; i++) {
        printf("%c", result[i]);
    }

    free(result);
    free(expression_string);
 
    return 0;
}
