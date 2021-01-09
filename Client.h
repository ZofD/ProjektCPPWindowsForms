#ifndef CLIENT_H
#define CLIENT_H

#pragma once
#include <vector>
#include "User.h"
#include "Transaction.h"
#include "Company.h"
#include "Category.h"
#include "Offer.h"
#include "QueryCategory.h"
#include "QueryCompany.h"
#include "QueryOffer.h"
#include "QueryTransaction.h"

class Client : public User{
private:
	std::vector<Transaction> myTransaction;
public:
	Client(User user);

	std::vector<Category> getAllCategory();
	std::vector<Company> getAllCompany();
	std::vector<Offer> getAllActiveOffer();
	std::vector<Offer> getAllActiveOfferByProductName(std::string name);
	std::vector<Offer> getAllActiveOfferByCategory(Category category);
	std::vector<Offer> getAllActiveOfferByCompany(Company company);
	std::vector<Offer> getAllActiveOfferByCategoryAndCompany(Category category, Company company);

	bool addNewTransaction(Transaction newTransaction);

	void setMyTransaction(std::vector<Transaction> trasaction);
	std::vector<Transaction> getMyTransaction();
};

#endif // !CLIENT_H