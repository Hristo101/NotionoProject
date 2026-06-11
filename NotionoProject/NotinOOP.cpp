#include "NotinOOP.h"
#include "Customer.h"

void NotinOOP::registerUser(const string& username, const string& password, const string& role) {
    for (const auto& u : this->users) {
        if (u->getUserName() == username) {
            cout << "Грешка: Потребителското име вече е заето!\n";
            return;
        }
    }

    if (role == "admin") {
        this->users.push_back(make_unique<Admin>(username, password));
        cout << "Успешно регистриран нов АДМИНИСТРАТОР: " << username << "\n";
    }
    else if (role == "customer" || role == "client") {
        users.push_back(make_unique<Customer>(username, password));
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
    for (int i = 0; i < this->users.size(); i++)
    {
        if (this->users[i]->getUserName() == username)
        {
            this->users.erase(this->users.begin() + i);
            break;
        }
    }

    throw invalid_argument("Invalid username");
}