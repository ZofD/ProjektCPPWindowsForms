#ifndef QUERY_H
#define QUERY_H

#pragma once
#include <mysql.h>
#include <string>

class Query{
private:
	static User mySQLRowToUser(char* id, char* login, char* password, char* permission);
	static Category mySQLRowToCategory(char* id, char* name);
	static Company mySQLRowToCompany(char* id, char* name);
	static Product mySQLRowToProduct(char* id, char* name, Category category, Company company);
	static Offer mySQLRowToOffer(char* id, char* price, char* startDate, char* stopDate, Product product);
	static Offer mySQLRowToOfferNull(char* id, char* price, char* startDate, Product product);
	static Transaction mySQLRowToTransaction(char* id, char* date, User user);
public:
	static MYSQL* conn();
	static void close(MYSQL* conn);
	static const char* stringToConstChar(std::string text);
	static std::string intToString(int number);
	static std::string doubleToString(double number);
	static MYSQL_RES* select(MYSQL* conn, std::string query);
	static bool insert(MYSQL* conn, std::string query);
	static bool insert(std::string query);

	static User mySQLRowToUser(MYSQL_ROW row);
	static Category mySQLRowToCategory(MYSQL_ROW row);
	static Company mySQLRowToCompany(MYSQL_ROW row);
	static Product mySQLRowToProduct(MYSQL_ROW row);
	static Offer mySQLRowToOffer(MYSQL_ROW row);
	static Offer mySQLRowToOfferNull(MYSQL_ROW row);
	static Transaction mySQLRowToTransaction(MYSQL_ROW row);
};

#endif