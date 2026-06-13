#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <exception>
#include "Review.h"
class Fragrance
{
    private:
        unsigned fragranceId;
		static unsigned fragranceIdCounter;
		string name;
		string brand;
		double price;
		string fragranceFamily;
		int quantity;
		vector<Review> reviews;
    public:
		double getRating() const;
		const string& toString() const;
		const string& getFragranceFamily() const;
		const string& getName() const;
		int getFragranceId() const;
		double getPrice() const;
		const string& getBrand() const;
		vector<Review>& getReviews();
		void setQuantity(int qantity);
		Fragrance(const string& name, const string& brand, double price, const string& fragranceFamily, int quantity);
};

