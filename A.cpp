#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Define the maximum size of the stack
#define MAXIMUM_SIZE 100

class Stack {
private:
    int* arr; // Pointer to dynamically allocated array to store stack elements
    int top;  // Index of the top element in the stack

public:
    Stack() {
        arr = NULL; // Initially set the array pointer to NULL
        top = -1;   // Initially set top to -1 (empty stack)
    }

    ~Stack() {
        delete[] arr; // Deallocate the dynamically allocated array
    }

    void push(int a) {
        // If the stack is empty, allocate memory for the array
        if (top == -1) {
            arr = new int[MAXIMUM_SIZE];
        }
        // Increment top and store the element at the new top position
        top += 1;
        arr[top] = a;
    }

    int pop() {
        // Store the top element and decrement top
        int oprand = arr[top--];
        return oprand; // Return the popped element
    }

    bool enough_operands() {
        // Check if there are at least two operands on the stack
        if (top < 1) return false;
        else return true;
    }

    bool push_peek() {
        // Check if the stack has space to push a new element
        if (top == MAXIMUM_SIZE - 1) return false;
        else return true;
    }

    int is_operator(int a, int b, char* c) {
        // Perform the arithmetic operation based on the operator
        switch (*c) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            // Handle division by zero
            if (a == 0) break;
            return b / a;
        default:
            break; // Handle any invalid operators
        }
        return 0;
    }

    void printer() {
        // Print all elements in the stack
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack stacky; // Create an instance of the Stack class
    char c;

    // Read characters from input until the end of file
    while (std::cin.get(c)) {
        int num = 0;

        // If the character is a digit
        if (std::isdigit(c)) {
            // Read consecutive digits and construct the integer
            while (std::isdigit(c)) {
                num = num * 10 + c - '0';
                std::cin.get(c);
            }
            std::cin.unget(); // Put the last non-digit character back into the input stream

            // Push the integer onto the stack if there is space
            if (stacky.push_peek()) stacky.push(num);
            else return -1; // Return -1 if the stack is full
        }
        // If the character is an arithmetic operator
        else if (strchr("+-*/", c) != NULL) {
            // Check if there are enough operands on the stack
            if (!stacky.enough_operands()) {
                return -1; // Return -1 if there are not enough operands
            }

            // Pop two operands from the stack
            int op1 = stacky.pop();
            int op2 = stacky.pop();
            char op = c; // Store the operator

            // Perform the arithmetic operation
            int result = stacky.is_operator(op1, op2, &op);

            // Push the result onto the stack if there is space
            if (stacky.push_peek()) stacky.push(result);
        }
    }

    // Print all elements in the stack
    stacky.printer();

    return 0;
}