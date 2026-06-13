#include "AddToCartCommand.h"

AddToCartCommand::AddToCartCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name)
{
	this->system = sys;
	this->fragranceName = name;
}

void AddToCartCommand::execute()
{
	this->system->handleAddToCart(fragranceName);
}
