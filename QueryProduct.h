#ifndef QUERY_PRODUCT_H
#define QUERY_PRODUCT_H

#pragma once
#include "Query.h"
#include "Product.h"
class QueryProduct : public Query{
private:
	static Product seletOnce(std::string query);
	static std::vector<Product> seletMany(std::string query);
public:
	static std::vector<Product> selectAll();
};

#endif // !QUERY_PRODUCT_H