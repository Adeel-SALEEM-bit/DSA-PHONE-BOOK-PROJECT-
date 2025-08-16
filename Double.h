#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

class Double {
private:
    node* head;

    string trim(const string& s) {
        size_t b = s.find_first_not_of(" \t\r\n");
        if (b == string::npos) return "";
        size_t e = s.find_last_not_of(" \t\r\n");
        return s.substr(b, e - b + 1);
    }

    bool isValidPakPhone(const string& sRaw) {
        string s = trim(sRaw);
        static const regex re(R"(^(?:\+92|0)3\d{9}$)");
        return regex_match(s, re);
    }

    bool isValidEmail(const string& sRaw) {
        string s = trim(sRaw);
        static const regex re(R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)");
        return regex_match(s, re);
    }

    string promptNonEmpty(const char* label) {
        string v;
        while (true) {
            cout << label;
            getline(cin, v);
            v = trim(v);
            if (!v.empty()) return v;
            cout << "Value cannot be empty. Please try again.\n";
        }
    }

    string promptPakPhone() {
        string v;
        while (true) {
            cout << "Enter Phone (+923XXXXXXXXX or 03XXXXXXXXX): ";
            getline(cin, v);
            v = trim(v);
            if (isValidPakPhone(v)) return v;
            cout << "Invalid Pakistani phone number format. Try again.\n";
        }
    }

    string promptEmail() {
        string v;
        while (true) {
            cout << "Enter Email: ";
            getline(cin, v);
            v = trim(v);
            if (isValidEmail(v)) return v;
            cout << "Invalid email. Example: user@example.com\n";
        }
    }

    void clearList() {
        node* curr = head;
        while (curr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }

public:
    Double() : head(nullptr) {}
    ~Double() { clearList(); }

    void addcontact() {
        string name = promptNonEmpty("Enter Name: ");
        string phone = promptPakPhone();
        string email = promptEmail();
        string address = promptNonEmpty("Enter Address: ");
        node* temp = new node(name, phone, email, address);
        if (!head) head = temp;
        else {
            temp->next = head;
            head->pre = temp;
            head = temp;
        }
        cout << "Contact added successfully.\n";
    }

    void display() {
        if (!head) {
            cout << "No contacts to display.\n";
            return;
        }
        node* curr = head;
        cout << "\n--- Contact List ---\n";
        while (curr) {
            cout << "Name: " << curr->Name << ", Phone: " << curr->Phone
                << ", Email: " << curr->Email << ", Address: " << curr->Address << "\n";
            curr = curr->next;
        }
    }

    void searchcontact() {
        string key;
        cout << "Enter name or phone to search: ";
        getline(cin, key);
        key = trim(key);
        node* curr = head;
        while (curr) {
            if (curr->Name == key || curr->Phone == key) {
                cout << "Found: " << curr->Name << ", " << curr->Phone
                    << ", " << curr->Email << ", " << curr->Address << "\n";
                return;
            }
            curr = curr->next;
        }
        cout << "Contact not found.\n";
    }

    void deletecontact() {
        string key;
        cout << "Enter name or phone to delete: ";
        getline(cin, key);
        key = trim(key);
        node* curr = head;
        while (curr) {
            if (curr->Name == key || curr->Phone == key) {
                if (curr->pre) curr->pre->next = curr->next;
                else head = curr->next;
                if (curr->next) curr->next->pre = curr->pre;
                cout << "Deleted: " << curr->Name << ", " << curr->Phone
                    << ", " << curr->Email << ", " << curr->Address << "\n";
                delete curr;
                return;
            }
            curr = curr->next;
        }
        cout << "Contact not found.\n";
    }

    void updatecontact() {
        string key;
        cout << "Enter name or phone to update: ";
        getline(cin, key);
        key = trim(key);
        node* curr = head;
        while (curr) {
            if (curr->Name == key || curr->Phone == key) {
                cout << "Updating: " << curr->Name << " (" << curr->Phone << ")\n";
                cout << "Leave blank to keep current.\n";
                while (true) {
                    cout << "New Phone [" << curr->Phone << "]: ";
                    string p; getline(cin, p);
                    p = trim(p);
                    if (p.empty()) break;
                    if (isValidPakPhone(p)) { curr->Phone = p; break; }
                    cout << "Invalid Pakistani phone number. Try again.\n";
                }
                while (true) {
                    cout << "New Email [" << curr->Email << "]: ";
                    string e; getline(cin, e);
                    e = trim(e);
                    if (e.empty()) break;
                    if (isValidEmail(e)) { curr->Email = e; break; }
                    cout << "Invalid email. Try again.\n";
                }
                cout << "New Address [" << curr->Address << "]: ";
                string a; getline(cin, a);
                a = trim(a);
                if (!a.empty()) curr->Address = a;
                cout << "New Name [" << curr->Name << "]: ";
                string n; getline(cin, n);
                n = trim(n);
                if (!n.empty()) curr->Name = n;
                cout << "Contact updated successfully.\n";
                return;
            }
            curr = curr->next;
        }
        cout << "Contact not found.\n";
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for saving.\n";
            return;
        }
        node* curr = head;
        while (curr) {
            file << curr->Name << "," << curr->Phone << ","
                << curr->Email << "," << curr->Address << "\n";
            curr = curr->next;
        }
        cout << "Contacts saved to file successfully.\n";
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for loading.\n";
            return;
        }
        clearList();
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone, email, address;
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            getline(ss, address);
            node* temp = new node(name, phone, email, address);
            if (!head) head = temp;
            else {
                temp->next = head;
                head->pre = temp;
                head = temp;
            }
        }
        cout << "Contacts loaded from file successfully.\n";
    }
};
