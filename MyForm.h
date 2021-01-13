#ifndef PanelClient
#define PanelClient

#pragma once
#include "Koszyk.h"

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ user;
	private: System::Windows::Forms::TextBox^ szukajTxt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ szukajBtn;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Button^ wylogujBtn;
	private: System::Windows::Forms::ColumnHeader^ Nazwa;

	private: System::Windows::Forms::ColumnHeader^ Firma;
	private: System::Windows::Forms::ColumnHeader^ Cena;
	private: System::Windows::Forms::ColumnHeader^ Kategoria;
	private: System::Windows::Forms::Button^ DodajDoBtn;
	private: System::Windows::Forms::Button^ KoszykBtn;

		   Client* client;
		   System::Windows::Forms::ListView^ koszykArr;

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>

		void setItems(std::vector<Offer> lista) {
			this->listView1->BeginUpdate();
			for (Offer item : lista) {
				//MessageBox::Show(gcnew String(std::to_string(item.getPrice()).c_str()));
				String^ productName = gcnew String(item.getProduct().getName().c_str());
				String^ productCompany = gcnew String(item.getProduct().getCompany().getName().c_str());
				String^ productCategory = gcnew String(item.getProduct().getCategory().getName().c_str());
				String^ price = gcnew String(std::to_string(item.getPrice()).c_str());
				System::Windows::Forms::ListViewItem^ listviewitem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  > {
					productName,
						price, productCompany, productCategory
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
			this->user = (gcnew System::Windows::Forms::Label());
			this->szukajTxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->szukajBtn = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Nazwa = (gcnew System::Windows::Forms::ColumnHeader());
			this->Cena = (gcnew System::Windows::Forms::ColumnHeader());
			this->Firma = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kategoria = (gcnew System::Windows::Forms::ColumnHeader());
			this->wylogujBtn = (gcnew System::Windows::Forms::Button());
			this->DodajDoBtn = (gcnew System::Windows::Forms::Button());
			this->KoszykBtn = (gcnew System::Windows::Forms::Button());
			this->koszykArr = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Location = System::Drawing::Point(49, 27);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(145, 20);
			this->user->TabIndex = 0;
			this->user->Text = "u¿ytkownik";
			// 
			// szukajTxt
			// 
			this->szukajTxt->Location = System::Drawing::Point(584, 24);
			this->szukajTxt->Name = L"szukajTxt";
			this->szukajTxt->Size = System::Drawing::Size(452, 26);
			this->szukajTxt->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(868, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 20);
			this->label1->TabIndex = 2;
			// 
			// szukajBtn
			// 
			this->szukajBtn->Location = System::Drawing::Point(501, 18);
			this->szukajBtn->Name = L"szukajBtn";
			this->szukajBtn->Size = System::Drawing::Size(77, 38);
			this->szukajBtn->TabIndex = 3;
			this->szukajBtn->Text = L"Szukaj";
			this->szukajBtn->UseVisualStyleBackColor = true;
			this->szukajBtn->Click += gcnew System::EventHandler(this, &MyForm::szukajBtn_Click);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listView1->CheckBoxes = true;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Nazwa, this->Cena,
					this->Firma, this->Kategoria
			});
			this->listView1->FullRowSelect = true;
			this->listView1->HideSelection = false;
			this->listView1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listView1->Location = System::Drawing::Point(12, 69);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1176, 675);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// Nazwa
			// 
			this->Nazwa->Tag = L"0";
			this->Nazwa->Text = L"Nazwa";
			this->Nazwa->Width = 200;
			// 
			// Cena
			// 
			this->Cena->Tag = L"2";
			this->Cena->Text = L"Cena";
			this->Cena->Width = 100;
			// 
			// Firma
			// 
			this->Firma->Tag = L"1";
			this->Firma->Text = L"Firma";
			// 
			// Kategoria
			// 
			this->Kategoria->Text = L"Kategoria";
			this->Kategoria->Width = 150;
			// 
			// wylogujBtn
			// 
			this->wylogujBtn->Location = System::Drawing::Point(1062, 12);
			this->wylogujBtn->Name = L"wylogujBtn";
			this->wylogujBtn->Size = System::Drawing::Size(126, 50);
			this->wylogujBtn->TabIndex = 5;
			this->wylogujBtn->Text = L"Wyloguj";
			this->wylogujBtn->UseVisualStyleBackColor = true;
			this->wylogujBtn->Click += gcnew System::EventHandler(this, &MyForm::wylogujBtn_Click);
			// 
			// DodajDoBtn
			// 
			this->DodajDoBtn->Location = System::Drawing::Point(12, 750);
			this->DodajDoBtn->Name = L"DodajDoBtn";
			this->DodajDoBtn->Size = System::Drawing::Size(147, 38);
			this->DodajDoBtn->TabIndex = 11;
			this->DodajDoBtn->Text = L"Dodaj do koszyka";
			this->DodajDoBtn->UseVisualStyleBackColor = true;
			this->DodajDoBtn->Click += gcnew System::EventHandler(this, &MyForm::DodajDoBtn_Click);
			// 
			// KoszykBtn
			// 
			this->KoszykBtn->Location = System::Drawing::Point(165, 750);
			this->KoszykBtn->Name = L"KoszykBtn";
			this->KoszykBtn->Size = System::Drawing::Size(147, 38);
			this->KoszykBtn->TabIndex = 12;
			this->KoszykBtn->Text = L"Koszyk";
			this->KoszykBtn->UseVisualStyleBackColor = true;
			this->KoszykBtn->Click += gcnew System::EventHandler(this, &MyForm::KoszykBtn_Click);
			// 
			// koszykArr
			// 
			this->koszykArr->HideSelection = false;
			this->koszykArr->Location = System::Drawing::Point(0, 0);
			this->koszykArr->Name = L"koszykArr";
			this->koszykArr->Size = System::Drawing::Size(121, 97);
			this->koszykArr->TabIndex = 0;
			this->koszykArr->UseCompatibleStateImageBehavior = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->KoszykBtn);
			this->Controls->Add(this->DodajDoBtn);
			this->Controls->Add(this->wylogujBtn);
			this->Controls->Add(this->szukajBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->szukajTxt);
			this->Controls->Add(this->user);
			setItems(client->getAllActiveOffer());
			this->Name = L"MyForm";
			this->Text = L"Panel klienta";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public: void setClient(User user);

#pragma endregion
	private: System::Void wylogujBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void KoszykBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProjektCPPWindowsForms::Koszyk koszyk;
		koszyk.setKoszykArr(this->koszykArr);
		koszyk.ShowDialog();
	}
	private: System::Void DodajDoBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listView1->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			this->koszykArr->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^ > {
				(ListViewItem^)item->Clone()
			});
		}
	}
	private: System::Void szukajBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*client->getAllActiveOfferByCategory(msclr::interop::marshal_as<std::string>(this->szukajTxt->Text));
		cli::array< System::Windows::Forms::ListViewItem^ >^ tab = this->koszykArr->Items->Find(this->szukajTxt->Text, true);
		this->listView1->Items->Clear();
		this->listView1->Items->AddRange(tab);*/
	}
};
}
#endif PanelClient