#include <iostream>
using namespace std;

// Define the structure of a node in the linked list
struct Node {
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node
};

// Step 2: Define the Stack Class
// The Stack class contains the necessary functions to implement the stack
// operations using a linked list.
class Stack {
private:
    Node* top; // Pointer to the top node in the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr; // Initially, the stack is empty
    }

    // Push operation to add an element to the stack
    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Assign the value
        newNode->next = top;        // New node points to the previous top
        top = newNode;              // The new node is now the top
        cout << "Pushed: " << value << endl;
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            Node* temp = top;           // Store the current top
            cout << "Popped: " << top->data << endl;
            top = top->next;            // Move top to the next node
            delete temp;                // Free memory of the old top node
        }
    }

    // Peek operation to view the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return top->data;           // Return the data at the top node
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Step 3: Demonstrating Stack Operations
int main() {
    Stack stack; // Create a stack object

    // Perform push operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Peek at the top element
    cout << "Top element is: " << stack.peek() << endl;

    // Perform pop operations
    stack.pop();
    stack.pop();

    // Peek again after popping
    cout << "Top element after popping is: " << stack.peek() << endl;

    // Check if the stack is empty
    stack.pop();
    if (stack.isEmpty()) {
        cout << "Stack is now empty." << endl;
    }

    // Try to pop from an empty stack
    stack.pop(); // This should display "Stack Underflow"

    return 0;
}

