#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;
#include <exception>
class NotinOOP;

class User
{
    protected:
		int userId;
		static int userIdCounter;
		string userName;
		string password;
		weak_ptr<NotinOOP> systemRef;
		User(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys);
    public:
		virtual ~User() = default;
		virtual void help() const = 0;
		const string& getUserName() const;
		const string& getUserPassword() const;
		int getUserId() const;

};

