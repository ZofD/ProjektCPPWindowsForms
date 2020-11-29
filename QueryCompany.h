#ifndef QUERYCOMPANY_H
#define QUERYCOMPANY_H

#pragma once
#include "Query.h"

class QueryCompany : public Query {
public:
	static std::vector<Company> selectAll();
};

#endif // !QUERYCOMPANY_H