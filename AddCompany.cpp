#include "pch.h"
#include "AddCompany.h"

void ProjektCPPWindowsForms::AddCompany::setAdmin(Admin* admin) {
	this->admin = admin;
}

void ProjektCPPWindowsForms::AddCompany::setCompany(ListViewItem^ company) {
	this->company = company;
	this->nameTxt->Text = company->SubItems[1]->Text;
}

void ProjektCPPWindowsForms::AddCompany::setOption(bool option) {
	this->option = option;
}