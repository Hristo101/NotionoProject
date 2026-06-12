#include "Fragrance.h"
unsigned Fragrance::fragranceIdCounter = 1;

const string& Fragrance::getName() const
{
	return this->name;
}

int Fragrance::getFragranceId() const
{
	return this->fragranceId;
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
