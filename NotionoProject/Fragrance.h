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
        int fragranceId;
		string name;
		string brand;
		double price;
		string fragranceFamily;
		int quantity;
		vector<unique_ptr<Review>> reviews;
    public:
		double getRating() const;

};

