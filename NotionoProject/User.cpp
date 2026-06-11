#include "User.h"

int User::userIdCounter = 1;

const string& User::getUserName() const
{
	return userName;
}

const string& User::getUserPassword() const
{
	return this->password;
}
