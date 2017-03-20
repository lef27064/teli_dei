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
	/// Summary for MassProccessSearchForm
	/// </summary>
	public ref class MassProccessSearchForm : public System::Windows::Forms::Form
	{
	public:
		MassProccessSearchForm(int Result, String^ diamerisma, String^ ZoneCode)
		{
			this->diamerisma =  diamerisma;
			this->Result = Result;
			this->ZoneCode = ZoneCode;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		};

	public: String^ diamerisma; 		
			int Result;
			String^ ZoneCode;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MassProccessSearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
		 
	private: System::Windows::Forms::Button^  Cancelbutton;
	protected: 
	private: System::Windows::Forms::Button^  okbutton;
	private: System::Windows::Forms::CheckedListBox^  MassProccessListBox;
	private: System::Windows::Forms::Label^  label1;
	
	
	private: System::Windows::Forms::CheckBox^  MassProccessCheckBoxFindTAPCode;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  MassProccesstextBoxDiamerisma;
	private: System::Windows::Forms::TextBox^  MassProccessTextBoxKodikosZonis;

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
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->okbutton = (gcnew System::Windows::Forms::Button());
			this->MassProccessListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MassProccessCheckBoxFindTAPCode = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->MassProccesstextBoxDiamerisma = (gcnew System::Windows::Forms::TextBox());
			this->MassProccessTextBoxKodikosZonis = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(356, 256);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(82, 42);
			this->Cancelbutton->TabIndex = 9;
			this->Cancelbutton->Text = L"Ακυρο";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			// 
			// okbutton
			// 
			this->okbutton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->okbutton->Location = System::Drawing::Point(39, 256);
			this->okbutton->Name = L"okbutton";
			this->okbutton->Size = System::Drawing::Size(75, 42);
			this->okbutton->TabIndex = 8;
			this->okbutton->Text = L"Εντάξει";
			this->okbutton->UseVisualStyleBackColor = true;
			this->okbutton->Click += gcnew System::EventHandler(this, &MassProccessSearchForm::okbutton_Click);
			// 
			// MassProccessListBox
			// 
			this->MassProccessListBox->FormattingEnabled = true;
			this->MassProccessListBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Εγγραφές με μηδένικο ΤΑΠ", L"Εγγραφές με Δημοτικά Τέλη διάφορα απο το Δημοτικό Φόρο ", 
				L"Εγγραφές με Δημοτικά Τέλη διάφορα απο το Δημοτικό Φόρο ή ΤΑΠ", L"Εγγραφές με μηδενικό Δημοτικά Τέλη", L"Εγγραφές με μηδενικό Δημοτικό Φόρο"});
			this->MassProccessListBox->Location = System::Drawing::Point(39, 93);
			this->MassProccessListBox->Name = L"MassProccessListBox";
			this->MassProccessListBox->Size = System::Drawing::Size(527, 94);
			this->MassProccessListBox->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Ποιές εγγραφές θέλετε να αναζητηθούν\?";
			// 
			// MassProccessCheckBoxFindTAPCode
			// 
			this->MassProccessCheckBoxFindTAPCode->AutoSize = true;
			this->MassProccessCheckBoxFindTAPCode->Location = System::Drawing::Point(39, 194);
			this->MassProccessCheckBoxFindTAPCode->Name = L"MassProccessCheckBoxFindTAPCode";
			this->MassProccessCheckBoxFindTAPCode->Size = System::Drawing::Size(194, 17);
			this->MassProccessCheckBoxFindTAPCode->TabIndex = 10;
			this->MassProccessCheckBoxFindTAPCode->Text = L"Ευρεση με Κωδ. ΤΑΠ στον οικισμό";
			this->MassProccessCheckBoxFindTAPCode->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(353, 194);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"και με κωδικό ζώνης";
			// 
			// MassProccesstextBoxDiamerisma
			// 
			this->MassProccesstextBoxDiamerisma->Location = System::Drawing::Point(249, 191);
			this->MassProccesstextBoxDiamerisma->Name = L"MassProccesstextBoxDiamerisma";
			this->MassProccesstextBoxDiamerisma->Size = System::Drawing::Size(100, 20);
			this->MassProccesstextBoxDiamerisma->TabIndex = 14;
			// 
			// MassProccessTextBoxKodikosZonis
			// 
			this->MassProccessTextBoxKodikosZonis->Location = System::Drawing::Point(466, 191);
			this->MassProccessTextBoxKodikosZonis->Name = L"MassProccessTextBoxKodikosZonis";
			this->MassProccessTextBoxKodikosZonis->Size = System::Drawing::Size(100, 20);
			this->MassProccessTextBoxKodikosZonis->TabIndex = 15;
			// 
			// MassProccessSearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 342);
			this->Controls->Add(this->MassProccessTextBoxKodikosZonis);
			this->Controls->Add(this->MassProccesstextBoxDiamerisma);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->MassProccessCheckBoxFindTAPCode);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->okbutton);
			this->Controls->Add(this->MassProccessListBox);
			this->Controls->Add(this->label1);
			this->Name = L"MassProccessSearchForm";
			this->Text = L"Μαζική αναζήτηση εγγραφών";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void okbutton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Result=0;
				 
				 if (this->MassProccessListBox->GetItemChecked(0))
				 this->Result=1+ this->Result;
				 
				 if (this->MassProccessListBox->GetItemChecked(1))
				this->Result=10+ this->Result;
				 
				 if (this->MassProccessListBox->GetItemChecked(2))
				this->Result=100+ this->Result;
				 
				 
				 if (this->MassProccessListBox->GetItemChecked(3))
				 this->Result=1000+ this->Result;

				 if (this->MassProccessListBox->GetItemChecked(4))
				 this->Result=10000+ this->Result;

				 if (this->MassProccessCheckBoxFindTAPCode->Checked)
				 this->Result=100000+ this->Result;

				 this->ZoneCode = this->MassProccessTextBoxKodikosZonis->Text;
				 this->diamerisma = this->MassProccesstextBoxDiamerisma->Text;
			 }

		

		private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();

		 }
	
};
}
