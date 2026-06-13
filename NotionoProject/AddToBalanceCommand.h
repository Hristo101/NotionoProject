#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class AddToBalanceCommand : public ICommand
{
private:
    std::shared_ptr<NotinOOP> system;
    double amount;
public:
    AddToBalanceCommand(const std::shared_ptr<NotinOOP>& sys, double amt);
    void execute() override;
};

