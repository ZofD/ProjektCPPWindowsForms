#ifndef PanelLogin
#define PanelLogin

#pragma once
#include "MyForm.h"
#include "AdminPanel.h"
#include "PanelSprzedawcy.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ login;
	private: System::Windows::Forms::TextBox^ haslo;
	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::LinkLabel^ NewAcountButton;
	private: System::Windows::Forms::Label^ info;



	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->login = (gcnew System::Windows::Forms::TextBox());
			this->haslo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NewAcountButton = (gcnew System::Windows::Forms::LinkLabel());
			this->info = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(209, 256);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Zaloguj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// login
			// 
			this->login->Location = System::Drawing::Point(209, 126);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(213, 26);
			this->login->TabIndex = 1;
			// 
			// haslo
			// 
			this->haslo->Location = System::Drawing::Point(209, 196);
			this->haslo->Name = L"haslo";
			this->haslo->Size = System::Drawing::Size(213, 26);
			this->haslo->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(205, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(205, 173);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Has³o";
			// 
			// NewAcountButton
			// 
			this->NewAcountButton->AutoSize = true;
			this->NewAcountButton->Location = System::Drawing::Point(215, 324);
			this->NewAcountButton->Name = L"NewAcountButton";
			this->NewAcountButton->Size = System::Drawing::Size(127, 20);
			this->NewAcountButton->TabIndex = 5;
			this->NewAcountButton->TabStop = true;
			this->NewAcountButton->Text = L"Nie masz konta\?\r\n";
			this->NewAcountButton->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkLabel1_LinkClicked);
			// 
			// info
			// 
			this->info->AutoSize = true;
			this->info->ForeColor = System::Drawing::Color::DarkRed;
			this->info->Location = System::Drawing::Point(205, 364);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(0, 20);
			this->info->TabIndex = 6;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 454);
			this->Controls->Add(this->info);
			this->Controls->Add(this->NewAcountButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->haslo);
			this->Controls->Add(this->login);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string login = msclr::interop::marshal_as<std::string>(this->login->Text);
		std::string haslo = msclr::interop::marshal_as<std::string>(this->haslo->Text);
		User user = UnVerify::logIn(login, haslo);
		if (user.getId() >= 0)
		{
			switch (user.getPermission())
			{
			case 0: 
				this->login->Clear();
				this->haslo->Clear();
				this->info->Text = "";
				this->Hide();
				{
					ProjektCPPWindowsForms::AdminPanel uzytkownikw;
					uzytkownikw.setAdmin(user);
					uzytkownikw.ShowDialog();
				}
				this->Show();
				break;
			case 1:
				this->login->Clear();
				this->haslo->Clear();
				this->info->Text = "";
				this->Hide();
				{
					ProjektCPPWindowsForms::PanelSprzedawcy uzytkownika;
					//uzytkownika.setEmployee(user);
					uzytkownika.ShowDialog();
				}
				this->Show();
				break;
			case 2:
				this->login->Clear();
				this->haslo->Clear();
				this->info->Text = "";
				this->Hide();
				{
					ProjektCPPWindowsForms::MyForm uzytkownik;
					uzytkownik.setClient(user);
					uzytkownik.ShowDialog();
				}
				this->Show();
				break;
			default:
				break;
			}
		}
		else {
			this->info->Text = "Konto o podanych danych nie istnieje";
		}
	}

	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->info->Text = "";
		/*this->Hide();
		ProjektCPPWindowsForms::MyForm uzytkownik();
		uzytkownik.ShowDialog();
		this->Show();*/
	}
};
}
#endif PanelLogin