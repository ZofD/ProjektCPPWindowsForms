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
	Admin(User user);

	std::vector<Category> getAllCategory();
	std::vector<Company> getAllCompany();
	std::vector<Product> getAllProduct();
	std::vector<Offer> getAllOffer();
	std::vector<Offer> getAllActiveOffer();
	std::vector<Offer> getAllActiveOfferByCategory(Category category);
	std::vector<Offer> getAllActiveOfferByCompany(Company company);
	std::vector<Offer> getAllActiveOfferByCategoryAndCompany(Category category, Company company);

	bool addCategory(Category category);
	bool addCompany(Company company);
	bool addProduct(Product product);
	bool addOffer(Offer offer);
	bool addUser(User user);
};

#endif // !ADMIN_H