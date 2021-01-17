#include "pch.h"
#include "AddCategory.h"

void ProjektCPPWindowsForms::AddCategory::setAdmin(Admin* admin) {
	this->admin = admin;
}

void ProjektCPPWindowsForms::AddCategory::setCategory(ListViewItem^ category) {
	this->category = category;
	this->nameTxt->Text = category->SubItems[1]->Text;
}

void ProjektCPPWindowsForms::AddCategory::setOption(bool option) {
	this->option = option;
}

void ProjektCPPWindowsForms::AddCategory::setDeleteOption(bool option) {
	this->deleteOption = option;
}