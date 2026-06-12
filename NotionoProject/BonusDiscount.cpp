#include "BonusDiscount.h"

BonusDiscount::BonusDiscount(double percent, double bonusValue) : Discount(percent)
{
	this->bonus = bonusValue;
}

double BonusDiscount::apply(const std::vector<const Fragrance*>& cartItems) const
{
    double priceAfterPercent = Discount::apply(cartItems);

    double finalPrice = priceAfterPercent - bonus;

    if (finalPrice < 0.0) {
        return 0.0;
    }

    return finalPrice;
}
