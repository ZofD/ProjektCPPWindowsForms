#ifndef OFFER_H
#define OFFER_H

#pragma once
#include "Product.h"

class Offer{
private:
	int id;
	double price;
	time_t startDate;
	time_t stopDate;
	Product product;
public:
	Offer();
	Offer(int id, double price);
	Offer(int id, double price, time_t startDate, time_t stopDate);
	Offer(int id, double price, time_t startDate, Product product);
	Offer(int id, double price, time_t startDate, time_t stopDate, Product product);

	bool isWrongRequest();

	void setWrongRequest();
	void setId(int id);
	int getId();
	void setPrice(double price);
	double getPrice();
	void setStartDate(time_t startDate);
	time_t getStartDate();
	void setStopDate(time_t stopDate);
	time_t getStopDate();
	void setProduct(Product product);
	Product getProduct();
};

#endif // !OFFER_H