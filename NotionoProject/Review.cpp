#include "Review.h"
unsigned Review::reviewIdCounter = 1;

Review::Review(int userId, const string& comment, unsigned rating) : reviewId(reviewIdCounter++)
{
    if (rating < 1 || rating > 5) {
        throw out_of_range("Грешка: Оценката на ревюто трябва да бъде между 1 и 5 звезди!");
    }
    if (comment.empty()) {
        throw invalid_argument("Грешка: Текстът на ревюто не може да бъде празен!");
    }

    this->userId = userId;
    this->rating = rating;
    this->comment = comment;
}

int Review::getUserId() const
{
	return this->reviewId;
}

int Review::getReviewId() const
{
	return this->reviewId;
}
int Review::getRating() const
{
	return this->rating;
}