#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddTransaction
	/// </summary>
	public ref class AddTransaction : public System::Windows::Forms::Form
	{
	public:
		AddTransaction(void)
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
		~AddTransaction()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::Label^ userIdLabel;
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::Button^ editOfferBtn;
	private: System::Windows::Forms::ComboBox^ userBox;
	private: System::Windows::Forms::MonthCalendar^ date;
	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::ListBox^ listOfUserOffer;
	private: System::Windows::Forms::ListBox^ listOfOffer;

	private:
		Admin* admin;
		ListViewItem^ transaction;
		bool option;
		String^ dateStr = DateTime().Today.ToString("yyyy-MM-dd");

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
			this->userIdLabel = (gcnew System::Windows::Forms::Label());
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			this->editOfferBtn = (gcnew System::Windows::Forms::Button());
			this->userBox = (gcnew System::Windows::Forms::ComboBox());
			this->date = (gcnew System::Windows::Forms::MonthCalendar());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->listOfUserOffer = (gcnew System::Windows::Forms::ListBox());
			this->listOfOffer = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// userIdLabel
			// 
			this->userIdLabel->AutoSize = true;
			this->userIdLabel->Location = System::Drawing::Point(477, 55);
			this->userIdLabel->Name = L"userIdLabel";
			this->userIdLabel->Size = System::Drawing::Size(116, 20);
			this->userIdLabel->TabIndex = 40;
			this->userIdLabel->Text = L"ID u¿ytkownika";
			// 
			// quitBtn
			// 
			this->quitBtn->Location = System::Drawing::Point(541, 406);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(128, 44);
			this->quitBtn->TabIndex = 35;
			this->quitBtn->Text = L"Anuluj";
			this->quitBtn->UseVisualStyleBackColor = true;
			this->quitBtn->Click += gcnew System::EventHandler(this, &AddTransaction::quitBtn_Click);
			// 
			// editOfferBtn
			// 
			this->editOfferBtn->Location = System::Drawing::Point(382, 406);
			this->editOfferBtn->Name = L"editOfferBtn";
			this->editOfferBtn->Size = System::Drawing::Size(128, 44);
			this->editOfferBtn->TabIndex = 34;
			this->editOfferBtn->Text = L"ZatwierdŸ";
			this->editOfferBtn->UseVisualStyleBackColor = true;
			this->editOfferBtn->Click += gcnew System::EventHandler(this, &AddTransaction::editOfferBtn_Click);
			// 
			// userBox
			// 
			this->userBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->userBox->FormattingEnabled = true;
			this->userBox->Location = System::Drawing::Point(603, 52);
			this->userBox->Name = L"userBox";
			this->userBox->Size = System::Drawing::Size(235, 28);
			this->userBox->TabIndex = 39;
			// 
			// date
			// 
			this->date->Location = System::Drawing::Point(59, 84);
			this->date->MaxSelectionCount = 1;
			this->date->Name = L"date";
			this->date->TabIndex = 37;
			this->date->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &AddTransaction::date_DateChanged);
			// 
			// dataLabel
			// 
			this->dataLabel->AutoSize = true;
			this->dataLabel->Location = System::Drawing::Point(55, 55);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(44, 20);
			this->dataLabel->TabIndex = 41;
			this->dataLabel->Text = L"Data";
			// 
			// listOfUserOffer
			// 
			this->listOfUserOffer->AllowDrop = true;
			this->listOfUserOffer->FormattingEnabled = true;
			this->listOfUserOffer->ItemHeight = 20;
			this->listOfUserOffer->Location = System::Drawing::Point(667, 150);
			this->listOfUserOffer->Name = L"listOfUserOffer";
			this->listOfUserOffer->Size = System::Drawing::Size(171, 184);
			this->listOfUserOffer->TabIndex = 43;
			this->listOfUserOffer->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &AddTransaction::listOfUserOffer_DragDrop);
			this->listOfUserOffer->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &AddTransaction::listOfUserOffer_DragEnter);
			this->listOfUserOffer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddTransaction::listOfUserOffer_MouseDown);
			// 
			// listOfOffer
			// 
			this->listOfOffer->FormattingEnabled = true;
			this->listOfOffer->ItemHeight = 20;
			this->listOfOffer->Location = System::Drawing::Point(481, 150);
			this->listOfOffer->Name = L"listOfOffer";
			this->listOfOffer->Size = System::Drawing::Size(171, 184);
			this->listOfOffer->TabIndex = 44;
			this->listOfOffer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddTransaction::listOfOffer_MouseDown);
			// 
			// AddTransaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(893, 503);
			this->Controls->Add(this->listOfOffer);
			this->Controls->Add(this->listOfUserOffer);
			this->Controls->Add(this->dataLabel);
			this->Controls->Add(this->userIdLabel);
			this->Controls->Add(this->date);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->editOfferBtn);
			this->Controls->Add(this->userBox);
			this->Name = L"AddTransaction";
			this->Text = L"AddTransaction";
			this->ResumeLayout(false);
			this->PerformLayout();
			this->setUsers(this->admin->getAllUser());
			this->setOffers(this->admin->getAllOffer());

		}

		public:
			void setAdmin(Admin* admin);
			void setTransaction(ListViewItem^ transaction);
			void setOption(bool option);
		private:
			void setUsers(std::vector<User> users);
			void setOffers(std::vector<Offer> offers);
			//this->setUsers(this->admin->getAllUser());
			//this->setOffers(this->admin->getAllOffer());
#pragma endregion
	private: System::Void editOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->userBox->SelectedIndex >= 0)
			if (this->option) {
				std::vector<Offer> offers;
				ListBox::ObjectCollection^ CompanyItems = this->listOfUserOffer->Items;
				System::Collections::IEnumerator^ comapanyEnum = CompanyItems->GetEnumerator();
				while (comapanyEnum->MoveNext()) {
					Object^ item = safe_cast<Object^>(comapanyEnum->Current);
					offers.push_back(Offer(System::Int32::Parse(item->ToString()), 0));
				}
				User user = User(System::Int32::Parse(this->userBox->Text), "", "");
				time_t start = Helper::stringToTime_t(msclr::interop::marshal_as<std::string>(this->dateStr->ToString()));
				Transaction transaction = Transaction(1, start, user);
				transaction.setOfferList(offers);
				this->admin->addTransaction(transaction);
				this->Close();
			}
			else {
				std::vector<Offer> offers;
				ListBox::ObjectCollection^ CompanyItems = this->listOfUserOffer->Items;
				System::Collections::IEnumerator^ comapanyEnum = CompanyItems->GetEnumerator();
				while (comapanyEnum->MoveNext()) {
					Object^ item = safe_cast<Object^>(comapanyEnum->Current);
					offers.push_back(Offer(System::Int32::Parse(item->ToString()), 0));
				}
				User user = User(System::Int32::Parse(this->userBox->Text), "", "");
				time_t start = Helper::stringToTime_t(msclr::interop::marshal_as<std::string>(this->dateStr->ToString()));
				Transaction transaction = Transaction(System::Int32::Parse(this->transaction->SubItems[0]->Text), start, user);
				transaction.setOfferList(offers);
				this->admin->updateTransaction(transaction);
				this->Close();
			}
	}
	private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void date_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		this->dateStr = (e->Start.GetDateTimeFormats()[21]->Split(' ')[0]);
	}
	private: System::Void listOfOffer_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ListBox^ item = dynamic_cast<ListBox^>(sender);
		Point pt = Point(e->X, e->Y);
		int index = item->IndexFromPoint(pt);
		if (index >= 0 && e->Button == System::Windows::Forms::MouseButtons::Left)
			item->DoDragDrop(item->Items[index]->ToString(), DragDropEffects::Move);
	}
	private: System::Void listOfUserOffer_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		if (e->Data->GetDataPresent("Text"))
			e->Effect = DragDropEffects::Move;
	}
	private: System::Void listOfUserOffer_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		ListBox^ item2 = dynamic_cast<ListBox^>(sender);
		item2->Items->Add(dynamic_cast<String^>(e->Data->GetData("Text")));
	}
	private: System::Void listOfUserOffer_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ListBox^ item = dynamic_cast<ListBox^>(sender);
		Point pt = Point(e->X, e->Y);
		int index = item->IndexFromPoint(pt);
		if (index >= 0 && e->Button == System::Windows::Forms::MouseButtons::Right)
			this->listOfUserOffer->Items->RemoveAt(index);
	}
};
}
