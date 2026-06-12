#pragma once
#include "Discount.h"
class BonusDiscount : public Discount
{
     private:
         double bonus;
public:
    BonusDiscount(double percent, double bonusValue);
    double apply(const std::vector<const Fragrance*>& cartItems) const override;
};

