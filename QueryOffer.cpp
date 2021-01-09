#include "pch.h"
#include "QueryOffer.h"

const static std::string SELECT_OFFER = "SELECT p.id_category, cat.name, p.id_company, com.name, o.id_product, p.name,"
										"o.id, o.price, o.start_date, o.stop_date "
										"FROM offer AS o, product AS p, company AS com, category AS cat "
										"WHERE o.id_product = p.id AND p.id_company = com.id AND p.id_category = cat.id ";
const static std::string SELECT_OFFER_FROM_TRANSACTION_OFFER = "SELECT p.id_category, cat.name, p.id_company, com.name, o.id_product, "
										"p.name, t_o.id_offer, o.price, o.start_date, o.stop_date "
										"FROM transaction_offer AS t_o, offer AS o, product AS p, company AS com, category AS cat "
										"WHERE o.id_product = p.id AND p.id_company = com.id AND p.id_category = cat.id AND t_o.id_offer = o.id ";
const static std::string INSERT_OFFER = "INSERT INTO offer (id, price, start_date, stop_date, id_product) ";
const static std::string DELETE_OFFER = "DELETE FROM offer WHERE id=";

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

std::vector<Offer> QueryOffer::selectAll() {
	return QueryOffer::seletManyOffer(SELECT_OFFER);
}
std::vector<Offer> QueryOffer::selectAllActive() {
	time_t now = time(0);
	std::string nowDate = Helper::time_tToString(now);
	std::string query = (SELECT_OFFER + " AND o.start_date<=\'" + nowDate + "\' AND (o.stop_date>=\'" + nowDate + "\' OR o.stop_date IS NULL) ");
	return QueryOffer::seletManyOffer(query);
}
std::vector<Offer> QueryOffer::selectAllActiveByCategory(Category category) {
	time_t now = time(0);
	std::string nowDate = Helper::time_tToString(now);
	std::string query = (SELECT_OFFER + " AND o.start_date<=\'" + nowDate + "\' AND (o.stop_date>=\'" + nowDate + "\' OR o.stop_date IS NULL) "
						"AND p.id_category=" + std::to_string(category.getId()));
	return QueryOffer::seletManyOffer(query);
}
std::vector<Offer> QueryOffer::selectAllActiveByCompany(Company company) {
	time_t now = time(0);
	std::string nowDate = Helper::time_tToString(now);
	std::string query = (SELECT_OFFER + " AND o.start_date<=\'" + nowDate + "\' AND (o.stop_date>=\'" + nowDate + "\' OR o.stop_date IS NULL) "
						"AND p.id_company=" + std::to_string(company.getId()));
	return QueryOffer::seletManyOffer(query);
}
std::vector<Offer> QueryOffer::selectAllActiveByCategoryAndCompany(Category category, Company company) {
	time_t now = time(0);
	std::string nowDate = Helper::time_tToString(now);
	std::string query = (SELECT_OFFER + " AND o.start_date<=\'" + nowDate + "\' AND (o.stop_date>=\'" + nowDate + "\' OR o.stop_date IS NULL) "
						"AND p.id_category=" + std::to_string(category.getId()) + " AND p.id_company=" + std::to_string(company.getId()));
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

bool QueryOffer::addOffer(Offer offer) {
	if (offer.getStopDate()==Helper::getNullTime()) {
		return QueryOffer::addOfferStopDateNull(offer);
	}
	return QueryOffer::insert( (INSERT_OFFER + " VALUES (NULL, " + QueryOffer::doubleToString(offer.getPrice()) + ", '" + Helper::time_tToString(offer.getStartDate()) + "', '"
		+ Helper::time_tToString(offer.getStopDate()) + "', " + QueryOffer::intToString(offer.getProduct().getId()) + ")") );
}
bool QueryOffer::addOfferStopDateNull(Offer offer) {
	return QueryOffer::insert( (INSERT_OFFER + " VALUES (NULL, " + QueryOffer::doubleToString(offer.getPrice()) + ", '" + Helper::time_tToString(offer.getStartDate()) + "', NULL"
		+ ", " + QueryOffer::intToString(offer.getProduct().getId()) + ")") );
}
bool QueryOffer::updateOffer(Offer offer) {
	if (offer.getStopDate() == Helper::getNullTime()) {
		return QueryOffer::update(("UPDATE offer SET price=" + QueryOffer::doubleToString(offer.getPrice()) + ", start_date='" + Helper::time_tToString(offer.getStartDate()) + "', stop_date=NULL, id_product=" + QueryOffer::intToString(offer.getProduct().getId()) + " WHERE id=" + QueryOffer::intToString(offer.getId())));
	}
	return QueryOffer::update( ("UPDATE offer SET price=" + QueryOffer::doubleToString(offer.getPrice()) + ", start_date='" + Helper::time_tToString(offer.getStartDate()) + "', stop_date='" + Helper::time_tToString(offer.getStopDate()) + "', id_product=" + QueryOffer::intToString(offer.getProduct().getId()) + " WHERE id=" + QueryOffer::intToString(offer.getId())) );
}
bool QueryOffer::deleteOffer(Offer offer) {
	return QueryOffer::del( (DELETE_OFFER + QueryOffer::intToString(offer.getId())) );
}