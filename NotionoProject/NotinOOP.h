#pragma once
#include "User.h"   
#include "Admin.h"  
#include "Customer.h"
#include "Fragrance.h"
class NotinOOP
{
    private:
        vector<unique_ptr<User>> users;
		vector<Fragrance> fragrances;
		User* currentUser;
    public:
		~NotinOOP() = default;
		void registerUser(const string& userName, const string& password, const string& role);
		void login(const string& userName, const string& password);
		void blockUser(const string& name);
		void createFragrance(const string& name, const string& brand, double price, const string& fragranceFamily);
		void addFragranceQuantity(const string& fragranceName, int quantity);
		void logout();
};

