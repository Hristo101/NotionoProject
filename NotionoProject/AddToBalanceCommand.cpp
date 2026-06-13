#include "AddToBalanceCommand.h"

AddToBalanceCommand::AddToBalanceCommand(const std::shared_ptr<NotinOOP>& sys, double amt)
{
	this->system = sys;
	this->amount = amt;
}

void AddToBalanceCommand::execute()
{
	this->system->handleAddToBalance(amount);
}
