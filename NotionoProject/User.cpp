#include "User.h"

int User::userIdCounter = 1;

User::User(const string& userName, const string& password) : userId(userIdCounter++)
{
	this->userName = userName;
	this->password = password;
}

const string& User::getUserName() const
{
	return userName;
}

const string& User::getUserPassword() const
{
	return this->password;
}
