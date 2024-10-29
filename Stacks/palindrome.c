#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int top = -1;
char arr[SIZE];

// Function to push an element onto the stack
void push(char data) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top = top + 1;
        arr[top] = data;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        char temp = arr[top];
        top = top - 1;
        return temp;
    }
}

// Function to check if a given string is a palindrome
int isPalindrome(char str[]) {
    int i, len = strlen(str);
    
    // Push all characters of the string onto the stack
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop characters from stack and compare with the original string
    for (i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // String is a palindrome
}

// Main function
int main() {
    char str[SIZE];

    printf("Enter the string: ");
    scanf("%s", str);

    // Check if the entered string is a palindrome
    if (isPalindrome(str)) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }

    return 0;
}
