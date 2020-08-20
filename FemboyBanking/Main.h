#pragma once


namespace FemboyBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  balLbl;
	private: System::Windows::Forms::Button^  depBtn;
	private: System::Windows::Forms::Button^  withBtn;
	private: System::Windows::Forms::Button^  logBtn;




	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->balLbl = (gcnew System::Windows::Forms::Label());
			this->depBtn = (gcnew System::Windows::Forms::Button());
			this->withBtn = (gcnew System::Windows::Forms::Button());
			this->logBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(220, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to FemboyFinancial Bank Corp. NA";
			// 
			// balLbl
			// 
			this->balLbl->AutoSize = true;
			this->balLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->balLbl->Location = System::Drawing::Point(36, 40);
			this->balLbl->Name = L"balLbl";
			this->balLbl->Size = System::Drawing::Size(110, 13);
			this->balLbl->TabIndex = 1;
			this->balLbl->Text = L"BALANCE: 0 LINK";
			// 
			// depBtn
			// 
			this->depBtn->Location = System::Drawing::Point(88, 91);
			this->depBtn->Name = L"depBtn";
			this->depBtn->Size = System::Drawing::Size(117, 23);
			this->depBtn->TabIndex = 2;
			this->depBtn->Text = L"Deposit";
			this->depBtn->UseVisualStyleBackColor = true;
			this->depBtn->Click += gcnew System::EventHandler(this, &Main::depBtn_Click);
			// 
			// withBtn
			// 
			this->withBtn->Location = System::Drawing::Point(88, 139);
			this->withBtn->Name = L"withBtn";
			this->withBtn->Size = System::Drawing::Size(117, 23);
			this->withBtn->TabIndex = 3;
			this->withBtn->Text = L"Withdraw";
			this->withBtn->UseVisualStyleBackColor = true;
			this->withBtn->Click += gcnew System::EventHandler(this, &Main::withBtn_Click);
			// 
			// logBtn
			// 
			this->logBtn->Location = System::Drawing::Point(88, 187);
			this->logBtn->Name = L"logBtn";
			this->logBtn->Size = System::Drawing::Size(117, 23);
			this->logBtn->TabIndex = 4;
			this->logBtn->Text = L"Transaction Log";
			this->logBtn->UseVisualStyleBackColor = true;
			this->logBtn->Click += gcnew System::EventHandler(this, &Main::logBtn_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->logBtn);
			this->Controls->Add(this->withBtn);
			this->Controls->Add(this->depBtn);
			this->Controls->Add(this->balLbl);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->Text = L"FemboyBanking";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void depBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 MessageBox::Show( this, "You selected DEPOSIT", "FemboyBanking Alert", MessageBoxButtons::OK, MessageBoxIcon::Information );
			 }
private: System::Void withBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 MessageBox::Show( this, "You selected WITHDRAW", "FemboyBanking Alert", MessageBoxButtons::OK, MessageBoxIcon::Information );
			 }
private: System::Void logBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 MessageBox::Show( this, "You selected TRANSACTION LOG", "FemboyBanking Alert", MessageBoxButtons::OK, MessageBoxIcon::Information );
			 }
};
}
