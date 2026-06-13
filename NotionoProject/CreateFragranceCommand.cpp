#include "CreateFragranceCommand.h"

CreateFragranceCommand::CreateFragranceCommand(const std::shared_ptr<NotinOOP>& sys, const std::string& n, const std::string& b, double p, const std::string& f)
{
	this->fragranceFamily = f;
	this->system = sys;
	this->brand = b;
	this->name = n;
	this->price = p;
}

void CreateFragranceCommand::execute()
{
	this->system->createFragrance(name, brand, price, fragranceFamily);
}
