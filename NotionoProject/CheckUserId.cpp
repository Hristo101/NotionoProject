#include "CheckUserId.h"

bool CheckUserId::checkUserIdIsInArray(const string& id)
{
	for (int i = 0; i < this->userIds.size(); i++)
	{
		if (this->userIds[i] == id)
		{
			return true;
		}
	}

	this->userIds.push_back(id);
	return false;
}
