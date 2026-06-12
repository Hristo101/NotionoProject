#include "Cart.h"
void Cart::add(const Fragrance* f)
{
	if (f != nullptr)
	{
	   this->fragrances.push_back(f);
	}
}
void Cart::remove(const string& fragranceName)
{
	for (size_t i = 0; i < this->fragrances.size(); i++)
	{
		if (this->fragrances[i]->getName() == fragranceName)
		{
			this->fragrances.erase(this->fragrances.begin() + i);
			return;
		}
	}
	throw invalid_argument("No such fragrance in the cart.");
}
void Cart::clear()
{
	this->fragrances.clear();
}
double Cart::getTotalPrice() const
{
	double total = 0.0;
	for (const auto& fragrance : this->fragrances)
	{
		total += fragrance->getPrice();
	}
	return total;
}
void Cart::view() const
{
	for (const auto& fragrance : this->fragrances)
	{
		cout << "Fragrance: " << fragrance->getName() << ", Price: " << fragrance->getPrice() << endl;
	}
}
const vector<const Fragrance*>& Cart::getItems() const
{
	return this->fragrances;
}