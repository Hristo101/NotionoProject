#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class MakeReviewCommand : public ICommand {
private:
    std::shared_ptr<NotinOOP> system;
    std::string fragranceName;
    unsigned rating;
    std::string comment;
public:
    MakeReviewCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name, unsigned r, const std::string& c);
    void execute() override;
};
