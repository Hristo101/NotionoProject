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

void Purchase::setCondition(Condition newCond)
{
    this->condition = newCond;
}
int Purchase::getUserId() const {
    return this->userId;
}