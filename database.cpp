#include "database.h"
2#include <iostream>

Database::Database(const std::string& dbName) : databaseName(dbName) {
    initializeDatabase();
}

Database::~Database() {}

void Database::initializeDatabase() {
    sqlite3* db;
    if (sqlite3_open(databaseName.c_str(), &db) == SQLITE_OK) {
        const char* sql =
            "CREATE TABLE IF NOT EXISTS contacts ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT, email TEXT, phone TEXT);";
        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
        sqlite3_close(db);
    }
}

bool Database::addContact(const Contact& contact) {
    sqlite3* db;
    if (sqlite3_open(databaseName.c_str(), &db) != SQLITE_OK) return false;

    const char* sql = "INSERT INTO contacts (name, email, phone) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, contact.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, contact.email.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, contact.phone.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return true;
    }

    sqlite3_close(db);
    return false;
}

std::vector<Contact> Database::getAllContacts() {
    sqlite3* db;
    std::vector<Contact> contacts;
    if (sqlite3_open(databaseName.c_str(), &db) != SQLITE_OK) return contacts;

    const char* sql = "SELECT name, email, phone FROM contacts;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            std::string phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            contacts.emplace_back(name, email, phone);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return contacts;
}

std::vector<Contact> Database::searchContacts(const std::string& query) {
    sqlite3* db;
    std::vector<Contact> contacts;
    if (sqlite3_open(databaseName.c_str(), &db) != SQLITE_OK) return contacts;

    const char* sql = "SELECT name, email, phone FROM contacts WHERE name LIKE ? OR phone LIKE ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        std::string likeQuery = "%" + query + "%";
        sqlite3_bind_text(stmt, 1, likeQuery.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, likeQuery.c_str(), -1, SQLITE_STATIC);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            std::string phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            contacts.emplace_back(name, email, phone);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return contacts;
}
