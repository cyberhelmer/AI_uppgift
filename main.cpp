#include <iostream>
#include <string>
#include "database.h"
#include "contact.h"

void displayMenu() {
    std::cout << "\n== Kontaktbok Menu ==" << std::endl;
    std::cout << "1. Lägg till kontakt" << std::endl;
    std::cout << "2. Visa alla kontakter" << std::endl;
    std::cout << "3. Sök efter kontakt" << std::endl;
    std::cout << "4. Avsluta" << std::endl;
    std::cout << "Välj ett alternativ: ";
}

void addContact(Database& db) {
    std::string name, email, phone;
    std::cout << "Ange namn: ";
    std::getline(std::cin, name);
    std::cout << "Ange e-mail: ";
    std::getline(std::cin, email);
    std::cout << "Ange telefonnummer: ";
    std::getline(std::cin, phone);

    Contact contact(name, email, phone);
    if (db.addContact(contact)) {
        std::cout << "Kontakt sparad!" << std::endl;
    } else {
        std::cout << "Misslyckades att spara kontakten." << std::endl;
    }
}

void listContacts(Database& db) {
    auto contacts = db.getAllContacts();
    if (contacts.empty()) {
        std::cout << "Inga kontakter hittades." << std::endl;
    } else {
        std::cout << "\n== Alla kontakter ==" << std::endl;
        for (const auto& contact : contacts) {
            std::cout << contact.toString() << std::endl;
        }
    }
}

void searchContact(Database& db) {
    std::string query;
    std::cout << "Ange namn eller telefonnummer för att söka: ";
    std::getline(std::cin, query);

    auto results = db.searchContacts(query);
    if (results.empty()) {
        std::cout << "Inga matchningar hittades." << std::endl;
    } else {
        std::cout << "\n== Sökträffar ==" << std::endl;
        for (const auto& contact : results) {
            std::cout << contact.toString() << std::endl;
        }
    }
}

int main() {
    Database db("contacts.db");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1: addContact(db); break;
            case 2: listContacts(db); break;
            case 3: searchContact(db); break;
            case 4: std::cout << "Avslutar..." << std::endl; break;
            default: std::cout << "Ogiltigt val. Försök igen." << std::endl; break;
        }
    } while (choice != 4);

    return 0;
}
