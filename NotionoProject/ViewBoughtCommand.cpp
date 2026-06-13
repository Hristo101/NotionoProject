#include "ViewBoughtCommand.h"

ViewBoughtCommand::ViewBoughtCommand(const std::shared_ptr<NotinOOP>& sys)
{
	this->system = sys;
}

void ViewBoughtCommand::execute()
{
	this->system->handleViewBought();
}
