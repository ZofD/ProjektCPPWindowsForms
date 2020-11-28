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
		qstate = mysql_query(conn, this->stringToConstChar(query));
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