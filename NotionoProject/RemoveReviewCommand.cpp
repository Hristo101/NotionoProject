#include "RemoveReviewCommand.h"

RemoveReviewCommand::RemoveReviewCommand(const std::shared_ptr<NotinOOP>& sys, int fId, int rId)
{
	this->system = sys;
	this->fragranceId = fId;
	this->reviewId = rId;
}

void RemoveReviewCommand::execute()
{
	this->system->removeReview(fragranceId,reviewId);
}
