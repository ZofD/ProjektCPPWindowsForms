#include "pch.h"
#include "QueryOffer.h"

const static std::string SELECT_OFFER = "SELECT p.id_category, cat.name, p.id_company, com.name, o.id_product, p.name, o.id, o.price, o.start_date, o.stop_date FROM offer AS o, product AS p, company AS com, category AS cat WHERE o.id_product = p.id AND p.id_company = com.id AND p.id_category = cat.id ";
const static std::string SELECT_OFFER_FROM_TRANSACTION_OFFER = "SELECT p.id_category, cat.name, p.id_company, com.name, o.id_product, p.name, t_o.id_offer, o.price, o.start_date, o.stop_date FROM transaction_offer AS t_o, offer AS o, product AS p, company AS com, category AS cat WHERE o.id_product = p.id AND p.id_company = com.id AND p.id_category = cat.id AND t_o.id_offer = o.id ";

Offer QueryOffer::seletOnce(std::string query) {
	Offer result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryOffer::conn();
		res = QueryOffer::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result = QueryOffer::mySQLRowToOffer(row);
			}
		}
		else {
			result.setWrongRequest();
		}
	}
	catch (std::exception) {
		result.setWrongRequest();
	}
	finally {
		QueryOffer::close(conn);
	}
	return result;
}
std::vector<Offer> QueryOffer::seletMany(std::string query) {
	std::vector<Offer> result{};
	MYSQL* conn;
	try {
		conn = QueryOffer::conn();
		result = QueryOffer::seletMany(conn, query);
	} 
	catch (std::exception) {}
	finally {
		QueryOffer::close(conn);
	}
	return result;
}
std::vector<Offer> QueryOffer::seletMany(MYSQL* conn, std::string query) {
	std::vector<Offer> result{};
	MYSQL_RES* res;
	MYSQL_ROW row;
	try {
		res = QueryOffer::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result.push_back(QueryOffer::mySQLRowToOffer(row));
			}
		}
	}
	catch (std::exception) {}
	finally {}
	return result;
}
std::vector<Offer> QueryOffer::seletManyNull(std::string query) {
	std::vector<Offer> result{};
	MYSQL* conn;
	try {
		conn = QueryOffer::conn();
		result = QueryOffer::seletManyNull(conn, query);
	}
	catch (std::exception) {}
	finally {
		QueryOffer::close(conn);
	}
	return result;
}
std::vector<Offer> QueryOffer::seletManyNull(MYSQL* conn, std::string query) {
	std::vector<Offer> result{};
	MYSQL_RES* res;
	MYSQL_ROW row;
	try {
		res = QueryOffer::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result.push_back(QueryOffer::mySQLRowToOfferNull(row));
			}
		}
	}
	catch (std::exception) {}
	finally {}
	return result;
}

std::vector<Offer> QueryOffer::seletManyOffer(std::string query) {
	std::vector<Offer> result{};
	MYSQL* conn;
	try {
		conn = QueryOffer::conn();
		result = QueryOffer::seletManyOffer(conn, query);
	}
	catch (std::exception) {}
	finally {
		QueryOffer::close(conn);
	}
	return result;
}
std::vector<Offer> QueryOffer::seletManyOffer(MYSQL* conn, std::string query) {
	std::vector<Offer> result, resultHelper;
	std::string queryTMP = (query + " AND o.stop_date IS NOT NULL ");
	result = QueryOffer::seletMany(conn, queryTMP);
	queryTMP = (query + " AND o.stop_date IS NULL ");
	resultHelper = QueryOffer::seletManyNull(conn, queryTMP);
	result.insert(result.end(), resultHelper.begin(), resultHelper.end());
	return result;
}

std::vector<Offer> QueryOffer::selectAllActive() {
	time_t now = time(0);
	std::string nowDate = Helper::time_tToString(now);
	std::string query = (SELECT_OFFER + " AND o.start_date<=\'" + nowDate + "\' AND (o.stop_date>=\'" + nowDate + "\' OR o.stop_date IS NULL) ");
	return QueryOffer::seletManyOffer(query);
}

std::vector<Offer> QueryOffer::selectAllInTransaction(Transaction transaction) {
	std::string query = (SELECT_OFFER_FROM_TRANSACTION_OFFER + " AND t_o.id_transaction=" + std::to_string(transaction.getId()));
	return QueryOffer::seletManyOffer(query);
}
std::vector<Offer> QueryOffer::selectAllInTransaction(MYSQL* conn, Transaction transaction) {
	std::string query = (SELECT_OFFER_FROM_TRANSACTION_OFFER + " AND t_o.id_transaction=" + std::to_string(transaction.getId()));
	return QueryOffer::seletManyOffer(conn, query);
}