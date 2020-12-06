#include "pch.h"
#include "Query.h"

static const char* ADDRES = "localhost";
static const int PORT = 3306;
static const char* DATABASE = "cppsklep";
static const char* USERNAME = "root";
static const char* PASSWORD = "password";

MYSQL* Query::conn() {
	return mysql_real_connect(mysql_init(0), ADDRES, USERNAME, PASSWORD, DATABASE, PORT, NULL, 0);
}

void Query::close(MYSQL* conn) {
	mysql_close(conn);
}

const char* Query::stringToConstChar(std::string text) {
	return text.c_str();
}

MYSQL_RES* Query::select(MYSQL* conn, std::string query) {
	int qstate;
	MYSQL_RES* res;
	if (conn) {
		qstate = mysql_query(conn, Query::stringToConstChar(query));
		if (!qstate) {
			res = mysql_store_result(conn);
		}
		else {
			res = NULL;
		}
	}
	else {
		res = NULL;
	}
	return res;
}

User Query::mySQLRowToUser(char* id, char* login, char* password, char* permission) {
	return User(atoi(id), std::string(login), std::string(password), atoi(permission));
}
Category Query::mySQLRowToCategory(char* id, char* name) {
	return Category(atoi(id), std::string(name));
}
Company Query::mySQLRowToCompany(char* id, char* name) {
	return Company(atoi(id), std::string(name));
}
Product Query::mySQLRowToProduct(char* id, char* name, Category category, Company company) {
	return Product(atoi(id), std::string(name), company, category);
}
Offer Query::mySQLRowToOffer(char* id, char* price, char* startDate, char* stopDate, Product product) {
	return Offer(atoi(id), atof(price), Helper::stringToTime_t(startDate), Helper::stringToTime_t(stopDate), product);
}
Offer Query::mySQLRowToOfferNull(char* id, char* price, char* startDate, Product product) {
	return Offer(atoi(id), atof(price), Helper::stringToTime_t(startDate), product);
}
Transaction Query::mySQLRowToTransaction(char* id, char* date, User user) {
	return Transaction(atoi(id), Helper::stringToTime_t(date), user);
}

User Query::mySQLRowToUser(MYSQL_ROW row) {
	return Query::mySQLRowToUser(row[0], row[1], row[2], row[3]);
}
Category Query::mySQLRowToCategory(MYSQL_ROW row) {
	return Query::mySQLRowToCategory(row[0], row[1]);
}
Company Query::mySQLRowToCompany(MYSQL_ROW row) {
	return Query::mySQLRowToCompany(row[0], row[1]);
}
Product Query::mySQLRowToProduct(MYSQL_ROW row) {
	return Query::mySQLRowToProduct(row[4], row[5],
		Query::mySQLRowToCategory(row[0], row[1]),
		Query::mySQLRowToCompany(row[2], row[3]));
}
Offer Query::mySQLRowToOffer(MYSQL_ROW row) {
	return Query::mySQLRowToOffer(row[6], row[7], row[8], row[9],
		Query::mySQLRowToProduct(row[4], row[5],
			Query::mySQLRowToCategory(row[0], row[1]),
			Query::mySQLRowToCompany(row[2], row[3]))
	);
}
Offer Query::mySQLRowToOfferNull(MYSQL_ROW row) {
	return Query::mySQLRowToOfferNull(row[6], row[7], row[8],
		Query::mySQLRowToProduct(row[4], row[5],
			Query::mySQLRowToCategory(row[0], row[1]),
			Query::mySQLRowToCompany(row[2], row[3]))
	);
}
Transaction Query::mySQLRowToTransaction(MYSQL_ROW row) {
	return Query::mySQLRowToTransaction(row[0], row[1], Query::mySQLRowToUser(row[2], row[3], row[4], row[5]));
}