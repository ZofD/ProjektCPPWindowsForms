#pragma once

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
	private: System::Windows::Forms::Button^ deleteUserBtn;
	private: System::Windows::Forms::Button^ addUserBtn;
	private: System::Windows::Forms::ListView^ listOfUsers;
	private: System::Windows::Forms::Button^ findUserBtn;
	private: System::Windows::Forms::TextBox^ findUserTxt;
	private: System::Windows::Forms::ColumnHeader^ userIdCol;
	private: System::Windows::Forms::ColumnHeader^ userLoginCol;
	private: System::Windows::Forms::ColumnHeader^ userPermisionCol;

	private: System::Windows::Forms::TabPage^ companyTab;
	private: System::Windows::Forms::Button^ editCompanyBtn;
	private: System::Windows::Forms::Button^ deleteCompanyBtn;
	private: System::Windows::Forms::Button^ addCompanyBtn;
	private: System::Windows::Forms::ListView^ listOfCompanies;
	private: System::Windows::Forms::Button^ findCompanyBtn;
	private: System::Windows::Forms::TextBox^ findCompanyTxt;
	private: System::Windows::Forms::ColumnHeader^ companyIdCol;
	private: System::Windows::Forms::ColumnHeader^ companyNameCol;

	private: System::Windows::Forms::TabPage^ categoryTab;
	private: System::Windows::Forms::Button^ editCategoryBtn;
	private: System::Windows::Forms::Button^ deleteCategoryBtn;
	private: System::Windows::Forms::Button^ addCategoryBtn;
	private: System::Windows::Forms::ListView^ listOfCategories;
	private: System::Windows::Forms::Button^ findCatregoryBtn;
	private: System::Windows::Forms::TextBox^ findCategoryTxt;
	private: System::Windows::Forms::ColumnHeader^ categoryIdCol;
	private: System::Windows::Forms::ColumnHeader^ categoryNameCol;

	private: System::Windows::Forms::TabPage^ productTab;
	private: System::Windows::Forms::Button^ editProductBtn;
	private: System::Windows::Forms::Button^ deleteProductBtn;
	private: System::Windows::Forms::Button^ addProductBtn;
	private: System::Windows::Forms::ListView^ listOfProducts;
	private: System::Windows::Forms::Button^ findProductBtn;
	private: System::Windows::Forms::TextBox^ findProductTxt;
	private: System::Windows::Forms::ColumnHeader^ productIdCol;
	private: System::Windows::Forms::ColumnHeader^ productNameCol;
	private: System::Windows::Forms::ColumnHeader^ productCategoryCol;
	private: System::Windows::Forms::ColumnHeader^ productCompanyCol;

	private: System::Windows::Forms::TabPage^ offerTab;
	private: System::Windows::Forms::Button^ editOfferBtn;
	private: System::Windows::Forms::Button^ deleteOfferBtn;
	private: System::Windows::Forms::Button^ addOfferBtn;
	private: System::Windows::Forms::ListView^ listOfOffers;
	private: System::Windows::Forms::Button^ findOfferBtn;
	private: System::Windows::Forms::TextBox^ findOfferTxt;
	private: System::Windows::Forms::ColumnHeader^ offerIdCol;
	private: System::Windows::Forms::ColumnHeader^ offerPriceCol;
	private: System::Windows::Forms::ColumnHeader^ offerProductCol;
	private: System::Windows::Forms::ColumnHeader^ offerDateStart;
	private: System::Windows::Forms::ColumnHeader^ offerDateEnd;

	private: System::Windows::Forms::TabPage^ transactionTab;
	private: System::Windows::Forms::Button^ editTransactionBtn;
	private: System::Windows::Forms::Button^ deleteTransactionBtn;
	private: System::Windows::Forms::Button^ addTransactionBtn;
	private: System::Windows::Forms::ListView^ listOfTransactions;
	private: System::Windows::Forms::Button^ findTransactionBtn;
	private: System::Windows::Forms::TextBox^ findTransactionTxt;
	private: System::Windows::Forms::ColumnHeader^ transactionIdCol;
	private: System::Windows::Forms::ColumnHeader^ transactionDateCol;
	private: System::Windows::Forms::ColumnHeader^ transactionUserCol;
	private: System::Windows::Forms::ColumnHeader^ transactionOffersListCol;

	private:
		Admin* admin;

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
		
		void setUsers(std::vector<User> users) {
			this->listOfUsers->BeginUpdate();
			for (User user : users) {
				String^ userID = gcnew String(user.getId().ToString());
				String^ userLogin = gcnew String(user.getLogin().c_str());
				String^ role;
				switch (user.getPermission())
				{
					case 0:
						role = "Administrator";
						break;
					case 1:
						role = "Pracownik";
						break;
					case 2:
						role = "Klient";
						break;
				}
				System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > (3){
					userID,
						userLogin, role
				}, -1));
				this->listOfUsers->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem
				});
			}
			this->listOfUsers->EndUpdate();
			//this->Controls->Add(this->listOfUsers);
		}
		void setCompanies(std::vector<Company> companies) {
			this->listOfCompanies->BeginUpdate();
			for (Company company : companies) {
				String^ companyID = gcnew String(company.getId().ToString());
				String^ companyName = gcnew String(company.getName().c_str());
				System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					companyID,
						companyName
				}, -1));
				this->listOfCompanies->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem
				});
			}
			this->listOfCompanies->EndUpdate();
			//this->Controls->Add(this->listOfCompanies);
		}
		void setCategories(std::vector<Category> categories) {
			this->listOfCategories->BeginUpdate();
			for (Category category : categories) {
				String^ categoryID = gcnew String(category.getId().ToString());
				String^ categoryName = gcnew String(category.getName().c_str());
				System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					categoryID,
						categoryName
				}, -1));
				this->listOfCategories->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem
				});
			}
			this->listOfCategories->EndUpdate();
			//this->Controls->Add(this->listOfCategories);
		}
		void setProducts(std::vector<Product> products) {
			this->listOfProducts->BeginUpdate();
			for (Product product : products) {
				String^ productID = gcnew String(product.getId().ToString());
				String^ productName = gcnew String(product.getName().c_str());
				String^ productCategory = gcnew String(product.getCategory().getId().ToString());
				String^ productCompany = gcnew String(product.getCompany().getId().ToString());
				System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					productID,
						productName, productCategory, productCompany
				}, -1));
				this->listOfProducts->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem
				});
			}
			this->listOfProducts->EndUpdate();
			//this->Controls->Add(this->listOfProducts);
		}
		void setOffers(std::vector<Offer> offers) {
			this->listOfOffers->BeginUpdate();
			for (Offer offer : offers) {
				String^ offerID = gcnew String(offer.getId().ToString());
				String^ offerPrice = gcnew String(offer.getPrice().ToString());
				String^ offerProduct = gcnew String(offer.getProduct().getId().ToString());
				String^ offerStartDate = gcnew String(Helper::time_tToString(offer.getStartDate()).c_str());
				String^ offerEndDate = gcnew String(Helper::time_tToString(offer.getStopDate()).c_str());
				System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					offerID,
						offerPrice, offerProduct, offerStartDate, offerEndDate
				}, -1));
				this->listOfOffers->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem
				});
			}
			this->listOfOffers->EndUpdate();
			//this->Controls->Add(this->listOfOffers);
		}
		void setTransactions(std::vector<Transaction> transactions) {
			this->listOfTransactions->BeginUpdate();
			for (Transaction transaction : transactions) {
				String^ transactionID = gcnew String(transaction.getId().ToString());
				String^ transactionDate = gcnew String(Helper::time_tToString(transaction.getDate()).c_str());
				String^ transactionUser = gcnew String(transaction.getUser().getId().ToString());
				String^ transactionOffers;
				std::string tmp;
				for (Offer offer : transaction.getOfferList()) {
					tmp += (std::to_string(offer.getId()) + ";");
				}
				transactionOffers = gcnew String(tmp.c_str());
				System::Windows::Forms::ListViewItem^ listviewitem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					transactionID,
						transactionDate, transactionUser, transactionOffers
				}, -1));
				this->listOfTransactions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem
				});
			}
			this->listOfTransactions->EndUpdate();
			//this->Controls->Add(this->listOfTransactions);
		}
		
		void setItems(std::vector<User> users, std::vector<Company> companies, std::vector<Category> categories, std::vector<Product> products, std::vector<Offer> offers, std::vector<Transaction> transactions) {
			setUsers(users);
			setCompanies(companies);
			setCategories(categories);
			setProducts(products);
			setOffers(offers);
			setTransactions(transactions);
		}

		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->user = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->userTab = (gcnew System::Windows::Forms::TabPage());
			this->editUserBtn = (gcnew System::Windows::Forms::Button());
			this->deleteUserBtn = (gcnew System::Windows::Forms::Button());
			this->addUserBtn = (gcnew System::Windows::Forms::Button());
			this->listOfUsers = (gcnew System::Windows::Forms::ListView());
			this->userIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->userLoginCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->userPermisionCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->findUserBtn = (gcnew System::Windows::Forms::Button());
			this->findUserTxt = (gcnew System::Windows::Forms::TextBox());
			this->companyTab = (gcnew System::Windows::Forms::TabPage());
			this->editCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->deleteCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->addCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->listOfCompanies = (gcnew System::Windows::Forms::ListView());
			this->companyIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->companyNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->findCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->findCompanyTxt = (gcnew System::Windows::Forms::TextBox());
			this->categoryTab = (gcnew System::Windows::Forms::TabPage());
			this->editCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->deleteCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->addCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->listOfCategories = (gcnew System::Windows::Forms::ListView());
			this->categoryIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->categoryNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->findCatregoryBtn = (gcnew System::Windows::Forms::Button());
			this->findCategoryTxt = (gcnew System::Windows::Forms::TextBox());
			this->productTab = (gcnew System::Windows::Forms::TabPage());
			this->editProductBtn = (gcnew System::Windows::Forms::Button());
			this->deleteProductBtn = (gcnew System::Windows::Forms::Button());
			this->addProductBtn = (gcnew System::Windows::Forms::Button());
			this->listOfProducts = (gcnew System::Windows::Forms::ListView());
			this->productIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productNameCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productCategoryCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->productCompanyCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->findProductBtn = (gcnew System::Windows::Forms::Button());
			this->findProductTxt = (gcnew System::Windows::Forms::TextBox());
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
			this->findOfferBtn = (gcnew System::Windows::Forms::Button());
			this->findOfferTxt = (gcnew System::Windows::Forms::TextBox());
			this->transactionTab = (gcnew System::Windows::Forms::TabPage());
			this->editTransactionBtn = (gcnew System::Windows::Forms::Button());
			this->deleteTransactionBtn = (gcnew System::Windows::Forms::Button());
			this->addTransactionBtn = (gcnew System::Windows::Forms::Button());
			this->listOfTransactions = (gcnew System::Windows::Forms::ListView());
			this->transactionIdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionDateCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionUserCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->transactionOffersListCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->findTransactionBtn = (gcnew System::Windows::Forms::Button());
			this->findTransactionTxt = (gcnew System::Windows::Forms::TextBox());
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
			this->userTab->Controls->Add(this->deleteUserBtn);
			this->userTab->Controls->Add(this->addUserBtn);
			this->userTab->Controls->Add(this->listOfUsers);
			this->userTab->Controls->Add(this->findUserBtn);
			this->userTab->Controls->Add(this->findUserTxt);
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
			this->editUserBtn->Location = System::Drawing::Point(222, 649);
			this->editUserBtn->Name = L"editUserBtn";
			this->editUserBtn->Size = System::Drawing::Size(101, 42);
			this->editUserBtn->TabIndex = 15;
			this->editUserBtn->Text = L"Edit";
			this->editUserBtn->UseVisualStyleBackColor = true;
			// 
			// deleteUserBtn
			// 
			this->deleteUserBtn->Location = System::Drawing::Point(115, 649);
			this->deleteUserBtn->Name = L"deleteUserBtn";
			this->deleteUserBtn->Size = System::Drawing::Size(101, 42);
			this->deleteUserBtn->TabIndex = 14;
			this->deleteUserBtn->Text = L"Usuñ";
			this->deleteUserBtn->UseVisualStyleBackColor = true;
			// 
			// addUserBtn
			// 
			this->addUserBtn->Location = System::Drawing::Point(8, 649);
			this->addUserBtn->Name = L"addUserBtn";
			this->addUserBtn->Size = System::Drawing::Size(101, 42);
			this->addUserBtn->TabIndex = 13;
			this->addUserBtn->Text = L"Dodaj";
			this->addUserBtn->UseVisualStyleBackColor = true;
			// 
			// listOfUsers
			// 
			this->listOfUsers->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfUsers->CheckBoxes = true;
			this->listOfUsers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->userIdCol, this->userLoginCol,
					this->userPermisionCol
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
			// userPermisionCol
			// 
			this->userPermisionCol->Tag = L"2";
			this->userPermisionCol->Text = L"Rola";
			this->userPermisionCol->Width = 200;
			// 
			// findUserBtn
			// 
			this->findUserBtn->Location = System::Drawing::Point(649, 6);
			this->findUserBtn->Name = L"findUserBtn";
			this->findUserBtn->Size = System::Drawing::Size(77, 38);
			this->findUserBtn->TabIndex = 11;
			this->findUserBtn->Text = L"Szukaj";
			this->findUserBtn->UseVisualStyleBackColor = true;
			// 
			// findUserTxt
			// 
			this->findUserTxt->Location = System::Drawing::Point(732, 12);
			this->findUserTxt->Name = L"findUserTxt";
			this->findUserTxt->Size = System::Drawing::Size(452, 26);
			this->findUserTxt->TabIndex = 10;
			// 
			// companyTab
			// 
			this->companyTab->Controls->Add(this->editCompanyBtn);
			this->companyTab->Controls->Add(this->deleteCompanyBtn);
			this->companyTab->Controls->Add(this->addCompanyBtn);
			this->companyTab->Controls->Add(this->listOfCompanies);
			this->companyTab->Controls->Add(this->findCompanyBtn);
			this->companyTab->Controls->Add(this->findCompanyTxt);
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
			// 
			// deleteCompanyBtn
			// 
			this->deleteCompanyBtn->Location = System::Drawing::Point(115, 651);
			this->deleteCompanyBtn->Name = L"deleteCompanyBtn";
			this->deleteCompanyBtn->Size = System::Drawing::Size(101, 42);
			this->deleteCompanyBtn->TabIndex = 20;
			this->deleteCompanyBtn->Text = L"Usuñ";
			this->deleteCompanyBtn->UseVisualStyleBackColor = true;
			// 
			// addCompanyBtn
			// 
			this->addCompanyBtn->Location = System::Drawing::Point(8, 651);
			this->addCompanyBtn->Name = L"addCompanyBtn";
			this->addCompanyBtn->Size = System::Drawing::Size(101, 42);
			this->addCompanyBtn->TabIndex = 19;
			this->addCompanyBtn->Text = L"Dodaj";
			this->addCompanyBtn->UseVisualStyleBackColor = true;
			// 
			// listOfCompanies
			// 
			this->listOfCompanies->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->companyIdCol,
					this->companyNameCol
			});
			this->listOfCompanies->HideSelection = false;
			this->listOfCompanies->Location = System::Drawing::Point(8, 52);
			this->listOfCompanies->Name = L"listOfCompanies";
			this->listOfCompanies->Size = System::Drawing::Size(1176, 593);
			this->listOfCompanies->TabIndex = 18;
			this->listOfCompanies->UseCompatibleStateImageBehavior = false;
			this->listOfCompanies->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfCompanies->CheckBoxes = true;
			this->listOfCompanies->FullRowSelect = true;
			this->listOfCompanies->ImeMode = System::Windows::Forms::ImeMode::NoControl;
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
			// findCompanyBtn
			// 
			this->findCompanyBtn->Location = System::Drawing::Point(649, 8);
			this->findCompanyBtn->Name = L"findCompanyBtn";
			this->findCompanyBtn->Size = System::Drawing::Size(77, 38);
			this->findCompanyBtn->TabIndex = 17;
			this->findCompanyBtn->Text = L"Szukaj";
			this->findCompanyBtn->UseVisualStyleBackColor = true;
			// 
			// findCompanyTxt
			// 
			this->findCompanyTxt->Location = System::Drawing::Point(732, 14);
			this->findCompanyTxt->Name = L"findCompanyTxt";
			this->findCompanyTxt->Size = System::Drawing::Size(452, 26);
			this->findCompanyTxt->TabIndex = 16;
			// 
			// categoryTab
			// 
			this->categoryTab->Controls->Add(this->editCategoryBtn);
			this->categoryTab->Controls->Add(this->deleteCategoryBtn);
			this->categoryTab->Controls->Add(this->addCategoryBtn);
			this->categoryTab->Controls->Add(this->listOfCategories);
			this->categoryTab->Controls->Add(this->findCatregoryBtn);
			this->categoryTab->Controls->Add(this->findCategoryTxt);
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
			// 
			// deleteCategoryBtn
			// 
			this->deleteCategoryBtn->Location = System::Drawing::Point(115, 651);
			this->deleteCategoryBtn->Name = L"deleteCategoryBtn";
			this->deleteCategoryBtn->Size = System::Drawing::Size(101, 42);
			this->deleteCategoryBtn->TabIndex = 20;
			this->deleteCategoryBtn->Text = L"Usuñ";
			this->deleteCategoryBtn->UseVisualStyleBackColor = true;
			// 
			// addCategoryBtn
			// 
			this->addCategoryBtn->Location = System::Drawing::Point(8, 651);
			this->addCategoryBtn->Name = L"addCategoryBtn";
			this->addCategoryBtn->Size = System::Drawing::Size(101, 42);
			this->addCategoryBtn->TabIndex = 19;
			this->addCategoryBtn->Text = L"Dodaj";
			this->addCategoryBtn->UseVisualStyleBackColor = true;
			// 
			// listOfCategories
			// 
			this->listOfCategories->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->categoryIdCol,
					this->categoryNameCol
			});
			this->listOfCategories->HideSelection = false;
			this->listOfCategories->Location = System::Drawing::Point(8, 52);
			this->listOfCategories->Name = L"listOfCategories";
			this->listOfCategories->Size = System::Drawing::Size(1176, 593);
			this->listOfCategories->TabIndex = 18;
			this->listOfCategories->UseCompatibleStateImageBehavior = false;
			this->listOfCategories->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfCategories->CheckBoxes = true;
			this->listOfCategories->FullRowSelect = true;
			this->listOfCategories->ImeMode = System::Windows::Forms::ImeMode::NoControl;
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
			// findCatregoryBtn
			// 
			this->findCatregoryBtn->Location = System::Drawing::Point(649, 8);
			this->findCatregoryBtn->Name = L"findCatregoryBtn";
			this->findCatregoryBtn->Size = System::Drawing::Size(77, 38);
			this->findCatregoryBtn->TabIndex = 17;
			this->findCatregoryBtn->Text = L"Szukaj";
			this->findCatregoryBtn->UseVisualStyleBackColor = true;
			// 
			// findCategoryTxt
			// 
			this->findCategoryTxt->Location = System::Drawing::Point(732, 14);
			this->findCategoryTxt->Name = L"findCategoryTxt";
			this->findCategoryTxt->Size = System::Drawing::Size(452, 26);
			this->findCategoryTxt->TabIndex = 16;
			// 
			// productTab
			// 
			this->productTab->Controls->Add(this->editProductBtn);
			this->productTab->Controls->Add(this->deleteProductBtn);
			this->productTab->Controls->Add(this->addProductBtn);
			this->productTab->Controls->Add(this->listOfProducts);
			this->productTab->Controls->Add(this->findProductBtn);
			this->productTab->Controls->Add(this->findProductTxt);
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
			// 
			// deleteProductBtn
			// 
			this->deleteProductBtn->Location = System::Drawing::Point(115, 651);
			this->deleteProductBtn->Name = L"deleteProductBtn";
			this->deleteProductBtn->Size = System::Drawing::Size(101, 42);
			this->deleteProductBtn->TabIndex = 20;
			this->deleteProductBtn->Text = L"Usuñ";
			this->deleteProductBtn->UseVisualStyleBackColor = true;
			// 
			// addProductBtn
			// 
			this->addProductBtn->Location = System::Drawing::Point(8, 651);
			this->addProductBtn->Name = L"addProductBtn";
			this->addProductBtn->Size = System::Drawing::Size(101, 42);
			this->addProductBtn->TabIndex = 19;
			this->addProductBtn->Text = L"Dodaj";
			this->addProductBtn->UseVisualStyleBackColor = true;
			// 
			// listOfProducts
			// 
			this->listOfProducts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->productIdCol,
					this->productNameCol, this->productCategoryCol, this->productCompanyCol
			});
			this->listOfProducts->HideSelection = false;
			this->listOfProducts->Location = System::Drawing::Point(8, 52);
			this->listOfProducts->Name = L"listOfProducts";
			this->listOfProducts->Size = System::Drawing::Size(1176, 593);
			this->listOfProducts->TabIndex = 18;
			this->listOfProducts->UseCompatibleStateImageBehavior = false;
			this->listOfProducts->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfProducts->CheckBoxes = true;
			this->listOfProducts->FullRowSelect = true;
			this->listOfProducts->ImeMode = System::Windows::Forms::ImeMode::NoControl;
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
			// findProductBtn
			// 
			this->findProductBtn->Location = System::Drawing::Point(649, 8);
			this->findProductBtn->Name = L"findProductBtn";
			this->findProductBtn->Size = System::Drawing::Size(77, 38);
			this->findProductBtn->TabIndex = 17;
			this->findProductBtn->Text = L"Szukaj";
			this->findProductBtn->UseVisualStyleBackColor = true;
			// 
			// findProductTxt
			// 
			this->findProductTxt->Location = System::Drawing::Point(732, 14);
			this->findProductTxt->Name = L"findProductTxt";
			this->findProductTxt->Size = System::Drawing::Size(452, 26);
			this->findProductTxt->TabIndex = 16;
			// 
			// offerTab
			// 
			this->offerTab->Controls->Add(this->editOfferBtn);
			this->offerTab->Controls->Add(this->deleteOfferBtn);
			this->offerTab->Controls->Add(this->addOfferBtn);
			this->offerTab->Controls->Add(this->listOfOffers);
			this->offerTab->Controls->Add(this->findOfferBtn);
			this->offerTab->Controls->Add(this->findOfferTxt);
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
			// 
			// deleteOfferBtn
			// 
			this->deleteOfferBtn->Location = System::Drawing::Point(115, 651);
			this->deleteOfferBtn->Name = L"deleteOfferBtn";
			this->deleteOfferBtn->Size = System::Drawing::Size(101, 42);
			this->deleteOfferBtn->TabIndex = 20;
			this->deleteOfferBtn->Text = L"Usuñ";
			this->deleteOfferBtn->UseVisualStyleBackColor = true;
			// 
			// addOfferBtn
			// 
			this->addOfferBtn->Location = System::Drawing::Point(8, 651);
			this->addOfferBtn->Name = L"addOfferBtn";
			this->addOfferBtn->Size = System::Drawing::Size(101, 42);
			this->addOfferBtn->TabIndex = 19;
			this->addOfferBtn->Text = L"Dodaj";
			this->addOfferBtn->UseVisualStyleBackColor = true;
			// 
			// listOfOffers
			// 
			this->listOfOffers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->offerIdCol, this->offerPriceCol,
					this->offerProductCol, this->offerDateStart, this->offerDateEnd
			});
			this->listOfOffers->HideSelection = false;
			this->listOfOffers->Location = System::Drawing::Point(8, 52);
			this->listOfOffers->Name = L"listOfOffers";
			this->listOfOffers->Size = System::Drawing::Size(1176, 593);
			this->listOfOffers->TabIndex = 18;
			this->listOfOffers->UseCompatibleStateImageBehavior = false;
			this->listOfOffers->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfOffers->CheckBoxes = true;
			this->listOfOffers->FullRowSelect = true;
			this->listOfOffers->ImeMode = System::Windows::Forms::ImeMode::NoControl;
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
			// findOfferBtn
			// 
			this->findOfferBtn->Location = System::Drawing::Point(649, 8);
			this->findOfferBtn->Name = L"findOfferBtn";
			this->findOfferBtn->Size = System::Drawing::Size(77, 38);
			this->findOfferBtn->TabIndex = 17;
			this->findOfferBtn->Text = L"Szukaj";
			this->findOfferBtn->UseVisualStyleBackColor = true;
			// 
			// findOfferTxt
			// 
			this->findOfferTxt->Location = System::Drawing::Point(732, 14);
			this->findOfferTxt->Name = L"findOfferTxt";
			this->findOfferTxt->Size = System::Drawing::Size(452, 26);
			this->findOfferTxt->TabIndex = 16;
			// 
			// transactionTab
			// 
			this->transactionTab->Controls->Add(this->editTransactionBtn);
			this->transactionTab->Controls->Add(this->deleteTransactionBtn);
			this->transactionTab->Controls->Add(this->addTransactionBtn);
			this->transactionTab->Controls->Add(this->listOfTransactions);
			this->transactionTab->Controls->Add(this->findTransactionBtn);
			this->transactionTab->Controls->Add(this->findTransactionTxt);
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
			this->editTransactionBtn->Location = System::Drawing::Point(222, 651);
			this->editTransactionBtn->Name = L"editTransactionBtn";
			this->editTransactionBtn->Size = System::Drawing::Size(101, 42);
			this->editTransactionBtn->TabIndex = 21;
			this->editTransactionBtn->Text = L"Edit";
			this->editTransactionBtn->UseVisualStyleBackColor = true;
			// 
			// deleteTransactionBtn
			// 
			this->deleteTransactionBtn->Location = System::Drawing::Point(115, 651);
			this->deleteTransactionBtn->Name = L"deleteTransactionBtn";
			this->deleteTransactionBtn->Size = System::Drawing::Size(101, 42);
			this->deleteTransactionBtn->TabIndex = 20;
			this->deleteTransactionBtn->Text = L"Usuñ";
			this->deleteTransactionBtn->UseVisualStyleBackColor = true;
			// 
			// addTransactionBtn
			// 
			this->addTransactionBtn->Location = System::Drawing::Point(8, 651);
			this->addTransactionBtn->Name = L"addTransactionBtn";
			this->addTransactionBtn->Size = System::Drawing::Size(101, 42);
			this->addTransactionBtn->TabIndex = 19;
			this->addTransactionBtn->Text = L"Dodaj";
			this->addTransactionBtn->UseVisualStyleBackColor = true;
			// 
			// listOfTransactions
			// 
			this->listOfTransactions->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->transactionIdCol,
					this->transactionDateCol, this->transactionUserCol, this->transactionOffersListCol
			});
			this->listOfTransactions->HideSelection = false;
			this->listOfTransactions->Location = System::Drawing::Point(8, 52);
			this->listOfTransactions->Name = L"listOfTransactions";
			this->listOfTransactions->Size = System::Drawing::Size(1176, 593);
			this->listOfTransactions->TabIndex = 18;
			this->listOfTransactions->UseCompatibleStateImageBehavior = false;
			this->listOfTransactions->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listOfTransactions->CheckBoxes = true;
			this->listOfTransactions->FullRowSelect = true;
			this->listOfTransactions->ImeMode = System::Windows::Forms::ImeMode::NoControl;
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
			// findTransactionBtn
			// 
			this->findTransactionBtn->Location = System::Drawing::Point(649, 8);
			this->findTransactionBtn->Name = L"findTransactionBtn";
			this->findTransactionBtn->Size = System::Drawing::Size(77, 38);
			this->findTransactionBtn->TabIndex = 17;
			this->findTransactionBtn->Text = L"Szukaj";
			this->findTransactionBtn->UseVisualStyleBackColor = true;
			// 
			// findTransactionTxt
			// 
			this->findTransactionTxt->Location = System::Drawing::Point(732, 14);
			this->findTransactionTxt->Name = L"findTransactionTxt";
			this->findTransactionTxt->Size = System::Drawing::Size(452, 26);
			this->findTransactionTxt->TabIndex = 16;
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
			this->Text = L"AdminPanel";
			this->tabControl1->ResumeLayout(false);
			this->userTab->ResumeLayout(false);
			this->userTab->PerformLayout();
			this->companyTab->ResumeLayout(false);
			this->companyTab->PerformLayout();
			this->categoryTab->ResumeLayout(false);
			this->categoryTab->PerformLayout();
			this->productTab->ResumeLayout(false);
			this->productTab->PerformLayout();
			this->offerTab->ResumeLayout(false);
			this->offerTab->PerformLayout();
			this->transactionTab->ResumeLayout(false);
			this->transactionTab->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
			this->setItems(this->admin->getAllUser(), this->admin->getAllCompany(), this->admin->getAllCategory(),
					this->admin->getAllProduct(), this->admin->getAllOffer(), this->admin->getAllTransaction());
		}

		public: void setAdmin(User user);

#pragma endregion
	};
}
