#ifndef QUERY_PRODUCT_H
#define QUERY_PRODUCT_H

#pragma once
#include <vector>
#include "Query.h"
#include "Product.h"
#include "Helper.h"

class QueryProduct : public Query{
private:
	static Product seletOnce(std::string query);
	static std::vector<Product> seletMany(std::string query);
public:
	static std::vector<Product> selectAll();

	static bool addProduct(Product product);
	static bool updateProduct(Product product);
	static bool deleteProduct(Product product);
};

#endif // !QUERY_PRODUCT_H