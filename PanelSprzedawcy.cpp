#include "pch.h"
#include "PanelSprzedawcy.h"

void ProjektCPPWindowsForms::PanelSprzedawcy::setClient(User user) {
	this->client = new Client(user);
	this->user->Text = gcnew String(this->client->getLogin().c_str());
}