#include "pch.h"
#include "MyForm.h"

void ProjektCPPWindowsForms::MyForm::setClient(User user) {
	this->client = new Client(user);
	this->user->Text = gcnew String(this->client->getLogin().c_str());
}