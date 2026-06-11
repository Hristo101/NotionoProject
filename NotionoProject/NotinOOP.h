#pragma once
#include "User.h"
class NotinOOP
{
    private:
        vector<unique_ptr<User>> users;
		User* currentUser;
    public:
		~NotinOOP() = default;
		void registerUser(const string& userName, const string& password, const string& role);
		void login(const string& userName, const string& password);
		void blockUser(const string& name);
		void logout();
};

