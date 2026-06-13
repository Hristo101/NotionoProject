#include "DeliverCommand.h"

DeliverCommand::DeliverCommand(const std::shared_ptr<NotinOOP>& sys, int pId)
{
	this->system = sys;
	this->purchaseId = pId;
}

void DeliverCommand::execute()
{
	this->system->deliver(purchaseId);
}
