#pragma once
#include "User.h"
#include "Cart.h"
#include <string>
#include <memory>

class Customer : public User
{
    private:
        Cart cart;
        vector<Purchase> purchases;
        vector<const Fragrance*> favoriteFragrances;;
		vector<unique_ptr<Discount>> discounts;
    public:
        Customer(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys)
            : User(userName, password, sys) {
        }
    
        void help() const override;
    
};