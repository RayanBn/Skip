#ifndef DATABASE
    #define DATABASE

    #include <mysql.h>
    #include <vector>
    #include <string>

namespace SkipDatabase
{
    class User;

    class Database {
        MYSQL *_con;

        private:
            void query(const std::string &query);

        public:
            Database();
            ~Database();

            MYSQL &getConnection() const;

            // USER
            SkipDatabase::User getUser(const std::string &username);
            SkipDatabase::User getUser(const size_t id);
            size_t addUser(const std::string &username, const std::string &password, const std::string &email);
            void removeUser(const std::string &username);
            void removeUser(const size_t id);
            void updateUser(const size_t id, const std::string &username, const std::string &password, const std::string &email);

            std::vector<User> getUsers();
    };
}

#endif // DATABASE
