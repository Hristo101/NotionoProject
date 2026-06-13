#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>
class ViewPurchasesCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
public:
    ViewPurchasesCommand(const std::shared_ptr<NotinOOP>& sys);
    void execute() override;
};

