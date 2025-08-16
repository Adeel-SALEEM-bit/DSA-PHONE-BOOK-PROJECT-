#pragma once
#include <string>
using namespace std;

class node {
public:
    string Name;
    string Phone;
    string Email;
    string Address;
    node* pre;
    node* next;

    node() : Name(""), Phone(""), Email(""), Address(""), pre(nullptr), next(nullptr) {}
    node(const string& Name, const string& Phone, const string& Email, const string& Address)
        : Name(Name), Phone(Phone), Email(Email), Address(Address), pre(nullptr), next(nullptr) {
    }
    ~node() = default;
};
