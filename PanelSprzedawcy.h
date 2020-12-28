#pragma once

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ szukaj;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ Nazwa;
	private: System::Windows::Forms::ColumnHeader^ Ilosc;
	private: System::Windows::Forms::ColumnHeader^ Cena;
	private: System::Windows::Forms::ColumnHeader^ Kategoria;
	private: System::Windows::Forms::Button^ dodaj;
	private: System::Windows::Forms::Button^ Edytuj;
	private: System::Windows::Forms::Button^ Usun;



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
			System::Windows::Forms::ListViewItem^ listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
				L"Zupa",
					L"5", L"50", L"Jedzenie"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
				L"Lipa",
					L"1", L"150", L"Drzewo"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem6 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(4) {
				L"Lol",
					L"oo", L"free", L"Gra"
			}, -1));
			this->user = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->szukaj = (gcnew System::Windows::Forms::TextBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Nazwa = (gcnew System::Windows::Forms::ColumnHeader());
			this->Ilosc = (gcnew System::Windows::Forms::ColumnHeader());
			this->Cena = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kategoria = (gcnew System::Windows::Forms::ColumnHeader());
			this->dodaj = (gcnew System::Windows::Forms::Button());
			this->Edytuj = (gcnew System::Windows::Forms::Button());
			this->Usun = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Location = System::Drawing::Point(49, 27);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(145, 20);
			this->user->TabIndex = 1;
			this->user->Text = L"nazwa uzytkownika";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1062, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 50);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Wyloguj";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(501, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 38);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Szukaj";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// szukaj
			// 
			this->szukaj->Location = System::Drawing::Point(584, 24);
			this->szukaj->Name = L"szukaj";
			this->szukaj->Size = System::Drawing::Size(452, 26);
			this->szukaj->TabIndex = 6;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Nazwa, this->Ilosc,
					this->Cena, this->Kategoria
			});
			this->listView1->HideSelection = false;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(3) {
				listViewItem4, listViewItem5,
					listViewItem6
			});
			this->listView1->Location = System::Drawing::Point(12, 69);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1176, 675);
			this->listView1->TabIndex = 9;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// dodaj
			// 
			this->dodaj->Location = System::Drawing::Point(12, 750);
			this->dodaj->Name = L"dodaj";
			this->dodaj->Size = System::Drawing::Size(147, 38);
			this->dodaj->TabIndex = 10;
			this->dodaj->Text = L"Dodaj";
			this->dodaj->UseVisualStyleBackColor = true;
			// 
			// Edytuj
			// 
			this->Edytuj->Location = System::Drawing::Point(165, 750);
			this->Edytuj->Name = L"Edytuj";
			this->Edytuj->Size = System::Drawing::Size(147, 38);
			this->Edytuj->TabIndex = 11;
			this->Edytuj->Text = L"Edytuj";
			this->Edytuj->UseVisualStyleBackColor = true;
			// 
			// Usun
			// 
			this->Usun->Location = System::Drawing::Point(318, 750);
			this->Usun->Name = L"Usun";
			this->Usun->Size = System::Drawing::Size(147, 38);
			this->Usun->TabIndex = 12;
			this->Usun->Text = L"Usuñ";
			this->Usun->UseVisualStyleBackColor = true;
			// 
			// PanelSprzedawcy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->Usun);
			this->Controls->Add(this->Edytuj);
			this->Controls->Add(this->dodaj);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->szukaj);
			this->Controls->Add(this->user);
			this->Name = L"PanelSprzedawcy";
			this->Text = L"PanelSprzedawcy";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
