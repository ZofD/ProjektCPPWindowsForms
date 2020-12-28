#include "pch.h"
#include "QueryTransaction.h"

const std::string SELECT_TRANSACTION = "SELECT t.id, t.date, t.id_user, u.login, u.password, u.permission  FROM transaction AS t, user AS u WHERE t.id_user=u.id";

Transaction QueryTransaction::seletOnce(std::string query) {
	Transaction result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryTransaction::conn();
		res = QueryTransaction::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result = QueryTransaction::mySQLRowToTransaction(row);
				result.setOfferList(QueryOffer::selectAllInTransaction(result));
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
		QueryTransaction::close(conn);
	}
	return result;
}
std::vector<Transaction> QueryTransaction::seletMany(std::string query) {
	std::vector<Transaction> result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryTransaction::conn();
		res = QueryTransaction::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				Transaction tmp;
				tmp = QueryTransaction::mySQLRowToTransaction(row);
				tmp.setOfferList(QueryOffer::selectAllInTransaction(conn, tmp));
				result.push_back(tmp);
				
			}
		}
	}
	catch (std::exception) {}
	finally {
		QueryTransaction::close(conn);
	}
	return result;
}

std::vector<Transaction> QueryTransaction::selectUserTransaction(User user) {
	std::ostringstream oss;
	oss << SELECT_TRANSACTION << " AND t.id_user = " << user.getId();
	return QueryTransaction::seletMany(oss.str());
}