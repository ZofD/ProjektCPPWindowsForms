#include "pch.h"
#include "Admin.h"
#include "QueryUser.h"

Admin::Admin(User user) : User(user) {}

std::vector<User> Admin::getAllUser() {
	return QueryUser::selectAll();
}
std::vector<Category> Admin::getAllCategory() {
	return QueryCategory::selectAll();
}
std::vector<Company> Admin::getAllCompany() {
	return QueryCompany::selectAll();
}
std::vector<Product> Admin::getAllProduct() {
	return QueryProduct::selectAll();
}
std::vector<Transaction> Admin::getAllTransaction() {
	return QueryTransaction::selectAll();
}
std::vector<Offer> Admin::getAllOffer() {
	return QueryOffer::selectAll();
}
std::vector<Offer> Admin::getAllActiveOffer() {
	return QueryOffer::selectAllActive();
}
std::vector<Offer> Admin::getAllActiveOfferByProductName(std::string name) {
	return QueryOffer::selectAllActiveByProductName(name);
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
bool Admin::addTransaction(Transaction transaction) {
	return QueryTransaction::insertTransaction(transaction);
}

bool Admin::updateCategory(Category category) {
	return QueryCategory::updateCategory(category);
}
bool Admin::updateCompany(Company company) {
	return QueryCompany::updateCompany(company);
}
bool Admin::updateProduct(Product product) {
	return QueryProduct::updateProduct(product);
}
bool Admin::updateOffer(Offer offer) {
	return QueryOffer::updateOffer(offer);
}
bool Admin::updateUser(User user) {
	return QueryUser::updateUser(user);
}
bool Admin::updateTransaction(Transaction transaction) {
	return QueryTransaction::updateTransaction(transaction);
}

bool Admin::deleteCategory(Category category) {
	return QueryCategory::deleteCategory(category);
}
bool Admin::deleteCompany(Company company) {
	return QueryCompany::deleteCompany(company);
}
bool Admin::deleteProduct(Product product) {
	return QueryProduct::deleteProduct(product);
}
bool Admin::deleteOffer(Offer offer) {
	return QueryOffer::deleteOffer(offer);
}
bool Admin::deleteUser(User user) {
	return QueryUser::deleteUser(user);
}
bool Admin::deleteTransaction(Transaction transaction) {
	return QueryTransaction::deleteTransaction(transaction);
}