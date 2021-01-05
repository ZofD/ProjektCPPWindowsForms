#include "pch.h"
#include "Admin.h"

Admin::Admin(User user) : User(user) {}

std::vector<Category> Admin::getAllCategory() {
	return QueryCategory::selectAll();
}
std::vector<Company> Admin::getAllCompany() {
	return QueryCompany::selectAll();
}
std::vector<Product> Admin::getAllProduct() {
	return QueryProduct::selectAll();
}
std::vector<Offer> Admin::getAllOffer() {
	return QueryOffer::selectAll();
}
std::vector<Offer> Admin::getAllActiveOffer() {
	return QueryOffer::selectAllActive();
}
std::vector<Offer> Admin::getAllActiveOfferByCategory(Category category) {
	return QueryOffer::selectAllActiveByCategory(category);
}
std::vector<Offer> Admin::getAllActiveOfferByCompany(Company company) {
	return QueryOffer::selectAllActiveByCompany(company);
}
std::vector<Offer> Admin::getAllActiveOfferByCategoryAndCompany(Category category, Company company) {
	return QueryOffer::selectAllActiveByCategoryAndCompany(category, company);
}

bool Admin::addCategory(Category category) {
	return QueryCategory::addCategory(category);
}
bool Admin::addCompany(Company company) {
	return QueryCompany::addCompany(company);
}
bool Admin::addProduct(Product product) {
	return QueryProduct::addProduct(product);
}
bool Admin::addOffer(Offer offer) {
	return QueryOffer::addOffer(offer);
}
bool Admin::addUser(User user) {
	return QueryUser::addUser(user);
}