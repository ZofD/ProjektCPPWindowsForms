#ifndef QUERY_H
#define QUERY_H

#pragma once
#include <mysql.h>
#include <string>

class Query{
protected:
	static MYSQL* conn();
	static void close(MYSQL* conn);
	static const char* stringToConstChar(std::string text);
	static MYSQL_RES* select(MYSQL* conn, std::string query);
};

#endif