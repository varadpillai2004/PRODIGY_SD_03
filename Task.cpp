#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
public:
    Contact(const string& name, const string& phone, const string& email)
        : name(name), phone(phone), email(email) {}

    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }

    void setName(const string& name) { this->name = name; }
    void setPhone(const string& phone) { this->phone = phone; }
    void setEmail(const string& email) { this->email = email; }

private:
    string name;
    string phone;
    string email;
};

class ContactManager {
public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void listContacts() const {
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.getName() << "\n";
            cout << "Phone: " << contact.getPhone() << "\n";
            cout << "Email: " << contact.getEmail() << "\n";
            cout << "\n";
        }
    }

    Contact* searchContact(const string& name) {
        for (auto& contact : contacts) {
            if (contact.getName() == name) {
                return &contact;
            }
        }
        return nullptr;
    }

private:
    vector<Contact> contacts;
};

void displayMenu() {
    cout << "Contact Management System\n";
    cout << "1. Add Contact\n";
    cout << "2. List Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    ContactManager manager;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string name, phone, email;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter email: ";
                getline(cin, email);

                Contact contact(name, phone, email);
                manager.addContact(contact);
                break;
            }
            case 2:
                manager.listContacts();
                break;
            case 3: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);

                Contact* contact = manager.searchContact(name);
                if (contact) {
                    cout << "Name: " << contact->getName() << "\n";
                    cout << "Phone: " << contact->getPhone() << "\n";
                    cout << "Email: " << contact->getEmail() << "\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
