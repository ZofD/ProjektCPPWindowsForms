#ifndef QUERY_H
#define QUERY_H

#pragma once
#include <mysql.h>
#include <string>

class Query{
protected:
	MYSQL* conn();
	void close(MYSQL* conn);
	const char* stringToConstChar(std::string text);
	MYSQL_RES* select(MYSQL* conn, std::string query);
};

#endif