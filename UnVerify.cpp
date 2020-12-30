#include "pch.h"
#include "UnVerify.h"
#include "QueryUser.h"

User UnVerify::logIn(std::string login, std::string password) {
	QueryUser queryUser;
	return queryUser.selectUserByLoginAndPassword(login, password);
}
bool UnVerify::registration(std::string login, std::string password) {
	QueryUser queryUser;
	User user(login, password);
	user.setPermissionClient();
	return queryUser.addUser(user);
}