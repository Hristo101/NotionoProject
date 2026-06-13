#include "RemoveFromCartCommand.h"

RemoveFromCartCommand::RemoveFromCartCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name)
{
	this->system = sys;
	this->fragranceName = name;
}

void RemoveFromCartCommand::execute()
{
	this->system->handleRemoveFromCart(fragranceName);
}
