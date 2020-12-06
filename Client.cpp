#include "pch.h"
#include "Client.h"

Client::Client(User user) : User(user) {
	this->myTransaction = QueryTransaction::selectUserTransaction(user);
	if(this->myTransaction.empty())
		this->myTransaction = QueryTransaction::selectUserTransaction(user);
}

std::vector<Category> Client::getAllCategory() {
	return QueryCategory::selectAll();
}
std::vector<Company> Client::getAllCompany() {
	return QueryCompany::selectAll();
}
std::vector<Offer> Client::getAllActiveOffer() {
	return QueryOffer::selectAllActive();
}

void Client::setMyTransaction(std::vector<Transaction> trasaction) {
	this->myTransaction = trasaction;
}
std::vector<Transaction> Client::getMyTransaction() {
	return this->myTransaction;
}