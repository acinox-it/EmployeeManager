#include "User.h"

User::User(){}

User::~User(){}

bool User::verifyPassword(const std::string& input)const
{
    return input == password;
}
