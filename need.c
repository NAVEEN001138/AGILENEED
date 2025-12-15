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

#hHHADSFLKHAJ,SDHJFKALSJDGFJASDF
