#ifndef QUERYOFFER_H
#define QUERYOFFER_H

#pragma once
#include <chrono>
#include <iomanip>
#include "Query.h"
#include "Transaction.h"

class QueryOffer : public Query {
private:
	static Offer seletOnce(std::string query);
	static std::vector<Offer> seletMany(std::string query);
	static std::vector<Offer> seletMany(MYSQL* conn, std::string query);
	static std::vector<Offer> seletManyNull(std::string query);
	static std::vector<Offer> seletManyNull(MYSQL* conn, std::string query);
	static std::vector<Offer> seletManyOffer(std::string query);
	static std::vector<Offer> seletManyOffer(MYSQL* conn, std::string query);
public:
	static std::vector<Offer> selectAllActive();
	static std::vector<Offer> selectAllInTransaction(Transaction transaction);
	static std::vector<Offer> selectAllInTransaction(MYSQL* conn, Transaction transaction);
};

#endif // !QUERYOFFER_H