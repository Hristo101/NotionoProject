#include "User.h"

int User::userIdCounter = 1;

User::User(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys) : userId(userIdCounter++)
{
}

const string& User::getUserName() const
{
	return userName;
}

const string& User::getUserPassword() const
{
	return this->password;
}
int User::getUserId() const {
	return this->userId;
}