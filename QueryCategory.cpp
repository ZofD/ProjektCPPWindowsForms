#include "pch.h"
#include "QueryCategory.h"

const std::string SELECT_CATEGORY = "SELECT id, name FROM category ";
const std::string INSERT_CATEGORY = "INSERT INTO category (id, name) ";
const std::string DELETE_CATEGORY = "DELETE FROM category WHERE id=";

Category QueryCategory::seletOnce(std::string query) {
	Category result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryCategory::conn();
		res = QueryCategory::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result = QueryCategory::mySQLRowToCategory(row);
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
		QueryCategory::close(conn);
	}
	return result;
}
std::vector<Category> QueryCategory::seletMany(std::string query) {
	std::vector<Category> result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryCategory::conn();
		res = QueryCategory::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result.push_back(QueryCategory::mySQLRowToCategory(row));
			}
		}
	}
	catch (std::exception) {}
	finally {
		QueryCategory::close(conn);
	}
	return result;
}

std::vector<Category> QueryCategory::selectAll() {
	return QueryCategory::seletMany(SELECT_CATEGORY);
}

bool QueryCategory::addCategory(Category category) {
	return QueryCategory::insert( (INSERT_CATEGORY + " VALUES (NULL, '" + category.getName() + "')") );
}
bool QueryCategory::updateCategory(Category category) {
	return QueryCategory::update("UPDATE category SET name='" + category.getName() + "' WHERE id=" + QueryCategory::intToString(category.getId()));
}
bool QueryCategory::deleteCategory(Category category) {
	return QueryCategory::del( (DELETE_CATEGORY + QueryCategory::intToString(category.getId())) );
}