#pragma once
#include "Fragrance.h"
class Discount
{
    protected:
		unsigned discountId;
		double discountPercent;
		static unsigned discountIdCounter;
   public:
	   Discount(double percent);
	virtual ~Discount() = default;
	virtual double apply(const vector<const Fragrance*>& cartItems) const;
    unsigned getDiscountId() const;
    double getDiscountPercent() const;

};

