#include "pch.h"
#include "QueryUser.h"

const std::string SELECT_USER = "SELECT ID, login, password, permission FROM user ";
const std::string INSERT_USER = "INSERT INTO `user`(`ID`, `login`, `password`, `permission`) VALUES ";

QueryUser::QueryUser(){}

User QueryUser::seletOnce(std::string query) {
	User result = User();
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryUser::conn();
		res = QueryUser::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result = QueryUser::mySQLRowToUser(row);
			}
		}
		else {
			result.setWrongRequest();
		}
	} catch (std::exception) {
		result.setWrongRequest();
	} finally {
		QueryUser::close(conn);
	}
	return result;
}
std::vector<User> QueryUser::seletMany(std::string query) {
	std::vector<User> result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryUser::conn();
		res = QueryUser::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
			result.push_back(QueryUser::mySQLRowToUser(row));
			}
		}
	}
	catch (std::exception) {}
	finally {
		QueryUser::close(conn);
	}
	return result;
}

User QueryUser::selectUserByLogin(std::string login) {
	std::ostringstream oss;
	oss << SELECT_USER << " WHERE login='" << login << "';";
	return QueryUser::seletOnce(oss.str());
}
User QueryUser::selectUserByLoginAndPassword (std::string login, std::string password){
	std::ostringstream oss;
	oss << SELECT_USER <<" WHERE login='" << login << "' AND password='" << password << "'";
	return QueryUser::seletOnce(oss.str());
}
bool QueryUser::addUser(User user) {
	bool result = false;
	if (QueryUser::selectUserByLogin(user.getLogin()).isNull()) {
		result = QueryUser::insert( (INSERT_USER + " (NULL, '" + user.getLogin() +"', '" + user.getPassword() + "', '" + QueryUser::intToString(user.getPermission()) + "') ") );
	}
	return result;
}