#include "ViewCartCommand.h"

ViewCartCommand::ViewCartCommand(const std::shared_ptr<NotinOOP>& sys)
{
	this->system = sys;
}

void ViewCartCommand::execute()
{
	this->system->handleViewCart();
}
