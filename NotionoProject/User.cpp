#include "User.h"

User::User(const string& userId, const string& userName, const string& password)
{
	if (this->checkUserId.checkUserIdIsInArray(userId))
	{
		throw invalid_argument("Invalid userId");
	}

	this->userId = userId;
	this->userName = userName;
	this->password = password;
}
