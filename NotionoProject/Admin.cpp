#include "NotinOOP.h"
#include "User.h"   
#include "Admin.h"  
#include "Customer.h"

Admin::Admin(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys) : User(userName,password,sys)
{
}

void Admin::help() const
{
}

void Admin::blockUser(const string& username)
{
    if (std::shared_ptr<NotinOOP> sys = systemRef.lock())
    {
        sys->blockUser(username);
    }
    else
    {
        std::cout << "Грешка: Главната система NotinOOP не е достъпна в паметта!" << std::endl;
    }
}

void Admin::createFragrance(const std::string& name, const std::string& brand, double price, const std::string& fragranceFamily)
{
    if (std::shared_ptr<NotinOOP> sys = systemRef.lock())
    {
        sys->createFragrance(name, brand, price, fragranceFamily);
    }
    else
    {
        std::cout << "Грешка: Главната система NotinOOP не е достъпна в паметта!\n";
    }
}

void Admin::addQuantity(const std::string& fragranceName, int quantity)
{
    if (quantity <= 0) {
        std::cout << "Грешка: Количеството за добавяне трябва да е положително число!\n";
        return;
    }

    if (std::shared_ptr<NotinOOP> sys = systemRef.lock())
    {
        std::cout << "[Admin] Заявка за актуализиране на наличност към NotinOOP...\n";

        sys->addFragranceQuantity(fragranceName, quantity);
    }
    else
    {
        std::cout << "Грешка: Главната система NotinOOP не е достъпна в паметта!\n";
    }
}

void Admin::deliver(int purchaseId)
{
}

void Admin::removeReview(int fragranceId, int reviewId)
{
}
