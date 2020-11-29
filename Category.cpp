#include "pch.h"
#include "Category.h"

Category::Category() {}
Category::Category(int id, std::string name) {
	this->id = id;
	this->name = name;
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