#include "BlockUserCommand.h"

BlockUserCommand::BlockUserCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& user)
{
	this->system = sys;
	this->username = user;
}

void BlockUserCommand::execute()
{
	this->system->blockUser(username);
}
