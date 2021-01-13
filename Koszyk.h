#ifndef PanelKoszyk
#define PanelKoszyk

#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Koszyk
	/// </summary>
	public ref class Koszyk : public System::Windows::Forms::Form
	{
	public:
		Koszyk(void)
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
		~Koszyk()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ szukajTxt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ szukajBtn;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ Nazwa;
	private: System::Windows::Forms::ColumnHeader^ Firma;
	private: System::Windows::Forms::ColumnHeader^ Cena;
	private: System::Windows::Forms::ColumnHeader^ Kategoria;
	private: System::Windows::Forms::Button^ UsuñBtn;
	private: System::Windows::Forms::Button^ KupBtn;

		   Client* client;


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
			this->szukajTxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->szukajBtn = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Nazwa = (gcnew System::Windows::Forms::ColumnHeader());
			this->Cena = (gcnew System::Windows::Forms::ColumnHeader());
			this->Firma = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kategoria = (gcnew System::Windows::Forms::ColumnHeader());
			this->UsuñBtn = (gcnew System::Windows::Forms::Button());
			this->KupBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
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
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Nazwa, this->Cena,
					this->Firma, this->Kategoria
			});
			this->listView1->FullRowSelect = true;
			this->listView1->HideSelection = false;
			this->listView1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
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
			// Cena
			// 
			this->Cena->Tag = L"2";
			this->Cena->Text = L"Cena";
			this->Cena->Width = 100;
			// 
			// Firma
			// 
			this->Firma->Tag = L"1";
			this->Firma->Text = L"Iloœæ";
			// 
			// Kategoria
			// 
			this->Kategoria->Text = L"Kategoria";
			this->Kategoria->Width = 150;
			// 
			// UsuñBtn
			// 
			this->UsuñBtn->Location = System::Drawing::Point(12, 750);
			this->UsuñBtn->Name = L"UsuñBtn";
			this->UsuñBtn->Size = System::Drawing::Size(147, 38);
			this->UsuñBtn->TabIndex = 11;
			this->UsuñBtn->Text = L"Usuñ";
			this->UsuñBtn->UseVisualStyleBackColor = true;
			this->UsuñBtn->Click += gcnew System::EventHandler(this, &Koszyk::UsuñBtn_Click);
			// 
			// KupBtn
			// 
			this->KupBtn->Location = System::Drawing::Point(165, 750);
			this->KupBtn->Name = L"KupBtn";
			this->KupBtn->Size = System::Drawing::Size(147, 38);
			this->KupBtn->TabIndex = 12;
			this->KupBtn->Text = L"Kup";
			this->KupBtn->UseVisualStyleBackColor = true;
			this->KupBtn->Click += gcnew System::EventHandler(this, &Koszyk::KupBtn_Click);
			// 
			// Koszyk
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->KupBtn);
			this->Controls->Add(this->UsuñBtn);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->szukajBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->szukajTxt);
			this->Name = L"Koszyk";
			this->Text = L"Koszyk";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	public: void setKoszykArr(ListView^ koszykArr);
	public: void setClient(Client* client);
#pragma endregion
	private: System::Void UsuñBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ListView::SelectedListViewItemCollection^ items = this->listView1->SelectedItems;
		System::Collections::IEnumerator^ myEnum = items->GetEnumerator();
		while (myEnum->MoveNext())
		{
			ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
			this->listView1->Items->RemoveAt(item->Index);
		}
	}
	private: System::Void KupBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
#endif PanelKoszyk