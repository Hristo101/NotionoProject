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