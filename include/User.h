#ifndef USER_H
#define USER_H

#include "Employe.h"

class User : public Employe
{
    public:
        User();
        virtual ~User();

        //Getters - Setters
        std::string getUsername() const { return username; }
        void setUsername(const std::string& u) { username = u; }

        std::string getPassword() const { return password; }
        void setPassword(const std::string& p) { password = p; }

        std::string getRole() const { return role; }
        void setRole(const std::string& r) { role = r; }

        bool verifyPassword(const std::string& input) const;

    protected:

    private:
        std::string username;
        std::string password;
        std::string role;

};

#endif // USER_H
