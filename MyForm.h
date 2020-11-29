#pragma once

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
		/// Wyczy�� wszystkie u�ywane zasoby.
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
	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->user = (gcnew System::Windows::Forms::Label());
			this->szukaj = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 69);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1176, 719);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;

			this->listView1->Columns->Add("Title", -2, HorizontalAlignment::Center);
			this->listView1->Columns->Add("Title", -2, HorizontalAlignment::Left);
			this->listView1->Columns->Add("Price", -2, HorizontalAlignment::Left);

			// Add items
			ListViewItem item1("Steve Martin");
			item1.SubItems->Add("Programming .NET");
			item1.SubItems->Add("39.95");

			ListViewItem item2("Irene Suzuki");
			item2.SubItems->Add("VB.NET Core Studies");
			item2.SubItems->Add("69.95");

			ListViewItem item3("Ricky Ericsson");
			item3.SubItems->Add("Passing Your .NET Exams");
			item3.SubItems->Add("19.95");

			// Add the items to the ListView.
			//listView1.Items.AddRange(new ListViewItem[]{ item1,item2,item3 });
			//this->listView1->Items->Add("bls", "df");
			//this->listView1->Items->AddRange();
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 800);
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
