#include "CheckoutCommand.h"

CheckoutCommand::CheckoutCommand(const std::shared_ptr<NotinOOP>& sys)
{
	this->system = sys;
}

void CheckoutCommand::execute()
{
	this->system->handleCheckout();
}
