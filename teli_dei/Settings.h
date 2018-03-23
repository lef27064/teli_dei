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


#include "Dei.h"
namespace teli_dei{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;
	using namespace System::Xml::Serialization;
	

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(ClassDei^ iSettingsdei)
		{
			
			Settingsdei = iSettingsdei;
					

			InitializeComponent();
			ReadValuesFromFile();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxMunicipality;
	private: System::Windows::Forms::TextBox^  textBoxUserName;
	protected: 

	protected: ClassDei^ Settingsdei;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Label^  labelRegion;
	private: System::Windows::Forms::TextBox^  textBoxRegion;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxTelephone;
	private: System::Windows::Forms::Label^  labelMaxRecords;
	private: System::Windows::Forms::TextBox^  textBoxMaxRecords;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBoxServerPassword;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBoxServerDatabase;
	private: System::Windows::Forms::TextBox^  textBoxServerUserName;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxServer;


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
			this->textBoxMunicipality = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUserName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->labelRegion = (gcnew System::Windows::Forms::Label());
			this->textBoxRegion = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxTelephone = (gcnew System::Windows::Forms::TextBox());
			this->labelMaxRecords = (gcnew System::Windows::Forms::Label());
			this->textBoxMaxRecords = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxServerPassword = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxServerDatabase = (gcnew System::Windows::Forms::TextBox());
			this->textBoxServerUserName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxServer = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxMunicipality
			// 
			this->textBoxMunicipality->Location = System::Drawing::Point(192, 73);
			this->textBoxMunicipality->Name = L"textBoxMunicipality";
			this->textBoxMunicipality->Size = System::Drawing::Size(193, 20);
			this->textBoxMunicipality->TabIndex = 0;
			// 
			// textBoxUserName
			// 
			this->textBoxUserName->Location = System::Drawing::Point(192, 115);
			this->textBoxUserName->Name = L"textBoxUserName";
			this->textBoxUserName->Size = System::Drawing::Size(193, 20);
			this->textBoxUserName->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Δήμος";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Ονοματεπώνυμο χειριστή";
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(662, 339);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(191, 65);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Ακύρωση";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &Settings::buttonCancel_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(95, 339);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(154, 65);
			this->buttonSave->TabIndex = 6;
			this->buttonSave->Text = L"Αποθήκευση";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Settings::buttonSave_Click);
			// 
			// labelRegion
			// 
			this->labelRegion->AutoSize = true;
			this->labelRegion->Location = System::Drawing::Point(19, 40);
			this->labelRegion->Name = L"labelRegion";
			this->labelRegion->Size = System::Drawing::Size(38, 13);
			this->labelRegion->TabIndex = 8;
			this->labelRegion->Text = L"Νομός";
			// 
			// textBoxRegion
			// 
			this->textBoxRegion->Location = System::Drawing::Point(192, 33);
			this->textBoxRegion->Name = L"textBoxRegion";
			this->textBoxRegion->Size = System::Drawing::Size(193, 20);
			this->textBoxRegion->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Τηλέφωνο Δήμου";
			// 
			// textBoxTelephone
			// 
			this->textBoxTelephone->Location = System::Drawing::Point(192, 149);
			this->textBoxTelephone->Name = L"textBoxTelephone";
			this->textBoxTelephone->Size = System::Drawing::Size(193, 20);
			this->textBoxTelephone->TabIndex = 9;
			// 
			// labelMaxRecords
			// 
			this->labelMaxRecords->AutoSize = true;
			this->labelMaxRecords->Location = System::Drawing::Point(35, 264);
			this->labelMaxRecords->Name = L"labelMaxRecords";
			this->labelMaxRecords->Size = System::Drawing::Size(143, 13);
			this->labelMaxRecords->TabIndex = 12;
			this->labelMaxRecords->Text = L"Μέγιστο πλήθος εγγραφών";
			// 
			// textBoxMaxRecords
			// 
			this->textBoxMaxRecords->Location = System::Drawing::Point(208, 257);
			this->textBoxMaxRecords->Name = L"textBoxMaxRecords";
			this->textBoxMaxRecords->Size = System::Drawing::Size(193, 20);
			this->textBoxMaxRecords->TabIndex = 11;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBoxMunicipality);
			this->groupBox1->Controls->Add(this->textBoxUserName);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBoxTelephone);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->labelRegion);
			this->groupBox1->Controls->Add(this->textBoxRegion);
			this->groupBox1->Location = System::Drawing::Point(16, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(413, 203);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Γενικά Στοιχεία";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxServerPassword);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBoxServerDatabase);
			this->groupBox2->Controls->Add(this->textBoxServerUserName);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBoxServer);
			this->groupBox2->Location = System::Drawing::Point(452, 30);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(401, 227);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Βάση Δεδομένων";
			// 
			// textBoxServerPassword
			// 
			this->textBoxServerPassword->Location = System::Drawing::Point(171, 165);
			this->textBoxServerPassword->Name = L"textBoxServerPassword";
			this->textBoxServerPassword->Size = System::Drawing::Size(193, 20);
			this->textBoxServerPassword->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(-2, 172);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Password";
			// 
			// textBoxServerDatabase
			// 
			this->textBoxServerDatabase->Location = System::Drawing::Point(171, 81);
			this->textBoxServerDatabase->Name = L"textBoxServerDatabase";
			this->textBoxServerDatabase->Size = System::Drawing::Size(193, 20);
			this->textBoxServerDatabase->TabIndex = 9;
			// 
			// textBoxServerUserName
			// 
			this->textBoxServerUserName->Location = System::Drawing::Point(171, 123);
			this->textBoxServerUserName->Name = L"textBoxServerUserName";
			this->textBoxServerUserName->Size = System::Drawing::Size(193, 20);
			this->textBoxServerUserName->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(-2, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Ονομα Βάσης";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(-2, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"User name";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(-2, 48);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Server";
			// 
			// textBoxServer
			// 
			this->textBoxServer->Location = System::Drawing::Point(171, 41);
			this->textBoxServer->Name = L"textBoxServer";
			this->textBoxServer->Size = System::Drawing::Size(193, 20);
			this->textBoxServer->TabIndex = 13;
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(928, 508);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->labelMaxRecords);
			this->Controls->Add(this->textBoxMaxRecords);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->buttonCancel);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Settings";
			this->Text = L"Ρυθμίσεις";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e) {
								
				
				Settingsdei->Settings->Region=this->textBoxRegion->Text;
				Settingsdei->Settings->Municipality=this->textBoxMunicipality->Text;
				Settingsdei->Settings->UserName =this->textBoxUserName->Text;
				Settingsdei->Settings->Telephone=this->textBoxTelephone->Text;
				Settingsdei->Settings->MaxRecords=Convert::ToInt32(this->textBoxMaxRecords->Text);
				Settingsdei->Settings->Server =this->textBoxServer->Text;
				Settingsdei->Settings->ServerDatabase=this->textBoxServerDatabase->Text;
				Settingsdei->Settings->ServerPassword=this->textBoxServerPassword->Text;
				Settingsdei->Settings->ServerUserName=this->textBoxServerUserName->Text;

				Settingsdei->UpdateSettings();
			
			}
	
	private: void ReadValuesFromFile(void)
			 {
								
				Settingsdei->ReadSettings();
							
				this->textBoxRegion->Text=Settingsdei->Settings->Region;
				this->textBoxMunicipality->Text=Settingsdei->Settings->Municipality;
				this->textBoxUserName->Text=Settingsdei->Settings->UserName;
				this->textBoxTelephone->Text=Settingsdei->Settings->Telephone;
				this->textBoxMaxRecords->Text = Settingsdei->Settings->MaxRecords.ToString();

				this->textBoxServer->Text= Settingsdei->Settings->Server;
				this->textBoxServerDatabase->Text=Settingsdei->Settings->ServerDatabase;
				this->textBoxServerPassword->Text=Settingsdei->Settings->ServerPassword;
				this->textBoxServerUserName->Text=Settingsdei->Settings->ServerUserName;
				
			 }

  
					  
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}
