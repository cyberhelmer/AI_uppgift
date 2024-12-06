#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "contact.h"

class Database {
public:
    Database(const std::string& dbName);
    ~Database();

    bool addContact(const Contact& contact);
    std::vector<Contact> getAllContacts();
    std::vector<Contact> searchContacts(const std::string& query);

private:
    std::string databaseName;
    void initializeDatabase();
};

#endif
