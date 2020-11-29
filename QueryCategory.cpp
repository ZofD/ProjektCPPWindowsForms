#include "pch.h"
#include "QueryCategory.h"

std::vector<Category> QueryCategory::selectAll() {
	std::vector<Category> categoryList;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn = QueryCategory::conn();
	std::ostringstream oss;
	oss << "SELECT id, name FROM category";
	res = QueryCategory::select(conn, oss.str());
	if (res != NULL) {
		while (row = mysql_fetch_row(res))
		{
			int id = atoi(row[0]);
			categoryList.push_back(Category(id, row[1]));
		}
	}
	QueryCategory::close(conn);
	return categoryList;
}