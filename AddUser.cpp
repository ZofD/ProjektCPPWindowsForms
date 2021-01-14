#include "pch.h"
#include "AddUser.h"

void ProjektCPPWindowsForms::AddUser::setAdmin(Admin* admin) {
	this->admin = admin;
}

void ProjektCPPWindowsForms::AddUser::setUser(ListViewItem^ user) {
	this->user = user;
	this->lobinTxt->Text = user->SubItems[1]->Text;
	this->passwordTxt->Text = user->SubItems[2]->Text;
	this->roleBox->Text = user->SubItems[3]->Text;
}

void ProjektCPPWindowsForms::AddUser::setOption(bool option) {
	this->option = option;
}