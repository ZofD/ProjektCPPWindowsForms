#include "pch.h"
#include "Company.h"

static const int WRONG_REQUEST = -1;

Company::Company() {}
Company::Company(int id, std::string name) {
	this->id = id;
	this->name = name;
}
Company::Company(std::string name) {
	this->name = name;
}

bool Company::isWrongRequest() {
	return this->id == WRONG_REQUEST;
}

void Company::setWrongRequest() {
	this->id = WRONG_REQUEST;
}
void Company::setId(int id) {
	this->id = id;
}
int Company::getId() {
	return this->id;
}
void Company::setName(std::string name) {
	this->name = name;
}
std::string Company::getName() {
	return this->name;
}