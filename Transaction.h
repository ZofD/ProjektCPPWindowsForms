#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma once
#include <vector>
#include "Offer.h"

class Transaction{
private:
	int id;
	time_t date;
	User user;
	std::vector<Offer> offerList;
public:
	Transaction();
	Transaction(int id);
	Transaction(int id, time_t date, User user);

	void setId(int id);
	int getId();
	void setDate(time_t date);
	time_t getDate();
	void setUser(User user);
	User getUser();
	void setOfferList(std::vector<Offer> offerList);
	void addOffer(Offer offer);
	std::vector<Offer> getOfferList();
	Offer getOffer(int index);
};

#endif // !TRANSACTION_H