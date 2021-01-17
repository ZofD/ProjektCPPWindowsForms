#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddCompany
	/// </summary>
	public ref class AddCompany : public System::Windows::Forms::Form
	{
	public:
		AddCompany(void)
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
		~AddCompany()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::Button^ editCompanyBtn;
	private: System::Windows::Forms::Label^ nameLabel;
	protected:




	private: System::Windows::Forms::TextBox^ nameTxt;

	private: System::Windows::Forms::Button^ deleteCompanyBtn;

	private:
		Admin* admin;
		ListViewItem^ company;
		bool option;
		bool deleteOption = true;

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
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			this->editCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTxt = (gcnew System::Windows::Forms::TextBox());
			this->deleteCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// quitBtn
			// 
			this->quitBtn->Location = System::Drawing::Point(397, 284);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(128, 44);
			this->quitBtn->TabIndex = 14;
			this->quitBtn->Text = L"Anuluj";
			this->quitBtn->UseVisualStyleBackColor = true;
			this->quitBtn->Click += gcnew System::EventHandler(this, &AddCompany::quitBtn_Click);
			// 
			// editCompanyBtn
			// 
			this->editCompanyBtn->Location = System::Drawing::Point(238, 284);
			this->editCompanyBtn->Name = L"editCompanyBtn";
			this->editCompanyBtn->Size = System::Drawing::Size(128, 44);
			this->editCompanyBtn->TabIndex = 13;
			this->editCompanyBtn->Text = L"ZatwierdŸ";
			this->editCompanyBtn->UseVisualStyleBackColor = true;
			this->editCompanyBtn->Click += gcnew System::EventHandler(this, &AddCompany::editCompanyBtn_Click);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(75, 76);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(57, 20);
			this->nameLabel->TabIndex = 10;
			this->nameLabel->Text = L"Nazwa";
			// 
			// nameTxt
			// 
			this->nameTxt->Location = System::Drawing::Point(201, 73);
			this->nameTxt->Name = L"nameTxt";
			this->nameTxt->Size = System::Drawing::Size(324, 26);
			this->nameTxt->TabIndex = 9;
			// 
			// deleteCompanyBtn
			// 
			this->deleteCompanyBtn->Location = System::Drawing::Point(79, 284);
			this->deleteCompanyBtn->Name = L"deleteCompanyBtn";
			this->deleteCompanyBtn->Size = System::Drawing::Size(128, 44);
			this->deleteCompanyBtn->TabIndex = 15;
			this->deleteCompanyBtn->Text = L"Usuñ";
			this->deleteCompanyBtn->UseVisualStyleBackColor = true;
			this->deleteCompanyBtn->Click += gcnew System::EventHandler(this, &AddCompany::deleteCompanyBtn_Click);
			// 
			// AddCompany
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 400);
			this->Controls->Add(this->deleteCompanyBtn);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->editCompanyBtn);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->nameTxt);
			this->Name = L"AddCompany";
			this->Text = L"Firma";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		public:
			void setAdmin(Admin* admin);
			void setCompany(ListViewItem^ company);
			void setOption(bool option);
			void setDeleteOption(bool option);
#pragma endregion
	private: System::Void deleteCompanyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!this->option && this->deleteOption) {
			Company company = Company(System::Int32::Parse(this->company->SubItems[0]->Text), "");
			if (this->admin->deleteCompany(company))
				this->Close();
		}
		MessageBox::Show("Nie masz uprawnieñ lub nie mo¿na usun¹æ tego rekordu");
	}
	private: System::Void editCompanyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->nameTxt->Text != "")
			if (this->option) {
				Company company = Company(msclr::interop::marshal_as<std::string>(this->nameTxt->Text));
				this->admin->addCompany(company);
				this->Close();
			}
			else {
				Company company = Company(
					System::Int32::Parse(this->company->SubItems[0]->Text), msclr::interop::marshal_as<std::string>(this->nameTxt->Text)
				);
				this->admin->updateCompany(company);
				this->Close();
			}
	}
	private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
