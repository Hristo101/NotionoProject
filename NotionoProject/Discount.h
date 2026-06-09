#pragma once
class Discount
{
    private:
		unsigned discountId;
		double discountPercent;
		static unsigned discountIdCounter;
   public:
	Discount(double percent) : discountPercent(percent++) {};
	virtual ~Discount() = default;

};

