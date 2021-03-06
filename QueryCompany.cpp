#include "pch.h"
#include "QueryCompany.h"

const std::string SELECT_COMPANY = "SELECT id, name FROM company ";
const std::string INSERT_COMPANY = "INSERT INTO company (id, name) ";
const std::string DELETE_COMAPNY = "DELETE FROM company WHERE id=";

Company QueryCompany::seletOnce(std::string query) {
	Company result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryCompany::conn();
		res = QueryCompany::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result = QueryCompany::mySQLRowToCompany(row);
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
		QueryCompany::close(conn);
	}
	return result;
}
std::vector<Company> QueryCompany::seletMany(std::string query) {
	std::vector<Company> result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryCompany::conn();
		res = QueryCompany::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result.push_back(QueryCompany::mySQLRowToCompany(row));
			}
		}
	}
	catch (std::exception) {}
	finally {
		QueryCompany::close(conn);
	}
	return result;
}

std::vector<Company> QueryCompany::selectAll() {
	return QueryCompany::seletMany(SELECT_COMPANY);
}

bool QueryCompany::addCompany(Company company) {
	return QueryCompany::insert( (INSERT_COMPANY + " VALUES (NULL, '" + company.getName() + "')") );
}
bool QueryCompany::updateCompany(Company company) {
	return QueryCompany::update("UPDATE company SET name='" + company.getName() + "' WHERE id=" + QueryCompany::intToString(company.getId()));
}
bool QueryCompany::deleteCompany(Company company) {
	return QueryCompany::del( (DELETE_COMAPNY + QueryCompany::intToString(company.getId())) );
}