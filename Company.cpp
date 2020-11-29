#include "pch.h"
#include "Company.h"

Company::Company() {}
Company::Company(int id, std::string name) {
	this->id = id;
	this->name = name;
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