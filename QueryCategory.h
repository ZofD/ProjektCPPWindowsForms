#ifndef QUERYCATEGORY_H
#define QUERYCATEGORY_H

#pragma once
#include <vector>
#include "Query.h"
#include "Category.h"

class QueryCategory : public Query {
public:
	static std::vector<Category> selectAll();
};

#endif // !QUERYCATEGORY_H