#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <exception>
class User
{
    protected:
		int userId;
		static int userIdCounter;
		string userName;
		string password;
    public:
		User(const string& userName, const string& password) : userId(userIdCounter++) {};
		virtual ~User() = default;
		virtual void help() const = 0;
		const string& getUserName() const;
		const string& getUserPassword() const;

};

