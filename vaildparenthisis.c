#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given character is an opening parenthesis
bool isOpeningParenthesis(char c) {
    return (c == '(' || c == '[' || c == '{');
}

// Function to check if a given character is a closing parenthesis
bool isClosingParenthesis(char c) {
    return (c == ')' || c == ']' || c == '}');
}

// Function to check if two characters form a valid pair of parentheses
bool isValidPair(char open, char close) {
    if (open == '(' && close == ')')
        return true;
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    return false;
}

// Function to check if a string of parentheses is valid
bool isValidParentheses(const char* str) {
    int n = strlen(str);
    char stack[n];
    int top = -1; // Stack top index

    // Traverse the string
    for (int i = 0; i < n; i++) {
        char current = str[i];

        // If current character is an opening parenthesis, push it onto the stack
        if (isOpeningParenthesis(current)) {
            stack[++top] = current;
        }
        // If current character is a closing parenthesis
        else if (isClosingParenthesis(current)) {
            // If stack is empty or the top element doesn't form a valid pair, return false
            if (top == -1 || !isValidPair(stack[top], current))
                return false;
            top--; // Pop the top element from the stack
        }
    }

    // If stack is empty, all parentheses are valid
    return top == -1;
}

int main() {
    const char* str1 = "(([]))";
    const char* str2 = "({[})";
    const char* str3 = "()[]{}";
    
    printf("%s: %s\n", str1, isValidParentheses(str1) ? "Valid" : "Invalid");
    printf("%s: %s\n", str2, isValidParentheses(str2) ? "Valid" : "Invalid");
    printf("%s: %s\n", str3, isValidParentheses(str3) ? "Valid" : "Invalid");
    
    return 0;
}
