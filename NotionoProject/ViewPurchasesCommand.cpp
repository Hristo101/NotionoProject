#include "ViewPurchasesCommand.h"

ViewPurchasesCommand::ViewPurchasesCommand(const std::shared_ptr<NotinOOP>& sys)
{
	this->system = sys;
}

void ViewPurchasesCommand::execute()
{
	this->system->handleViewPurchases();
}
