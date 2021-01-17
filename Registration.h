#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Registration
	/// </summary>
	public ref class Registration : public System::Windows::Forms::Form
	{
	public:
		Registration(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ loginTxt;
	private: System::Windows::Forms::TextBox^ passwdTxt;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ repeatPasswdTxt;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ cpnfirnBtn;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->loginTxt = (gcnew System::Windows::Forms::TextBox());
			this->passwdTxt = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->repeatPasswdTxt = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cpnfirnBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(56, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login";
			// 
			// loginTxt
			// 
			this->loginTxt->Location = System::Drawing::Point(60, 76);
			this->loginTxt->Name = L"loginTxt";
			this->loginTxt->Size = System::Drawing::Size(256, 26);
			this->loginTxt->TabIndex = 1;
			// 
			// passwdTxt
			// 
			this->passwdTxt->Location = System::Drawing::Point(60, 167);
			this->passwdTxt->Name = L"passwdTxt";
			this->passwdTxt->PasswordChar = '*';
			this->passwdTxt->Size = System::Drawing::Size(256, 26);
			this->passwdTxt->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(56, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Has³o";
			// 
			// repeatPasswdTxt
			// 
			this->repeatPasswdTxt->Location = System::Drawing::Point(60, 235);
			this->repeatPasswdTxt->Name = L"repeatPasswdTxt";
			this->repeatPasswdTxt->PasswordChar = '*';
			this->repeatPasswdTxt->Size = System::Drawing::Size(256, 26);
			this->repeatPasswdTxt->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(56, 203);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Powtórz has³o";
			// 
			// cpnfirnBtn
			// 
			this->cpnfirnBtn->Location = System::Drawing::Point(60, 303);
			this->cpnfirnBtn->Name = L"cpnfirnBtn";
			this->cpnfirnBtn->Size = System::Drawing::Size(255, 44);
			this->cpnfirnBtn->TabIndex = 6;
			this->cpnfirnBtn->Text = L"Stwórz";
			this->cpnfirnBtn->UseVisualStyleBackColor = true;
			this->cpnfirnBtn->Click += gcnew System::EventHandler(this, &Registration::cpnfirnBtn_Click);
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(371, 382);
			this->Controls->Add(this->cpnfirnBtn);
			this->Controls->Add(this->repeatPasswdTxt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->passwdTxt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->loginTxt);
			this->Controls->Add(this->label1);
			this->Name = L"Registration";
			this->Text = L"Rejestracja";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cpnfirnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->passwdTxt->Text->Equals(this->repeatPasswdTxt->Text) && this->loginTxt->Text != "" && this->passwdTxt->Text != "") {
			std::string login = msclr::interop::marshal_as<std::string>(this->loginTxt->Text);
			std::string haslo = msclr::interop::marshal_as<std::string>(this->passwdTxt->Text);
			User user = User(login, haslo, 2);
			Admin admin = Admin(user);
			admin.addUser(user);
			this->Close();
		}
	}
};
}
