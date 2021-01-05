#ifndef QUERYCOMPANY_H
#define QUERYCOMPANY_H

#pragma once
#include "Query.h"
#include "Company.h"

class QueryCompany : public Query {
private:
	static Company seletOnce(std::string query);
	static std::vector<Company> seletMany(std::string query);
public:
	static std::vector<Company> selectAll();

	static bool addCompany(Company company);
};

#endif // !QUERYCOMPANY_H