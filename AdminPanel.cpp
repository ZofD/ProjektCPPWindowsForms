#include "pch.h"
#include "AdminPanel.h"

void ProjektCPPWindowsForms::AdminPanel::setAdmin(User user) {
	this->admin = new Admin(user);
	this->user->Text = gcnew String(this->admin->getLogin().c_str());
}