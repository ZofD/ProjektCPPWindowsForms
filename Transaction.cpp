#include "pch.h"
#include "Transaction.h"

Transaction::Transaction() {
	this->offerList = {};
}
Transaction::Transaction(int id) {
	this->id = id;
	this->offerList = {};
}
Transaction::Transaction(int id, time_t date, User user) {
	this->id = id;
	this->date = date;
	this->user = user;
	this->offerList = {};
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