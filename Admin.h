#ifndef ADMIN_H
#define ADMIN_H

#pragma once
#include "User.h"
#include "Company.h"
#include "Category.h"
#include "Offer.h"
#include "Product.h"
#include "QueryProduct.h"
#include "QueryCategory.h"
#include "QueryCompany.h"
#include "QueryOffer.h"
class Admin : public User {
public:
	Admin(User user);

	std::vector<User> getAllUser();
	std::vector<Category> getAllCategory();
	std::vector<Company> getAllCompany();
	std::vector<Product> getAllProduct();
	std::vector<Transaction> getAllTransaction();
	std::vector<Offer> getAllOffer();
	std::vector<Offer> getAllActiveOffer();
	std::vector<Offer> getAllActiveOfferByProductName(std::string name);
	std::vector<Offer> getAllActiveOfferByCategory(Category category);
	std::vector<Offer> getAllActiveOfferByCompany(Company company);
	std::vector<Offer> getAllActiveOfferByCategoryAndCompany(Category category, Company company);

	bool addCategory(Category category);
	bool addCompany(Company company);
	bool addProduct(Product product);
	bool addOffer(Offer offer);
	bool addUser(User user);
	bool addTransaction(Transaction transaction);

	bool updateCategory(Category category);
	bool updateCompany(Company company);
	bool updateProduct(Product product);
	bool updateOffer(Offer offer);
	bool updateUser(User user);
	bool updateTransaction(Transaction transaction);

	bool deleteCategory(Category category);
	bool deleteCompany(Company company);
	bool deleteProduct(Product product);
	bool deleteOffer(Offer offer);
	bool deleteUser(User user);
	bool deleteTransaction(Transaction transaction);
};

#endif // !ADMIN_H