#ifndef QUERYCATEGORY_H
#define QUERYCATEGORY_H

#pragma once
#include <vector>
#include "Query.h"
#include "Category.h"

class QueryCategory : public Query {
private:
	static Category seletOnce(std::string query);
	static std::vector<Category> seletMany(std::string query);
public:
	static std::vector<Category> selectAll();

	static bool addCategory(Category category);
};

#endif // !QUERYCATEGORY_H