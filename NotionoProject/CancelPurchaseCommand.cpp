#include "CancelPurchaseCommand.h"

CancelPurchaseCommand::CancelPurchaseCommand(const std::shared_ptr<NotinOOP>& sys, unsigned pId)
{
	this->system = sys;
	this->purchaseId = pId;
}

void CancelPurchaseCommand::execute()
{
	this->system->handleCancel(purchaseId);
}
