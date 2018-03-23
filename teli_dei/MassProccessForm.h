//*EN
//    TeliDei 
//	Simple tool to Create reports forPublic Electricity Corporation of Grecce. This tool must be usefull for Municipalities. The tool can read files from P.E.C change fees factors and year of construction and save as proper files for submit to P.E.C
//	Copyright (C) 2008-2017  Eleftherios Lamprou
//
//	Creative Commons Attribution/Share-Alike License
//    This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by   the Free Software Foundation, either version 3 of the License, or any later version.
//	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//	You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//	contact e-mail lef27064@otenet.gr
//	webpage at source forge http://sourceforge.net/projects/telidei/
//	souce code (current version) https://github.com/lef27064/teli_dei
//
//GR
//	TeliDei
//	Το λογισμικό teli_dei, έχει στόχο την δημιουργία αναφορών προς την ΔΕΔΗΕ, με στόχο την εξυπηρέτηση στελεχών των Δήμων για την υποβολή μεταβολών Τελών ΔΕΔΗΕ (Δημοτικά Τέλη, Δημοτικό Φόρο, ΤΑΠ). Το πρόγραμμα έχει την δυνατότητα ανάγνωσης του προτώτυπου αρχείου της ΔΕΔΗΕ, επεξεργασία μεμονομένων εγγραφών (ή μαζικών) και δημιουργεία αναφορών σύμφωνα με τα πρότυπα της ΔΕΔΗΕ (Δημιουργία αρχείου για Ψηφιακό Μέσο (Δισκέτα ή CD) για την υποβολή του στο αρμόδιο Δ/νση της ΔΕΗ). Οι εγγραφές μπορούν να τροποποιηθούν στα τετραγωνικά μέτρα των Δημοτικών Τέλων, Δημοτικού Φόρου, ΤΑΠ και έτος κατασκευής
//	Copyright (C) 2008-2017  Eleftherios Lamprou
//	Επαφή lef27064@otenet.gr
//	Ιστοσελίδα προγράμματος http://sourceforge.net/projects/telidei/
//	Πηγαίος κώδικας (current version) https://github.com/lef27064/teli_dei
//	
//	Αδεια Creative Commons Attribution/Share-Alike License
//	Το  λογισμικό TeliDei, παρέχεται "ΩΣ ΕΧΕΙ", χωρίς περαιτέρω εγγύηση καταλληλότητας και υποστήριξης αυτού.
//	Η παραγωγή του συγκεκριμένου λογισμικού, δεν αποσκοπεί στην εμπορική εκμετάλλευσή και είναι επιτρεπτή η Δωρεάν Αντιγραφή, Διανομή και Χρήση του. 
//	
//	Μπορείτε αντιγράψετε, τροποποιήστε,  και να διανείμετε ελεύθερα τον παρών κώδικα με την αναφορά του δημιουργού. 

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
		public:String^ ZoneCode;

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
	
	private: System::Windows::Forms::CheckBox^  checkBoxZoneCode;
	private: System::Windows::Forms::TextBox^  textBoxCodeZone;


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
			this->checkBoxZoneCode = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxCodeZone = (gcnew System::Windows::Forms::TextBox());
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
			this->MassProccessListBox->Size = System::Drawing::Size(477, 94);
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
			// checkBoxZoneCode
			// 
			this->checkBoxZoneCode->AutoSize = true;
			this->checkBoxZoneCode->Location = System::Drawing::Point(24, 198);
			this->checkBoxZoneCode->Name = L"checkBoxZoneCode";
			this->checkBoxZoneCode->Size = System::Drawing::Size(156, 17);
			this->checkBoxZoneCode->TabIndex = 6;
			this->checkBoxZoneCode->Text = L"Θέσε κωδικό ζώνης ισο με";
			this->checkBoxZoneCode->UseVisualStyleBackColor = true;
			// 
			// textBoxCodeZone
			// 
			this->textBoxCodeZone->Location = System::Drawing::Point(229, 195);
			this->textBoxCodeZone->Name = L"textBoxCodeZone";
			this->textBoxCodeZone->Size = System::Drawing::Size(105, 20);
			this->textBoxCodeZone->TabIndex = 7;
			// 
			// MassProccessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 361);
			this->Controls->Add(this->textBoxCodeZone);
			this->Controls->Add(this->checkBoxZoneCode);
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
				 if (this->checkBoxZoneCode->Checked)
				 {
					 *Result=100000+*Result;
					 ZoneCode =textBoxCodeZone->Text;
				 }
				 this->Close();
			 }
private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }

};
}
