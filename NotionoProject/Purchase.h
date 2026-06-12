#pragma once
#include "Fragrance.h"
#include "Condition.h"
class Purchase
{
private:
	unsigned purchaseId;
	static unsigned purchaseIdCounter;
	vector<Fragrance> fragrances;
	Condition condition = Condition::PENDING;
	int userId;
public:
    Purchase(const vector<Fragrance>& cartFragrances, int uId);

    ~Purchase() = default;

    void show() const;

    unsigned getPurchaseId() const;
    Condition getCondition() const;
	const string getConditionString() const;
    void setCondition(Condition newCond);
    int getUserId() const;
};

