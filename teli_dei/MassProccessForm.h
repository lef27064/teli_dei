#pragma once

namespace teli_dei{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MassProccessForm
	/// </summary>
	public ref class MassProccessForm : public System::Windows::Forms::Form
	{
	public:
		MassProccessForm(int* Result)
		{
			
			this->Result =Result;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MassProccessForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckedListBox^  MassProccessListBox;

	private: System::Windows::Forms::Button^  okbutton;
	private: System::Windows::Forms::Button^  Cancelbutton;


	private: int* Result;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MassProccessListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->okbutton = (gcnew System::Windows::Forms::Button());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Τι θέλετε να κάνετε με τις εγγραφές\?";
			// 
			// MassProccessListBox
			// 
			this->MassProccessListBox->FormattingEnabled = true;
			this->MassProccessListBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Μηδένισμα του ΤΑΠ", L"Δημοτικά Τέλη = Δημοτικός Φόρος (επιλογή του μεγαλύτερου)", 
				L"Δημοτικά Τέλη = Δημοτικός Φόρος = ΤΑΠ (μεγαλύτερο)", L"Δημοτικά Τέλη = Δημοτικός Φόρος = ΤΑΠ = (Δημοτικά Τέλη + Δημοτικός Φόρος + ΤΑΠ)/3" 
				L"", 
				L"Δημοτικά Τέλη = Δημοτικός Φόρος = ΤΑΠ (Δημοτικά Τέλη)"});
			this->MassProccessListBox->Location = System::Drawing::Point(24, 86);
			this->MassProccessListBox->Name = L"MassProccessListBox";
			this->MassProccessListBox->Size = System::Drawing::Size(477, 109);
			this->MassProccessListBox->TabIndex = 3;
			// 
			// okbutton
			// 
			this->okbutton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->okbutton->Location = System::Drawing::Point(24, 249);
			this->okbutton->Name = L"okbutton";
			this->okbutton->Size = System::Drawing::Size(75, 42);
			this->okbutton->TabIndex = 4;
			this->okbutton->Text = L"Εντάξει";
			this->okbutton->UseVisualStyleBackColor = true;
			this->okbutton->Click += gcnew System::EventHandler(this, &MassProccessForm::okbutton_Click);
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(419, 249);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(82, 42);
			this->Cancelbutton->TabIndex = 5;
			this->Cancelbutton->Text = L"Ακυρο";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &MassProccessForm::Cancelbutton_Click);
			// 
			// MassProccessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 361);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->okbutton);
			this->Controls->Add(this->MassProccessListBox);
			this->Controls->Add(this->label1);
			this->Name = L"MassProccessForm";
			this->Text = L"Μαζική επεξεργασία Εγγραφών";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okbutton_Click(System::Object^  sender, System::EventArgs^  e) {
				 *Result=0;
				 if (this->MassProccessListBox->GetItemChecked(0))
				 *Result=1+*Result;
				 if (this->MassProccessListBox->GetItemChecked(1))
				 *Result=10+*Result;
				 if (this->MassProccessListBox->GetItemChecked(2))
				 *Result=100+*Result;
				 if (this->MassProccessListBox->GetItemChecked(3))
				 *Result=1000+*Result;
				 if (this->MassProccessListBox->GetItemChecked(4))
				 *Result=10000+*Result;
				 this->Close();
			 }
private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }

};
}
