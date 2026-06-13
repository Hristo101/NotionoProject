#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class DeliverCommand : public ICommand
{
private:
    std::shared_ptr<NotinOOP> system;
    int purchaseId;
public:
    DeliverCommand(const std::shared_ptr<NotinOOP>& sys, int pId);
    void execute() override;
};

