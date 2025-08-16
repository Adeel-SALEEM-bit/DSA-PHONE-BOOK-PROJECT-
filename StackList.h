#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class stack {
private:
    node* top;
public:
    stack() : top(nullptr) {}

    bool isempty() { return top == nullptr; }

    void push(const string& name, const string& phone, const string& email, const string& address) {
        node* temp = new node(name, phone, email, address);
        if (isempty()) {
            top = temp;
        }
        else {
            temp->next = top;
            top->pre = temp;
            top = temp;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "Stack is empty, nothing to undo.\n";
            return;
        }
        cout << "Undo operation for: " << top->Name << ", " << top->Phone << ", " << top->Email << ", " << top->Address << "\n";
        node* temp = top;
        top = top->next;
        delete temp;
    }
};
