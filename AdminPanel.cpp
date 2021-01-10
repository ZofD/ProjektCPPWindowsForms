#include "pch.h"
#include "AdminPanel.h"

void ProjektCPPWindowsForms::AdminPanel::setClient(User user) {
	this->client = new Client(user);
	this->user->Text = gcnew String(this->client->getLogin().c_str());
}