#include "System.h"

void System::registerUser(const string& userName, const string& password)
{
	for (const auto& user : users) {
		if (user->getUserName() == userName) {
			throw runtime_error("Username already exists.");
		}
	}

	users.push_back(make_unique<User>(userName, password));
}

void System::login(const string& userName, const string& password)
{
	for (const auto& user : users) {
		if (user->getUserName() == userName && user->getUserPassword() == password) {
			currentUser = user.get();
			return;
		}
	}
	throw runtime_error("Invalid username or password.");
}

void System::logout()
{
	if (this->currentUser == nullptr)
	{
		throw runtime_error("No user is currently logged in.");
	}

	currentUser = nullptr;
}
