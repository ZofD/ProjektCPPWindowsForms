#include "pch.h"
#include "Offer.h"

Offer::Offer() {}
Offer::Offer(int id, double price) {
	this->id = id;
	this->price = price;
}
Offer::Offer(int id, double price, time_t startDate, time_t stopDate, Product product) {
	this->id = id;
	this->price = price;
	this->startDate = startDate;
	this->stopDate = stopDate;
	this->product = product;
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