#ifndef CLIENT_H
#define CLIENT_H

#pragma once
#include <vector>
#include "User.h"
#include "Transaction.h"
#include "Category.h"
#include "QueryCategory.h"

class Client : public User{
private:
	Transaction transactionUser;
public:
	Client(User user);

	std::vector<Category> getAllCategory();

	void setTransactionUser(Transaction trasaction);
	Transaction getTransactionUser();
};

#endif // !CLIENT_H