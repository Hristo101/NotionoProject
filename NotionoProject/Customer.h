#pragma once
#include "User.h"
#include "Cart.h"
#include <string>
#include <memory>
#include "Discount.h"
#include "Purchase.h"

class Customer : public User
{
    private:
        Cart cart;
        vector<Purchase> purchases;
        vector<const Fragrance*> favoriteFragrances;;
		vector<unique_ptr<Discount>> discounts;
		double balance;
    public:
        Customer(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys)
            : User(userName, password, sys) {
        }

        const Cart& getCart() const;
        vector<unique_ptr<Discount>>& getDiscounts();
		vector<Purchase>& getPurchases();


        void help() const override;
        void addToBalance(double amount);
        void addToWishlist(const Fragrance* f);
        void removeFromWishlist(const string& fragranceName);

        void addToCart(const Fragrance* f);
        void removeFromCart(const string& fragranceName);

        void viewCart() const;
        void viewBought() const;
        void viewPurchases() const;

        void recommend(const vector<Fragrance>& allFragrances) const;
        void checkout(double finalPrice);

        void cancelPurchase(unsigned purchaseId);
        void addReviewToHistory(unsigned reviewId);
};