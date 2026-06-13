#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class CancelPurchaseCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
    unsigned purchaseId;
public:
    CancelPurchaseCommand(const std::shared_ptr<NotinOOP>& sys, unsigned pId);
    void execute() override;
};

