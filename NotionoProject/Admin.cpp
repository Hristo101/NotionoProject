#include "Admin.h"
#include "NotinOOP.h"

Admin::Admin(const std::string& userName, const std::string& password, std::shared_ptr<NotinOOP> sys)
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

void Admin::createFragrance(const string& name, const string& brand, double price, const string& fragranceFamily)
{

}

void Admin::addQuantity(const string& fragName, int quantity)
{
}

void Admin::deliver(int purchaseId)
{
}

void Admin::removeReview(int fragranceId, int reviewId)
{
}
