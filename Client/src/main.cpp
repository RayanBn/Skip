#include <iostream>
#include "SkipDatabase/SkipDatabase.hpp"

int main() {
    SkipDatabase::Database db;
    SkipDatabase::User user1 = db.getUser("rayan");
    SkipDatabase::User user2 = db.getUser(4);
    size_t id;

    std::cout << "User 1 -> " << user1.getId() << " : " << user1.getUsername() << " : " << user1.getPassword() << " : " << user1.getEmail() << std::endl;
    std::cout << "User 2 -> " << user2.getId() << " : " << user2.getUsername() << " : " << user2.getPassword() << " : " << user2.getEmail() << std::endl;

    db.removeUser("rayan");
    id = db.addUser("rayan", "rayan", "rayan1");
    user1 = db.getUser("rayan");
    std::cout << "New User 1 -> " << user1.getId() << " : " << user1.getUsername() << " : " << user1.getPassword() << " : " << user1.getEmail() << std::endl;
    user2 = db.getUser(id);
    std::cout << "New User 2 -> " << user2.getId() << " : " << user2.getUsername() << " : " << user2.getPassword() << " : " << user2.getEmail() << std::endl;

    return 0;
}
