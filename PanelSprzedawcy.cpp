#include "pch.h"
#include "PanelSprzedawcy.h"

void ProjektCPPWindowsForms::PanelSprzedawcy::setEmployee(User user) {
	this->employee = new Employee(user);
	this->user->Text = gcnew String(this->employee->getLogin().c_str());
}

void ProjektCPPWindowsForms::PanelSprzedawcy::setItems(std::vector<Company> companies, std::vector<Category> categories,
	std::vector<Product> products, std::vector<Offer> offers) {
	this->setCompanies(companies);
	this->setCategories(categories);
	this->setProducts(products);
	this->setOffers(offers);
}

void ProjektCPPWindowsForms::PanelSprzedawcy::setCompanies(std::vector<Company> companies) {
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
void ProjektCPPWindowsForms::PanelSprzedawcy::setCategories(std::vector<Category> categories) {
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
void ProjektCPPWindowsForms::PanelSprzedawcy::setProducts(std::vector<Product> products) {
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
	}
	this->listOfProducts->EndUpdate();
	//this->Controls->Add(this->listOfProducts);
}
void ProjektCPPWindowsForms::PanelSprzedawcy::setOffers(std::vector<Offer> offers) {
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