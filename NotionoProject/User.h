#pragma once
#include "CheckUserId.h"
#include <exception>
class User
{
    protected:
        CheckUserId checkUserId;
		string userId;
		string userName;
		string password;
    public:
		User(const string& userId, const string& userName, const string& password);
		virtual ~User() = default;
		virtual void help() const = 0;
};

