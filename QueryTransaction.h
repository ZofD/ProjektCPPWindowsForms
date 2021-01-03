#ifndef QUERYTRANSACTION_H
#define QUERYTRANSACTION_H

#pragma once
#include "Query.h"
class QueryTransaction : public Query {
private:
	static Transaction seletOnce(std::string query);
	static std::vector<Transaction> seletMany(std::string query);
	static Transaction selectCreateTransaction(Transaction transaction);
	static bool insertTransactionOffer(Transaction transaction, Offer offer);
	static bool insertTransactionOffer(MYSQL* conn, Transaction transaction, Offer offer);
public:
	static std::vector<Transaction> selectUserTransaction(User user);
	static bool insertTransaction(Transaction transaction);
};

#endif // !QUERYTRANSACTION_H