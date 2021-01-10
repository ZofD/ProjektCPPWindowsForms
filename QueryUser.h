#ifndef QUERYUSER_H
#define QUERYUSER_H

#pragma once
#include <vector>
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
	static std::vector<User> selectAll();
	static bool addUser(User user);
	static bool updateUser(User user);
	static bool deleteUser(User user);
};

#endif