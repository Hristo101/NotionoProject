#pragma once
#include "NotinOOP.h"
#include "IComand.h"
#include <string>
#include <memory>

class BlockUserCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
    std::string username;
public:
    BlockUserCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& user);
    void execute() override;
};

