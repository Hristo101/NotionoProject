#include "RemoveFromWishlistCommand.h"

RemoveFromWishlistCommand::RemoveFromWishlistCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name)
{
	this->system = sys;
	this->fragranceName = name;
}

void RemoveFromWishlistCommand::execute()
{
	this->system->handleRemoveFromWishlist(fragranceName);
}
