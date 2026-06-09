#pragma once
#include "User.h"
class Customer : public User
{
    private:

    public:
    Customer(const string& userName, const string& password) : User(userName, password) {};
	void help() const override;
};

