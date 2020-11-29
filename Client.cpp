#include "pch.h"
#include "Client.h"

Client::Client(User user) : User(user) {

}

std::vector<Category> Client::getAllCategory() {
	return QueryCategory::selectAll();
}
std::vector<Company> Client::getAllCompany() {
	return QueryCompany::selectAll();
}

void Client::setTransactionUser(Transaction trasaction) {
	this->transactionUser = trasaction;
}
Transaction Client::getTransactionUser() {
	return this->transactionUser;
}