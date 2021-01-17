#include "pch.h"
#include "AddProduct.h"

void ProjektCPPWindowsForms::AddProduct::setAdmin(Admin* admin) {
	this->admin = admin;
}

void ProjektCPPWindowsForms::AddProduct::setProduct(ListViewItem^ product) {
	this->product = product;
	this->nameTxt->Text = product->SubItems[1]->Text;
	ComboBox::ObjectCollection^ CompanyItems = this->companyBox->Items;
	System::Collections::IEnumerator^ comapanyEnum = CompanyItems->GetEnumerator();
	while (comapanyEnum->MoveNext()) {
		Object^ item = safe_cast<Object^>(comapanyEnum->Current);
		if (System::Int32::Parse(item->ToString()->Split(' ')[0]) == System::Int32::Parse(product->SubItems[3]->Text)) {
			this->companyBox->Text = item->ToString();
			break;
		}
	}
	ComboBox::ObjectCollection^ categoryItems = this->categoryBox->Items;
	System::Collections::IEnumerator^ categoryEnum = categoryItems->GetEnumerator();
	while (categoryEnum->MoveNext()) {
		Object^ item = safe_cast<Object^>(categoryEnum->Current);
		if (System::Int32::Parse(item->ToString()->Split(' ')[0]) == System::Int32::Parse(product->SubItems[2]->Text)) {
			this->categoryBox->Text = item->ToString();
			break;
		}
	}
}

void ProjektCPPWindowsForms::AddProduct::setOption(bool option) {
	this->option = option;
}

void ProjektCPPWindowsForms::AddProduct::setDeleteOption(bool option) {
	this->deleteOption = option;
}

void ProjektCPPWindowsForms::AddProduct::setCategories(std::vector<Category> categories) {
	this->categoryBox->BeginUpdate();
	for (Category category : categories) {
		std::string tmp = std::to_string(category.getId()) + " " + category.getName();
		String^ rekord = gcnew String(tmp.c_str());

		this->categoryBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { 
			rekord
		});
	}
	this->categoryBox->EndUpdate();
}

void ProjektCPPWindowsForms::AddProduct::setCompanies(std::vector<Company> companies) {
	this->companyBox->BeginUpdate();
	for (Company company : companies) {
		std::string tmp = std::to_string(company.getId()) + " " + company.getName();
		String^ rekord = gcnew String(tmp.c_str());

		this->companyBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
			rekord
		});
	}
	this->companyBox->EndUpdate();
}