#include "Fragrance.h"
unsigned Fragrance::fragranceIdCounter = 1;

double Fragrance::getRating() const
{
	int size = this->reviews.size();

	double rating = 0.0;

	for (int i = 0; i < size; i++)
	{
		rating = this->reviews[i].getRating();
	}

	return rating / size;
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

const string& Fragrance::toString() const
{
	double rating = this->getRating();
	string result = "Fragrance: " + this->name + ", Brand: " + this->brand + ", Price: " + to_string(this->price) + ", Rating: " + to_string(rating);
	return result;
}