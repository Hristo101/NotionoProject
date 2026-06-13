#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class RecommendCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
public:
    RecommendCommand(const std::shared_ptr<NotinOOP>& sys);
    void execute() override;
};