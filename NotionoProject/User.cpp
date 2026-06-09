#include "User.h"

int User::userIdCounter = 1;

User::User(const string& userName, const string& password) : userId(userIdCounter++)
{
	this->userName = userName;
	this->password = password;
}