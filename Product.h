#ifndef PRODUCT_H
#define PRODUCT_H

#pragma once
#include "Company.h"
#include "Category.h"

class Product{
private:
	int id;
	std::string name;
	Company company;
	Category category;
public:
	Product();
	Product(int id, std::string name);
	Product(int id, std::string name, Company company, Category category);

	void setId(int id);
	int getId();
	void setName(std::string name);
	std::string getName();
	void setCompany(Company company);
	Company getCompany();
	void setCategory(Category category);
	Category getCategory();
};

#endif // !PRODUCT_H