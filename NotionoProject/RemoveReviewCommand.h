#pragma once
#include "IComand.h"
#include "NotinOOP.h"
#include <string>
#include <memory>

class RemoveReviewCommand : public ICommand
{
private:
    std::shared_ptr<NotinOOP> system;
    int fragranceId, reviewId;
public:
    RemoveReviewCommand(const std::shared_ptr<NotinOOP>& sys, int fId, int rId);
    void execute() override;
};

