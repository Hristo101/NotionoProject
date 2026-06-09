#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class CheckUserId
{
   private:
	   vector<string> userIds;
   public:
	   bool checkUserIdIsInArray(const string& id);
};

