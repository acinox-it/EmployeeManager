#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <string>
#include <vector>
#include <optional>
#include <mysql.h>
#include "User.h"

class DatabaseManager {
public:
    DatabaseManager();
    virtual ~DatabaseManager();

    bool connect(const std::string& host,
                 const std::string& user,
                 const std::string& password,
                 const std::string& dbName,
                 unsigned int port = 3306);
    void disconnect();
    bool isConnected() const;
    std::string lastError() const;

    // CRUD Users (qui sont aussi employés)
    bool addUser(const User& u);
    bool updateUser(const User& u);
    bool deleteUser(int id);
    std::optional<User> findUser(const std::string& username);
    std::vector<User> listUsers();

private:
    MYSQL* conn_;
    std::string lastError_;

    bool execSimple(const std::string& sql);
    std::vector<std::vector<std::string>> queryRows(const std::string& sql);
    std::string escape(const std::string& value) const;

    static User mapUserRow(const std::vector<std::string>& row);
};

#endif
