#include "Customer.h"
#include <map>
#include <algorithm>
const Cart& Customer::getCart() const
{
    return this->cart;
}
vector<unique_ptr<Discount>>& Customer::getDiscounts()
{
	return this->discounts;
}
vector<Purchase>& Customer::getPurchases()
{
    return this->purchases;
}
void Customer::help() const
{
    std::cout << "Това е помощното меню за Клиенти (Customers)." << std::endl;
}

void Customer::addToBalance(double amount)
{
	this->balance += amount;
}

void Customer::addToWishlist(const Fragrance* f)
{
	this->favoriteFragrances.push_back(f);
}


void Customer::removeFromWishlist(const std::string& fragranceName)
{
    for (int i = 0; i < this->favoriteFragrances.size(); i++)
    {
        if (this->favoriteFragrances[i]->getName() == fragranceName)
        {
            this->favoriteFragrances.erase(this->favoriteFragrances.begin() + i);
        }
    }
}

void Customer::addToCart(const Fragrance* f)
{
	cart.add(f);
}

void Customer::removeFromCart(const string& fragranceName)
{
	cart.remove(fragranceName);
}


void Customer::viewCart() const
{
	cart.view();
}

void Customer::viewBought() const
{
    bool hasBought = false;

    for (int i = 0; i < this->purchases.size(); i++)
    {
        if (this->purchases[i].getCondition() == Condition::DELIVERED)
        {
            this->purchases[i].show();
            hasBought = true;
        }
    }

    if (!hasBought)
    {
        std::cout << "Нямате закупени продукти." << std::endl;
    }
}

void Customer::viewPurchases() const
{
    if (this->purchases.empty()) {
        std::cout << "Нямате направени поръчки.\n";
        return;
    }

    for (size_t i = 0; i < this->purchases.size(); i++)
    {
        this->purchases[i].show(); 
    }
}

void Customer::recommend(const vector<Fragrance>& allFragrances) const
{
	map<string, int> fragranceFamilyCounter;

    for (int i = 0; i < this->favoriteFragrances.size(); i++)
    {
        if (fragranceFamilyCounter.contains(this->favoriteFragrances[i]->getFragranceFamily()))
        {
            fragranceFamilyCounter[this->favoriteFragrances[i]->getFragranceFamily()]++;
        }
        else {
			fragranceFamilyCounter[this->favoriteFragrances[i]->getFragranceFamily()] = 1;
        }
    }

	string maxFamily;
	int maxCount = 0;

    for (const auto& item : fragranceFamilyCounter)
    {
        if (maxCount < item.second)
        {
            maxFamily = item.first;
			maxCount = item.second;
        }
    }

    int recommendedCount = 0;

    for (size_t i = 0; i < allFragrances.size(); i++)
    {
        if (recommendedCount >= 3) {
            break;
        }

        if (allFragrances[i].getFragranceFamily() == maxFamily)
        {
            auto it = std::find(this->favoriteFragrances.begin(), this->favoriteFragrances.end(), &allFragrances[i]);

            if (it == this->favoriteFragrances.end())
            {
                std::cout << " - " << allFragrances[i].toString();
                recommendedCount++;
            }
        }
    }
}

void Customer::checkout(double finalPrice) {
    if (this->balance < finalPrice) {
        throw std::runtime_error("Грешка: Нямате достатъчно наличност в баланса!");
    }

    this->balance -= finalPrice;

    this->cart.clear();
}

void Customer::cancelPurchase(unsigned purchaseId)
{
    for (int i = 0; i < this->purchases.size(); i++)
    {
        if (this->purchases[i].getPurchaseId() == purchaseId)
        {
            if (this->purchases[i].getCondition() == Condition::PENDING)
            {
                this->purchases[i].setCondition(Condition::CANCELED);
            }

		    double returnAmount = 0.0;

            for (const auto& fragrance : this->purchases[i].getFragrances())
            {
                returnAmount += fragrance.getPrice();
            }
            this->balance += returnAmount;
			return;
        }
    }
}

void Customer::addReviewToHistory(unsigned reviewId)
{
}
