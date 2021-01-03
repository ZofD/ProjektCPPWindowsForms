#include "pch.h"
#include "QueryTransaction.h"

const std::string SELECT_TRANSACTION = "SELECT t.id, t.date, t.id_user, u.login, u.password, u.permission  FROM transaction AS t, user AS u WHERE t.id_user=u.id ";
const std::string INSERT_TRANSACTION = "INSERT INTO transaction(id, date, id_user) ";
const std::string INSERT_TRANSACTION_OFFER = "INSERT INTO transaction_offer (id_transaction, id_offer) ";

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
				std::vector<Offer> offerInTransaction = QueryOffer::selectAllInTransaction(result);
				if (!offerInTransaction.empty()) {
					result.setOfferList(offerInTransaction);
				}
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
				std::vector<Offer> offerInTransaction = QueryOffer::selectAllInTransaction(conn, tmp);
				if (!offerInTransaction.empty()) {
					tmp.setOfferList(offerInTransaction);
				}
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
Transaction QueryTransaction::selectCreateTransaction(Transaction transaction) {
	return QueryTransaction::seletOnce( (SELECT_TRANSACTION + " AND t.date='" + Helper::time_tToString(transaction.getDate()) + "' AND t.id_user=" + QueryTransaction::intToString(transaction.getUser().getId()) + " ORDER BY t.id DESC LIMIT 1") );
}
bool QueryTransaction::insertTransactionOffer(Transaction transaction, Offer offer) {
	bool result = false;
	MYSQL* conn;
	try {
		conn = QueryTransaction::conn();
		result = QueryTransaction::insertTransactionOffer(conn, transaction, offer);
	} catch (std::exception) {}
	finally {
		QueryTransaction::close(conn);
	}
	return result;
}
bool QueryTransaction::insertTransactionOffer(MYSQL* conn, Transaction transaction, Offer offer) {
	return QueryTransaction::insert(conn, (INSERT_TRANSACTION_OFFER + " VALUES (" + QueryTransaction::intToString(transaction.getId()) + ", " + QueryTransaction::intToString(offer.getId()) + ")"));
}

std::vector<Transaction> QueryTransaction::selectUserTransaction(User user) {
	std::ostringstream oss;
	oss << SELECT_TRANSACTION << " AND t.id_user = " << user.getId();
	return QueryTransaction::seletMany(oss.str());
}
bool QueryTransaction::insertTransaction(Transaction transaction) {
	MYSQL* conn;
	bool result = false;
	try {
		conn = QueryTransaction::conn();
		transaction.setDate(Helper::getNowTime());
		result = QueryTransaction::insert(conn, (INSERT_TRANSACTION + " VALUES (NULL, '" + Helper::time_tToString(transaction.getDate()) + "', " + QueryTransaction::intToString(transaction.getUser().getId()) + ")"));
		if (result) {
			transaction.setId(QueryTransaction::selectCreateTransaction(transaction).getId());
			for (int i = 0; i < transaction.getOfferList().size(); i++) {
				QueryTransaction::insertTransactionOffer(conn, transaction, transaction.getOffer(i));
			}
		}
	} catch (std::exception) {}
	finally {
		QueryTransaction::close(conn);
	}
	return result;
}