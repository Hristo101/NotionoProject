#include "AddQuantityCommand.h"

AddQuantityCommand::AddQuantityCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name, int q)
{
	this->system = sys;
	this->fragranceName = name;
	this->quantity = q;
}

void AddQuantityCommand::execute()
{
	this->system->addFragranceQuantity(fragranceName, quantity);
}
