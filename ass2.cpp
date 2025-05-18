#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Address {
    string name;
    string phone;
    string email;
};

vector<Address> addressBook;

void createAddressBook() {
    addressBook.clear();
    cout << "Address book created successfully!\n";
}

void viewAddressBook() {
    if (addressBook.empty()) {
        cout << "Address book is empty.\n";
        return;
    }
    for (int i = 0; i < addressBook.size(); i++) {
        cout << "Record " << i + 1 << ":\n";
        cout << "Name: " << addressBook[i].name << "\n";
        cout << "Phone: " << addressBook[i].phone << "\n";
        cout << "Email: " << addressBook[i].email << "\n\n";
    }
}

void insertRecord() {
    Address a;
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, a.name);
    cout << "Enter phone: ";
    getline(cin, a.phone);
    cout << "Enter email: ";
    getline(cin, a.email);
    addressBook.push_back(a);
    cout << "Record inserted successfully!\n";
}

void deleteRecord() {
    int index;
    viewAddressBook();
    cout << "Enter record number to delete: ";
    cin >> index;
    if (index < 1 || index > addressBook.size()) {
        cout << "Invalid record number.\n";
        return;
    }
    addressBook.erase(addressBook.begin() + index - 1);
    cout << "Record deleted successfully!\n";
}

void modifyRecord() {
    int index;
    viewAddressBook();
    cout << "Enter record number to modify: ";
    cin >> index;
    if (index < 1 || index > addressBook.size()) {
        cout << "Invalid record number.\n";
        return;
    }
    Address& a = addressBook[index - 1];
    cout << "Enter new name: ";
    cin >> ws;
    getline(cin, a.name);
    cout << "Enter new phone: ";
    getline(cin, a.phone);
    cout << "Enter new email: ";
    getline(cin, a.email);
    cout << "Record modified successfully!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Address Book Menu ---\n";
        cout << "1. Create Address Book\n";
        cout << "2. View Address Book\n";
        cout << "3. Insert Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Modify Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAddressBook(); break;
            case 2: viewAddressBook(); break;
            case 3: insertRecord(); break;
            case 4: deleteRecord(); break;
            case 5: modifyRecord(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
