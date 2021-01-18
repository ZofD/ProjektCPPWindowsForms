#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddOffer
	/// </summary>
	public ref class AddOffer : public System::Windows::Forms::Form
	{
	public:
		AddOffer(void)
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
		~AddOffer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ deleteOfferBtn;
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::Button^ editOfferBtn;
	private: System::Windows::Forms::Label^ priceLabel;
	private: System::Windows::Forms::NumericUpDown^ zlTxt;
	private: System::Windows::Forms::MonthCalendar^ dateStart;
	private: System::Windows::Forms::MonthCalendar^ dateStop;
	private: System::Windows::Forms::Label^ userIdLabel;
	private: System::Windows::Forms::ComboBox^ productBox;
	private: System::Windows::Forms::Label^ dateStartLabel;
	private: System::Windows::Forms::Label^ dateStopLabel;
	private: System::Windows::Forms::NumericUpDown^ grTxt;
	private: System::Windows::Forms::Label^ label1;

	private:
		Admin* admin;
		ListViewItem^ offer;
		bool option;
		bool deleteOption = true;
		String^ start = DateTime().Today.ToString("yyyy-MM-dd");
		String^ stop = DateTime().Today.ToString("yyyy-MM-dd");

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
			this->deleteOfferBtn = (gcnew System::Windows::Forms::Button());
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			this->editOfferBtn = (gcnew System::Windows::Forms::Button());
			this->priceLabel = (gcnew System::Windows::Forms::Label());
			this->zlTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->dateStart = (gcnew System::Windows::Forms::MonthCalendar());
			this->dateStop = (gcnew System::Windows::Forms::MonthCalendar());
			this->userIdLabel = (gcnew System::Windows::Forms::Label());
			this->productBox = (gcnew System::Windows::Forms::ComboBox());
			this->dateStartLabel = (gcnew System::Windows::Forms::Label());
			this->dateStopLabel = (gcnew System::Windows::Forms::Label());
			this->grTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grTxt))->BeginInit();
			this->SuspendLayout();
			// 
			// deleteOfferBtn
			// 
			this->deleteOfferBtn->Location = System::Drawing::Point(225, 427);
			this->deleteOfferBtn->Name = L"deleteOfferBtn";
			this->deleteOfferBtn->Size = System::Drawing::Size(128, 44);
			this->deleteOfferBtn->TabIndex = 25;
			this->deleteOfferBtn->Text = L"Usuñ";
			this->deleteOfferBtn->UseVisualStyleBackColor = true;
			this->deleteOfferBtn->Click += gcnew System::EventHandler(this, &AddOffer::deleteOfferBtn_Click);
			// 
			// quitBtn
			// 
			this->quitBtn->Location = System::Drawing::Point(543, 427);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(128, 44);
			this->quitBtn->TabIndex = 24;
			this->quitBtn->Text = L"Anuluj";
			this->quitBtn->UseVisualStyleBackColor = true;
			this->quitBtn->Click += gcnew System::EventHandler(this, &AddOffer::quitBtn_Click);
			// 
			// editOfferBtn
			// 
			this->editOfferBtn->Location = System::Drawing::Point(384, 427);
			this->editOfferBtn->Name = L"editOfferBtn";
			this->editOfferBtn->Size = System::Drawing::Size(128, 44);
			this->editOfferBtn->TabIndex = 23;
			this->editOfferBtn->Text = L"ZatwierdŸ";
			this->editOfferBtn->UseVisualStyleBackColor = true;
			this->editOfferBtn->Click += gcnew System::EventHandler(this, &AddOffer::editOfferBtn_Click);
			// 
			// priceLabel
			// 
			this->priceLabel->AutoSize = true;
			this->priceLabel->Location = System::Drawing::Point(75, 76);
			this->priceLabel->Name = L"priceLabel";
			this->priceLabel->Size = System::Drawing::Size(68, 20);
			this->priceLabel->TabIndex = 22;
			this->priceLabel->Text = L"Z³otówki";
			// 
			// zlTxt
			// 
			this->zlTxt->Location = System::Drawing::Point(149, 73);
			this->zlTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->zlTxt->Name = L"zlTxt";
			this->zlTxt->Size = System::Drawing::Size(139, 26);
			this->zlTxt->TabIndex = 21;
			this->zlTxt->ThousandsSeparator = true;
			// 
			// dateStart
			// 
			this->dateStart->Location = System::Drawing::Point(61, 149);
			this->dateStart->MaxSelectionCount = 1;
			this->dateStart->Name = L"dateStart";
			this->dateStart->TabIndex = 26;
			this->dateStart->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &AddOffer::dateStart_DateChanged);
			// 
			// dateStop
			// 
			this->dateStop->Location = System::Drawing::Point(465, 149);
			this->dateStop->MaxSelectionCount = 1;
			this->dateStop->Name = L"dateStop";
			this->dateStop->TabIndex = 27;
			this->dateStop->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &AddOffer::dateStop_DateChanged);
			// 
			// userIdLabel
			// 
			this->userIdLabel->AutoSize = true;
			this->userIdLabel->Location = System::Drawing::Point(479, 76);
			this->userIdLabel->Name = L"userIdLabel";
			this->userIdLabel->Size = System::Drawing::Size(64, 20);
			this->userIdLabel->TabIndex = 29;
			this->userIdLabel->Text = L"Produkt";
			// 
			// productBox
			// 
			this->productBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->productBox->FormattingEnabled = true;
			this->productBox->Location = System::Drawing::Point(605, 73);
			this->productBox->Name = L"productBox";
			this->productBox->Size = System::Drawing::Size(235, 28);
			this->productBox->TabIndex = 27;
			// 
			// dateStartLabel
			// 
			this->dateStartLabel->AutoSize = true;
			this->dateStartLabel->Location = System::Drawing::Point(57, 120);
			this->dateStartLabel->Name = L"dateStartLabel";
			this->dateStartLabel->Size = System::Drawing::Size(133, 20);
			this->dateStartLabel->TabIndex = 30;
			this->dateStartLabel->Text = L"Data rozpoczêcia";
			// 
			// dateStopLabel
			// 
			this->dateStopLabel->AutoSize = true;
			this->dateStopLabel->Location = System::Drawing::Point(461, 120);
			this->dateStopLabel->Name = L"dateStopLabel";
			this->dateStopLabel->Size = System::Drawing::Size(137, 20);
			this->dateStopLabel->TabIndex = 31;
			this->dateStopLabel->Text = L"Data zakoñczenia";
			// 
			// grTxt
			// 
			this->grTxt->Location = System::Drawing::Point(361, 73);
			this->grTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99, 0, 0, 0 });
			this->grTxt->Name = L"grTxt";
			this->grTxt->Size = System::Drawing::Size(75, 26);
			this->grTxt->TabIndex = 32;
			this->grTxt->ThousandsSeparator = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(294, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 20);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Grosze";
			// 
			// AddOffer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(893, 503);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->grTxt);
			this->Controls->Add(this->dateStopLabel);
			this->Controls->Add(this->dateStartLabel);
			this->Controls->Add(this->userIdLabel);
			this->Controls->Add(this->dateStop);
			this->Controls->Add(this->dateStart);
			this->Controls->Add(this->deleteOfferBtn);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->editOfferBtn);
			this->Controls->Add(this->priceLabel);
			this->Controls->Add(this->zlTxt);
			this->Controls->Add(this->productBox);
			this->Name = L"AddOffer";
			this->Text = L"Oferta";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grTxt))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
			this->setProducts(this->admin->getAllProduct());

		}

		public:
			void setAdmin(Admin* admin);
			void setOffer(ListViewItem^ offer);
			void setOption(bool option);
			void setDeleteOption(bool option);
		private:
			void setProducts(std::vector<Product> product);
			//this->setProducts(this->admin->getAllProduct());
#pragma endregion
	private: System::Void deleteOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!this->option && this->deleteOption) {
			Offer offer = Offer(System::Int32::Parse(this->offer->SubItems[0]->Text), 0);
			if (this->admin->deleteOffer(offer))
				this->Close();
		}
		MessageBox::Show("Nie masz uprawnieñ lub nie mo¿na usun¹æ tego rekordu");
	}
	private: System::Void editOfferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->zlTxt->Value > 0 && this->productBox->SelectedIndex >= 0) {
			System::Double price = System::Decimal::ToDouble(this->zlTxt->Value) + (System::Decimal::ToDouble(this->grTxt->Value) / 100);
			if (this->option) {
				Product product = Product(System::Int32::Parse(this->productBox->Text->Split(' ')[0]), "");
				time_t start = Helper::stringToTime_t(msclr::interop::marshal_as<std::string>(this->start->ToString()));
				time_t stop = Helper::stringToTime_t(msclr::interop::marshal_as<std::string>(this->stop->ToString()));
				Offer offer = Offer(1, price, start, stop, product);
				this->admin->addOffer(offer);
				this->Close();
			}
			else {
				Product product = Product(System::Int32::Parse(this->productBox->Text->Split(' ')[0]), "");
				time_t start = Helper::stringToTime_t(msclr::interop::marshal_as<std::string>(this->start->ToString()));
				time_t stop = Helper::stringToTime_t(msclr::interop::marshal_as<std::string>(this->stop->ToString()));
				Offer offer = Offer(System::Int32::Parse(this->offer->SubItems[0]->Text),
					price, start, stop, product);
				this->admin->updateOffer(offer);
				this->Close();
			}
		}
	}
	private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void dateStart_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		this->start = (e->Start.GetDateTimeFormats()[21]->Split(' ')[0]);
	}
	private: System::Void dateStop_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		this->stop = (e->Start.GetDateTimeFormats()[21]->Split(' ')[0]);
	}
};
}
