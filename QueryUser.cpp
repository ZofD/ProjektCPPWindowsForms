#include "pch.h"
#include "QueryUser.h"

QueryUser::QueryUser(){}

User QueryUser::selectUserByLoginAndPassword (std::string login, std::string password){
	User user;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn = this->conn();
	std::ostringstream oss;
	oss << "SELECT ID, login, password, permission FROM user WHERE login='" << login << "' AND password='" << password << "'";
	res = this->select(conn, oss.str());
	if (res != NULL) {
		while (row = mysql_fetch_row(res))
		{
			int id = atoi(row[0]);
			int permission = atoi(row[3]);
			User tmp(id, row[1], row[2], permission);
			user = tmp;
		}
	}
	else {
		user.setId(-1);
		user.setPermission(-1);
	}
	this->close(conn);
	return user;
}