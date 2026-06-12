#include "NotinOOP.h"
#include "User.h"   
#include "Admin.h"  
#include "Customer.h"

void NotinOOP::registerUser(const string& username, const string& password, const string& role) {
    for (const auto& u : this->users) {
        if (u->getUserName() == username) {
            cout << "Грешка: Потребителското име вече е заето!\n";
            return;
        }
    }


    auto sysPtr = this->shared_from_this();

    if (role == "admin") {
        this->users.push_back(make_unique<Admin>(username, password, sysPtr));
        cout << "Успешно регистриран нов АДМИНИСТРАТОР: " << username << "\n";
    }
    else if (role == "customer" || role == "client") {
        this->users.push_back(make_unique<Customer>(username, password, sysPtr));
        cout << "Успешно регистриран нов КУПУВАЧ: " << username << "\n";
    }
    else {
        cout << "Грешка: Невалидна роля! Възможни роли: admin, customer.\n";
    }
}

void NotinOOP::login(const string& userName, const string& password)
{
    for (const auto& user : users) {
        if (user->getUserName() == userName && user->getUserPassword() == password) {
            currentUser = user.get();
            return;
        }
    }
    throw runtime_error("Invalid username or password.");
}

void NotinOOP::logout()
{
    if (this->currentUser == nullptr)
    {
        throw runtime_error("No user is currently logged in.");
    }
    currentUser = nullptr;
}

void NotinOOP::blockUser(const string& username) {
    for (size_t i = 0; i < this->users.size(); i++)
    {
        if (this->users[i]->getUserName() == username)
        {
            this->users.erase(this->users.begin() + i);
            return;
        }
    }
    throw invalid_argument("Invalid username");
}

void NotinOOP::createFragrance(const string& name, const string& brand, double price, const string& fragranceFamily) {
    for (const auto& f : fragrances) {
        if (f.getName() == name) {
            throw invalid_argument("This fragrance already exists");
        }
    }
    this->fragrances.push_back(Fragrance(name, brand, price, fragranceFamily, 0));
}

void NotinOOP::addFragranceQuantity(const string& fragranceName, int quantity)
{
    for (auto& f : fragrances) {
        if (f.getName() == fragranceName) {
            f.setQuantity(quantity);
            return;
        }
    }
    throw invalid_argument("Invalid fragranceName");
}

void NotinOOP::removeReview(int fragranceId, int reviewId) {
    for (int i = 0; i < this->fragrances.size(); i++)
    {
        if (this->fragrances[i].getFragranceId() == fragranceId)
        {
            for (int j = 0; j < this->fragrances[i].getReviews().size(); j++)
            {
                if (this->fragrances[i].getReviews()[j].getReviewId() == reviewId)
                {
                    if (deletedReviewsCounter.contains(this->fragrances[i].getReviews()[j].getUserId()))
                    {
                        deletedReviewsCounter[this->fragrances[i].getReviews()[j].getUserId()]++;
                        if (deletedReviewsCounter[this->fragrances[i].getReviews()[j].getUserId()] == 7)
                        {
                            for (int k = 0; k < this->users.size(); k++)
                            {
                                if (this->users[k]->getUserId() == this->fragrances[i].getReviews()[j].getUserId())
                                {
                                    this->blockUser(this->users[k]->getUserName());
                                }
                            }
                        }
                    }
                }

                this->fragrances[i].getReviews().erase(this->fragrances[i].getReviews().begin() + j);

                return;
            }
        }
    }

    throw logic_error("No such review was found for this perfume.");
};

void NotinOOP::deliver(int purchaseId) {
    for (auto& p : purchases) {
        if (p.getPurchaseId() == purchaseId) {
            p.setCondition(Condition::DELIVERED);
            return;
        }
    }
    throw invalid_argument("Invalid purchaseId");
}

void NotinOOP::handleAddToBalance(double amount)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

	client->addToBalance(amount);
}

void NotinOOP::handleAddToWishlist(const string& fragranceName)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

    for (const auto& f : this->fragrances) {
        if (f.getName() == fragranceName) {
            client->addToWishlist(&f);
            cout << "Успешно добавен в количката ви.\n";
            return;
        }
    }
}

void NotinOOP::handleRemoveFromWishlist(const string& fragranceName)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }
    
    client->removeFromWishlist(fragranceName);
}

void NotinOOP::handleAddToCart(const string& fragranceName)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

    for (const auto& f : this->fragrances) {
        if (f.getName() == fragranceName) {
            client->addToCart(&f);
            cout << "Успешно добавен в количката ви.\n";
            return;
        }
    }
}

void NotinOOP::handleRemoveFromCart(const string& fragranceName)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

	client->removeFromCart(fragranceName);
}

void NotinOOP::handleViewCart() const
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

	client->viewCart();
}

void NotinOOP::handleViewBought() const
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

	client->viewBought();
}

void NotinOOP::handleViewPurchases() const
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

    client->viewPurchases();
}

void NotinOOP::handleRecommend() const
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

	client->recommend(this->fragrances);
}

void NotinOOP::handleCheckout()
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

    vector<const Fragrance*> cartItems = client->getCart().getItems();

    if (cartItems.empty()) {
        cout << "Грешка: Количката ви е празна!\n";
        return;
    }

    vector<Fragrance> fragrancesToBuy;

    for (const auto* itemPtr : cartItems) {
        fragrancesToBuy.push_back(*itemPtr);
    }

	double finalPrice = client->getCart().getTotalPrice();
	double bestPrice = finalPrice;
	int bestDiscountIndex = -1;
	vector<unique_ptr<Discount>> discounts = client->getDiscounts();

    for (int i = 0; i < discounts.size(); i++)
    {
		double priceWithDiscount = discounts[i]->apply(cartItems);

        if (priceWithDiscount < bestPrice)
        {
            bestPrice = priceWithDiscount;
			bestDiscountIndex = i;
        }
    }

    try {
        client->checkout(bestPrice); 
    }
    catch (const std::exception& e) {
        cout << e.what() << "\n"; 
        return;
    }

    if (bestDiscountIndex != -1)
    {
        discounts.erase(discounts.begin() + bestDiscountIndex);
    }

    Purchase newPurshase(fragrancesToBuy,client->getUserId());

	this->purchases.push_back(newPurshase);
	client->getPurchases().push_back(newPurshase);
}

void NotinOOP::handleCancel(unsigned purchaseId)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

	client->cancelPurchase(purchaseId);
}

void NotinOOP::handleMakeReview(const string& fragranceName, unsigned rating, const string& comment)
{
    Customer* client = dynamic_cast<Customer*>(currentUser);
    if (!client) {
        cout << "Грешка: Само клиенти могат да пълнят количка!\n";
        return;
    }

    
}
