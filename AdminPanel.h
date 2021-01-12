#ifndef PanelAdmin
#define PanelAdmin

#pragma once
#include "admin.h"

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

	private: System::Windows::Forms::TabControl^ Tabs;
	private: System::Windows::Forms::TabPage^ userTab;

	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ szukajUseraBtn;

	private: System::Windows::Forms::TextBox^ szukajUsera;

	private: System::Windows::Forms::Label^ user;
	private: System::Windows::Forms::TabPage^ companyTab;



	private: System::Windows::Forms::ListView^ listView2;
	private: System::Windows::Forms::Button^ szukajCompanyBtn;
	private: System::Windows::Forms::TextBox^ szukajCompany;



	private: System::Windows::Forms::TabPage^ categoryTab;


	private: System::Windows::Forms::ListView^ listView3;
	private: System::Windows::Forms::Button^ szukajCategryBtn;
	private: System::Windows::Forms::TextBox^ szukajCategory;



	private: System::Windows::Forms::TabPage^ productTab;

	private: System::Windows::Forms::ListView^ listView4;
	private: System::Windows::Forms::Button^ szukajProductBtn;
	private: System::Windows::Forms::TextBox^ szukajProductTxt;


	private: System::Windows::Forms::TabPage^ offerTab;

	private: System::Windows::Forms::ListView^ listView5;
	private: System::Windows::Forms::Button^ szukajOfferBtn;


	private: System::Windows::Forms::TextBox^ textBox4;

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
		 
		void setItems(std::vector<User> lista) {
			this->listView1->BeginUpdate();
			for (User item : lista) {
				//MessageBox::Show(gcnew String(std::to_string(item.getPrice()).c_str()));
				String^ userID = gcnew String(item.getId().ToString());
				String^ userLogin = gcnew String(item.getLogin().c_str());
				String^ userPermision = gcnew String(item.getPermission().ToString());
				System::Windows::Forms::ListViewItem^ listviewitem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					userID,
						userLogin, userPermision
				}, -1));
				this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  > {
					listviewitem1
				});
			}
			this->listView1->EndUpdate();
			this->Controls->Add(this->listView1);
		}
		 
		void InitializeComponent(void)
		{
			this->Tabs = (gcnew System::Windows::Forms::TabControl());
			this->userTab = (gcnew System::Windows::Forms::TabPage());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->szukajUseraBtn = (gcnew System::Windows::Forms::Button());
			this->szukajUsera = (gcnew System::Windows::Forms::TextBox());
			this->companyTab = (gcnew System::Windows::Forms::TabPage());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->szukajCompanyBtn = (gcnew System::Windows::Forms::Button());
			this->szukajCompany = (gcnew System::Windows::Forms::TextBox());
			this->categoryTab = (gcnew System::Windows::Forms::TabPage());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->szukajCategryBtn = (gcnew System::Windows::Forms::Button());
			this->szukajCategory = (gcnew System::Windows::Forms::TextBox());
			this->productTab = (gcnew System::Windows::Forms::TabPage());
			this->listView4 = (gcnew System::Windows::Forms::ListView());
			this->szukajProductBtn = (gcnew System::Windows::Forms::Button());
			this->szukajProductTxt = (gcnew System::Windows::Forms::TextBox());
			this->offerTab = (gcnew System::Windows::Forms::TabPage());
			this->listView5 = (gcnew System::Windows::Forms::ListView());
			this->szukajOfferBtn = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->user = (gcnew System::Windows::Forms::Label());
			this->Tabs->SuspendLayout();
			this->userTab->SuspendLayout();
			this->companyTab->SuspendLayout();
			this->categoryTab->SuspendLayout();
			this->productTab->SuspendLayout();
			this->offerTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// Tabs
			// 
			this->Tabs->Controls->Add(this->userTab);
			this->Tabs->Controls->Add(this->companyTab);
			this->Tabs->Controls->Add(this->categoryTab);
			this->Tabs->Controls->Add(this->productTab);
			this->Tabs->Controls->Add(this->offerTab);
			this->Tabs->Location = System::Drawing::Point(1, 68);
			this->Tabs->Name = L"Tabs";
			this->Tabs->SelectedIndex = 0;
			this->Tabs->Size = System::Drawing::Size(1198, 731);
			this->Tabs->TabIndex = 10;
			// 
			// userTab
			// 
			this->userTab->Controls->Add(this->listView1);
			this->userTab->Controls->Add(this->szukajUseraBtn);
			this->userTab->Controls->Add(this->szukajUsera);
			this->userTab->Location = System::Drawing::Point(4, 29);
			this->userTab->Name = L"userTab";
			this->userTab->Padding = System::Windows::Forms::Padding(3);
			this->userTab->Size = System::Drawing::Size(1190, 698);
			this->userTab->TabIndex = 0;
			this->userTab->Text = L"U¿ytkownicy";
			this->userTab->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(7, 74);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1176, 675);
			this->listView1->TabIndex = 14;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// szukajUseraBtn
			// 
			this->szukajUseraBtn->Location = System::Drawing::Point(648, 23);
			this->szukajUseraBtn->Name = L"szukajUseraBtn";
			this->szukajUseraBtn->Size = System::Drawing::Size(77, 38);
			this->szukajUseraBtn->TabIndex = 12;
			this->szukajUseraBtn->Text = L"Szukaj";
			this->szukajUseraBtn->UseVisualStyleBackColor = true;
			// 
			// szukajUsera
			// 
			this->szukajUsera->Location = System::Drawing::Point(731, 29);
			this->szukajUsera->Name = L"szukajUsera";
			this->szukajUsera->Size = System::Drawing::Size(452, 26);
			this->szukajUsera->TabIndex = 11;
			// 
			// companyTab
			// 
			this->companyTab->Controls->Add(this->listView2);
			this->companyTab->Controls->Add(this->szukajCompanyBtn);
			this->companyTab->Controls->Add(this->szukajCompany);
			this->companyTab->Location = System::Drawing::Point(4, 29);
			this->companyTab->Name = L"companyTab";
			this->companyTab->Padding = System::Windows::Forms::Padding(3);
			this->companyTab->Size = System::Drawing::Size(1190, 698);
			this->companyTab->TabIndex = 1;
			this->companyTab->Text = L"Firma";
			this->companyTab->UseVisualStyleBackColor = true;
			// 
			// listView2
			// 
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(7, 74);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(1176, 675);
			this->listView2->TabIndex = 14;
			this->listView2->UseCompatibleStateImageBehavior = false;
			// 
			// szukajCompanyBtn
			// 
			this->szukajCompanyBtn->Location = System::Drawing::Point(648, 23);
			this->szukajCompanyBtn->Name = L"szukajCompanyBtn";
			this->szukajCompanyBtn->Size = System::Drawing::Size(77, 38);
			this->szukajCompanyBtn->TabIndex = 12;
			this->szukajCompanyBtn->Text = L"Szukaj";
			this->szukajCompanyBtn->UseVisualStyleBackColor = true;
			// 
			// szukajCompany
			// 
			this->szukajCompany->Location = System::Drawing::Point(731, 29);
			this->szukajCompany->Name = L"szukajCompany";
			this->szukajCompany->Size = System::Drawing::Size(452, 26);
			this->szukajCompany->TabIndex = 11;
			// 
			// categoryTab
			// 
			this->categoryTab->Controls->Add(this->listView3);
			this->categoryTab->Controls->Add(this->szukajCategryBtn);
			this->categoryTab->Controls->Add(this->szukajCategory);
			this->categoryTab->Location = System::Drawing::Point(4, 29);
			this->categoryTab->Name = L"categoryTab";
			this->categoryTab->Padding = System::Windows::Forms::Padding(3);
			this->categoryTab->Size = System::Drawing::Size(1190, 698);
			this->categoryTab->TabIndex = 2;
			this->categoryTab->Text = L"Kategorie";
			this->categoryTab->UseVisualStyleBackColor = true;
			// 
			// listView3
			// 
			this->listView3->HideSelection = false;
			this->listView3->Location = System::Drawing::Point(7, 74);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(1176, 675);
			this->listView3->TabIndex = 14;
			this->listView3->UseCompatibleStateImageBehavior = false;
			// 
			// szukajCategryBtn
			// 
			this->szukajCategryBtn->Location = System::Drawing::Point(648, 23);
			this->szukajCategryBtn->Name = L"szukajCategryBtn";
			this->szukajCategryBtn->Size = System::Drawing::Size(77, 38);
			this->szukajCategryBtn->TabIndex = 12;
			this->szukajCategryBtn->Text = L"Szukaj";
			this->szukajCategryBtn->UseVisualStyleBackColor = true;
			// 
			// szukajCategory
			// 
			this->szukajCategory->Location = System::Drawing::Point(731, 29);
			this->szukajCategory->Name = L"szukajCategory";
			this->szukajCategory->Size = System::Drawing::Size(452, 26);
			this->szukajCategory->TabIndex = 11;
			// 
			// productTab
			// 
			this->productTab->Controls->Add(this->listView4);
			this->productTab->Controls->Add(this->szukajProductBtn);
			this->productTab->Controls->Add(this->szukajProductTxt);
			this->productTab->Location = System::Drawing::Point(4, 29);
			this->productTab->Name = L"productTab";
			this->productTab->Padding = System::Windows::Forms::Padding(3);
			this->productTab->Size = System::Drawing::Size(1190, 698);
			this->productTab->TabIndex = 3;
			this->productTab->Text = L"Produkty";
			this->productTab->UseVisualStyleBackColor = true;
			// 
			// listView4
			// 
			this->listView4->HideSelection = false;
			this->listView4->Location = System::Drawing::Point(7, 74);
			this->listView4->Name = L"listView4";
			this->listView4->Size = System::Drawing::Size(1176, 675);
			this->listView4->TabIndex = 14;
			this->listView4->UseCompatibleStateImageBehavior = false;
			// 
			// szukajProductBtn
			// 
			this->szukajProductBtn->Location = System::Drawing::Point(648, 23);
			this->szukajProductBtn->Name = L"szukajProductBtn";
			this->szukajProductBtn->Size = System::Drawing::Size(77, 38);
			this->szukajProductBtn->TabIndex = 12;
			this->szukajProductBtn->Text = L"Szukaj";
			this->szukajProductBtn->UseVisualStyleBackColor = true;
			// 
			// szukajProductTxt
			// 
			this->szukajProductTxt->Location = System::Drawing::Point(731, 29);
			this->szukajProductTxt->Name = L"szukajProductTxt";
			this->szukajProductTxt->Size = System::Drawing::Size(452, 26);
			this->szukajProductTxt->TabIndex = 11;
			// 
			// offerTab
			// 
			this->offerTab->Controls->Add(this->listView5);
			this->offerTab->Controls->Add(this->szukajOfferBtn);
			this->offerTab->Controls->Add(this->textBox4);
			this->offerTab->Location = System::Drawing::Point(4, 29);
			this->offerTab->Name = L"offerTab";
			this->offerTab->Padding = System::Windows::Forms::Padding(3);
			this->offerTab->Size = System::Drawing::Size(1190, 698);
			this->offerTab->TabIndex = 4;
			this->offerTab->Text = L"Oferty";
			this->offerTab->UseVisualStyleBackColor = true;
			// 
			// listView5
			// 
			this->listView5->HideSelection = false;
			this->listView5->Location = System::Drawing::Point(7, 74);
			this->listView5->Name = L"listView5";
			this->listView5->Size = System::Drawing::Size(1176, 675);
			this->listView5->TabIndex = 14;
			this->listView5->UseCompatibleStateImageBehavior = false;
			// 
			// szukajOfferBtn
			// 
			this->szukajOfferBtn->Location = System::Drawing::Point(648, 23);
			this->szukajOfferBtn->Name = L"szukajOfferBtn";
			this->szukajOfferBtn->Size = System::Drawing::Size(77, 38);
			this->szukajOfferBtn->TabIndex = 12;
			this->szukajOfferBtn->Text = L"Szukaj";
			this->szukajOfferBtn->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(731, 29);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(452, 26);
			this->textBox4->TabIndex = 11;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1062, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 50);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Wyloguj";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Location = System::Drawing::Point(12, 9);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(86, 20);
			this->user->TabIndex = 10;
			this->user->Text = L"u¿ytkownik";
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->Tabs);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->user);
			this->Name = L"AdminPanel";
			this->Text = L"Panel adminstratora";
			this->Tabs->ResumeLayout(false);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public: void setClient(User user);
#pragma endregion
	private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
#endif
