#include "User.hpp"

SkipDatabase::User::User() :
    _id(0),
    _username(""),
    _password(""),
    _email("")
{
}

SkipDatabase::User::User(const size_t id, const std::string &username, const std::string &password, const std::string &email) :
    _id(id),
    _username(username),
    _password(password),
    _email(email)
{
}

void SkipDatabase::User::setId(const size_t id)
{
    this->_id = id;
}

void SkipDatabase::User::setUsername(const std::string &username)
{
    this->_username = username;
}

void SkipDatabase::User::setPassword(const std::string &password)
{
    this->_password = password;
}

void SkipDatabase::User::setEmail(const std::string &email)
{
    this->_email = email;
}

const size_t &SkipDatabase::User::getId() const
{
    return this->_id;
}

const std::string &SkipDatabase::User::getUsername() const
{
    return this->_username;
}

const std::string &SkipDatabase::User::getPassword() const
{
    return this->_password;
}

const std::string &SkipDatabase::User::getEmail() const
{
    return this->_email;
}
