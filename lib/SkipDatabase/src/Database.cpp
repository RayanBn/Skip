#include "Database.hpp"
#include "User.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

SkipDatabase::Database::Database() :
    _con(mysql_init(NULL))
{
    const char *host = std::getenv("DATABASE_HOST");
    const char *user = std::getenv("DATABASE_USER");
    const char *password = std::getenv("DATABASE_PASSWORD");
    const char *database = std::getenv("DATABASE_NAME");

    std::cout << "Connecting to database..." << std::endl;
    if (mysql_real_connect(this->_con, host, user, password, database, 0, NULL, 0) == NULL) {
        std::cout << mysql_error(this->_con) << std::endl;
    }
    std::cout << "Connected to database!" << std::endl;
}

SkipDatabase::Database::~Database()
{
    mysql_close(this->_con);
}

void SkipDatabase::Database::query(const std::string &query)
{
    try {
        if (mysql_query(this->_con, query.c_str()))
            throw std::exception();
    } catch (std::exception &e) {
        std::cout << mysql_error(this->_con) << std::endl;
    }
}

MYSQL &SkipDatabase::Database::getConnection() const
{
    return *this->_con;
}

SkipDatabase::User SkipDatabase::Database::getUser(const std::string &username)
{
    try {
        MYSQL_RES *result;
        MYSQL_ROW row;
        std::string query = "SELECT ID, Username, Password, Email FROM Users WHERE Username = '" + username + "'";

        this->query(query);
        result = mysql_store_result(this->_con);
        if (result == NULL)
            throw std::exception();
        row = mysql_fetch_row(result);
        if (row == NULL)
            throw std::exception();

        return SkipDatabase::User(std::stoi(row[0]), row[1], row[2], row[3]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return SkipDatabase::User();
}

SkipDatabase::User SkipDatabase::Database::getUser(const size_t id)
{
    try {
        MYSQL_RES *result;
        MYSQL_ROW row;
        std::string query = "SELECT ID, Username, Password, Email FROM Users WHERE ID = " + std::to_string(id);

        this->query(query);
        result = mysql_store_result(this->_con);
        if (result == NULL)
            throw std::exception();
        row = mysql_fetch_row(result);
        if (row == NULL)
            throw std::exception();

        return SkipDatabase::User(std::stoi(row[0]), row[1], row[2], row[3]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return SkipDatabase::User();
}

size_t SkipDatabase::Database::addUser(const std::string &username, const std::string &password, const std::string &email)
{
    try {
        std::string query = "INSERT INTO Users (Username, Password, Email) VALUES ('" + username + "', '" + password + "', '" + email + "')";

        this->query(query);
        return mysql_insert_id(this->_con);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

void SkipDatabase::Database::removeUser(const std::string &username)
{
    try {
        std::string query = "DELETE FROM Users WHERE Username = '" + username + "'";

        this->query(query);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void SkipDatabase::Database::removeUser(const size_t id)
{
    try {
        std::string query = "DELETE FROM Users WHERE ID = " + std::to_string(id);

        this->query(query);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void SkipDatabase::Database::updateUser(const size_t id, const std::string &username, const std::string &password, const std::string &email)
{
    try {
        std::string query = "UPDATE Users SET Username = '" + username + "', Password = '" + password + "', Email = '" + email + "' WHERE ID = " + std::to_string(id);

        this->query(query);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
