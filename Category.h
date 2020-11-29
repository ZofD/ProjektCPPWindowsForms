#ifndef CATEGORY_H
#define CATEGORY_H

#pragma once

class Category{
private:
	int id;
	std::string name;
public:
	Category();
	Category(int id, std::string name);

	void setId(int id);
	int getId();
	void setName(std::string name);
	std::string getName();
};

#endif // !CATEGORY_H