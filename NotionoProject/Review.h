#pragma once
#include "User.h"
class Review
{
    private:
		unsigned reviewId;
		static unsigned reviewIdCounter;
		int userId;
		string comment;
		unsigned rating;
    public:
		Review(int userId, const string& comment, unsigned rating);
		int getUserId() const;
		int getReviewId() const;
		int getRating() const;
};

