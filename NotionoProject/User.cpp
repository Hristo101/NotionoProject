#include "User.h"

int User::userIdCounter = 1;

User::User(const string& userName, const string& password, shared_ptr<NotinOOP> sys)
{
    if (userName.empty()) {
        throw invalid_argument("Грешка: Потребителското име не може да бъде празно!");
    }
    if (password.length() < 4) {
        throw invalid_argument("Грешка: Паролата трябва да бъде поне 4 символа дълга!");
    }
    if (sys == nullptr) {
        throw invalid_argument("Грешка: Системният указател не може да бъде nullptr!");
    }


    this->userId = userIdCounter++;
    this->userName = userName;
    this->password = password;
    this->systemRef = sys;
}

const string& User::getUserName() const
{
	return userName;
}

const string& User::getUserPassword() const
{
	return this->password;
}
int User::getUserId() const {
	return this->userId;
}