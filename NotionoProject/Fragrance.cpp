#include "Fragrance.h"
unsigned Fragrance::fragranceIdCounter = 1;

const string& Fragrance::getName() const
{
	return this->name;
}

void Fragrance::setQuantity(int qantity)
{
	this->quantity += quantity;
}

Fragrance::Fragrance(const string& name, const string& brand, double price, const string& fragranceFamily, int quantity) : fragranceId(fragranceIdCounter++)
{
}
