#pragma once
#include "User.h"
class System
{
    private:
        vector<unique_ptr<User>> users;
		User* currentUser;
    public:
		~System() = default;
		void registerUser(const string& userName, const string& password);
		void login(const string& userName, const string& password);
		void logout();
};

