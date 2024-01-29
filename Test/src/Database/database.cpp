#include <gtest/gtest.h>
#include "SkipDatabase/SkipDatabase.hpp"

TEST(Database, DatabaseCreation)
{
    SkipDatabase::Database db;
    MYSQL *connection = db.getConnection();

    EXPECT_NE(connection, nullptr);
}
