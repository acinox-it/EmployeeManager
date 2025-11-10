#include "DatabaseManager.h"
#include <sstream>
#include <iomanip>

DatabaseManager::DatabaseManager() : conn_(nullptr) {}
DatabaseManager::~DatabaseManager() { disconnect(); }

bool DatabaseManager::connect(const std::string& host,
                              const std::string& user,
                              const std::string& password,
                              const std::string& dbName,
                              unsigned int port) {
    disconnect();
    conn_ = mysql_init(nullptr);
    if (!conn_) {
        lastError_ = "mysql_init failed";
        return false;
    }
    if (!mysql_real_connect(conn_, host.c_str(), user.c_str(), password.c_str(),
                            dbName.c_str(), port, nullptr, 0)) {
        lastError_ = mysql_error(conn_);
        disconnect();
        return false;
    }
    return true;
}

void DatabaseManager::disconnect() {
    if (conn_) {
        mysql_close(conn_);
        conn_ = nullptr;
    }
}

bool DatabaseManager::isConnected() const { return conn_ != nullptr; }
std::string DatabaseManager::lastError() const { return lastError_; }

bool DatabaseManager::execSimple(const std::string& sql) {
    if (!isConnected()) { lastError_ = "Not connected"; return false; }
    if (mysql_query(conn_, sql.c_str()) != 0) {
        lastError_ = mysql_error(conn_);
        return false;
    }
    return true;
}

std::vector<std::vector<std::string>> DatabaseManager::queryRows(const std::string& sql) {
    std::vector<std::vector<std::string>> rows;
    if (!isConnected()) { lastError_ = "Not connected"; return rows; }
    if (mysql_query(conn_, sql.c_str()) != 0) { lastError_ = mysql_error(conn_); return rows; }
    MYSQL_RES* res = mysql_store_result(conn_);
    if (!res) return rows;
    int numFields = mysql_num_fields(res);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        std::vector<std::string> cols;
        unsigned long* lengths = mysql_fetch_lengths(res);
        for (int i = 0; i < numFields; ++i) {
            cols.emplace_back(row[i] ? std::string(row[i], lengths[i]) : "");
        }
        rows.push_back(cols);
    }
    mysql_free_result(res);
    return rows;
}

std::string DatabaseManager::escape(const std::string& value) const {
    if (!isConnected()) return value;
    std::string out;
    out.resize(value.size() * 2 + 1);
    unsigned long len = mysql_real_escape_string(conn_, out.data(), value.c_str(), value.size());
    out.resize(len);
    return out;
}

// --- Users (qui sont aussi employés) ---
bool DatabaseManager::addUser(const User& u) {
    std::ostringstream ss;
    ss << "INSERT INTO users (first_name,last_name,birth_date,position,salary,joined_year,username,password,role) VALUES ('"
       << escape(u.getFirstName()) << "','" << escape(u.getLastName()) << "','"
       << escape(u.getBirthDate()) << "','" << escape(u.getPosition()) << "',"
       << std::fixed << std::setprecision(2) << u.getSalary() << ","
       << u.getJoinedYear() << ",'"
       << escape(u.getUsername()) << "','" << escape(u.getPassword()) << "','"
       << escape(u.getRole()) << "');";
    return execSimple(ss.str());
}

bool DatabaseManager::updateUser(const User& u) {
    std::ostringstream ss;
    ss << "UPDATE users SET "
       << "first_name='" << escape(u.getFirstName()) << "', "
       << "last_name='" << escape(u.getLastName()) << "', "
       << "birth_date='" << escape(u.getBirthDate()) << "', "
       << "position='" << escape(u.getPosition()) << "', "
       << "salary=" << std::fixed << std::setprecision(2) << u.getSalary() << ", "
       << "joined_year=" << u.getJoinedYear() << ", "
       << "username='" << escape(u.getUsername()) << "', "
       << "password='" << escape(u.getPassword()) << "', "
       << "role='" << escape(u.getRole()) << "' "
       << "WHERE id=" << u.getId() << ";";
    return execSimple(ss.str());
}

bool DatabaseManager::deleteUser(int id) {
    std::ostringstream ss; ss << "DELETE FROM users WHERE id=" << id << ";";
    return execSimple(ss.str());
}

std::optional<User> DatabaseManager::findUser(const std::string& username) {
    std::ostringstream ss;
    ss << "SELECT id,first_name,last_name,birth_date,position,salary,joined_year,username,password,role "
       << "FROM users WHERE username='" << escape(username) << "' LIMIT 1;";
    auto rows = queryRows(ss.str());
    if (rows.empty()) return std::nullopt;
    return mapUserRow(rows.front());
}

std::vector<User> DatabaseManager::listUsers() {
    std::vector<User> list;
    auto rows = queryRows("SELECT id,first_name,last_name,birth_date,position,salary,joined_year,username,password,role FROM users;");
    for (auto& r : rows) list.push_back(mapUserRow(r));
    return list;
}

User DatabaseManager::mapUserRow(const std::vector<std::string>& row) {
    User u;
    u.setId(std::stoi(row[0]));
    u.setFirstName(row[1]);
    u.setLastName(row[2]);
    u.setBirthDate(row[3]);
    u.setPosition(row[4]);
    u.setSalary(std::stod(row[5]));
    u.setJoinedYear(std::stoi(row[6]));
    u.setUsername(row[7]);
    u.setPassword(row[8]);
    u.setRole(row[9]);
    return u;
}


