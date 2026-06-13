#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>
class ViewBoughtCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
public:
    ViewBoughtCommand(const std::shared_ptr<NotinOOP>& sys);
    void execute() override;
};
