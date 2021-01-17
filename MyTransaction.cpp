#include "pch.h"
#include "MyTransaction.h"

void ProjektCPPWindowsForms::MyTransaction::setTransactions(std::vector<Transaction> transactions) {
	this->listView1->BeginUpdate();
	for (Transaction transaction : transactions) {
		String^ transactionID = gcnew String(transaction.getId().ToString());
		String^ transactionDate = gcnew String(Helper::time_tToString(transaction.getDate()).c_str());
		String^ transactionUser = gcnew String(transaction.getUser().getId().ToString());
		String^ transactionOffers;
		std::string tmp;
		int licznik = 0;
		for (Offer offer : transaction.getOfferList()) {
			if (licznik == transaction.getOfferList().size() - 1)
				tmp += (std::to_string(offer.getId()));
			else
				tmp += (std::to_string(offer.getId()) + ";");
			licznik++;
		}
		transactionOffers = gcnew String(tmp.c_str());
		System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
			transactionID,
				transactionDate, transactionOffers
		}, -1));
		this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			listviewitem
		});
	}
	this->listView1->EndUpdate();
}