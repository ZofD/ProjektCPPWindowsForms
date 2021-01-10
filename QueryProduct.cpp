#include "pch.h"
#include "QueryProduct.h"

const std::string SELECT_PRODUCT = "SELECT p.id, p.name, p.id_category, cat.name, p.id_company, com.name "
			"FROM product AS p, category AS cat, company AS com WHERE p.id_category=cat.id AND p.id_company=com.id";
const std::string INSERT_PRODUCT = "INSERT INTO product (id, name, id_company, id_category) ";
const std::string DELETE_PRODUCT = "DELETE FROM product WHERE id=";

Product QueryProduct::seletOnce(std::string query) {
	Product result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryProduct::conn();
		res = QueryProduct::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result = QueryProduct::mySQLRowToProduct(row);
			}
		}
		else {
			result.setId(-1);
		}
	}
	catch (std::exception) {
		result.setId(-1);
	}
	finally {
		QueryProduct::close(conn);
	}
	return result;
}
std::vector<Product> QueryProduct::seletMany(std::string query) {
	std::vector<Product> result;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	try {
		conn = QueryProduct::conn();
		res = QueryProduct::select(conn, query);
		if (res != NULL) {
			while (row = mysql_fetch_row(res))
			{
				result.push_back(QueryProduct::mySQLRowToProduct(row));
			}
		}
	}
	catch (std::exception) {}
	finally {
		QueryProduct::close(conn);
	}
	return result;
}

std::vector<Product> QueryProduct::selectAll() {
	return QueryProduct::seletMany(SELECT_PRODUCT);
}

bool QueryProduct::addProduct(Product product) {
	return QueryProduct::insert( (INSERT_PRODUCT + " VALUES (NULL, '" + product.getName() + "', " + QueryProduct::intToString(product.getCompany().getId()) + ", " + QueryProduct::intToString(product.getCategory().getId()) + ")" ) );
}
bool QueryProduct::updateProduct(Product product) {
	return QueryProduct::update("UPDATE product SET name='" + product.getName() +"', id_company=" + QueryProduct::intToString(product.getCompany().getId()) + ", id_category=" + QueryProduct::intToString(product.getCategory().getId()) + " WHERE id=" + QueryProduct::intToString(product.getId()));
}
bool QueryProduct::deleteProduct(Product product) {
	return QueryProduct::del(DELETE_PRODUCT + QueryProduct::intToString(product.getId()));
}