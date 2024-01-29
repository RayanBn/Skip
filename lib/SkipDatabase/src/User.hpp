#include <iostream>

namespace SkipDatabase
{
    class User
    {
        size_t _id;
        std::string _username;
        std::string _password;
        std::string _email;

        public:
            User();
            User(const size_t id, const std::string &username, const std::string &password, const std::string &email);
            ~User() = default;

            void setId(const size_t id);
            void setUsername(const std::string &username);
            void setPassword(const std::string &password);
            void setEmail(const std::string &email);

            const size_t &getId() const;
            const std::string &getUsername() const;
            const std::string &getPassword() const;
            const std::string &getEmail() const;
    };
}
