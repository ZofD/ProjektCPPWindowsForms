#pragma once
#include <vector>

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
	private: System::Windows::Forms::TextBox^ szukaj;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ColumnHeader^ Nazwa;
	private: System::Windows::Forms::ColumnHeader^ Ilosc;
	private: System::Windows::Forms::ColumnHeader^ Cena;
	private: System::Windows::Forms::ColumnHeader^ Kategoria;
	private: System::Windows::Forms::Button^ Kup;

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

		//void setItems(lista) {
		//	for (int x : arr)
		//		System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
		//	L x-> tytul,
		//		L x->ilosc, L x->cena, L x->kategoria"
		//	}, -1));
		//	}
		//
		//}

		void InitializeComponent(void)
		{
			//setItems(listarekordow);

			System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
				L"Lipa",
					L"1", L"150", L"Drzewo"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
				L"Lipa",
					L"1", L"150", L"Drzewo"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
				L"Lol",
					L"oo", L"free", L"Gra"
			}, -1));
			this->user = (gcnew System::Windows::Forms::Label());
			this->szukaj = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Nazwa = (gcnew System::Windows::Forms::ColumnHeader());
			this->Ilosc = (gcnew System::Windows::Forms::ColumnHeader());
			this->Cena = (gcnew System::Windows::Forms::ColumnHeader());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Kategoria = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kup = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Location = System::Drawing::Point(49, 27);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(145, 20);
			this->user->TabIndex = 0;
			this->user->Text = L"nazwa uzytkownika";
			// 
			// szukaj
			// 
			this->szukaj->Location = System::Drawing::Point(584, 24);
			this->szukaj->Name = L"szukaj";
			this->szukaj->Size = System::Drawing::Size(452, 26);
			this->szukaj->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(868, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 20);
			this->label1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(501, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Szukaj";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Nazwa, this->Ilosc,
					this->Cena, this->Kategoria
			});
			this->listView1->HideSelection = false;
			listViewItem1->Tag = L"0";
			listViewItem2->IndentCount = 5;
			listViewItem2->Tag = L"1";
			listViewItem2->ToolTipText = L"text";
			listViewItem2->UseItemStyleForSubItems = false;
			listViewItem3->IndentCount = 3;
			listViewItem3->Tag = L"2";
			listViewItem3->ToolTipText = L"fs";
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(3) {
				listViewItem1, listViewItem2,
					listViewItem3
			});
			this->listView1->Location = System::Drawing::Point(12, 69);
			this->listView1->MultiSelect = false;
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
			// Ilosc
			// 
			this->Ilosc->Tag = L"1";
			this->Ilosc->Text = L"Iloœæ";
			// 
			// Cena
			// 
			this->Cena->Tag = L"2";
			this->Cena->Text = L"Cena";
			this->Cena->Width = 100;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1062, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 50);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Wyloguj";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// Kategoria
			// 
			this->Kategoria->Text = L"Kategoria";
			this->Kategoria->Width = 150;
			// 
			// Kup
			// 
			this->Kup->Location = System::Drawing::Point(12, 750);
			this->Kup->Name = L"Kup";
			this->Kup->Size = System::Drawing::Size(147, 38);
			this->Kup->TabIndex = 11;
			this->Kup->Text = L"Kup";
			this->Kup->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->Kup);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->szukaj);
			this->Controls->Add(this->user);
			this->Name = L"MyForm";
			this->Text = L"Panel klienta";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	};
}
