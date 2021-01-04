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
std::vector<Offer> Employee::getAllActiveOfferByCategory(Category category) {
	return QueryOffer::selectAllActiveByCategory(category);
}
std::vector<Offer> Employee::getAllActiveOfferByCompany(Company company) {
	return QueryOffer::selectAllActiveByCompany(company);
}
std::vector<Offer> Employee::getAllActiveOfferByCategoryAndCompany(Category category, Company company) {
	return QueryOffer::selectAllActiveByCategoryAndCompany(category, company);
}