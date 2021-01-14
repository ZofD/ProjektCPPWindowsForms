#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddProduct
	/// </summary>
	public ref class AddProduct : public System::Windows::Forms::Form
	{
	public:
		AddProduct(void)
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
		~AddProduct()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ deleteProductBtn;
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::Button^ editProductBtn;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::TextBox^ nameTxt;
	private: System::Windows::Forms::ComboBox^ categoryBox;
	private: System::Windows::Forms::ComboBox^ companyBox;
	private: System::Windows::Forms::Label^ companyLabel;
	private: System::Windows::Forms::Label^ categoryLabel;

	private:
		Admin* admin;
		ListViewItem^ product;
		bool option;



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
			this->deleteProductBtn = (gcnew System::Windows::Forms::Button());
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			this->editProductBtn = (gcnew System::Windows::Forms::Button());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTxt = (gcnew System::Windows::Forms::TextBox());
			this->categoryBox = (gcnew System::Windows::Forms::ComboBox());
			this->companyBox = (gcnew System::Windows::Forms::ComboBox());
			this->companyLabel = (gcnew System::Windows::Forms::Label());
			this->categoryLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// deleteProductBtn
			// 
			this->deleteProductBtn->Location = System::Drawing::Point(79, 284);
			this->deleteProductBtn->Name = L"deleteProductBtn";
			this->deleteProductBtn->Size = System::Drawing::Size(128, 44);
			this->deleteProductBtn->TabIndex = 25;
			this->deleteProductBtn->Text = L"Usuñ";
			this->deleteProductBtn->UseVisualStyleBackColor = true;
			this->deleteProductBtn->Click += gcnew System::EventHandler(this, &AddProduct::deleteProductBtn_Click);
			// 
			// quitBtn
			// 
			this->quitBtn->Location = System::Drawing::Point(397, 284);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(128, 44);
			this->quitBtn->TabIndex = 24;
			this->quitBtn->Text = L"Anuluj";
			this->quitBtn->UseVisualStyleBackColor = true;
			this->quitBtn->Click += gcnew System::EventHandler(this, &AddProduct::quitBtn_Click);
			// 
			// editProductBtn
			// 
			this->editProductBtn->Location = System::Drawing::Point(238, 284);
			this->editProductBtn->Name = L"editProductBtn";
			this->editProductBtn->Size = System::Drawing::Size(128, 44);
			this->editProductBtn->TabIndex = 23;
			this->editProductBtn->Text = L"ZatwierdŸ";
			this->editProductBtn->UseVisualStyleBackColor = true;
			this->editProductBtn->Click += gcnew System::EventHandler(this, &AddProduct::editProductBtn_Click);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(75, 76);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(57, 20);
			this->nameLabel->TabIndex = 22;
			this->nameLabel->Text = L"Nazwa";
			// 
			// nameTxt
			// 
			this->nameTxt->Location = System::Drawing::Point(201, 73);
			this->nameTxt->Name = L"nameTxt";
			this->nameTxt->Size = System::Drawing::Size(324, 26);
			this->nameTxt->TabIndex = 21;
			// 
			// categoryBox
			// 
			this->categoryBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->categoryBox->FormattingEnabled = true;
			this->categoryBox->Location = System::Drawing::Point(307, 163);
			this->categoryBox->Name = L"categoryBox";
			this->categoryBox->Size = System::Drawing::Size(218, 28);
			this->categoryBox->TabIndex = 26;
			// 
			// companyBox
			// 
			this->companyBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->companyBox->FormattingEnabled = true;
			this->companyBox->Location = System::Drawing::Point(79, 163);
			this->companyBox->Name = L"companyBox";
			this->companyBox->Size = System::Drawing::Size(218, 28);
			this->companyBox->TabIndex = 27;
			// 
			// companyLabel
			// 
			this->companyLabel->AutoSize = true;
			this->companyLabel->Location = System::Drawing::Point(75, 131);
			this->companyLabel->Name = L"companyLabel";
			this->companyLabel->Size = System::Drawing::Size(49, 20);
			this->companyLabel->TabIndex = 28;
			this->companyLabel->Text = L"Firma";
			// 
			// categoryLabel
			// 
			this->categoryLabel->AutoSize = true;
			this->categoryLabel->Location = System::Drawing::Point(303, 131);
			this->categoryLabel->Name = L"categoryLabel";
			this->categoryLabel->Size = System::Drawing::Size(77, 20);
			this->categoryLabel->TabIndex = 29;
			this->categoryLabel->Text = L"Kategoria";
			// 
			// AddProduct
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 400);
			this->Controls->Add(this->categoryLabel);
			this->Controls->Add(this->companyLabel);
			this->Controls->Add(this->companyBox);
			this->Controls->Add(this->categoryBox);
			this->Controls->Add(this->deleteProductBtn);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->editProductBtn);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->nameTxt);
			this->Name = L"AddProduct";
			this->Text = L"Prudukt";
			this->ResumeLayout(false);
			this->PerformLayout();
			this->setCompanies(this->admin->getAllCompany());
			this->setCategories(this->admin->getAllCategory());
		}

		public:
			void setAdmin(Admin* admin);
			void setProduct(ListViewItem^ product);
			void setOption(bool option);
		private:
			void setCompanies(std::vector<Company> companies);
			void setCategories(std::vector<Category> categories);
#pragma endregion
	private: System::Void deleteProductBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!this->option) {
			Product product = Product(System::Int32::Parse(this->product->SubItems[0]->Text), "");
			this->admin->deleteProduct(product);
		}
		this->Close();
	}
	private: System::Void editProductBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->nameTxt->Text != "" && this->categoryBox->SelectedIndex >= 0 && this->companyBox->SelectedIndex >= 0)
			if (this->option) {
				Company company = Company(System::Int32::Parse(this->companyBox->Text->Split(' ')[0]), "");
				Category category = Category(System::Int32::Parse(this->categoryBox->Text->Split(' ')[0]), "");
				Product product = Product(1, msclr::interop::marshal_as<std::string>(this->nameTxt->Text),
					company, category);
				this->admin->addProduct(product);
				this->Close();
			}
			else {
				Company company = Company(System::Int32::Parse(this->companyBox->Text->Split(' ')[0]), "");
				Category category = Category(System::Int32::Parse(this->categoryBox->Text->Split(' ')[0]), "");
				Product product = Product(System::Int32::Parse(this->product->SubItems[0]->Text), msclr::interop::marshal_as<std::string>(this->nameTxt->Text),
					company, category);
				this->admin->updateProduct(product);
				this->Close();
			}
	}
	private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
