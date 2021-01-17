#ifndef PanelAdmin
#define PanelAdmin

#pragma once
#include "AddUser.h"
#include "AddCompany.h"
#include "AddCategory.h"
#include "AddProduct.h"
#include "AddOffer.h"
#include "AddTransaction.h"

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AdminPanel
	/// </summary>
	public ref class AdminPanel : public System::Windows::Forms::Form
	{
	public:
		AdminPanel(void)
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
		~AdminPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ user;
	private: System::Windows::Forms::TabControl^ tabControl1;

	private: System::Windows::Forms::TabPage^ userTab;
	private: System::Windows::Forms::Button^ editUserBtn;

	private: System::Windows::Forms::Button^ addUserBtn;
	private: System::Windows::Forms::ListView^ listOfUsers;


	private: System::Windows::Forms::ColumnHeader^ userIdCol;
	private: System::Windows::Forms::ColumnHeader^ userLoginCol;

	private: System::Windows::Forms::ColumnHeader^ userPermisionCol;

	private: System::Windows::Forms::TabPage^ companyTab;
	private: System::Windows::Forms::Button^ editCompanyBtn;
	private: System::Windows::Forms::Button^ deleteCompanyBtn;
	private: System::Windows::Forms::Button^ addCompanyBtn;
	private: System::Windows::Forms::ListView^ listOfCompanies;


	private: System::Windows::Forms::ColumnHeader^ companyIdCol;
	private: System::Windows::Forms::ColumnHeader^ companyNameCol;

	private: System::Windows::Forms::TabPage^ categoryTab;
	private: System::Windows::Forms::Button^ editCategoryBtn;
	private: System::Windows::Forms::Button^ deleteCategoryBtn;
	private: System::Windows::Forms::Button^ addCategoryBtn;
	private: System::Windows::Forms::ListView^ listOfCategories;


	private: System::Windows::Forms::ColumnHeader^ categoryIdCol;
	private: System::Windows::Forms::ColumnHeader^ categoryNameCol;

	private: System::Windows::Forms::TabPage^ productTab;
	private: System::Windows::Forms::Button^ editProductBtn;
	private: System::Windows::Forms::Button^ deleteProductBtn;
	private: System::Windows::Forms::Button^ addProductBtn;
	private: System::Windows::Forms::ListView^ listOfProducts;


	private: System::Windows::Forms::ColumnHeader^ productIdCol;
	private: System::Windows::Forms::ColumnHeader^ productNameCol;
	private: System::Windows::Forms::ColumnHeader^ productCategoryCol;
	private: System::Windows::Forms::ColumnHeader^ productCompanyCol;

	private: System::Windows::Forms::TabPage^ offerTab;
	private: System::Windows::Forms::Button^ editOfferBtn;
	private: System::Windows::Forms::Button^ deleteOfferBtn;
	private: System::Windows::Forms::Button^ addOfferBtn;
	private: System::Windows::Forms::ListView^ listOfOffers;


	private: System::Windows::Forms::ColumnHeader^ offerIdCol;
	private: System::Windows::Forms::ColumnHeader^ offerPriceCol;
	private: System::Windows::Forms::ColumnHeader^ offerProductCol;
	private: System::Windows::Forms::ColumnHeader^ offerDateStart;
	private: System::Windows::Forms::ColumnHeader^ offerDateEnd;

	private: System::Windows::Forms::TabPage^ transactionTab;
	private: System::Windows::Forms::Button^ editTransactionBtn;

	private: System::Windows::Forms::Button^ addTransactionBtn;
	private: System::Windows::Forms::ListView^ listOfTransactions;


	private: System::Windows::Forms::ColumnHeader^ transactionIdCol;
	private: System::Windows::Forms::ColumnHeader^ transactionDateCol;
	private: System::Windows::Forms::ColumnHeader^ transactionUserCol;
	private: System::Windows::Forms::ColumnHeader^ transactionOffersListCol;

	private:
		Admin* admin;
	private: System::Windows::Forms::ColumnHeader^ userPasswordCol;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->user = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->userTab = (gcnew System::Windows::Forms::TabPage());
			this->editUserBtn = (gcnew System::Windows::Forms::Button());
			this->addUserBtn = (gcnew System::Windows::Forms::Button());
			this->listOfUsers = (gcnew System::Windows::Forms::ListView());
			this->userIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->userLoginCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->userPasswordCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->userPermisionCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->companyTab = (gcnew System::Windows::Forms::TabPage());
			this->editCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->deleteCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->addCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->listOfCompanies = (gcnew System::Windows::Forms::ListView());
			this->companyIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->companyNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->categoryTab = (gcnew System::Windows::Forms::TabPage());
			this->editCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->deleteCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->addCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->listOfCategories = (gcnew System::Windows::Forms::ListView());
			this->categoryIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->categoryNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productTab = (gcnew System::Windows::Forms::TabPage());
			this->editProductBtn = (gcnew System::Windows::Forms::Button());
			this->deleteProductBtn = (gcnew System::Windows::Forms::Button());
			this->addProductBtn = (gcnew System::Windows::Forms::Button());
			this->listOfProducts = (gcnew System::Windows::Forms::ListView());
			this->productIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productCategoryCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productCompanyCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerTab = (gcnew System::Windows::Forms::TabPage());
			this->editOfferBtn = (gcnew System::Windows::Forms::Button());
			this->deleteOfferBtn = (gcnew System::Windows::Forms::Button());
			this->addOfferBtn = (gcnew System::Windows::Forms::Button());
			this->listOfOffers = (gcnew System::Windows::Forms::ListView());
			this->offerIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerPriceCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerProductCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerDateStart = (gcnew System::Windows::Forms::ColumnHeader());
			this->offerDateEnd = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionTab = (gcnew System::Windows::Forms::TabPage());
			this->editTransactionBtn = (gcnew System::Windows::Forms::Button());
			this->addTransactionBtn = (gcnew System::Windows::Forms::Button());
			this->listOfTransactions = (gcnew System::Windows::Forms::ListView());
			this->transactionIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionDateCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionUserCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionOffersListCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabControl1->SuspendLayout();
			this->userTab->SuspendLayout();
			this->companyTab->SuspendLayout();
			this->categoryTab->SuspendLayout();
			this->productTab->SuspendLayout();
			this->offerTab->SuspendLayout();
			this->transactionTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1062, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 50);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Wyloguj";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminPanel::button2_Click);
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Location = System::Drawing::Point(49, 27);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(86, 20);
			this->user->TabIndex = 9;
			this->user->Text = L"u¿ytkownik";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->userTab);
			this->tabControl1->Controls->Add(this->companyTab);
			this->tabControl1->Controls->Add(this->categoryTab);
			this->tabControl1->Controls->Add(this->productTab);
			this->tabControl1->Controls->Add(this->offerTab);
			this->tabControl1->Controls->Add(this->transactionTab);
			this->tabControl1->Location = System::Drawing::Point(0, 68);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1201, 734);
			this->tabControl1->TabIndex = 11;
			// 
			// userTab
			// 
			this->userTab->Controls->Add(this->editUserBtn);
			this->userTab->Controls->Add(this->addUserBtn);
			this->userTab->Controls->Add(this->listOfUsers);
			this->userTab->Location = System::Drawing::Point(4, 29);
			this->userTab->Name = L"userTab";
			this->userTab->Padding = System::Windows::Forms::Padding(3);
			this->userTab->Size = System::Drawing::Size(1193, 701);
			this->userTab->TabIndex = 0;
			this->userTab->Text = L"U¿ytkownicy";
			this->userTab->UseVisualStyleBackColor = true;
			// 
			// editUserBtn
			// 
			this->editUserBtn->Location = System::Drawing::Point(115, 649);
			this->editUserBtn->Name = L"editUserBtn";
			this->editUserBtn->Size = System::Drawing::Size(101, 42);
			this->editUserBtn->TabIndex = 15;
			this->editUserBtn->Text = L"Edit";
			this->editUserBtn->UseVisualStyleBackColor = true;
			this->editUserBtn->Click += gcnew System::EventHandler(this, &AdminPanel::editUserBtn_Click);
			// 
			// addUserBtn
			// 
			this->addUserBtn->Location = System::Drawing::Point(8, 649);
			this->addUserBtn->Name = L"addUserBtn";
			this->addUserBtn->Size = System::Drawing::Size(101, 42);
			this->addUserBtn->TabIndex = 13;
			this->addUserBtn->Text = L"Dodaj";
			this->addUserBtn->UseVisualStyleBackColor = true;
			this->addUserBtn->Click += gcnew System::EventHandler(this, &AdminPanel::addUserBtn_Click);
			// 
			// listOfUsers
			// 
			this->listOfUsers->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfUsers->CheckBoxes = true;
			this->listOfUsers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->userIdCol, this->userLoginCol,
					this->userPasswordCol, this->userPermisionCol
			});
			this->listOfUsers->FullRowSelect = true;
			this->listOfUsers->HideSelection = false;
			this->listOfUsers->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listOfUsers->Location = System::Drawing::Point(8, 50);
			this->listOfUsers->Name = L"listOfUsers";
			this->listOfUsers->Size = System::Drawing::Size(1176, 593);
			this->listOfUsers->TabIndex = 12;
			this->listOfUsers->UseCompatibleStateImageBehavior = false;
			this->listOfUsers->View = System::Windows::Forms::View::Details;
			// 
			// userIdCol
			// 
			this->userIdCol->Tag = L"0";
			this->userIdCol->Text = L"Id";
			this->userIdCol->Width = 100;
			// 
			// userLoginCol
			// 
			this->userLoginCol->Tag = L"1";
			this->userLoginCol->Text = L"Login";
			this->userLoginCol->Width = 300;
			// 
			// userPasswordCol
			// 
			this->userPasswordCol->Tag = L"2";
			this->userPasswordCol->Text = L"Haslo";
			this->userPasswordCol->Width = 0;
			// 
			// userPermisionCol
			// 
			this->userPermisionCol->Tag = L"3";
			this->userPermisionCol->Text = L"Rola";
			this->userPermisionCol->Width = 200;
			// 
			// companyTab
			// 
			this->companyTab->Controls->Add(this->editCompanyBtn);
			this->companyTab->Controls->Add(this->deleteCompanyBtn);
			this->companyTab->Controls->Add(this->addCompanyBtn);
			this->companyTab->Controls->Add(this->listOfCompanies);
			this->companyTab->Location = System::Drawing::Point(4, 29);
			this->companyTab->Name = L"companyTab";
			this->companyTab->Padding = System::Windows::Forms::Padding(3);
			this->companyTab->Size = System::Drawing::Size(1193, 701);
			this->companyTab->TabIndex = 1;
			this->companyTab->Text = L"Firmy";
			this->companyTab->UseVisualStyleBackColor = true;
			// 
			// editCompanyBtn
			// 
			this->editCompanyBtn->Location = System::Drawing::Point(222, 651);
			this->editCompanyBtn->Name = L"editCompanyBtn";
			this->editCompanyBtn->Size = System::Drawing::Size(101, 42);
			this->editCompanyBtn->TabIndex = 21;
			this->editCompanyBtn->Text = L"Edit";
			this->editCompanyBtn->UseVisualStyleBackColor = true;
			this->editCompanyBtn->Click += gcnew System::EventHandler(this, &AdminPanel::editCompanyBtn_Click);
			// 
			// deleteCompanyBtn
			// 
			this->deleteCompanyBtn->Location = System::Drawing::Point(115, 651);
			this->deleteCompanyBtn->Name = L"deleteCompanyBtn";
			this->deleteCompanyBtn->Size = System::Drawing::Size(101, 42);
			this->deleteCompanyBtn->TabIndex = 20;
			this->deleteCompanyBtn->Text = L"Usuñ";
			this->deleteCompanyBtn->UseVisualStyleBackColor = true;
			this->deleteCompanyBtn->Click += gcnew System::EventHandler(this, &AdminPanel::deleteCompanyBtn_Click);
			// 
			// addCompanyBtn
			// 
			this->addCompanyBtn->Location = System::Drawing::Point(8, 651);
			this->addCompanyBtn->Name = L"addCompanyBtn";
			this->addCompanyBtn->Size = System::Drawing::Size(101, 42);
			this->addCompanyBtn->TabIndex = 19;
			this->addCompanyBtn->Text = L"Dodaj";
			this->addCompanyBtn->UseVisualStyleBackColor = true;
			this->addCompanyBtn->Click += gcnew System::EventHandler(this, &AdminPanel::addCompanyBtn_Click);
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
			this->categoryTab->Controls->Add(this->editCategoryBtn);
			this->categoryTab->Controls->Add(this->deleteCategoryBtn);
			this->categoryTab->Controls->Add(this->addCategoryBtn);
			this->categoryTab->Controls->Add(this->listOfCategories);
			this->categoryTab->Location = System::Drawing::Point(4, 29);
			this->categoryTab->Name = L"categoryTab";
			this->categoryTab->Padding = System::Windows::Forms::Padding(3);
			this->categoryTab->Size = System::Drawing::Size(1193, 701);
			this->categoryTab->TabIndex = 2;
			this->categoryTab->Text = L"Kategorie";
			this->categoryTab->UseVisualStyleBackColor = true;
			// 
			// editCategoryBtn
			// 
			this->editCategoryBtn->Location = System::Drawing::Point(222, 651);
			this->editCategoryBtn->Name = L"editCategoryBtn";
			this->editCategoryBtn->Size = System::Drawing::Size(101, 42);
			this->editCategoryBtn->TabIndex = 21;
			this->editCategoryBtn->Text = L"Edit";
			this->editCategoryBtn->UseVisualStyleBackColor = true;
			this->editCategoryBtn->Click += gcnew System::EventHandler(this, &AdminPanel::editCategoryBtn_Click);
			// 
			// deleteCategoryBtn
			// 
			this->deleteCategoryBtn->Location = System::Drawing::Point(115, 651);
			this->deleteCategoryBtn->Name = L"deleteCategoryBtn";
			this->deleteCategoryBtn->Size = System::Drawing::Size(101, 42);
			this->deleteCategoryBtn->TabIndex = 20;
			this->deleteCategoryBtn->Text = L"Usuñ";
			this->deleteCategoryBtn->UseVisualStyleBackColor = true;
			this->deleteCategoryBtn->Click += gcnew System::EventHandler(this, &AdminPanel::deleteCategoryBtn_Click);
			// 
			// addCategoryBtn
			// 
			this->addCategoryBtn->Location = System::Drawing::Point(8, 651);
			this->addCategoryBtn->Name = L"addCategoryBtn";
			this->addCategoryBtn->Size = System::Drawing::Size(101, 42);
			this->addCategoryBtn->TabIndex = 19;
			this->addCategoryBtn->Text = L"Dodaj";
			this->addCategoryBtn->UseVisualStyleBackColor = true;
			this->addCategoryBtn->Click += gcnew System::EventHandler(this, &AdminPanel::addCategoryBtn_Click);
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
			// productTab
			// 
			this->productTab->Controls->Add(this->editProductBtn);
			this->productTab->Controls->Add(this->deleteProductBtn);
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
			// editProductBtn
			// 
			this->editProductBtn->Location = System::Drawing::Point(222, 651);
			this->editProductBtn->Name = L"editProductBtn";
			this->editProductBtn->Size = System::Drawing::Size(101, 42);
			this->editProductBtn->TabIndex = 21;
			this->editProductBtn->Text = L"Edit";
			this->editProductBtn->UseVisualStyleBackColor = true;
			this->editProductBtn->Click += gcnew System::EventHandler(this, &AdminPanel::editProductBtn_Click);
			// 
			// deleteProductBtn
			// 
			this->deleteProductBtn->Location = System::Drawing::Point(115, 651);
			this->deleteProductBtn->Name = L"deleteProductBtn";
			this->deleteProductBtn->Size = System::Drawing::Size(101, 42);
			this->deleteProductBtn->TabIndex = 20;
			this->deleteProductBtn->Text = L"Usuñ";
			this->deleteProductBtn->UseVisualStyleBackColor = true;
			this->deleteProductBtn->Click += gcnew System::EventHandler(this, &AdminPanel::deleteProductBtn_Click);
			// 
			// addProductBtn
			// 
			this->addProductBtn->Location = System::Drawing::Point(8, 651);
			this->addProductBtn->Name = L"addProductBtn";
			this->addProductBtn->Size = System::Drawing::Size(101, 42);
			this->addProductBtn->TabIndex = 19;
			this->addProductBtn->Text = L"Dodaj";
			this->addProductBtn->UseVisualStyleBackColor = true;
			this->addProductBtn->Click += gcnew System::EventHandler(this, &AdminPanel::addProductBtn_Click);
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
			this->offerTab->Controls->Add(this->editOfferBtn);
			this->offerTab->Controls->Add(this->deleteOfferBtn);
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
			// editOfferBtn
			// 
			this->editOfferBtn->Location = System::Drawing::Point(222, 651);
			this->editOfferBtn->Name = L"editOfferBtn";
			this->editOfferBtn->Size = System::Drawing::Size(101, 42);
			this->editOfferBtn->TabIndex = 21;
			this->editOfferBtn->Text = L"Edit";
			this->editOfferBtn->UseVisualStyleBackColor = true;
			this->editOfferBtn->Click += gcnew System::EventHandler(this, &AdminPanel::editOfferBtn_Click);
			// 
			// deleteOfferBtn
			// 
			this->deleteOfferBtn->Location = System::Drawing::Point(115, 651);
			this->deleteOfferBtn->Name = L"deleteOfferBtn";
			this->deleteOfferBtn->Size = System::Drawing::Size(101, 42);
			this->deleteOfferBtn->TabIndex = 20;
			this->deleteOfferBtn->Text = L"Usuñ";
			this->deleteOfferBtn->UseVisualStyleBackColor = true;
			this->deleteOfferBtn->Click += gcnew System::EventHandler(this, &AdminPanel::deleteOfferBtn_Click);
			// 
			// addOfferBtn
			// 
			this->addOfferBtn->Location = System::Drawing::Point(8, 651);
			this->addOfferBtn->Name = L"addOfferBtn";
			this->addOfferBtn->Size = System::Drawing::Size(101, 42);
			this->addOfferBtn->TabIndex = 19;
			this->addOfferBtn->Text = L"Dodaj";
			this->addOfferBtn->UseVisualStyleBackColor = true;
			this->addOfferBtn->Click += gcnew System::EventHandler(this, &AdminPanel::addOfferBtn_Click);
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
			// transactionTab
			// 
			this->transactionTab->Controls->Add(this->editTransactionBtn);
			this->transactionTab->Controls->Add(this->addTransactionBtn);
			this->transactionTab->Controls->Add(this->listOfTransactions);
			this->transactionTab->Location = System::Drawing::Point(4, 29);
			this->transactionTab->Name = L"transactionTab";
			this->transactionTab->Padding = System::Windows::Forms::Padding(3);
			this->transactionTab->Size = System::Drawing::Size(1193, 701);
			this->transactionTab->TabIndex = 5;
			this->transactionTab->Text = L"Transakcje";
			this->transactionTab->UseVisualStyleBackColor = true;
			// 
			// editTransactionBtn
			// 
			this->editTransactionBtn->Location = System::Drawing::Point(115, 651);
			this->editTransactionBtn->Name = L"editTransactionBtn";
			this->editTransactionBtn->Size = System::Drawing::Size(101, 42);
			this->editTransactionBtn->TabIndex = 21;
			this->editTransactionBtn->Text = L"Edit";
			this->editTransactionBtn->UseVisualStyleBackColor = true;
			this->editTransactionBtn->Click += gcnew System::EventHandler(this, &AdminPanel::editTransactionBtn_Click);
			// 
			// addTransactionBtn
			// 
			this->addTransactionBtn->Location = System::Drawing::Point(8, 651);
			this->addTransactionBtn->Name = L"addTransactionBtn";
			this->addTransactionBtn->Size = System::Drawing::Size(101, 42);
			this->addTransactionBtn->TabIndex = 19;
			this->addTransactionBtn->Text = L"Dodaj";
			this->addTransactionBtn->UseVisualStyleBackColor = true;
			this->addTransactionBtn->Click += gcnew System::EventHandler(this, &AdminPanel::addTransactionBtn_Click);
			// 
			// listOfTransactions
			// 
			this->listOfTransactions->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfTransactions->CheckBoxes = true;
			this->listOfTransactions->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->transactionIdCol,
					this->transactionDateCol, this->transactionUserCol, this->transactionOffersListCol
			});
			this->listOfTransactions->FullRowSelect = true;
			this->listOfTransactions->HideSelection = false;
			this->listOfTransactions->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listOfTransactions->Location = System::Drawing::Point(8, 52);
			this->listOfTransactions->Name = L"listOfTransactions";
			this->listOfTransactions->Size = System::Drawing::Size(1176, 593);
			this->listOfTransactions->TabIndex = 18;
			this->listOfTransactions->UseCompatibleStateImageBehavior = false;
			this->listOfTransactions->View = System::Windows::Forms::View::Details;
			// 
			// transactionIdCol
			// 
			this->transactionIdCol->Tag = L"0";
			this->transactionIdCol->Text = L"Id";
			this->transactionIdCol->Width = 100;
			// 
			// transactionDateCol
			// 
			this->transactionDateCol->Tag = L"1";
			this->transactionDateCol->Text = L"Data";
			this->transactionDateCol->Width = 100;
			// 
			// transactionUserCol
			// 
			this->transactionUserCol->Tag = L"2";
			this->transactionUserCol->Text = L"Id u¿ytkownika";
			this->transactionUserCol->Width = 100;
			// 
			// transactionOffersListCol
			// 
			this->transactionOffersListCol->Tag = L"3";
			this->transactionOffersListCol->Text = L"Lista ofert";
			this->transactionOffersListCol->Width = 400;
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->user);
			this->Name = L"AdminPanel";
			this->Text = L"Panel Administratora";
			this->tabControl1->ResumeLayout(false);
			this->userTab->ResumeLayout(false);
			this->companyTab->ResumeLayout(false);
			this->categoryTab->ResumeLayout(false);
			this->productTab->ResumeLayout(false);
			this->offerTab->ResumeLayout(false);
			this->transactionTab->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->setItems(this->admin->getAllUser(), this->admin->getAllCompany(), this->admin->getAllCategory(),
				this->admin->getAllProduct(), this->admin->getAllOffer(), this->admin->getAllTransaction());
		}

		public: 
			void setAdmin(User user);
		private: 
			void setItems(std::vector<User> users, std::vector<Company> companies, std::vector<Category> categories,
					std::vector<Product> products, std::vector<Offer> offers, std::vector<Transaction> transactions);
			void setUsers(std::vector<User> users);
			void setCompanies(std::vector<Company> companies);
			void setCategories(std::vector<Category> categories);
			void setProducts(std::vector<Product> products);
			void setOffers(std::vector<Offer> offers);
			void setTransactions(std::vector<Transaction> transactions);

			/*this->setItems(this->admin->getAllUser(), this->admin->getAllCompany(), this->admin->getAllCategory(),
				this->admin->getAllProduct(), this->admin->getAllOffer(), this->admin->getAllTransaction());*/

#pragma endregion
	private: System::Void deleteCompanyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfCompanies->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			Company company = Company(System::Int32::Parse(item->SubItems[0]->Text), "");
			if (this->admin->deleteCompany(company))
				this->listOfCompanies->Items->RemoveAt(item->Index);
		}
	}
	private: System::Void deleteCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfCategories->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			Category category = Category(System::Int32::Parse(item->SubItems[0]->Text), "");
			if (this->admin->deleteCategory(category))
				this->listOfCategories->Items->RemoveAt(item->Index);
		}
	}
	private: System::Void deleteProductBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfProducts->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			Product product = Product(System::Int32::Parse(item->SubItems[0]->Text), "");
			if (this->admin->deleteProduct(product))
				this->listOfProducts->Items->RemoveAt(item->Index);
		}
	}
	private: System::Void deleteOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfOffers->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			Offer offer = Offer(System::Int32::Parse(item->SubItems[0]->Text), 0);
			if (this->admin->deleteOffer(offer))
				this->listOfOffers->Items->RemoveAt(item->Index);
		}
	}
	private: System::Void addUserBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddUser addUser;
		addUser.setAdmin(this->admin);
		addUser.setOption(true);
		addUser.ShowDialog();
		this->listOfUsers->Items->Clear();
		this->setUsers(this->admin->getAllUser());
	}
	private: System::Void editUserBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfUsers->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			ProjektCPPWindowsForms::AddUser addUser;
			addUser.setAdmin(this->admin);
			addUser.setUser(item);
			addUser.setOption(false);
			addUser.ShowDialog();
			this->listOfUsers->Items->Clear();
			this->setUsers(this->admin->getAllUser());
		}
	}
	private: System::Void addCompanyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddCompany addCompany;
		addCompany.setAdmin(this->admin);
		addCompany.setOption(true);
		addCompany.ShowDialog();
		this->listOfCompanies->Items->Clear();
		this->setCompanies(this->admin->getAllCompany());
	}
	private: System::Void editCompanyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfCompanies->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			ProjektCPPWindowsForms::AddCompany addCompany;
			addCompany.setAdmin(this->admin);
			addCompany.setCompany(item);
			addCompany.setOption(false);
			addCompany.ShowDialog();
			this->listOfCompanies->Items->Clear();
			this->setCompanies(this->admin->getAllCompany());
		}
	}
	private: System::Void addCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddCategory addCategory;
		addCategory.setAdmin(this->admin);
		addCategory.setOption(true);
		addCategory.ShowDialog();
		this->listOfCategories->Items->Clear();
		this->setCategories(this->admin->getAllCategory());
	}
	private: System::Void editCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfCategories->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			ProjektCPPWindowsForms::AddCategory addCategory;
			addCategory.setAdmin(this->admin);
			addCategory.setCategory(item);
			addCategory.setOption(false);
			addCategory.ShowDialog();
			this->listOfCategories->Items->Clear();
			this->setCategories(this->admin->getAllCategory());
		}
	}
	private: System::Void addProductBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddProduct addProduct;
		addProduct.setAdmin(this->admin);
		addProduct.setOption(true);
		addProduct.ShowDialog();
		this->listOfProducts->Items->Clear();
		this->setProducts(this->admin->getAllProduct());
	}
	private: System::Void editProductBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfProducts->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			ProjektCPPWindowsForms::AddProduct addProduct;
			addProduct.setAdmin(this->admin);
			addProduct.setProduct(item);
			addProduct.setOption(false);
			addProduct.ShowDialog();
			this->listOfProducts->Items->Clear();
			this->setProducts(this->admin->getAllProduct());
		}
	}
	private: System::Void addOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddOffer addOffer;
		addOffer.setAdmin(this->admin);
		addOffer.setOption(true);
		addOffer.ShowDialog();
		this->listOfOffers->Items->Clear();
		this->setOffers(this->admin->getAllOffer());
	}
	private: System::Void editOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfOffers->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			ProjektCPPWindowsForms::AddOffer addOffer;
			addOffer.setAdmin(this->admin);
			addOffer.setOffer(item);
			addOffer.setOption(false);
			addOffer.ShowDialog();
			this->listOfOffers->Items->Clear();
			this->setOffers(this->admin->getAllOffer());
		}
	}
	private: System::Void addTransactionBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::AddTransaction addTransaction;
		addTransaction.setAdmin(this->admin);
		addTransaction.setOption(true);
		addTransaction.ShowDialog();
		this->listOfTransactions->Items->Clear();
		this->setTransactions(this->admin->getAllTransaction());
	}
	private: System::Void editTransactionBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listOfTransactions->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			ProjektCPPWindowsForms::AddTransaction addTransaction;
			addTransaction.setAdmin(this->admin);
			addTransaction.setTransaction(item);
			addTransaction.setOption(false);
			addTransaction.ShowDialog();
			this->listOfTransactions->Items->Clear();
			this->setTransactions(this->admin->getAllTransaction());
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
#endif PanelAdmin