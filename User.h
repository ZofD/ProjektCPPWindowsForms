#ifndef USER_H
#define USER_H

#pragma once
#include <string>
#include <sstream>
#include <mysql.h>

class User{
protected:
	int id;
	std::string login;
	std::string password;
	int permission;
public:
	User();
	User(std::string login, std::string password);
	User(std::string login, std::string password, int permission);
	User(int id, std::string login, std::string password);
	User(int id, std::string login, std::string password, int permission);
	User(User& cUser);

	bool isClient();
	bool isEmployee();
	bool isAdmin();
	bool isWrongRequest();
	bool isNull();
	std::string print();

	void setWrongRequest();
	void setNull();
	void setId(int id);
	int getId();
	void setLogin(std::string login);
	std::string getLogin();
	void setPassword(std::string password);
	std::string getPassword();
	void setPermission(int permission);
	void setPermissionClient();
	void setPermissionEmployee();
	void setPermissionAdmin();
	int getPermission();
};

#endif 