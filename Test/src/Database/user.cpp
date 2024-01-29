#include <gtest/gtest.h>
#include "SkipDatabase/SkipDatabase.hpp"

size_t createUser()
{
    SkipDatabase::Database db;

    return db.addUser("gtest", "gtest", "gtest");
}

void removeUser()
{
    SkipDatabase::Database db;

    db.removeUser("gtest");
}

TEST(Database, CreateUser)
{
    SkipDatabase::Database db;
    size_t id = createUser();
    SkipDatabase::User user = db.getUser(id);

    EXPECT_EQ(user.getId(), id);
    EXPECT_EQ(user.getUsername(), "gtest");
    EXPECT_EQ(user.getPassword(), "gtest");
    EXPECT_EQ(user.getEmail(), "gtest");
}

TEST(Database, RemoveUser)
{
    SkipDatabase::Database db;
    SkipDatabase::User user;

    db.removeUser("gtest");
    user = db.getUser("gtest");

    EXPECT_EQ(user.getId(), 0);
}

TEST(Database, getUser)
{
    SkipDatabase::Database db;
    size_t id = createUser();
    SkipDatabase::User user1 = db.getUser(id);
    SkipDatabase::User user2 = db.getUser("gtest");

    EXPECT_EQ(user1.getId(), user2.getId());
    EXPECT_EQ(user1.getUsername(), user2.getUsername());
    EXPECT_EQ(user1.getPassword(), user2.getPassword());
    EXPECT_EQ(user1.getEmail(), user2.getEmail());
}

TEST(Database, getUsers)
{
    SkipDatabase::Database db;
    size_t id = createUser();
    std::vector<SkipDatabase::User> users = db.getUsers();
    SkipDatabase::User user = db.getUser(id);

    EXPECT_EQ(users.back().getId(), user.getId());
    EXPECT_EQ(users.back().getUsername(), user.getUsername());
    EXPECT_EQ(users.back().getPassword(), user.getPassword());
    EXPECT_EQ(users.back().getEmail(), user.getEmail());
}

TEST(Database, updateUser)
{
    SkipDatabase::Database db;
    size_t id = createUser();
    SkipDatabase::User user1 = db.getUser(id);

    db.updateUser(id, "gtest2", "gtest2", "gtest2");
    SkipDatabase::User user2 = db.getUser(id);

    EXPECT_EQ(user1.getId(), user2.getId());
    EXPECT_NE(user1.getUsername(), user2.getUsername());
    EXPECT_NE(user1.getPassword(), user2.getPassword());
    EXPECT_NE(user1.getEmail(), user2.getEmail());
}
