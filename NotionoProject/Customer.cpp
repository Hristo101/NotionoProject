#include "Customer.h"
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

void Customer::addToWishlist(const std::string& fragranceName)
{

}

void Customer::removeFromWishlist(const std::string& fragranceName)
{
}

void Customer::addToCart(const std::string& fragranceName)
{
	cart.add();
}

void Customer::viewBought() const
{
    for (int i = 0; i < this->purchases.size(); i++)
    {
        if (this->purchases[i].getCondition() == Condition::DELIVERED)
        {
            cout << this->purchases[i].toString();
        }
    }
}

void Customer::viewPurchases() const
{

}

void Customer::checkout(double finalPrice) {
    if (this->balance < finalPrice) {
        throw std::runtime_error("Грешка: Нямате достатъчно наличност в баланса!");
    }

    this->balance -= finalPrice;

    this->cart.clear();
}