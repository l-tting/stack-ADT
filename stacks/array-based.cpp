#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the stack

class Stack {
private:
    int arr[MAX]; // Array to store stack elements
    int top;      // To keep track of the top element

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1; // Stack is initially empty
    }

    // Push operation to add an element to the stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << element << endl;
        } else {
            top++;          // Increment the top index
            arr[top] = element; // Add element to the top
            cout << "Pushed: " << element << endl;
        }
    }

    // Pop operation to remove an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << "Popped: " << arr[top] << endl;
            top--; // Decrement the top index
        }
    }

    // Peek operation to view the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Return a dummy value
        } else {
            return arr[top]; // Return the top element
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX - 1;
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack stack; // Create a stack object

    // Perform push operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    // Try to push into a full stack
    stack.push(60);

    // Peek at the top element
    cout << "Top element is: " << stack.peek() << endl;

    // Perform pop operations
    stack.pop();
    stack.pop();
    stack.pop();

    // Peek again after popping
    cout << "Top element after popping is: " << stack.peek() << endl;

    // Try to pop from an empty stack
    stack.pop();
    stack.pop();
    stack.pop(); // This should display "Stack Underflow"
    
    return 0;
}

