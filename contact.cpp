#include "contact.h"

// Constructor implementation
Contact::Contact(const std::string& n, const std::string& e, const std::string& p)
    : name(n), email(e), phone(p) {}

// Method to return a string representation of the contact
std::string Contact::toString() const {
    return "Namn: " + name + ", E-mail: " + email + ", Telefonnummer: " + phone;
}
