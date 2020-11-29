#include "pch.h"
#include "QueryCompany.h"

std::vector<Company> QueryCompany::selectAll() {
	std::vector<Company> companyList;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn = QueryCategory::conn();
	std::ostringstream oss;
	oss << "SELECT id, name FROM company";
	res = QueryCategory::select(conn, oss.str());
	if (res != NULL) {
		while (row = mysql_fetch_row(res))
		{
			int id = atoi(row[0]);
			companyList.push_back(Company(id, row[1]));
		}
	}
	QueryCategory::close(conn);
	return companyList;
}