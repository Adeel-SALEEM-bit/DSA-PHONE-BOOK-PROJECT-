#include "Double.h"
#include "StackList.h"
#include "QueueList.h"
#include <iostream>
using namespace std;

int main() {
    Double phonebook;
    stack undoStack;
    queue operationHistory;

    int choice;
    string filename = "contacts.csv";

    do {
        cout << "\n--- Phone Book Menu ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Update Contact\n";
        cout << "6. Save Contacts to File\n";
        cout << "7. Load Contacts from File\n";
        cout << "8. Undo Last Operation\n";
        cout << "9. Display Operation History\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            phonebook.addcontact();
            // You can manually add undoStack.push(...) and operationHistory.insert(...) here as needed for consistent tracking.
            break;
        case 2:
            phonebook.display();
            break;
        case 3:
            phonebook.searchcontact();
            break;
        case 4:
            phonebook.deletecontact();
            break;
        case 5:
            phonebook.updatecontact();
            break;
        case 6:
            phonebook.saveToFile(filename);
            break;
        case 7:
            phonebook.loadFromFile(filename);
            break;
        case 8:
            undoStack.pop();
            break;
        case 9:
            operationHistory.display();
            break;
        case 0:
            cout << "Exiting Phone Book.\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
