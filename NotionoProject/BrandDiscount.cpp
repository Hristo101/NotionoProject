#include "BrandDiscount.h"

BrandDiscount::BrandDiscount(double percent, const std::string& brand) : Discount(percent)
{
	this->brandName = brand;
}

double BrandDiscount::apply(const std::vector<const Fragrance*>& cartItems) const
{
    double total = 0.0;

    for (const auto& item : cartItems)
    {
        if (item->getBrand() == brandName)
        {
            total += item->getPrice() - (item->getPrice() * (discountPercent / 100.0));
        }
        else
        {
            total += item->getPrice();
        }
    }
    return total;
}
