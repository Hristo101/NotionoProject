#pragma once
#include "User.h"
#include <string>
#include <memory>

class Admin : public User
{
public:
    Admin(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys);
    virtual ~Admin() = default;

    void help() const override;
    void blockUser(const std::string& username);
    void createFragrance(const std::string& name, const std::string& brand, double price, const std::string& fragranceFamily);
    void addQuantity(const std::string& fragName, int quantity);
    void deliver(int purchaseId);
    void removeReview(int fragranceId, int reviewId);
};