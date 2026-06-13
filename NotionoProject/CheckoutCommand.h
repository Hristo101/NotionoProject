#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class CheckoutCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
public:
    CheckoutCommand(const std::shared_ptr<NotinOOP>& sys);
    void execute() override;
};
