#include "pch.h"
#include "UnVerify.h"
#include "QueryUser.h"

User UnVerify::logIn(std::string login, std::string password) {
	QueryUser queryUser;
	return queryUser.selectUserByLoginAndPassword(login, password);
}