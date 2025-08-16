#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class queue {
private:
    node* front;
    node* rear;
public:
    queue() : front(nullptr), rear(nullptr) {}

    void insert(const string& name, const string& phone, const string& email, const string& address) {
        node* temp = new node(name, phone, email, address);
        if (!front && !rear) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            temp->pre = rear;
            rear = temp;
        }
    }

    void display() {
        if (!front) {
            cout << "No operations in history.\n";
            return;
        }
        node* curr = front;
        cout << "\n--- Operation History ---\n";
        while (curr) {
            cout << "Operation on: " << curr->Name << ", " << curr->Phone << ", " << curr->Email << ", " << curr->Address << "\n";
            curr = curr->next;
        }
    }
};
