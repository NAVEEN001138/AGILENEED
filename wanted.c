#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if(top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return -1 for invalid pop
    } else {
        return stack[top--];
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int performOperation(int operand1, int operand2, char operator) {
    switch(operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if(operand2 == 0) {
                printf("Division by zero error\n");           
                exit(1);
            }
            return operand1 / operand2;
        case '^': {
            int result = 1;
            for(int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            return result;
        }
        default: return 0;
    }
}

void postfixEvaluation(char* expression) {
    for(int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if(isdigit(ch)) {
            // Push operand to stack
            push(ch - '0'); // Convert char to int
        } else if(isOperator(ch)) {
            // Pop two operands from stack
            int operand2 = pop();
            int operand1 = pop();

            if(operand1 == -1 || operand2 == -1) {
                printf("Invalid postfix expression\n");
                return;
            }


            int result = performOperation(operand1, operand2, ch);
            push(result);
        } else {
            printf("Invalid character in expression: %c\n", ch);
            return;
        }
    }


    int result = pop();
    if(top != -1) {
        printf("Invalid postfix expression\n");
    } else {
        printf("Result of postfix evaluation: %d\n", result);
    }
}

int main() {
    char expression[SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    postfixEvaluation(expression);
    return 0;
}


