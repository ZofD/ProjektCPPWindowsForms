#include "pch.h"
#include "AddTransaction.h"

void ProjektCPPWindowsForms::AddTransaction::setAdmin(Admin* admin) {
	this->admin = admin;
}

void ProjektCPPWindowsForms::AddTransaction::setTransaction(ListViewItem^ transaction) {
	this->transaction = transaction;
	ComboBox::ObjectCollection^ CompanyItems = this->userBox->Items;
	System::Collections::IEnumerator^ comapanyEnum = CompanyItems->GetEnumerator();
	while (comapanyEnum->MoveNext()) {
		Object^ item = safe_cast<Object^>(comapanyEnum->Current);
		if (System::Int32::Parse(item->ToString()->Split(' ')[0]) == System::Int32::Parse(transaction->SubItems[2]->Text)) {
			this->userBox->Text = item->ToString();
			break;
		}
	}
	System::DateTime date = System::DateTime(System::Int32::Parse(transaction->SubItems[1]->Text->Split('-')[0]),
		System::Int32::Parse(transaction->SubItems[1]->Text->Split('-')[1]), System::Int32::Parse(transaction->SubItems[1]->Text->Split('-')[2]));
	this->date->SetDate(date);
	this->dateStr = this->transaction->SubItems[1]->Text;
	this->listOfUserOffer->Items->AddRange(transaction->SubItems[3]->Text->Split(';'));
}

void ProjektCPPWindowsForms::AddTransaction::setOption(bool option) {
	this->option = option;
}

void ProjektCPPWindowsForms::AddTransaction::setUsers(std::vector<User> users) {
	this->userBox->BeginUpdate();
	for (User user : users) {
		String^ rekord = gcnew String(user.getId().ToString());

		this->userBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
			rekord
		});
	}
	this->userBox->EndUpdate();
}

void ProjektCPPWindowsForms::AddTransaction::setOffers(std::vector<Offer> offers) {
	this->listOfOffer->BeginUpdate();
	for (Offer offer : offers) {
		String^ rekord = gcnew String(offer.getId().ToString());

		this->listOfOffer->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
			rekord
		});
	}
	this->listOfOffer->EndUpdate();
}