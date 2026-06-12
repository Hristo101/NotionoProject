#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include "Fragrance.h"

using namespace std;

class User;

class NotinOOP : public std::enable_shared_from_this<NotinOOP>
{
private:
    vector<unique_ptr<User>> users;
    vector<Fragrance> fragrances;
    User* currentUser;
    map<int, int> deletedReviewsCounter;
public:
    ~NotinOOP() = default;
    void registerUser(const string& userName, const string& password, const string& role);
    void login(const string& userName, const string& password);
    void blockUser(const string& name);
    void createFragrance(const string& name, const string& brand, double price, const string& fragranceFamily);
    void addFragranceQuantity(const string& fragranceName, int quantity);
    void removeReview(int fragranceId, int reviewId);
    void logout();
    void deliver(int purchaseId);
};