#include "MakeReviewCommand.h"

MakeReviewCommand::MakeReviewCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& name, unsigned r, const std::string& c)
{
	this->system = sys;
	this->fragranceName = name;
	this->rating = r;
	this->comment = comment;
}

void MakeReviewCommand::execute()
{
	this->system->handleMakeReview(fragranceName,rating,comment);
}
