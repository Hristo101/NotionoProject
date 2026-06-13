#include "AddToWishlistCommand.h"

AddToWishlistCommand::AddToWishlistCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name)
{
	this->system = sys;
	this->fragranceName = name;
}

void AddToWishlistCommand::execute()
{
	this->system->handleAddToWishlist(fragranceName);
}
