#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class AddToCartCommand : public ICommand
{
private:
    std::shared_ptr<NotinOOP> system;
    std::string fragranceName;
public:
    AddToCartCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name);
    void execute() override;
};

