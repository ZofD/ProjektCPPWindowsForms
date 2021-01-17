#pragma once

namespace ProjektCPPWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AddCategory
	/// </summary>
	public ref class AddCategory : public System::Windows::Forms::Form
	{
	public:
		AddCategory(void)
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
		~AddCategory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ deleteCategoryBtn;
	private: System::Windows::Forms::Button^ quitBtn;
	private: System::Windows::Forms::Button^ editCategoryBtn;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::TextBox^ nameTxt;

	private:
		Admin* admin;
		ListViewItem^ category;
		bool option;
		bool deleteOption = true;

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
			this->deleteCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->quitBtn = (gcnew System::Windows::Forms::Button());
			this->editCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTxt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// deleteCategoryBtn
			// 
			this->deleteCategoryBtn->Location = System::Drawing::Point(79, 284);
			this->deleteCategoryBtn->Name = L"deleteCategoryBtn";
			this->deleteCategoryBtn->Size = System::Drawing::Size(128, 44);
			this->deleteCategoryBtn->TabIndex = 20;
			this->deleteCategoryBtn->Text = L"Usuñ";
			this->deleteCategoryBtn->UseVisualStyleBackColor = true;
			this->deleteCategoryBtn->Click += gcnew System::EventHandler(this, &AddCategory::deleteCategoryBtn_Click);
			// 
			// quitBtn
			// 
			this->quitBtn->Location = System::Drawing::Point(397, 284);
			this->quitBtn->Name = L"quitBtn";
			this->quitBtn->Size = System::Drawing::Size(128, 44);
			this->quitBtn->TabIndex = 19;
			this->quitBtn->Text = L"Anuluj";
			this->quitBtn->UseVisualStyleBackColor = true;
			this->quitBtn->Click += gcnew System::EventHandler(this, &AddCategory::quitBtn_Click);
			// 
			// editCategoryBtn
			// 
			this->editCategoryBtn->Location = System::Drawing::Point(238, 284);
			this->editCategoryBtn->Name = L"editCategoryBtn";
			this->editCategoryBtn->Size = System::Drawing::Size(128, 44);
			this->editCategoryBtn->TabIndex = 18;
			this->editCategoryBtn->Text = L"ZatwierdŸ";
			this->editCategoryBtn->UseVisualStyleBackColor = true;
			this->editCategoryBtn->Click += gcnew System::EventHandler(this, &AddCategory::editCategoryBtn_Click);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(75, 76);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(57, 20);
			this->nameLabel->TabIndex = 17;
			this->nameLabel->Text = L"Nazwa";
			// 
			// nameTxt
			// 
			this->nameTxt->Location = System::Drawing::Point(201, 73);
			this->nameTxt->Name = L"nameTxt";
			this->nameTxt->Size = System::Drawing::Size(324, 26);
			this->nameTxt->TabIndex = 16;
			// 
			// AddCategory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 400);
			this->Controls->Add(this->deleteCategoryBtn);
			this->Controls->Add(this->quitBtn);
			this->Controls->Add(this->editCategoryBtn);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->nameTxt);
			this->Name = L"AddCategory";
			this->Text = L"Kategoria";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		public:
			void setAdmin(Admin* admin);
			void setCategory(ListViewItem^ category);
			void setOption(bool option);
			void setDeleteOption(bool option);
#pragma endregion
	private: System::Void deleteCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!this->option && this->deleteOption) {
			Category category = Category(System::Int32::Parse(this->category->SubItems[0]->Text), "");
			if (this->admin->deleteCategory(category))
				this->Close();
		}
		MessageBox::Show("Nie masz uprawnieñ lub nie mo¿na usun¹æ tego rekordu");
	}
	private: System::Void editCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->nameTxt->Text != "")
			if (this->option) {
				Category category = Category(msclr::interop::marshal_as<std::string>(this->nameTxt->Text));
				this->admin->addCategory(category);
				this->Close();
			}
			else {
				Category category = Category(
					System::Int32::Parse(this->category->SubItems[0]->Text), msclr::interop::marshal_as<std::string>(this->nameTxt->Text)
				);
				this->admin->updateCategory(category);
				this->Close();
			}
	}
	private: System::Void quitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
