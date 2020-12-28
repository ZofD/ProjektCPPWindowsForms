#include "pch.h"
#include "User.h"

static const int UNDEFINED_PERMISSION = -1;
static const int ADMIN = 0;
static const int EMPLOYEE = 1;
static const int CLIENT = 2;

static const int WRONG_REQUEST = -1;

User::User() {}
User::User(int id, std::string login, std::string password) {
	this->id = id;
	this->login = login;
	this->password = password;
	this->permission = UNDEFINED_PERMISSION;
}
User::User(int id, std::string login, std::string password, int permission) {
	this->id = id;
	this->login = login;
	this->password = password;
	this->permission = permission;
}
User::User(User& cUser) {
	this->id = cUser.getId();
	this->login = cUser.getLogin();
	this->password = cUser.getPassword();
	this->permission = cUser.getPermission();
}

bool User::isClient() {
	return this->permission == CLIENT;
}
bool User::isEmployee() {
	return this->permission == EMPLOYEE;
}
bool User::isAdmin() {
	return this->permission == ADMIN;
}
bool User::isWrongRequest() {
	return (this->id == WRONG_REQUEST && this->permission == UNDEFINED_PERMISSION);
}
std::string User::print() {
	std::ostringstream oss;
	oss << "Id: " << this->id << " Login: " << this->login << " Password: " << this->password << " Permission: " << this->permission;
	return oss.str();
}

void User::setWrongRequest() {
	this->setId(WRONG_REQUEST);
	this->setPermission(UNDEFINED_PERMISSION);
}
void User::setId(int id) {
	this->id = id;
}
int User::getId() {
	return this->id;
}
void User::setLogin(std::string login) {
	this->login = login;
}
std::string User::getLogin() {
	return this->login;
}
void User::setPassword(std::string password) {
	this->password = password;
}
std::string User::getPassword() {
	return this->password;
}
void User::setPermission(int permission) {
	this->permission = permission;
}
int User::getPermission() {
	return this->permission;
}