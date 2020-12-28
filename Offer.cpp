#include "pch.h"
#include "Offer.h"

static const int WRONG_REQUEST = -1;

Offer::Offer() {}
Offer::Offer(int id, double price) {
	this->id = id;
	this->price = price;
}
Offer::Offer(int id, double price, time_t startDate, time_t stopDate) {
	this->id = id;
	this->price = price;
	this->startDate = startDate;
	this->stopDate = stopDate;
}
Offer::Offer(int id, double price, time_t startDate, Product product) {
	this->id = id;
	this->price = price;
	this->startDate = startDate;
	this->stopDate = (time_t)(-1);
	this->product = product;
}
Offer::Offer(int id, double price, time_t startDate, time_t stopDate, Product product) {
	this->id = id;
	this->price = price;
	this->startDate = startDate;
	this->stopDate = stopDate;
	this->product = product;
}

bool Offer::isWrongRequest() {
	return this->id == WRONG_REQUEST;
}

void Offer::setWrongRequest() {
	this->id = WRONG_REQUEST;
}
void Offer::setId(int id) {
	this->id = id;
}
int Offer::getId() {
	return this->id;
}
void Offer::setPrice(double price) {
	this->price = price;
}
double Offer::getPrice() {
	return this->price;
}
void Offer::setStartDate(time_t startDate) {
	this->startDate = startDate;
}
time_t Offer::getStartDate() {
	return this->startDate;
}
void Offer::setStopDate(time_t stopDate) {
	this->stopDate = stopDate;
}
time_t Offer::getStopDate() {
	return this->stopDate;
}
void Offer::setProduct(Product product) {
	this->product = product;
}
Product Offer::getProduct() {
	return this->product;
}