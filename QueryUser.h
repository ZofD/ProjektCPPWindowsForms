#ifndef QUERYUSER_H
#define QUERYUSER_H

#pragma once
#include <string>
#include "Query.h"
#include "User.h"

class QueryUser : public Query {
public:
	QueryUser();
	static User selectUserByLoginAndPassword (std::string login, std::string password);
};

#endif