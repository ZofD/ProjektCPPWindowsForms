#include "pch.h"
#include "Transaction.h"

static const int WRONG_REQUEST = -1;

Transaction::Transaction() {
	this->offerList = {};
}
Transaction::Transaction(int id) {
	this->id = id;
	this->offerList = {};
}
Transaction::Transaction(User user) {
	this->user = user;
	this->offerList = {};
}
Transaction::Transaction(int id, time_t date) {
	this->id = id;
	this->date = date;
	this->user = User();
	this->offerList = {};
}
Transaction::Transaction(int id, time_t date, User user) {
	this->id = id;
	this->date = date;
	this->user = user;
	this->offerList = {};
}
Transaction::Transaction(Transaction& transaction) {
	this->id = transaction.getId();
	this->date = transaction.getDate();
	this->user = transaction.getUser();
	this->offerList = transaction.getOfferList();
}
Transaction::Transaction(const Transaction& transaction) {
	this->id = transaction.id;
	this->date = transaction.date;
	this->user = transaction.user;
	this->offerList = transaction.offerList;
}

bool Transaction::isWrongRequest() {
	return this->id == WRONG_REQUEST;
}

void Transaction::setWrongRequest() {
	this->id = WRONG_REQUEST;
}
void Transaction::setId(int id) {
	this->id = id;
}
int Transaction::getId() {
	return this->id;
}
void Transaction::setDate(time_t date) {
	this->date = date;
}
time_t Transaction::getDate() {
	return this->date;
}
void Transaction::setUser(User user) {
	this->user = user;
}
User Transaction::getUser() {
	return this->user;
}
void Transaction::setOfferList(std::vector<Offer> offerList) {
	this->offerList = offerList;
}
void Transaction::addOffer(Offer offer) {
	this->offerList.push_back(offer);
}
std::vector<Offer> Transaction::getOfferList() {
	return this->offerList;
}
Offer Transaction::getOffer(int index) {
	return this->offerList[index];
}