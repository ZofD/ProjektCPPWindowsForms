#ifndef QUERYTRANSACTION_H
#define QUERYTRANSACTION_H

#pragma once
#include "Query.h"
class QueryTransaction : public Query {
private:
	static Transaction seletOnce(std::string query);
	static std::vector<Transaction> seletMany(std::string query);
public:
	static std::vector<Transaction> selectUserTransaction(User user);
};

#endif // !QUERYTRANSACTION_H