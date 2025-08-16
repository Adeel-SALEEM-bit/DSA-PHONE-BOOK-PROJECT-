//#include <iostream>
//#include <fstream>
//#include <string>
//#include <stack>
//using namespace std;
//
//struct Contact {
//    string name;
//    string phone;
//    string email;
//    Contact* prev;
//    Contact* next;
//};
//
//Contact* head = nullptr;
//stack<Contact*> undoStack;
//stack<Contact*> redoStack;
//
//Contact* createContact(string name, string phone, string email) {
//    Contact* newContact = new Contact{ name, phone, email, nullptr, nullptr };
//    return newContact;
//}
//
//void addContact(string name, string phone, string email) {
//    Contact* newContact = createContact(name, phone, email);
//    newContact->next = head;
//    if (head != nullptr) head->prev = newContact;
//    head = newContact;
//    undoStack.push(newContact);
//    cout << "Contact added successfully.\n";
//}
//
//void displayContacts() {
//    if (!head) {
//        cout << "No contacts to display.\n";
//        return;
//    }
//    Contact* temp = head;
//    cout << "\n--- Contact List ---\n";
//    while (temp) {
//        cout << "Name: " << temp->name << ", Phone: " << temp->phone << ", Email: " << temp->email << "\n";
//        temp = temp->next;
//    }
//    cout << "--------------------\n";
//}
//
//Contact* searchContact(string key) {
//    Contact* temp = head;
//    while (temp) {
//        if (temp->name == key || temp->phone == key) return temp;
//        temp = temp->next;
//    }
//    return nullptr;
//}
//
//void deleteContact(string key) {
//    Contact* toDelete = searchContact(key);
//    if (!toDelete) {
//        cout << "Contact not found.\n";
//        return;
//    }
//    if (toDelete->prev) toDelete->prev->next = toDelete->next;
//    else head = toDelete->next;
//    if (toDelete->next) toDelete->next->prev = toDelete->prev;
//    undoStack.push(toDelete);
//    cout << "Contact deleted (pushed to undo stack).\n";
//}
//
//void updateContact(string key, string newPhone, string newEmail) {
//    Contact* toUpdate = searchContact(key);
//    if (!toUpdate) {
//        cout << "Contact not found.\n";
//        return;
//    }
//    toUpdate->phone = newPhone;
//    toUpdate->email = newEmail;
//    undoStack.push(toUpdate);
//    cout << "Contact updated and pushed to undo stack.\n";
//}
//
//void undoLastAction() {
//    if (undoStack.empty()) {
//        cout << "Nothing to undo.\n";
//        return;
//    }
//    Contact* lastAction = undoStack.top();
//    undoStack.pop();
//    redoStack.push(lastAction);
//    cout << "Last action undone (pushed to redo stack).\n";
//}
//
//void redoLastAction() {
//    if (redoStack.empty()) {
//        cout << "Nothing to redo.\n";
//        return;
//    }
//    Contact* lastRedo = redoStack.top();
//    redoStack.pop();
//    undoStack.push(lastRedo);
//    cout << "Last undone action redone.\n";
//}
//
//void saveContactsToFile(string filename) {
//    ofstream file(filename);
//    if (!file) {
//        cout << "Error opening file for writing.\n";
//        return;
//    }
//    Contact* temp = head;
//    while (temp) {
//        file << temp->name << "," << temp->phone << "," << temp->email << "\n";
//        temp = temp->next;
//    }
//    file.close();
//    cout << "Contacts saved to file.\n";
//}
//
//void loadContactsFromFile(string filename) {
//    ifstream file(filename);
//    if (!file) {
//        cout << "Error opening file for reading.\n";
//        return;
//    }
//    string line, name, phone, email;
//    while (getline(file, line)) {
//        size_t pos1 = line.find(',');
//        size_t pos2 = line.find_last_of(',');
//        if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
//            name = line.substr(0, pos1);
//            phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
//            email = line.substr(pos2 + 1);
//            addContact(name, phone, email);
//        }
//    }
//    file.close();
//    cout << "Contacts loaded from file.\n";
//}
//
//int main() {
//    int choice;
//    string name, phone, email, key, filename;
//    do {
//        cout << "\n--- Phone Book Menu ---\n";
//        cout << "1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n5. Update Contact\n6. Undo\n7. Redo\n8. Save Contacts to File\n9. Load Contacts from File\n0. Exit\nEnter your choice: ";
//        cin >> choice;
//        cin.ignore();
//        switch (choice) {
//        case 1:
//            cout << "Enter Name: "; getline(cin, name);
//            cout << "Enter Phone: "; getline(cin, phone);
//            cout << "Enter Email: "; getline(cin, email);
//            addContact(name, phone, email);
//            break;
//        case 2:
//            displayContacts();
//            break;
//        case 3:
//            cout << "Enter name or phone to search: "; getline(cin, key);
//            if (Contact* found = searchContact(key))
//                cout << "Found: " << found->name << ", " << found->phone << ", " << found->email << "\n";
//            else
//                cout << "Contact not found.\n";
//            break;
//        case 4:
//            cout << "Enter name or phone to delete: "; getline(cin, key);
//            deleteContact(key);
//            break;
//        case 5:
//            cout << "Enter name or phone to update: "; getline(cin, key);
//            cout << "Enter new phone: "; getline(cin, phone);
//            cout << "Enter new email: "; getline(cin, email);
//            updateContact(key, phone, email);
//            break;
//        case 6:
//            undoLastAction();
//            break;
//        case 7:
//            redoLastAction();
//            break;
//        case 8:
//            cout << "Enter filename to save: "; getline(cin, filename);
//            saveContactsToFile(filename);
//            break;
//        case 9:
//            cout << "Enter filename to load: "; getline(cin, filename);
//            loadContactsFromFile(filename);
//            break;
//        case 0:
//            cout << "Exiting...\n";
//            break;
//        default:
//            cout << "Invalid choice. Try again.\n";
//        }
//    } while (choice != 0);
//    return 0;
//}
