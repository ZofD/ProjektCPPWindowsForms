#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddUser
	/// </summary>
	public ref class AddUser : public System::Windows::Forms::Form
	{
	public:
		AddUser(void)
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
		~AddUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ lobinTxt;
	private: System::Windows::Forms::Label^ loginLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ passwordTxt;
	private: System::Windows::Forms::Label^ permisionLabel;
	private: System::Windows::Forms::Button^ editUserBtn;
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::ComboBox^ roleBox;

	private: 
		Admin* admin;
		ListViewItem^ user;
		bool option;

	protected:

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
			this->lobinTxt = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->passwordTxt = (gcnew System::Windows::Forms::TextBox());
			this->permisionLabel = (gcnew System::Windows::Forms::Label());
			this->editUserBtn = (gcnew System::Windows::Forms::Button());
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			this->roleBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// lobinTxt
			// 
			this->lobinTxt->Location = System::Drawing::Point(200, 66);
			this->lobinTxt->Name = L"lobinTxt";
			this->lobinTxt->Size = System::Drawing::Size(324, 26);
			this->lobinTxt->TabIndex = 0;
			// 
			// loginLabel
			// 
			this->loginLabel->AutoSize = true;
			this->loginLabel->Location = System::Drawing::Point(74, 69);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(48, 20);
			this->loginLabel->TabIndex = 1;
			this->loginLabel->Text = L"Login";
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(74, 136);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(51, 20);
			this->passwordLabel->TabIndex = 3;
			this->passwordLabel->Text = L"Has³o";
			// 
			// passwordTxt
			// 
			this->passwordTxt->Location = System::Drawing::Point(200, 133);
			this->passwordTxt->Name = L"passwordTxt";
			this->passwordTxt->Size = System::Drawing::Size(324, 26);
			this->passwordTxt->TabIndex = 2;
			// 
			// permisionLabel
			// 
			this->permisionLabel->AutoSize = true;
			this->permisionLabel->Location = System::Drawing::Point(74, 208);
			this->permisionLabel->Name = L"permisionLabel";
			this->permisionLabel->Size = System::Drawing::Size(42, 20);
			this->permisionLabel->TabIndex = 5;
			this->permisionLabel->Text = L"Rola";
			// 
			// editUserBtn
			// 
			this->editUserBtn->Location = System::Drawing::Point(237, 277);
			this->editUserBtn->Name = L"editUserBtn";
			this->editUserBtn->Size = System::Drawing::Size(128, 44);
			this->editUserBtn->TabIndex = 7;
			this->editUserBtn->Text = L"ZatwierdŸ";
			this->editUserBtn->UseVisualStyleBackColor = true;
			this->editUserBtn->Click += gcnew System::EventHandler(this, &AddUser::editUserBtn_Click);
			// 
			// quitBtn
			// 
			this->quitBtn->Location = System::Drawing::Point(396, 277);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(128, 44);
			this->quitBtn->TabIndex = 8;
			this->quitBtn->Text = L"Anuluj";
			this->quitBtn->UseVisualStyleBackColor = true;
			this->quitBtn->Click += gcnew System::EventHandler(this, &AddUser::quitBtn_Click);
			// 
			// roleBox
			// 
			this->roleBox->FormattingEnabled = true;
			this->roleBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Administrator", L"Pracownik", L"Klient" });
			this->roleBox->Location = System::Drawing::Point(200, 205);
			this->roleBox->Name = L"roleBox";
			this->roleBox->Size = System::Drawing::Size(324, 28);
			this->roleBox->TabIndex = 9;
			this->roleBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			// 
			// AddUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 400);
			this->Controls->Add(this->roleBox);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->editUserBtn);
			this->Controls->Add(this->permisionLabel);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->passwordTxt);
			this->Controls->Add(this->loginLabel);
			this->Controls->Add(this->lobinTxt);
			this->Name = L"AddUser";
			this->Text = L"U¿ytkownik";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		public:
			void setAdmin(Admin* admin);
			void setUser(ListViewItem^ user);
			void setOption(bool option);
#pragma endregion
	private: System::Void editUserBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!(this->lobinTxt->Text == "") && !(this->passwordTxt->Text == "") && this->roleBox->SelectedIndex >= 0)
			if (this->option) {
				User user = User(msclr::interop::marshal_as<std::string>(this->lobinTxt->Text), 
						msclr::interop::marshal_as<std::string>(this->passwordTxt->Text), this->roleBox->SelectedIndex);
				this->admin->addUser(user);
				this->Close();
			} else {
				User user = User(System::Int32::Parse(this->user->SubItems[0]->Text), msclr::interop::marshal_as<std::string>(this->lobinTxt->Text),
						msclr::interop::marshal_as<std::string>(this->passwordTxt->Text), this->roleBox->SelectedIndex);
				this->admin->updateUser(user);
				this->Close();
			}
	}
	private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
