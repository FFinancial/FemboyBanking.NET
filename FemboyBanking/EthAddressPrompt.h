#pragma once
#include <stdio.h>
#include "Etherscan.h"
#include "Main.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FemboyBanking {

	/// <summary>
	/// Summary for EthAddressPrompt
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class EthAddressPrompt : public System::Windows::Forms::Form
	{
	public:
		EthAddressPrompt(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			InitializeBackgoundWorker();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EthAddressPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Button^  doneBtn;
		System::Windows::Forms::Button^  cancelBtn;
		System::Windows::Forms::TextBox^  ethTextBox;
		System::Windows::Forms::CheckBox^  privacyCheckBox;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::ComponentModel::BackgroundWorker^  etherscanWorker;
		System::Windows::Forms::ProgressBar^  progressBar;
	private: System::Windows::Forms::Label^  label3;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EthAddressPrompt::typeid));
			this->doneBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->ethTextBox = (gcnew System::Windows::Forms::TextBox());
			this->privacyCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->etherscanWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// doneBtn
			// 
			this->doneBtn->Location = System::Drawing::Point(235, 70);
			this->doneBtn->Name = L"doneBtn";
			this->doneBtn->Size = System::Drawing::Size(75, 23);
			this->doneBtn->TabIndex = 0;
			this->doneBtn->Text = L"Done";
			this->doneBtn->UseVisualStyleBackColor = true;
			this->doneBtn->Click += gcnew System::EventHandler(this, &EthAddressPrompt::doneBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->Location = System::Drawing::Point(154, 70);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(75, 23);
			this->cancelBtn->TabIndex = 1;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EthAddressPrompt::cancelBtn_Click);
			// 
			// ethTextBox
			// 
			this->ethTextBox->AllowDrop = true;
			this->ethTextBox->Location = System::Drawing::Point(12, 42);
			this->ethTextBox->MaxLength = 42;
			this->ethTextBox->Name = L"ethTextBox";
			this->ethTextBox->Size = System::Drawing::Size(298, 20);
			this->ethTextBox->TabIndex = 2;
			// 
			// privacyCheckBox
			// 
			this->privacyCheckBox->AutoSize = true;
			this->privacyCheckBox->Location = System::Drawing::Point(12, 74);
			this->privacyCheckBox->Name = L"privacyCheckBox";
			this->privacyCheckBox->Size = System::Drawing::Size(78, 17);
			this->privacyCheckBox->TabIndex = 3;
			this->privacyCheckBox->Text = L"Hard mode";
			this->privacyCheckBox->UseVisualStyleBackColor = true;
			this->privacyCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EthAddressPrompt::privacyCheckBox_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Enter your Ethereum address.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(9, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(207, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"NOTE: The only token we accept is LINK.";
			// 
			// etherscanWorker
			// 
			this->etherscanWorker->WorkerReportsProgress = true;
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(12, 112);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(298, 18);
			this->progressBar->TabIndex = 6;
			this->progressBar->UseWaitCursor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Connecting to the Femboy Network... Please wait.";
			// 
			// EthAddressPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(322, 103);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->privacyCheckBox);
			this->Controls->Add(this->ethTextBox);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->doneBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"EthAddressPrompt";
			this->Text = L"Connect Ethereum Wallet";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void InitializeBackgoundWorker()
		{
			this->etherscanWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler( this, &EthAddressPrompt::etherscanWorker_DoWork );
			this->etherscanWorker->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler( this, &EthAddressPrompt::etherscanWorker_RunWorkerCompleted );
			this->etherscanWorker->ProgressChanged += gcnew ProgressChangedEventHandler( this, &EthAddressPrompt::etherscanWorker_ProgressChanged );
		}

		System::Void privacyCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			this->ethTextBox->UseSystemPasswordChar = this->privacyCheckBox->Checked;
		}
		System::Void cancelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}
		System::Void doneBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			this->ethTextBox->Enabled = false;
			this->Height += 50;
			etherscanWorker->RunWorkerAsync( this->ethTextBox->Text );
		}
		System::Void etherscanWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Get the BackgroundWorker that raised this event.
			BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

			// Assign the result of the computation
			// to the Result property of the DoWorkEventArgs
			// object. This is will be available to the 
			// RunWorkerCompleted eventhandler.
			e->Result = Etherscan::FetchLinkBalance( e->Argument->ToString(), worker, e );
		}
		System::Void etherscanWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			if ((UInt64) e->Result != -1)
			{
				Double balance = (UInt64) e->Result / 1e18;
				String^ balanceMsg = String::Format("You have {0} LINK", balance);

				Main^ form = gcnew Main(this->ethTextBox->Text, balance);
				this->Owner = form;
				this->Owner->Show();
				this->Hide();
			}
			this->ethTextBox->Enabled = true;
			this->Height -= 50;
		}
		System::Void etherscanWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			this->progressBar->Value = e->ProgressPercentage;
		}
	};
}
