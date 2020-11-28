#ifndef USER_H
#define USER_H

#pragma once
#include <string>
#include <sstream>

class User{
private:
	int id;
	std::string login;
	std::string password;
	int permission;
public:
	User();
	User(int id, std::string login, std::string password);
	User(int id, std::string login, std::string password, int permission);
	User(User& cUser);

	bool isClient();
	bool isEmployee();
	bool isAdmin();
	std::string print();

	void setId(int id);
	int getId();
	void setLogin(std::string login);
	std::string getLogin();
	void setPassword(std::string password);
	std::string getPassword();
	void setPermission(int permission);
	int getPermission();
};

#endif 