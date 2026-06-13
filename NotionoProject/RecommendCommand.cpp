#include "RecommendCommand.h"

RecommendCommand::RecommendCommand(const std::shared_ptr<NotinOOP>& sys)
{
	this->system = sys;
}

void RecommendCommand::execute()
{
	this->system->handleRecommend();
}
