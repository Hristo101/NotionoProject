#include "Purchase.h"

void Purchase::show() const
{

}

unsigned Purchase::getPurchaseId() const
{
    return this->purchaseId;
}

Condition Purchase::getCondition() const
{
    return this->condition;
}

const string& Purchase::toString() const
{
	double totalPrice = 0.0;
    for (int i = 0; i < this->fragrances.size(); i++)
    {
		totalPrice += this->fragrances[i].getPrice();
    }
}

void Purchase::setCondition(Condition newCond)
{
    this->condition = newCond;
}
int Purchase::getUserId() const {
    return this->userId;
}