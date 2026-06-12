#include "Fragrance.h"
unsigned Fragrance::fragranceIdCounter = 1;

double Fragrance::getRating() const
{
	
}

const string& Fragrance::getName() const
{
	return this->name;
}

int Fragrance::getFragranceId() const
{
	return this->fragranceId;
}

double Fragrance::getPrice() const
{
	return this->price;
}

const string& Fragrance::getBrand() const
{
	return this->brand;
}

vector<Review>& Fragrance::getReviews()
{
	return this->reviews;
}

void Fragrance::setQuantity(int qantity)
{
	this->quantity += quantity;
}

Fragrance::Fragrance(const string& name, const string& brand, double price, const string& fragranceFamily, int quantity) : fragranceId(fragranceIdCounter++)
{
}
