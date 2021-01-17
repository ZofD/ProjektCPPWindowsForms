#include "pch.h"
#include "Koszyk.h"

void ProjektCPPWindowsForms::Koszyk::setKoszykArr(ListView^ koszykArr) {
	for (int i = 0; i < koszykArr->Items->Count; i++) {
		this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
			(ListViewItem^)koszykArr->Items[i]->Clone()
		});
	}
}

void ProjektCPPWindowsForms::Koszyk::setClient(Client* client) {
	this->client = client;
}

bool ProjektCPPWindowsForms::Koszyk::checkOption() {
	return this->opcja;
}