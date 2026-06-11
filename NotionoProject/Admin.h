#pragma once
#include "User.h"

class Admin : public User
{
public:
    Admin(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys);

    virtual ~Admin() = default;

    void help() const override;

    void blockUser(const string& username);
    void createFragrance(const string& name,const string& brand,double price,const string& fragranceFamily);
    void addQuantity(const string& fragName, int quantity);
    void deliver(int purchaseId);
    void removeReview(int fragranceId, int reviewId);
};