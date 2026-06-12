#pragma once
#include "Discount.h"
class BrandDiscount : public Discount
{
    private:
        std::string brandName;
    public:
        BrandDiscount(double percent, const std::string& brand);
        double apply(const std::vector<const Fragrance*>& cartItems) const override;
};

