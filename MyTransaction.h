#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyTransaction
	/// </summary>
	public ref class MyTransaction : public System::Windows::Forms::Form
	{
	public:
		MyTransaction(void)
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
		~MyTransaction()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ dataCol;
	private: System::Windows::Forms::ColumnHeader^ offersCol;
	private: System::Windows::Forms::ColumnHeader^ IdCol;

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->IdCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->dataCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->offersCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			//
			// IdCol
			// 
			this->IdCol->Tag = L"0";
			this->IdCol->Text = L"Id";
			this->IdCol->Width = 50;
			// 
			// dataCol
			// 
			this->dataCol->Tag = L"1";
			this->dataCol->Text = L"Data";
			this->dataCol->Width = 80;
			// 
			// offersCol
			// 
			this->offersCol->Tag = L"2";
			this->offersCol->Text = L"Oferty";
			this->offersCol->Width = 300;
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->FullRowSelect = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(669, 454);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->IdCol, 
					this->dataCol, this->offersCol
			});
			// 
			// MyTransaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(693, 478);
			this->Controls->Add(this->listView1);
			this->Name = L"MyTransaction";
			this->Text = L"Moje transakcje";
			this->ResumeLayout(false);
		}

	public:
		void setTransactions(std::vector<Transaction> transactions);
#pragma endregion
	};
}
