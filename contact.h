#ifndef CONTACT_H
#define CONTACT_H

#include <string>

struct Contact {
    std::string name;
    std::string email;
    std::string phone;

    Contact(const std::string& n, const std::string& e, const std::string& p);
    std::string toString() const;
};

#endif
