#ifndef PanelEmployee
#define PanelEmployee

#pragma once
#include "AddProduct.h"
#include "AddOffer.h"
#include "AddCategory.h"
#include "AddCompany.h"

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o PanelSprzedawcy
	/// </summary>
	public ref class PanelSprzedawcy : public System::Windows::Forms::Form
	{
	public:
		PanelSprzedawcy(void)
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
		~PanelSprzedawcy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ user;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ productTab;


	private: System::Windows::Forms::Button^ addProductBtn;
	private: System::Windows::Forms::ListView^ listOfProducts;
	private: System::Windows::Forms::ColumnHeader^ productIdCol;
	private: System::Windows::Forms::ColumnHeader^ productNameCol;
	private: System::Windows::Forms::ColumnHeader^ productCategoryCol;
	private: System::Windows::Forms::ColumnHeader^ productCompanyCol;


	private: System::Windows::Forms::TabPage^ offerTab;


	private: System::Windows::Forms::Button^ addOfferBtn;
	private: System::Windows::Forms::ListView^ listOfOffers;
	private: System::Windows::Forms::ColumnHeader^ offerIdCol;
	private: System::Windows::Forms::ColumnHeader^ offerPriceCol;
	private: System::Windows::Forms::ColumnHeader^ offerProductCol;
	private: System::Windows::Forms::ColumnHeader^ offerDateStart;
	private: System::Windows::Forms::ColumnHeader^ offerDateEnd;


	private: System::Windows::Forms::TabPage^ companyTab;


	private: System::Windows::Forms::Button^ addCompanyBtn;
	private: System::Windows::Forms::ListView^ listOfCompanies;
	private: System::Windows::Forms::ColumnHeader^ companyIdCol;
	private: System::Windows::Forms::ColumnHeader^ companyNameCol;


	private: System::Windows::Forms::TabPage^ categoryTab;


	private: System::Windows::Forms::Button^ addCategoryBtn;
	private: System::Windows::Forms::ListView^ listOfCategories;
	private: System::Windows::Forms::ColumnHeader^ categoryIdCol;
	private: System::Windows::Forms::ColumnHeader^ categoryNameCol;



	private:
		   Employee* employee;
		   Admin* admin = new Admin(User());

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
			this->user = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->productTab = (gcnew System::Windows::Forms::TabPage());
			this->addProductBtn = (gcnew System::Windows::Forms::Button());
			this->listOfProducts = (gcnew System::Windows::Forms::ListView());
			this->productIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productCategoryCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productCompanyCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerTab = (gcnew System::Windows::Forms::TabPage());
			this->addOfferBtn = (gcnew System::Windows::Forms::Button());
			this->listOfOffers = (gcnew System::Windows::Forms::ListView());
			this->offerIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerPriceCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerProductCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerDateStart = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerDateEnd = (gcnew System::Windows::Forms::ColumnHeader());
			this->companyTab = (gcnew System::Windows::Forms::TabPage());
			this->addCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->listOfCompanies = (gcnew System::Windows::Forms::ListView());
			this->companyIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->companyNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->categoryTab = (gcnew System::Windows::Forms::TabPage());
			this->addCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->listOfCategories = (gcnew System::Windows::Forms::ListView());
			this->categoryIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->categoryNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabControl1->SuspendLayout();
			this->productTab->SuspendLayout();
			this->offerTab->SuspendLayout();
			this->companyTab->SuspendLayout();
			this->categoryTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Location = System::Drawing::Point(49, 27);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(86, 20);
			this->user->TabIndex = 1;
			this->user->Text = L"u¿ytkownik";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1062, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 50);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Wyloguj";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PanelSprzedawcy::button2_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->productTab);
			this->tabControl1->Controls->Add(this->offerTab);
			this->tabControl1->Controls->Add(this->companyTab);
			this->tabControl1->Controls->Add(this->categoryTab);
			this->tabControl1->Location = System::Drawing::Point(0, 68);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1201, 734);
			this->tabControl1->TabIndex = 12;
			// 
			// productTab
			// 
			this->productTab->Controls->Add(this->addProductBtn);
			this->productTab->Controls->Add(this->listOfProducts);
			this->productTab->Location = System::Drawing::Point(4, 29);
			this->productTab->Name = L"productTab";
			this->productTab->Padding = System::Windows::Forms::Padding(3);
			this->productTab->Size = System::Drawing::Size(1193, 701);
			this->productTab->TabIndex = 3;
			this->productTab->Text = L"Produkty";
			this->productTab->UseVisualStyleBackColor = true;
			// 
			// addProductBtn
			// 
			this->addProductBtn->Location = System::Drawing::Point(8, 651);
			this->addProductBtn->Name = L"addProductBtn";
			this->addProductBtn->Size = System::Drawing::Size(101, 42);
			this->addProductBtn->TabIndex = 19;
			this->addProductBtn->Text = L"Dodaj";
			this->addProductBtn->UseVisualStyleBackColor = true;
			this->addProductBtn->Click += gcnew System::EventHandler(this, &PanelSprzedawcy::addProductBtn_Click);
			// 
			// listOfProducts
			// 
			this->listOfProducts->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfProducts->CheckBoxes = true;
			this->listOfProducts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->productIdCol,
					this->productNameCol, this->productCategoryCol, this->productCompanyCol
			});
			this->listOfProducts->FullRowSelect = true;
			this->listOfProducts->HideSelection = false;
			this->listOfProducts->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listOfProducts->Location = System::Drawing::Point(8, 52);
			this->listOfProducts->Name = L"listOfProducts";
			this->listOfProducts->Size = System::Drawing::Size(1176, 593);
			this->listOfProducts->TabIndex = 18;
			this->listOfProducts->UseCompatibleStateImageBehavior = false;
			this->listOfProducts->View = System::Windows::Forms::View::Details;
			// 
			// productIdCol
			// 
			this->productIdCol->Tag = L"0";
			this->productIdCol->Text = L"Id";
			this->productIdCol->Width = 100;
			// 
			// productNameCol
			// 
			this->productNameCol->Tag = L"1";
			this->productNameCol->Text = L"Nazwa";
			this->productNameCol->Width = 300;
			// 
			// productCategoryCol
			// 
			this->productCategoryCol->Tag = L"2";
			this->productCategoryCol->Text = L"Id kategori";
			this->productCategoryCol->Width = 100;
			// 
			// productCompanyCol
			// 
			this->productCompanyCol->Tag = L"3";
			this->productCompanyCol->Text = L"Id firmy";
			this->productCompanyCol->Width = 100;
			// 
			// offerTab
			// 
			this->offerTab->Controls->Add(this->addOfferBtn);
			this->offerTab->Controls->Add(this->listOfOffers);
			this->offerTab->Location = System::Drawing::Point(4, 29);
			this->offerTab->Name = L"offerTab";
			this->offerTab->Padding = System::Windows::Forms::Padding(3);
			this->offerTab->Size = System::Drawing::Size(1193, 701);
			this->offerTab->TabIndex = 4;
			this->offerTab->Text = L"Oferty";
			this->offerTab->UseVisualStyleBackColor = true;
			// 
			// addOfferBtn
			// 
			this->addOfferBtn->Location = System::Drawing::Point(8, 651);
			this->addOfferBtn->Name = L"addOfferBtn";
			this->addOfferBtn->Size = System::Drawing::Size(101, 42);
			this->addOfferBtn->TabIndex = 19;
			this->addOfferBtn->Text = L"Dodaj";
			this->addOfferBtn->UseVisualStyleBackColor = true;
			this->addOfferBtn->Click += gcnew System::EventHandler(this, &PanelSprzedawcy::addOfferBtn_Click);
			// 
			// listOfOffers
			// 
			this->listOfOffers->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfOffers->CheckBoxes = true;
			this->listOfOffers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->offerIdCol, this->offerPriceCol,
					this->offerProductCol, this->offerDateStart, this->offerDateEnd
			});
			this->listOfOffers->FullRowSelect = true;
			this->listOfOffers->HideSelection = false;
			this->listOfOffers->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listOfOffers->Location = System::Drawing::Point(8, 52);
			this->listOfOffers->Name = L"listOfOffers";
			this->listOfOffers->Size = System::Drawing::Size(1176, 593);
			this->listOfOffers->TabIndex = 18;
			this->listOfOffers->UseCompatibleStateImageBehavior = false;
			this->listOfOffers->View = System::Windows::Forms::View::Details;
			// 
			// offerIdCol
			// 
			this->offerIdCol->Tag = L"0";
			this->offerIdCol->Text = L"Id";
			this->offerIdCol->Width = 100;
			// 
			// offerPriceCol
			// 
			this->offerPriceCol->Tag = L"1";
			this->offerPriceCol->Text = L"Cena";
			this->offerPriceCol->Width = 100;
			// 
			// offerProductCol
			// 
			this->offerProductCol->Tag = L"2";
			this->offerProductCol->Text = L"Id produktu";
			this->offerProductCol->Width = 100;
			// 
			// offerDateStart
			// 
			this->offerDateStart->Tag = L"3";
			this->offerDateStart->Text = L"Data rozpoczêcia";
			this->offerDateStart->Width = 100;
			// 
			// offerDateEnd
			// 
			this->offerDateEnd->Tag = L"4";
			this->offerDateEnd->Text = L"Data ukoñczenia";
			this->offerDateEnd->Width = 100;
			// 
			// companyTab
			// 
			this->companyTab->Controls->Add(this->addCompanyBtn);
			this->companyTab->Controls->Add(this->listOfCompanies);
			this->companyTab->Location = System::Drawing::Point(4, 29);
			this->companyTab->Name = L"companyTab";
			this->companyTab->Padding = System::Windows::Forms::Padding(3);
			this->companyTab->Size = System::Drawing::Size(1193, 701);
			this->companyTab->TabIndex = 5;
			this->companyTab->Text = L"Firmy";
			this->companyTab->UseVisualStyleBackColor = true;
			// 
			// addCompanyBtn
			// 
			this->addCompanyBtn->Location = System::Drawing::Point(8, 651);
			this->addCompanyBtn->Name = L"addCompanyBtn";
			this->addCompanyBtn->Size = System::Drawing::Size(101, 42);
			this->addCompanyBtn->TabIndex = 19;
			this->addCompanyBtn->Text = L"Dodaj";
			this->addCompanyBtn->UseVisualStyleBackColor = true;
			this->addCompanyBtn->Click += gcnew System::EventHandler(this, &PanelSprzedawcy::addCompanyBtn_Click);
			// 
			// listOfCompanies
			// 
			this->listOfCompanies->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfCompanies->CheckBoxes = true;
			this->listOfCompanies->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->companyIdCol,
					this->companyNameCol
			});
			this->listOfCompanies->FullRowSelect = true;
			this->listOfCompanies->HideSelection = false;
			this->listOfCompanies->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listOfCompanies->Location = System::Drawing::Point(8, 52);
			this->listOfCompanies->Name = L"listOfCompanies";
			this->listOfCompanies->Size = System::Drawing::Size(1176, 593);
			this->listOfCompanies->TabIndex = 18;
			this->listOfCompanies->UseCompatibleStateImageBehavior = false;
			this->listOfCompanies->View = System::Windows::Forms::View::Details;
			// 
			// companyIdCol
			// 
			this->companyIdCol->Tag = L"0";
			this->companyIdCol->Text = L"Id";
			this->companyIdCol->Width = 100;
			// 
			// companyNameCol
			// 
			this->companyNameCol->Tag = L"1";
			this->companyNameCol->Text = L"Nazwa";
			this->companyNameCol->Width = 200;
			// 
			// categoryTab
			// 
			this->categoryTab->Controls->Add(this->addCategoryBtn);
			this->categoryTab->Controls->Add(this->listOfCategories);
			this->categoryTab->Location = System::Drawing::Point(4, 29);
			this->categoryTab->Name = L"categoryTab";
			this->categoryTab->Padding = System::Windows::Forms::Padding(3);
			this->categoryTab->Size = System::Drawing::Size(1193, 701);
			this->categoryTab->TabIndex = 6;
			this->categoryTab->Text = L"Kategorie";
			this->categoryTab->UseVisualStyleBackColor = true;
			// 
			// addCategoryBtn
			// 
			this->addCategoryBtn->Location = System::Drawing::Point(8, 651);
			this->addCategoryBtn->Name = L"addCategoryBtn";
			this->addCategoryBtn->Size = System::Drawing::Size(101, 42);
			this->addCategoryBtn->TabIndex = 19;
			this->addCategoryBtn->Text = L"Dodaj";
			this->addCategoryBtn->UseVisualStyleBackColor = true;
			this->addCategoryBtn->Click += gcnew System::EventHandler(this, &PanelSprzedawcy::addCategoryBtn_Click);
			// 
			// listOfCategories
			// 
			this->listOfCategories->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfCategories->CheckBoxes = true;
			this->listOfCategories->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->categoryIdCol,
					this->categoryNameCol
			});
			this->listOfCategories->FullRowSelect = true;
			this->listOfCategories->HideSelection = false;
			this->listOfCategories->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listOfCategories->Location = System::Drawing::Point(8, 52);
			this->listOfCategories->Name = L"listOfCategories";
			this->listOfCategories->Size = System::Drawing::Size(1176, 593);
			this->listOfCategories->TabIndex = 18;
			this->listOfCategories->UseCompatibleStateImageBehavior = false;
			this->listOfCategories->View = System::Windows::Forms::View::Details;
			// 
			// categoryIdCol
			// 
			this->categoryIdCol->Tag = L"0";
			this->categoryIdCol->Text = L"Id";
			this->categoryIdCol->Width = 100;
			// 
			// categoryNameCol
			// 
			this->categoryNameCol->Tag = L"1";
			this->categoryNameCol->Text = L"Nazwa";
			this->categoryNameCol->Width = 200;
			// 
			// PanelSprzedawcy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->user);
			this->Name = L"PanelSprzedawcy";
			this->Text = L"Panel Sprzedawcy";
			this->tabControl1->ResumeLayout(false);
			this->productTab->ResumeLayout(false);
			this->offerTab->ResumeLayout(false);
			this->companyTab->ResumeLayout(false);
			this->categoryTab->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->setItems(this->employee->getAllCompany(), this->employee->getAllCategory(),
				this->employee->getAllProduct(), this->employee->getAllOffer());
		}

	public: 
		void setEmployee(User user);
	private:
		void setItems(std::vector<Company> companies, std::vector<Category> categories,
			std::vector<Product> products, std::vector<Offer> offers);
		void setCompanies(std::vector<Company> companies);
		void setCategories(std::vector<Category> categories);
		void setProducts(std::vector<Product> products);
		void setOffers(std::vector<Offer> offers);
		/*this->setItems(this->employee->getAllCompany(), this->employee->getAllCategory(),
				this->employee->getAllProduct(), this->employee->getAllOffer());*/
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void addProductBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		User user = User(1, "", "");
		Admin* admin = new Admin(user);
		ProjektCPPWindowsForms::AddProduct addProduct;
		addProduct.setAdmin(this->admin);
		addProduct.setOption(true);
		addProduct.setDeleteOption(false);
		addProduct.ShowDialog();
		this->listOfProducts->Items->Clear();
		this->setProducts(this->employee->getAllProduct());
	}
	private: System::Void addOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddOffer addOffer;
		addOffer.setAdmin(this->admin);
		addOffer.setOption(true);
		addOffer.setDeleteOption(false);
		addOffer.ShowDialog();
		this->listOfOffers->Items->Clear();
		this->setOffers(this->employee->getAllOffer());
	}
	private: System::Void addCompanyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddCompany addCompany;
		addCompany.setAdmin(this->admin);
		addCompany.setOption(true);
		addCompany.setDeleteOption(false);
		addCompany.ShowDialog();
		this->listOfCompanies->Items->Clear();
		this->setCompanies(this->employee->getAllCompany());
	}
	private: System::Void addCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddCategory addCategory;
		addCategory.setAdmin(this->admin);
		addCategory.setOption(true);
		addCategory.setDeleteOption(false);
		addCategory.ShowDialog();
		this->listOfCategories->Items->Clear();
		this->setCategories(this->employee->getAllCategory());
	}
};
}
#endif PanelEmployee