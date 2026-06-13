#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class CreateFragranceCommand : public ICommand
{
private:
    std::shared_ptr<NotinOOP> system;
    std::string name, brand, fragranceFamily;
    double price;
public:
    CreateFragranceCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& n, const std::string& b, double p, const std::string& f);
    void execute() override;
};

