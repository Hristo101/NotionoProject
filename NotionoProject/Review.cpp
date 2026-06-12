#include "Review.h"
unsigned Review::reviewIdCounter = 1;

Review::Review(int userId, const string& comment, unsigned rating) : reviewId(reviewIdCounter++)
{
}

int Review::getUserId() const
{
	return this->reviewId;
}

int Review::getReviewId() const
{
	return this->reviewId;
}
