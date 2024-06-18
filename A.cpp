#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAXIMUM_SIZE 100

class Stack {
private:
    int* arr;
    int top;
public:
    Stack() {
        arr = NULL;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int a) {
        if (top == -1) {
            arr = new int[MAXIMUM_SIZE];
        }
        top += 1;
        arr[top] = a;
    }
    int pop() {
        int oprand = arr[top--];
        return oprand;
    }
    bool enough_operands() {
        if (top < 1) return false;
        else return true;
    }
    bool push_peek() {
        if (top == MAXIMUM_SIZE - 1) return false;
        else return true;
    }
    int is_operator(int a, int b, char* c) {
        switch (*c) {
            case '+':
                return b + a;
            case '-':
                return b - a;
            case '*':
                return b * a;
            case '/':
                if (a == 0) break;
                return b / a;
            default:
                return 0; // Handle any invalid operators
        }
    }
    void printer() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack stacky;
    char c;
    while (std::cin.get(c)) {
        int num = 0;
        if (std::isdigit(c)) {
            while (std::isdigit(c)) {
                num = num * 10 + c - '0';
                std::cin.get(c);
            }
            std::cin.unget();
            if (stacky.push_peek()) stacky.push(num);
            else return -1;
        } else if (strchr("+-*/", c) != NULL) {
            if (!stacky.enough_operands()) {
                return -1;
            }
            int op1 = stacky.pop();
            int op2 = stacky.pop();
            char op = c;
            int result = stacky.is_operator(op1, op2, &c);
            if (stacky.push_peek()) stacky.push(result);
        }
    }
    stacky.printer();
    return 0;
}

