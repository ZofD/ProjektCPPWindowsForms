#include "pch.h"
#include "Employee.h"

Employee::Employee(User user) : User(user) {}

std::vector<Category> Employee::getAllCategory() {
	return QueryCategory::selectAll();
}
std::vector<Company> Employee::getAllCompany() {
	return QueryCompany::selectAll();
}
std::vector<Product> Employee::getAllProduct() {
	return QueryProduct::selectAll();
}
std::vector<Offer> Employee::getAllOffer() {
	return QueryOffer::selectAll();
}
std::vector<Offer> Employee::getAllActiveOffer() {
	return QueryOffer::selectAllActive();
}
std::vector<Offer> Employee::getAllActiveOfferByProductName(std::string name) {
	return QueryOffer::selectAllActiveByProductName(name);
}
std::vector<Offer> Employee::getAllActiveOfferByCategory(Category category) {
	return QueryOffer::selectAllActiveByCategory(category);
}
std::vector<Offer> Employee::getAllActiveOfferByCompany(Company company) {
	return QueryOffer::selectAllActiveByCompany(company);
}
std::vector<Offer> Employee::getAllActiveOfferByCategoryAndCompany(Category category, Company company) {
	return QueryOffer::selectAllActiveByCategoryAndCompany(category, company);
}

bool Employee::addCategory(Category category) {
	return QueryCategory::addCategory(category);
}
bool Employee::addCompany(Company company) {
	return QueryCompany::addCompany(company);
}
bool Employee::addProduct(Product product) {
	return QueryProduct::addProduct(product);
}
bool Employee::addOffer(Offer offer) {
	return QueryOffer::addOffer(offer);
}