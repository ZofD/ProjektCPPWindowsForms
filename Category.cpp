#include "pch.h"
#include "Category.h"

static const int WRONG_REQUEST = -1;

Category::Category() {}
Category::Category(int id, std::string name) {
	this->id = id;
	this->name = name;
}
Category::Category(std::string name) {
	this->name = name;
}

bool Category::isWrongRequest() {
	return this->id == WRONG_REQUEST;
}

void Category::setWrongRequest() {
	this->id = WRONG_REQUEST;
}
void Category::setId(int id) {
	this->id = id;
}
int Category::getId() {
	return this->id;
}
void Category::setName(std::string name) {
	this->name = name;
}
std::string Category::getName() {
	return this->name;
}