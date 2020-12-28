#include "pch.h"
#include "Product.h"

Product::Product() {}
Product::Product(int id, std::string name) {
	this->id = id;
	this->name = name;
}
Product::Product(int id, std::string name, Company company, Category category) {
	this->id = id;
	this->name = name;
	this->company = company;
	this->category = category;
}

void Product::setId(int id) {
	this->id = id;
}
int Product::getId() {
	return this->id;
}
void Product::setName(std::string name) {
	this->name = name;
}
std::string Product::getName() {
	return this->name;
}
void Product::setCompany(Company company) {
	this->company = company;
}
Company Product::getCompany() {
	return this->company;
}
void Product::setCategory(Category category) {
	this->category = category;
}
Category Product::getCategory() {
	return this->category;
}