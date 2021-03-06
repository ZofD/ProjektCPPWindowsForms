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
std::vector<Offer> Client::getAllActiveOfferByProductName(std::string name) {
	return QueryOffer::selectAllActiveByProductName(name);
}
std::vector<Offer> Client::getAllActiveOfferByCategory(Category category) {
	return QueryOffer::selectAllActiveByCategory(category);
}
std::vector<Offer> Client::getAllActiveOfferByCompany(Company company) {
	return QueryOffer::selectAllActiveByCompany(company);
}
std::vector<Offer> Client::getAllActiveOfferByCategoryAndCompany(Category category, Company company) {
	return QueryOffer::selectAllActiveByCategoryAndCompany(category, company);
}

bool Client::addNewTransaction(Transaction newTransaction) {
	bool result = QueryTransaction::insertTransaction(newTransaction);
	this->myTransaction = QueryTransaction::selectUserTransaction(User(this->id, this->login, this->password, this->permission));
	return result;
}

void Client::setMyTransaction(std::vector<Transaction> trasaction) {
	this->myTransaction = trasaction;
}
std::vector<Transaction> Client::getMyTransaction() {
	return this->myTransaction;
}