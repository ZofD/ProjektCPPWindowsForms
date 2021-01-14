#include "pch.h"
#include "AdminPanel.h"

void ProjektCPPWindowsForms::AdminPanel::setAdmin(User user) {
	this->admin = new Admin(user);
	this->user->Text = gcnew String(this->admin->getLogin().c_str());
}

void ProjektCPPWindowsForms::AdminPanel::setItems(std::vector<User> users, std::vector<Company> companies, std::vector<Category> categories,
		std::vector<Product> products, std::vector<Offer> offers, std::vector<Transaction> transactions) {
	this->setUsers(users);
	this->setCompanies(companies);
	this->setCategories(categories);
	this->setProducts(products);
	this->setOffers(offers);
	this->setTransactions(transactions);
}

void ProjektCPPWindowsForms::AdminPanel::setUsers(std::vector<User> users) {
	this->listOfUsers->BeginUpdate();
	for (User user : users) {
		String^ userID = gcnew String(user.getId().ToString());
		String^ userLogin = gcnew String(user.getLogin().c_str());
		String^ userPassword = gcnew String(user.getPassword().c_str());
		String^ role;
		switch (user.getPermission())
		{
		case 0:
			role = "Administrator";
			break;
		case 1:
			role = "Pracownik";
			break;
		case 2:
			role = "Klient";
			break;
		}
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
			userID,
				userLogin, userPassword, role
		}, -1));
		this->listOfUsers->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
	}
	this->listOfUsers->EndUpdate();
	//this->Controls->Add(this->listOfUsers);
}

void ProjektCPPWindowsForms::AdminPanel::setCompanies(std::vector<Company> companies) {
	this->listOfCompanies->BeginUpdate();
	for (Company company : companies) {
		String^ companyID = gcnew String(company.getId().ToString());
		String^ companyName = gcnew String(company.getName().c_str());
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
			companyID,
				companyName
		}, -1));
		this->listOfCompanies->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
	}
	this->listOfCompanies->EndUpdate();
	//this->Controls->Add(this->listOfCompanies);
}
void ProjektCPPWindowsForms::AdminPanel::setCategories(std::vector<Category> categories) {
	this->listOfCategories->BeginUpdate();
	for (Category category : categories) {
		String^ categoryID = gcnew String(category.getId().ToString());
		String^ categoryName = gcnew String(category.getName().c_str());
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
			categoryID,
				categoryName
		}, -1));
		this->listOfCategories->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
	}
	this->listOfCategories->EndUpdate();
	//this->Controls->Add(this->listOfCategories);
}
void ProjektCPPWindowsForms::AdminPanel::setProducts(std::vector<Product> products) {
	this->listOfProducts->BeginUpdate();
	for (Product product : products) {
		String^ productID = gcnew String(product.getId().ToString());
		String^ productName = gcnew String(product.getName().c_str());
		String^ productCategory = gcnew String(product.getCategory().getId().ToString());
		String^ productCompany = gcnew String(product.getCompany().getId().ToString());
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
			productID,
				productName, productCategory, productCompany
		}, -1));
		this->listOfProducts->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
		MessageBox::Show(gcnew String(product.getName().c_str()));
	}
	this->listOfProducts->EndUpdate();
	//this->Controls->Add(this->listOfProducts);
}
void ProjektCPPWindowsForms::AdminPanel::setOffers(std::vector<Offer> offers) {
	this->listOfOffers->BeginUpdate();
	for (Offer offer : offers) {
		String^ offerID = gcnew String(offer.getId().ToString());
		String^ offerPrice = gcnew String(offer.getPrice().ToString());
		String^ offerProduct = gcnew String(offer.getProduct().getId().ToString());
		String^ offerStartDate = gcnew String(Helper::time_tToString(offer.getStartDate()).c_str());
		String^ offerEndDate = gcnew String(Helper::time_tToString(offer.getStopDate()).c_str());
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
			offerID,
				offerPrice, offerProduct, offerStartDate, offerEndDate
		}, -1));
		this->listOfOffers->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
	}
	this->listOfOffers->EndUpdate();
	//this->Controls->Add(this->listOfOffers);
}
void ProjektCPPWindowsForms::AdminPanel::setTransactions(std::vector<Transaction> transactions) {
	this->listOfTransactions->BeginUpdate();
	for (Transaction transaction : transactions) {
		String^ transactionID = gcnew String(transaction.getId().ToString());
		String^ transactionDate = gcnew String(Helper::time_tToString(transaction.getDate()).c_str());
		String^ transactionUser = gcnew String(transaction.getUser().getId().ToString());
		String^ transactionOffers;
		std::string tmp;
		for (Offer offer : transaction.getOfferList()) {
			tmp += (std::to_string(offer.getId()) + ";");
		}
		transactionOffers = gcnew String(tmp.c_str());
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
			transactionID,
				transactionDate, transactionUser, transactionOffers
		}, -1));
		this->listOfTransactions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
	}
	this->listOfTransactions->EndUpdate();
	//this->Controls->Add(this->listOfTransactions);
}