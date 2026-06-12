#pragma once
#include "User.h"
#include <string>
#include <memory>

class Customer : public User
{
public:
    Customer(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys)
        : User(userName, password, sys) {
    }

    void help() const override;
};