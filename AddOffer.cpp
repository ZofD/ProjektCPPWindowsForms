#include "pch.h"
#include "AddOffer.h"

void ProjektCPPWindowsForms::AddOffer::setAdmin(Admin* admin) {
	this->admin = admin;
}

void ProjektCPPWindowsForms::AddOffer::setOffer(ListViewItem^ offer) {
	this->offer = offer;
	int liczba = System::Double::Parse(offer->SubItems[1]->Text) * 100;
	this->zlTxt->Text = (liczba / 100).ToString();
	this->grTxt->Text = (liczba % 100).ToString();
	ComboBox::ObjectCollection^ CompanyItems = this->productBox->Items;
	System::Collections::IEnumerator^ comapanyEnum = CompanyItems->GetEnumerator();
	while (comapanyEnum->MoveNext()) {
		Object^ item = safe_cast<Object^>(comapanyEnum->Current);
		if (System::Int32::Parse(item->ToString()->Split(' ')[0]) == System::Int32::Parse(offer->SubItems[2]->Text)) {
			this->productBox->Text = item->ToString();
			break;
		}
	}
	System::DateTime startTime = System::DateTime(System::Int32::Parse(offer->SubItems[3]->Text->Split('-')[0]), 
		System::Int32::Parse(offer->SubItems[3]->Text->Split('-')[1]), System::Int32::Parse(offer->SubItems[3]->Text->Split('-')[2]));
	this->dateStart->SetDate(startTime);
	System::DateTime stopTime = System::DateTime(System::Int32::Parse(offer->SubItems[4]->Text->Split('-')[0]),
		System::Int32::Parse(offer->SubItems[4]->Text->Split('-')[1]), System::Int32::Parse(offer->SubItems[4]->Text->Split('-')[2]));
	this->dateStop->SetDate(stopTime);
	this->start = this->offer->SubItems[3]->Text;
	this->stop = this->offer->SubItems[4]->Text;
}

void ProjektCPPWindowsForms::AddOffer::setOption(bool option) {
	this->option = option;
}

void ProjektCPPWindowsForms::AddOffer::setDeleteOption(bool option) {
	this->deleteOption = option;
}

void ProjektCPPWindowsForms::AddOffer::setProducts(std::vector<Product> products) {
	this->productBox->BeginUpdate();
	for (Product product : products) {
		std::string tmp = std::to_string(product.getId()) + " " + product.getName();
		String^ rekord = gcnew String(tmp.c_str());

		this->productBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
			rekord
		});
	}
	this->productBox->EndUpdate();
}