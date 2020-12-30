#ifndef QUERYUSER_H
#define QUERYUSER_H

#pragma once
#include <string>
#include "Query.h"
#include "User.h"

class QueryUser : public Query{
private:
	static User seletOnce(std::string query);
	static std::vector<User> seletMany(std::string query);
public:
	QueryUser();

	static User selectUserByLogin (std::string login);
	static User selectUserByLoginAndPassword (std::string login, std::string password);
	static bool addUser(User user);
};

#endif