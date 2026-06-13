#include "Purchase.h"

void Purchase::show() const
{
    double totalPrice = 0.0;
    cout << "Purchase ID: " << this->purchaseId << ", Condition: " << getConditionString() << ", User ID: " << this->userId << endl;
    for (int i = 0; i < this->fragrances.size(); i++)
    {
        cout << this->fragrances[i].toString() << endl;
        totalPrice += this->fragrances[i].getPrice();
    }
    cout << totalPrice << endl;
}

unsigned Purchase::getPurchaseId() const
{
    return this->purchaseId;
}

const vector<Fragrance> Purchase::getFragrances() const
{
	return this->fragrances;
}

Condition Purchase::getCondition() const
{
    return this->condition;
}

const string Purchase::getConditionString() const
{
    switch (this->condition)
    {
    case Condition::PENDING:
        return "Pending";
    case Condition::DELIVERED:
        return "Delivered";
    case Condition::CANCELED:
        return "Canceled";
    default:
        return "Unknown";
    }
}

void Purchase::setCondition(Condition newCond)
{
    this->condition = newCond;
}
int Purchase::getUserId() const {
    return this->userId;
}
Purchase::Purchase(const vector<Fragrance>& fragrances, int userId) : purchaseId(purchaseIdCounter++)
{
    if (fragrances.empty()) {
        throw logic_error("Грешка: Не може да се създаде поръчка с празна количка!");
    }

    this->userId = userId;
    this->fragrances = fragrances;
    this->condition = Condition::PENDING; 
}