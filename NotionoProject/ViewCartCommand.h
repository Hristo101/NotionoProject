#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class ViewCartCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
public:
    ViewCartCommand(const std::shared_ptr<NotinOOP>& sys);
    void execute() override;
};

