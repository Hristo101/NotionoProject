#include "Discount.h"
unsigned Discount::discountIdCounter = 1;

Discount::Discount(double percent) : discountId(discountIdCounter++)
{
}

double Discount::apply(const vector<const Fragrance*>& cartItems) const
{
    double total = 0.0;
    for (const auto& item : cartItems)
    {
        double currentPrice = item->getPrice();
        total += currentPrice - (currentPrice * (discountPercent / 100));
    }
    return total;
}

unsigned Discount::getDiscountId() const
{
	return discountId;
}

double Discount::getDiscountPercent() const
{
	return discountPercent;
}
