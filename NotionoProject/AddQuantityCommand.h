#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory> 
class AddQuantityCommand : public ICommand
{
private:
    std::shared_ptr<NotinOOP> system;
    std::string fragranceName;
    int quantity;
public:
    AddQuantityCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name, int q);
    void execute() override;
};

