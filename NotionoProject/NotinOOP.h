#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include "Fragrance.h"
#include "Purchase.h"

using namespace std;

class User;

class NotinOOP
{
private:
    vector<unique_ptr<User>> users;
    vector<Fragrance> fragrances;
	vector<Purchase> purchases;
    User* currentUser;
    map<int, int> deletedReviewsCounter;
public:
    ~NotinOOP() = default;
    void registerUser(const string& userName, const string& password, const string& role, shared_ptr<NotinOOP> sysPtr);
    void login(const string& userName, const string& password);
    void blockUser(const string& name);
    void createFragrance(const string& name, const string& brand, double price, const string& fragranceFamily);
    void addFragranceQuantity(const string& fragranceName, int quantity);
    void removeReview(int fragranceId, int reviewId);
    void logout();
    void deliver(int purchaseId);
    void handleAddToBalance(double amount);
    void handleAddToWishlist(const string& fragranceName);
    void handleRemoveFromWishlist(const string& fragranceName);
    void handleAddToCart(const string& fragranceName);
    void handleRemoveFromCart(const string& fragranceName);
    void handleViewCart() const;
    void handleViewBought() const;
    void handleViewPurchases() const;
    void handleRecommend() const;
    void handleCheckout();
    void handleCancel(unsigned purchaseId);
    void handleMakeReview(const string& fragranceName, unsigned rating, const string& comment);
};