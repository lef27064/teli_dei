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
#using <System.dll>

#include "Dei.h"
#include "Settings.h"
#include "MassProccessForm.h"
#include "MassProccessSearchForm.h"

namespace teli_dei {
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Xml;
	using namespace System::Xml::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	



//	using namespace System::Drawing;

	/// <summary>
	/// Η φόρμα αυτή είναι η βασική φόρμα μεταβολών
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
		
			InitializeComponent();
			this->InitializeChangedGridView();
			VersionHelper::VersionHelper^ VH; 
				
			
			//
			//
			//TODO: Add the constructor code here
			//
			
			massproccess= new int(0);
			
			
			String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
			String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
			XmlSerializer^ serializer = gcnew XmlSerializer(ClassDei::typeid );

			//Υπάρχει το Directory?
			if (!Directory::Exists(path))
			{
				dei = gcnew ClassDei(0);				//Δημιουργεία του Directory teli_dei
				dei->SaveSettings();				// Γράψε ένα settings.xml στο directory
				dei->SaveData();					// Γράψε ένα data.xml στο directory
				
				
				
				dei->ReadFromBinaryData();
				dei->UpdateTotalInputRecords(dei->SavedData->Data->Count);
				this->UpdateInputGrid();
			
						
			}
			else
			{
				//Προσωρινή δομή
				ClassDei^ deiSettings;
				deiSettings = gcnew ClassDei(10);
				//

				deiSettings->ReadSettings(deiSettings,"settings.xml");
			
								
				
				dei = gcnew ClassDei(deiSettings->Settings->MaxRecords);
				delete deiSettings;
				dei->ReadData();


			  
				 dei->ReadFromBinaryData();
				 dei->UpdateTotalInputRecords(dei->SavedData->Data->Count);
				 this->UpdateInputGrid();
			  			
			}
			this->UpdateButtons();  
	     //Version check for update
			//   VH = gcnew(VersionHelper::VersionHelper);
		//	VH->CheckForNewVersion();

		}


	

	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  ReadFromFileButton;
	private: System::Windows::Forms::Button^  TransferButton;

	public:  ClassDei^ dei;


	private: System::Windows::Forms::DataGridView^  ChangedGridView;
	private: System::Windows::Forms::DataGridView^  OutputGridView;
	private: System::Windows::Forms::Button^  SaveChangesbutton;
	private: System::Windows::Forms::Button^  InputFromFilebutton;
	private: System::Windows::Forms::Button^  MakeReportButton;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::TextBox^  SearchBox;
	private: System::Windows::Forms::Button^  SearchNamebutton;

	private: System::Windows::Forms::Form^ SettingsForm;


	private: System::Windows::Forms::Button^  buttonSearchProvider;
	private: System::Windows::Forms::TextBox^  textBoxProvider;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::Button^  buttonPrintReport;
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Onomateponimo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Periferia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Paroxi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Diadoxos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  GrafeioDei;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MetraTelon;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MetraForou;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MetraTap;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PosoAnadrXreosis;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DoseisAnadromikesDT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PosoAnadrXreosisTap;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PlithosDoseonAnadrTAP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EtosAdeias;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  KodikosZonisTap;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DeiktisXreosisXrisisTAP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  KodikosDimou;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MetraForouOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MetraTelonOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MetraTapOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EtosAdeiasOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PosoAnadrXreosisOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DoseisAnadromikesDTOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PosoAnadrXreosisTAPOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PlithosDoseonAnadrTAPOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  KodikosZonisTAPOriginal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DeiktisXreosisXrisisTAPOriginal;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  MassProccessButton;
	private: int* massproccess;
	private: System::Windows::Forms::Button^  MassSearchbutton;
private: System::Windows::Forms::DataGridView^  InputDataGrid;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Arithmos;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cParoxi;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cOnomateponimo;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cOdos;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cArithmos;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cPoli;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cTaxKodikas;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cKodikosDK;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cKodikosXreosis;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cKodikosApalagis;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  TetragonikaMetraDimTelon;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cTetragonikaMetraDimForou;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cKodikosXreosisTap;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cDeiktisXreosisXrisisTap;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cKodikosApalagisTap;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cTetragvnikaMetraTap;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cEtosAdeias;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cCodeZone;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cOnomasiaDimou;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  cKodikosDimou;
private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;




























































	 


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
			this->ReadFromFileButton = (gcnew System::Windows::Forms::Button());
			this->TransferButton = (gcnew System::Windows::Forms::Button());
			this->ChangedGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Onomateponimo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Periferia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Paroxi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Diadoxos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GrafeioDei = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MetraTelon = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MetraForou = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MetraTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosoAnadrXreosis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DoseisAnadromikesDT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosoAnadrXreosisTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PlithosDoseonAnadrTAP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EtosAdeias = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->KodikosZonisTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DeiktisXreosisXrisisTAP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->KodikosDimou = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MetraForouOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MetraTelonOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MetraTapOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EtosAdeiasOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosoAnadrXreosisOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DoseisAnadromikesDTOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosoAnadrXreosisTAPOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PlithosDoseonAnadrTAPOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->KodikosZonisTAPOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DeiktisXreosisXrisisTAPOriginal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SaveChangesbutton = (gcnew System::Windows::Forms::Button());
			this->InputFromFilebutton = (gcnew System::Windows::Forms::Button());
			this->MakeReportButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SearchBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchNamebutton = (gcnew System::Windows::Forms::Button());
			this->buttonSearchProvider = (gcnew System::Windows::Forms::Button());
			this->textBoxProvider = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->buttonPrintReport = (gcnew System::Windows::Forms::Button());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->MassProccessButton = (gcnew System::Windows::Forms::Button());
			this->MassSearchbutton = (gcnew System::Windows::Forms::Button());
			this->InputDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Arithmos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cParoxi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cOnomateponimo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cOdos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cArithmos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cPoli = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cTaxKodikas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cKodikosDK = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cKodikosXreosis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cKodikosApalagis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TetragonikaMetraDimTelon = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cTetragonikaMetraDimForou = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cKodikosXreosisTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cDeiktisXreosisXrisisTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cKodikosApalagisTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cTetragvnikaMetraTap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cEtosAdeias = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cCodeZone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cOnomasiaDimou = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cKodikosDimou = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ChangedGridView))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputDataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// ReadFromFileButton
			// 
			this->ReadFromFileButton->Location = System::Drawing::Point(12, 297);
			this->ReadFromFileButton->Name = L"ReadFromFileButton";
			this->ReadFromFileButton->Size = System::Drawing::Size(144, 55);
			this->ReadFromFileButton->TabIndex = 0;
			this->ReadFromFileButton->Text = L"Ανάγνωση από πρωτότυπο αρχείο ΔΕΗ";
			this->ReadFromFileButton->UseCompatibleTextRendering = true;
			this->ReadFromFileButton->UseVisualStyleBackColor = true;
			this->ReadFromFileButton->Click += gcnew System::EventHandler(this, &Form1::ReadFromFileButton_Click);
			// 
			// TransferButton
			// 
			this->TransferButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F));
			this->TransferButton->Location = System::Drawing::Point(1025, 299);
			this->TransferButton->Name = L"TransferButton";
			this->TransferButton->Size = System::Drawing::Size(85, 63);
			this->TransferButton->TabIndex = 3;
			this->TransferButton->Text = L">";
			this->TransferButton->UseVisualStyleBackColor = true;
			this->TransferButton->Click += gcnew System::EventHandler(this, &Form1::TransferButton_Click);
			// 
			// ChangedGridView
			// 
			this->ChangedGridView->AllowUserToAddRows = false;
			this->ChangedGridView->AllowUserToOrderColumns = true;
			this->ChangedGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ChangedGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(26) {this->Onomateponimo, 
				this->Periferia, this->Paroxi, this->Diadoxos, this->GrafeioDei, this->MetraTelon, this->MetraForou, this->MetraTap, this->PosoAnadrXreosis, 
				this->DoseisAnadromikesDT, this->PosoAnadrXreosisTap, this->PlithosDoseonAnadrTAP, this->EtosAdeias, this->KodikosZonisTap, this->DeiktisXreosisXrisisTAP, 
				this->KodikosDimou, this->MetraForouOriginal, this->MetraTelonOriginal, this->MetraTapOriginal, this->EtosAdeiasOriginal, this->PosoAnadrXreosisOriginal, 
				this->DoseisAnadromikesDTOriginal, this->PosoAnadrXreosisTAPOriginal, this->PlithosDoseonAnadrTAPOriginal, this->KodikosZonisTAPOriginal, 
				this->DeiktisXreosisXrisisTAPOriginal});
			this->ChangedGridView->Location = System::Drawing::Point(6, 387);
			this->ChangedGridView->Name = L"ChangedGridView";
			this->ChangedGridView->Size = System::Drawing::Size(925, 208);
			this->ChangedGridView->TabIndex = 10;
			// 
			// Onomateponimo
			// 
			this->Onomateponimo->HeaderText = L"Ονοματεπώνυμο";
			this->Onomateponimo->Name = L"Onomateponimo";
			this->Onomateponimo->ReadOnly = true;
			this->Onomateponimo->Width = 160;
			// 
			// Periferia
			// 
			this->Periferia->HeaderText = L"Περιφέρεια";
			this->Periferia->Name = L"Periferia";
			this->Periferia->ReadOnly = true;
			this->Periferia->Visible = false;
			this->Periferia->Width = 50;
			// 
			// Paroxi
			// 
			this->Paroxi->HeaderText = L"Αριθμός Παροχής";
			this->Paroxi->Name = L"Paroxi";
			this->Paroxi->ReadOnly = true;
			this->Paroxi->Visible = false;
			this->Paroxi->Width = 140;
			// 
			// Diadoxos
			// 
			this->Diadoxos->HeaderText = L"Διαδοχος";
			this->Diadoxos->Name = L"Diadoxos";
			this->Diadoxos->ReadOnly = true;
			this->Diadoxos->Visible = false;
			this->Diadoxos->Width = 50;
			// 
			// GrafeioDei
			// 
			this->GrafeioDei->HeaderText = L"Γραφείο ΔΕΗ";
			this->GrafeioDei->Name = L"GrafeioDei";
			this->GrafeioDei->ReadOnly = true;
			this->GrafeioDei->Visible = false;
			this->GrafeioDei->Width = 60;
			// 
			// MetraTelon
			// 
			this->MetraTelon->HeaderText = L"m2 Δημ. Τελών";
			this->MetraTelon->Name = L"MetraTelon";
			this->MetraTelon->Width = 50;
			// 
			// MetraForou
			// 
			this->MetraForou->HeaderText = L"m2 Δημ. Φόρου";
			this->MetraForou->Name = L"MetraForou";
			this->MetraForou->Width = 50;
			// 
			// MetraTap
			// 
			this->MetraTap->HeaderText = L"m2 ΤΑΠ";
			this->MetraTap->Name = L"MetraTap";
			this->MetraTap->Width = 50;
			// 
			// PosoAnadrXreosis
			// 
			this->PosoAnadrXreosis->HeaderText = L"Ποσό Αναδρ. χρέωσης ΔΤ-ΔΦ";
			this->PosoAnadrXreosis->Name = L"PosoAnadrXreosis";
			this->PosoAnadrXreosis->Width = 70;
			// 
			// DoseisAnadromikesDT
			// 
			this->DoseisAnadromikesDT->HeaderText = L"Αριθμός Δόσεων αναδρ. ΔΤ-ΔΦ";
			this->DoseisAnadromikesDT->Name = L"DoseisAnadromikesDT";
			this->DoseisAnadromikesDT->Width = 60;
			// 
			// PosoAnadrXreosisTap
			// 
			this->PosoAnadrXreosisTap->HeaderText = L"Ποσό Αναδρομικής Χρέωσης ΤΑΠ";
			this->PosoAnadrXreosisTap->Name = L"PosoAnadrXreosisTap";
			this->PosoAnadrXreosisTap->Width = 90;
			// 
			// PlithosDoseonAnadrTAP
			// 
			this->PlithosDoseonAnadrTAP->HeaderText = L"Πλήθος Δόσεων Αναδρομικού ΤΑΠ";
			this->PlithosDoseonAnadrTAP->Name = L"PlithosDoseonAnadrTAP";
			this->PlithosDoseonAnadrTAP->Width = 60;
			// 
			// EtosAdeias
			// 
			this->EtosAdeias->HeaderText = L"Ετος Οικοδομικής Αδειας";
			this->EtosAdeias->Name = L"EtosAdeias";
			this->EtosAdeias->Width = 90;
			// 
			// KodikosZonisTap
			// 
			this->KodikosZonisTap->HeaderText = L"Κωδικός Ζώνης ΤΑΠ";
			this->KodikosZonisTap->Name = L"KodikosZonisTap";
			this->KodikosZonisTap->Width = 70;
			// 
			// DeiktisXreosisXrisisTAP
			// 
			this->DeiktisXreosisXrisisTAP->HeaderText = L"Δείκτης Χρέωσης Χρήσης ΤΑΠ";
			this->DeiktisXreosisXrisisTAP->Name = L"DeiktisXreosisXrisisTAP";
			this->DeiktisXreosisXrisisTAP->Width = 60;
			// 
			// KodikosDimou
			// 
			this->KodikosDimou->HeaderText = L"Κωδικός Δήμου";
			this->KodikosDimou->Name = L"KodikosDimou";
			this->KodikosDimou->ReadOnly = true;
			this->KodikosDimou->Width = 70;
			// 
			// MetraForouOriginal
			// 
			this->MetraForouOriginal->HeaderText = L"m2 Δημ. Φόρου (Αρχικά)";
			this->MetraForouOriginal->Name = L"MetraForouOriginal";
			this->MetraForouOriginal->Visible = false;
			// 
			// MetraTelonOriginal
			// 
			this->MetraTelonOriginal->HeaderText = L"m2 Δημοτικών Τελών (Αρχικά)";
			this->MetraTelonOriginal->Name = L"MetraTelonOriginal";
			this->MetraTelonOriginal->Visible = false;
			// 
			// MetraTapOriginal
			// 
			this->MetraTapOriginal->HeaderText = L"m2 ΤΑΠ (Αρχικά)";
			this->MetraTapOriginal->Name = L"MetraTapOriginal";
			this->MetraTapOriginal->Visible = false;
			// 
			// EtosAdeiasOriginal
			// 
			this->EtosAdeiasOriginal->HeaderText = L"Ετος Οικοδομικής Αδειας (Αρχικό)";
			this->EtosAdeiasOriginal->Name = L"EtosAdeiasOriginal";
			this->EtosAdeiasOriginal->Visible = false;
			// 
			// PosoAnadrXreosisOriginal
			// 
			this->PosoAnadrXreosisOriginal->HeaderText = L"Ποσό Αναδρ. χρέωσης ΔΤ-ΔΦ (Αρχικό)";
			this->PosoAnadrXreosisOriginal->Name = L"PosoAnadrXreosisOriginal";
			this->PosoAnadrXreosisOriginal->Visible = false;
			// 
			// DoseisAnadromikesDTOriginal
			// 
			this->DoseisAnadromikesDTOriginal->HeaderText = L"Αριθμός Δόσεων αναδρ. ΔΤ+ΔΦ (Αρχικό)";
			this->DoseisAnadromikesDTOriginal->Name = L"DoseisAnadromikesDTOriginal";
			this->DoseisAnadromikesDTOriginal->Visible = false;
			// 
			// PosoAnadrXreosisTAPOriginal
			// 
			this->PosoAnadrXreosisTAPOriginal->HeaderText = L"Ποσό Αναδομικής Χρέωσης ΤΑΠ (Αρχικό)";
			this->PosoAnadrXreosisTAPOriginal->Name = L"PosoAnadrXreosisTAPOriginal";
			this->PosoAnadrXreosisTAPOriginal->Visible = false;
			// 
			// PlithosDoseonAnadrTAPOriginal
			// 
			this->PlithosDoseonAnadrTAPOriginal->HeaderText = L"Πλήθος Δόσεων Αναδρομικού ΤΑΠ (Αρχικό)";
			this->PlithosDoseonAnadrTAPOriginal->Name = L"PlithosDoseonAnadrTAPOriginal";
			this->PlithosDoseonAnadrTAPOriginal->Visible = false;
			// 
			// KodikosZonisTAPOriginal
			// 
			this->KodikosZonisTAPOriginal->HeaderText = L"Κωδικός Ζώνης ΤΑΠ (Αρχικό)";
			this->KodikosZonisTAPOriginal->Name = L"KodikosZonisTAPOriginal";
			this->KodikosZonisTAPOriginal->Visible = false;
			// 
			// DeiktisXreosisXrisisTAPOriginal
			// 
			this->DeiktisXreosisXrisisTAPOriginal->HeaderText = L"Δείκτης Χρέωσης Χρήσης ΤΑΠ (Αρχικό)";
			this->DeiktisXreosisXrisisTAPOriginal->Name = L"DeiktisXreosisXrisisTAPOriginal";
			this->DeiktisXreosisXrisisTAPOriginal->Visible = false;
			// 
			// SaveChangesbutton
			// 
			this->SaveChangesbutton->Enabled = false;
			this->SaveChangesbutton->Location = System::Drawing::Point(226, 600);
			this->SaveChangesbutton->Name = L"SaveChangesbutton";
			this->SaveChangesbutton->Size = System::Drawing::Size(159, 49);
			this->SaveChangesbutton->TabIndex = 11;
			this->SaveChangesbutton->Text = L"Αποθήκευση Πίνακα Μεταβολών";
			this->SaveChangesbutton->UseVisualStyleBackColor = true;
			this->SaveChangesbutton->Click += gcnew System::EventHandler(this, &Form1::SaveChangesbutton_Click);
			// 
			// InputFromFilebutton
			// 
			this->InputFromFilebutton->Location = System::Drawing::Point(12, 600);
			this->InputFromFilebutton->Name = L"InputFromFilebutton";
			this->InputFromFilebutton->Size = System::Drawing::Size(145, 49);
			this->InputFromFilebutton->TabIndex = 12;
			this->InputFromFilebutton->Text = L"Εισαγωγή Πίνακα μεταβολών από αρχείο";
			this->InputFromFilebutton->UseVisualStyleBackColor = true;
			this->InputFromFilebutton->Click += gcnew System::EventHandler(this, &Form1::InputFromFilebutton_Click);
			// 
			// MakeReportButton
			// 
			this->MakeReportButton->Enabled = false;
			this->MakeReportButton->Location = System::Drawing::Point(790, 601);
			this->MakeReportButton->Name = L"MakeReportButton";
			this->MakeReportButton->Size = System::Drawing::Size(141, 49);
			this->MakeReportButton->TabIndex = 14;
			this->MakeReportButton->Text = L"Δημιουργεία αναφοράς";
			this->MakeReportButton->UseVisualStyleBackColor = true;
			this->MakeReportButton->Click += gcnew System::EventHandler(this, &Form1::buttonMakeReport_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Αρχικό αρχείο ΔΕΗ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 371);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Πίνακας Μεταβολών";
			// 
			// SearchBox
			// 
			this->SearchBox->Location = System::Drawing::Point(6, 16);
			this->SearchBox->Name = L"SearchBox";
			this->SearchBox->Size = System::Drawing::Size(212, 20);
			this->SearchBox->TabIndex = 19;
			// 
			// SearchNamebutton
			// 
			this->SearchNamebutton->Enabled = false;
			this->SearchNamebutton->Location = System::Drawing::Point(225, 11);
			this->SearchNamebutton->Name = L"SearchNamebutton";
			this->SearchNamebutton->Size = System::Drawing::Size(96, 31);
			this->SearchNamebutton->TabIndex = 20;
			this->SearchNamebutton->Text = L"Εύρεση ονο/μο";
			this->SearchNamebutton->UseVisualStyleBackColor = true;
			this->SearchNamebutton->Click += gcnew System::EventHandler(this, &Form1::buttonSearchName_Click);
			// 
			// buttonSearchProvider
			// 
			this->buttonSearchProvider->Enabled = false;
			this->buttonSearchProvider->Location = System::Drawing::Point(225, 42);
			this->buttonSearchProvider->Name = L"buttonSearchProvider";
			this->buttonSearchProvider->Size = System::Drawing::Size(96, 30);
			this->buttonSearchProvider->TabIndex = 23;
			this->buttonSearchProvider->Text = L"Εύρεση Παροχή";
			this->buttonSearchProvider->UseVisualStyleBackColor = true;
			this->buttonSearchProvider->Click += gcnew System::EventHandler(this, &Form1::buttonSearchProvider_Click);
			// 
			// textBoxProvider
			// 
			this->textBoxProvider->Location = System::Drawing::Point(6, 49);
			this->textBoxProvider->Name = L"textBoxProvider";
			this->textBoxProvider->Size = System::Drawing::Size(212, 20);
			this->textBoxProvider->TabIndex = 22;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"File Name";
			// 
			// buttonPrintReport
			// 
			this->buttonPrintReport->Location = System::Drawing::Point(971, 600);
			this->buttonPrintReport->Name = L"buttonPrintReport";
			this->buttonPrintReport->Size = System::Drawing::Size(148, 49);
			this->buttonPrintReport->TabIndex = 24;
			this->buttonPrintReport->Text = L"Εκτύπωση Εντύπου";
			this->buttonPrintReport->UseVisualStyleBackColor = true;
			this->buttonPrintReport->Click += gcnew System::EventHandler(this, &Form1::buttonPrintReport_Click);
			// 
			// buttonSettings
			// 
			this->buttonSettings->Location = System::Drawing::Point(971, 460);
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->Size = System::Drawing::Size(148, 47);
			this->buttonSettings->TabIndex = 25;
			this->buttonSettings->Text = L"Ρυθμίσεις";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &Form1::buttonSettings_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonSearchProvider);
			this->groupBox1->Controls->Add(this->SearchNamebutton);
			this->groupBox1->Controls->Add(this->SearchBox);
			this->groupBox1->Controls->Add(this->textBoxProvider);
			this->groupBox1->Location = System::Drawing::Point(314, 297);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(326, 81);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Αναζήτηση Ονοματεπωνύμου - Παροχής";
			// 
			// MassProccessButton
			// 
			this->MassProccessButton->Enabled = false;
			this->MassProccessButton->Location = System::Drawing::Point(489, 601);
			this->MassProccessButton->Name = L"MassProccessButton";
			this->MassProccessButton->Size = System::Drawing::Size(146, 48);
			this->MassProccessButton->TabIndex = 27;
			this->MassProccessButton->Text = L"Μαζική επεξεργασία εγγραφών";
			this->MassProccessButton->UseVisualStyleBackColor = true;
			this->MassProccessButton->Click += gcnew System::EventHandler(this, &Form1::MassProccessButton_Click);
			// 
			// MassSearchbutton
			// 
			this->MassSearchbutton->Enabled = false;
			this->MassSearchbutton->Location = System::Drawing::Point(752, 309);
			this->MassSearchbutton->Name = L"MassSearchbutton";
			this->MassSearchbutton->Size = System::Drawing::Size(146, 48);
			this->MassSearchbutton->TabIndex = 28;
			this->MassSearchbutton->Text = L"Μαζική εύρεση εγγραφών";
			this->MassSearchbutton->UseVisualStyleBackColor = true;
			this->MassSearchbutton->Click += gcnew System::EventHandler(this, &Form1::MassSearchbutton_Click);
			// 
			// InputDataGrid
			// 
			this->InputDataGrid->AllowUserToAddRows = false;
			this->InputDataGrid->AllowUserToDeleteRows = false;
			this->InputDataGrid->AllowUserToOrderColumns = true;
			this->InputDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->InputDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(20) {this->Arithmos, 
				this->cParoxi, this->cOnomateponimo, this->cOdos, this->cArithmos, this->cPoli, this->cTaxKodikas, this->cKodikosDK, this->cKodikosXreosis, 
				this->cKodikosApalagis, this->TetragonikaMetraDimTelon, this->cTetragonikaMetraDimForou, this->cKodikosXreosisTap, this->cDeiktisXreosisXrisisTap, 
				this->cKodikosApalagisTap, this->cTetragvnikaMetraTap, this->cEtosAdeias, this->cCodeZone, this->cOnomasiaDimou, this->cKodikosDimou});
			this->InputDataGrid->Location = System::Drawing::Point(6, 44);
			this->InputDataGrid->Name = L"InputDataGrid";
			this->InputDataGrid->Size = System::Drawing::Size(1203, 225);
			this->InputDataGrid->TabIndex = 7;
			// 
			// Arithmos
			// 
			this->Arithmos->HeaderText = L"A/A";
			this->Arithmos->Name = L"Arithmos";
			this->Arithmos->Width = 30;
			// 
			// cParoxi
			// 
			this->cParoxi->HeaderText = L"Αριθμός Παροχής";
			this->cParoxi->Name = L"cParoxi";
			this->cParoxi->Width = 80;
			// 
			// cOnomateponimo
			// 
			this->cOnomateponimo->HeaderText = L"Ονοματεπώνυμο";
			this->cOnomateponimo->Name = L"cOnomateponimo";
			this->cOnomateponimo->Width = 130;
			// 
			// cOdos
			// 
			this->cOdos->HeaderText = L"Οδός";
			this->cOdos->Name = L"cOdos";
			this->cOdos->Width = 80;
			// 
			// cArithmos
			// 
			this->cArithmos->HeaderText = L"Αριθμός";
			this->cArithmos->Name = L"cArithmos";
			this->cArithmos->Width = 30;
			// 
			// cPoli
			// 
			this->cPoli->HeaderText = L"Πόλη";
			this->cPoli->Name = L"cPoli";
			this->cPoli->Width = 60;
			// 
			// cTaxKodikas
			// 
			this->cTaxKodikas->HeaderText = L"Τ.Κ.";
			this->cTaxKodikas->Name = L"cTaxKodikas";
			this->cTaxKodikas->Width = 40;
			// 
			// cKodikosDK
			// 
			this->cKodikosDK->HeaderText = L"Κωδικός Δ.Κ.";
			this->cKodikosDK->Name = L"cKodikosDK";
			this->cKodikosDK->Width = 40;
			// 
			// cKodikosXreosis
			// 
			this->cKodikosXreosis->HeaderText = L"Κωδικός Χρέωσης";
			this->cKodikosXreosis->Name = L"cKodikosXreosis";
			this->cKodikosXreosis->Width = 40;
			// 
			// cKodikosApalagis
			// 
			this->cKodikosApalagis->HeaderText = L"Κωδικός Απαλαγής";
			this->cKodikosApalagis->Name = L"cKodikosApalagis";
			this->cKodikosApalagis->Width = 40;
			// 
			// TetragonikaMetraDimTelon
			// 
			this->TetragonikaMetraDimTelon->HeaderText = L"m2 Δημ. Τελών";
			this->TetragonikaMetraDimTelon->Name = L"TetragonikaMetraDimTelon";
			this->TetragonikaMetraDimTelon->Width = 50;
			// 
			// cTetragonikaMetraDimForou
			// 
			this->cTetragonikaMetraDimForou->HeaderText = L"m2 Δημοτικού Φόρου";
			this->cTetragonikaMetraDimForou->Name = L"cTetragonikaMetraDimForou";
			this->cTetragonikaMetraDimForou->Width = 50;
			// 
			// cKodikosXreosisTap
			// 
			this->cKodikosXreosisTap->HeaderText = L"Κωδικός Χρέωσης Τ.Α.Π.";
			this->cKodikosXreosisTap->Name = L"cKodikosXreosisTap";
			this->cKodikosXreosisTap->Width = 50;
			// 
			// cDeiktisXreosisXrisisTap
			// 
			this->cDeiktisXreosisXrisisTap->HeaderText = L"Δείκτης Χρέωσης Χρήσης ΤΑΠ";
			this->cDeiktisXreosisXrisisTap->Name = L"cDeiktisXreosisXrisisTap";
			this->cDeiktisXreosisXrisisTap->Width = 60;
			// 
			// cKodikosApalagisTap
			// 
			this->cKodikosApalagisTap->HeaderText = L"Κωδικός Απαλαγής ΤΑΠ";
			this->cKodikosApalagisTap->Name = L"cKodikosApalagisTap";
			this->cKodikosApalagisTap->Width = 50;
			// 
			// cTetragvnikaMetraTap
			// 
			this->cTetragvnikaMetraTap->HeaderText = L"m2 Τ.Α.Π.";
			this->cTetragvnikaMetraTap->Name = L"cTetragvnikaMetraTap";
			this->cTetragvnikaMetraTap->Width = 50;
			// 
			// cEtosAdeias
			// 
			this->cEtosAdeias->HeaderText = L"Ετος Αδειας";
			this->cEtosAdeias->Name = L"cEtosAdeias";
			this->cEtosAdeias->Width = 60;
			// 
			// cCodeZone
			// 
			this->cCodeZone->HeaderText = L"Κωδ. ζώνης";
			this->cCodeZone->Name = L"cCodeZone";
			this->cCodeZone->ReadOnly = true;
			// 
			// cOnomasiaDimou
			// 
			this->cOnomasiaDimou->HeaderText = L"Ονομασία Δήμου";
			this->cOnomasiaDimou->Name = L"cOnomasiaDimou";
			this->cOnomasiaDimou->Width = 70;
			// 
			// cKodikosDimou
			// 
			this->cKodikosDimou->HeaderText = L"Κωδικός Δήμου";
			this->cKodikosDimou->Name = L"cKodikosDimou";
			this->cKodikosDimou->Width = 50;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1210, 0);
			this->flowLayoutPanel1->TabIndex = 29;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1210, 674);
			this->Controls->Add(this->InputDataGrid);
			this->Controls->Add(this->MassSearchbutton);
			this->Controls->Add(this->MassProccessButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonSettings);
			this->Controls->Add(this->buttonPrintReport);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MakeReportButton);
			this->Controls->Add(this->InputFromFilebutton);
			this->Controls->Add(this->SaveChangesbutton);
			this->Controls->Add(this->ChangedGridView);
			this->Controls->Add(this->TransferButton);
			this->Controls->Add(this->ReadFromFileButton);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"Form1";
			this->Text = L"ΕΦΑΡΜΟΓΗ ΔΙΟΡΘΩΣΗΣ ΔΗΜΟΤΙΚΩΝ ΤΕΛΩΝ  v 4.6 - 24/1/2017";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::FormIsClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ChangedGridView))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputDataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	
		//Αρχικοποίηση των DataGrids
private: void ClearDataGrids(void)
			 {
			 this->InputDataGrid->SelectAll();
			 this->InputDataGrid->Rows->Clear();
			 this->InputDataGrid->Refresh();

			 this->MassSearchbutton->Enabled=false;
			
			 }


			 //Ανάγνωση απο το πρωτότυπο αρχείο	Δ.Ε.Η
private: System::Void ReadFromFileButton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 System::Windows::Forms::DialogResult answer;
				 if (this->InputDataGrid->RowCount>1)
				   answer =	 System::Windows::Forms::MessageBox::Show("Προσοχή τα υπαρχοντα δεδομένα θα καταστραφούν. Θέλετε να συνεχίσετε? ","Διαγραφή υπαρχόντων δεδομένων",System::Windows::Forms::MessageBoxButtons::YesNo);
				 if ((answer == System::Windows::Forms::DialogResult::Yes) || (answer == System::Windows::Forms::DialogResult::None)){

				
				 answer = this->openFileDialog->ShowDialog(); // == System::Windows::Forms::DialogResult::OK
				 if (answer != System::Windows::Forms::DialogResult::Cancel)
				 {   int filenamesize = this->openFileDialog->FileName->Length;
					 if (filenamesize>0)
					 { 
						 long filesize = System::IO::FileInfo(this->openFileDialog->FileName).Length;
						 int records = (filesize /150) +1;
						 delete dei;
						 dei = gcnew ClassDei(records);
						 ClearDataGrids();

						 if (dei->ReadFromFile(this->openFileDialog->FileName)>-1)
						 {
							UpdateInputGrid();
							this->TransferButton->Enabled=true;
			 
		
							 this->SaveChangesbutton->Enabled=false;
							 this->MassProccessButton->Enabled=false;
							 this->SearchNamebutton->Enabled=true;
							 this->buttonSearchProvider->Enabled=true;
							 this->MakeReportButton->Enabled=false;
							 this->MassSearchbutton->Enabled=true;

						 }
						 else
						 {
							 // dei = gcnew ClassDei(int(1000));
							 this->TransferButton->Enabled=false;
							

						 }
					 }
				 }

				 }
			 }
			
		 
		 //Μεταφορά στον πίνακα των μεταβολών
private: System::Void TransferButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			int i;
			int count=this->ChangedGridView->Rows->Count;
			
			if (this->InputDataGrid->SelectedRows->Count>0)
			{
				this->MakeReportButton->Enabled=true;
				this->SaveChangesbutton->Enabled=true;
				this->MassProccessButton->Enabled=true;
				this->SearchNamebutton->Enabled=true;
				this->buttonSearchProvider->Enabled=true;
			
				for (i=0; i<this->InputDataGrid->SelectedRows->Count; i++)
				{  
					int position=this->InputDataGrid->SelectedRows[i]->Index+1;
					this->ChangedGridView->Rows->Add();
					this->ChangedGridView->Rows[i+count]->Cells[0]->Value = this->dei->Input[position].Onomateponimo;
					this->ChangedGridView->Rows[i+count]->Cells[1]->Value = this->dei->Input[position].Periferia;
					this->ChangedGridView->Rows[i+count]->Cells[2]->Value = this->dei->Input[position].Paroxi;
					this->ChangedGridView->Rows[i+count]->Cells[3]->Value = this->dei->Input[position].Diadoxos;
					this->ChangedGridView->Rows[i+count]->Cells[4]->Value = this->dei->Input[position].Grafeio;
					this->ChangedGridView->Rows[i+count]->Cells[5]->Value = this->dei->Input[position].TetragonikaMetraDimTelon;
					this->ChangedGridView->Rows[i+count]->Cells[6]->Value = this->dei->Input[position].TetragonikaMetraDimForou;
					this->ChangedGridView->Rows[i+count]->Cells[7]->Value = this->dei->Input[position].TetragvnikaMetraTap;
					int zero=0;
					this->ChangedGridView->Rows[i+count]->Cells[8]->Value = zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[9]->Value = zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[10]->Value = zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[11]->Value =zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[12]->Value =this->dei->Input[position].EtosAdeias;
					this->ChangedGridView->Rows[i+count]->Cells[13]->Value =this->dei->Input[position].KodikosZonisTap;
					this->ChangedGridView->Rows[i+count]->Cells[14]->Value =this->dei->Input[position].DiktisXreosisXrisisTap;
					this->ChangedGridView->Rows[i+count]->Cells[15]->Value =this->dei->Input[position].KodikosDimou;
					this->ChangedGridView->Rows[i+count]->Cells[16]->Value = this->dei->Input[position].TetragonikaMetraDimTelon;
					this->ChangedGridView->Rows[i+count]->Cells[17]->Value = this->dei->Input[position].TetragonikaMetraDimForou;
					this->ChangedGridView->Rows[i+count]->Cells[18]->Value = this->dei->Input[position].TetragvnikaMetraTap;
					this->ChangedGridView->Rows[i+count]->Cells[19]->Value =this->dei->Input[position].EtosAdeias;
					this->ChangedGridView->Rows[i+count]->Cells[20]->Value =zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[21]->Value =zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[22]->Value =zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[23]->Value =zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[24]->Value =this->dei->Input[position].KodikosZonisTap;
					this->ChangedGridView->Rows[i+count]->Cells[25]->Value =this->dei->Input[position].DiktisXreosisXrisisTap;
				}
			}
			
			
		 }

		 //Ενημέρωση του InpudGrid
private: void UpdateInputGrid()
		 {
			 int i;
			 for (i=1;i<dei->TotalInputRecords;i++)
			 {
				 this->InputDataGrid->Rows->Add();
				 this->InputDataGrid->Rows[i-1]->Cells[0]->Value=dei->Input[i].AfxonArithmos;			 
				 this->InputDataGrid->Rows[i-1]->Cells[1]->Value=dei->Input[i].Paroxi;	
				 this->InputDataGrid->Rows[i-1]->Cells[2]->Value=dei->Input[i].Onomateponimo;
				 this->InputDataGrid->Rows[i-1]->Cells[3]->Value=dei->Input[i].Odos;
				 this->InputDataGrid->Rows[i-1]->Cells[4]->Value=dei->Input[i].Arithmos;
				 this->InputDataGrid->Rows[i-1]->Cells[5]->Value=dei->Input[i].Poli;
				 this->InputDataGrid->Rows[i-1]->Cells[6]->Value=dei->Input[i].TaxKodikas;
				 this->InputDataGrid->Rows[i-1]->Cells[7]->Value=dei->Input[i].KodikosDK;
				 this->InputDataGrid->Rows[i-1]->Cells[8]->Value=dei->Input[i].KodikosXreosis;
				 this->InputDataGrid->Rows[i-1]->Cells[9]->Value=dei->Input[i].KodikosApalagis;
				 this->InputDataGrid->Rows[i-1]->Cells[10]->Value=dei->Input[i].TetragonikaMetraDimTelon;
				 this->InputDataGrid->Rows[i-1]->Cells[11]->Value=dei->Input[i].TetragonikaMetraDimForou;
				this->InputDataGrid->Rows[i-1]->Cells[12]->Value=dei->Input[i].KodikosXreosisTap;
				this->InputDataGrid->Rows[i-1]->Cells[13]->Value=dei->Input[i].DiktisXreosisXrisisTap;
				this->InputDataGrid->Rows[i-1]->Cells[14]->Value=dei->Input[i].KodikosApalagisTap;
				this->InputDataGrid->Rows[i-1]->Cells[15]->Value=dei->Input[i].TetragvnikaMetraTap;
				this->InputDataGrid->Rows[i-1]->Cells[16]->Value=dei->Input[i].EtosAdeias;
				this->InputDataGrid->Rows[i-1]->Cells[17]->Value=dei->Input[i].KodikosZonisTap;
				this->InputDataGrid->Rows[i-1]->Cells[18]->Value=dei->Input[i].OnomasiaDimou;
				this->InputDataGrid->Rows[i-1]->Cells[19]->Value=dei->Input[i].KodikosDimou;

					 }

		 }
		 
		//Αντιγραφή εγγραφής στο πίνακα Αλλαγών		 
private: void CopyRecord(int i)
				  {

				   dei->AddChangesRecord(static_cast <int> (this->InputDataGrid->Rows[i]->Cells[0]->Value));

	   			   this->InputDataGrid->Rows->RemoveAt(i);
				  }

		//Αντιγραφή επιλεγμένων εγγραφών στο πίνακα Αλλαγών		 
private: void CopySelectedRecords(void)
				 {
	           
					 for (int k=this->InputDataGrid->SelectedRows->Count-1;k>-1;k--)
					 {
						  CopyRecord(this->InputDataGrid->SelectedRows[k]->Index);
					 }
					 for (int k=this->InputDataGrid->SelectedRows->Count-1;k>-1;k--)
					 {
				
						 this->InputDataGrid->Rows->RemoveAt(k);
					 }
					 this->InputDataGrid->Refresh();

				 }

         //Αντιγραφή στον πίνακα 
private: void CopyOutPutGrid()
		 {

			 if (this->InputDataGrid->SelectedRows->Count<2)
			 {
				int i = this->InputDataGrid->CurrentCell->RowIndex;
				CopyRecord(i);
				this->InputDataGrid->Refresh();
			 }
			 else
			 {  
				this->CopySelectedRecords();
			
			 }
		 }



       
private: System::Void BackTransfer_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
		
        
			if (this->OutputGridView->Rows->Count>0)
			{
			this->InputDataGrid->Rows->Add();
			int i = this->OutputGridView->CurrentCell->RowIndex;
			int j = this->InputDataGrid->Rows->Count-1;
			dei->RemoveChangesRecord(static_cast <int> (this->OutputGridView->Rows[i]->Cells[0]->Value));
			InputDataGrid->Rows[j]->Cells[0]->Value=this->OutputGridView->Rows[i]->Cells[0]->Value;			 
			InputDataGrid->Rows[j]->Cells[1]->Value=this->OutputGridView->Rows[i]->Cells[1]->Value;
			InputDataGrid->Rows[j]->Cells[2]->Value=this->OutputGridView->Rows[i]->Cells[2]->Value;
			InputDataGrid->Rows[j]->Cells[3]->Value=this->OutputGridView->Rows[i]->Cells[3]->Value;
			InputDataGrid->Rows[j]->Cells[4]->Value=this->OutputGridView->Rows[i]->Cells[4]->Value;
			this->OutputGridView->Rows->RemoveAt(i);
			
			}
			

		 }
        

private: System::Void TransferAll_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
		 	 this->InputDataGrid->SelectAll();
			 this->CopySelectedRecords();
			
		 }
		 
private: System::Void NextButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 System::Windows::Forms::DialogResult answer;
			 answer = this->saveFileDialog->ShowDialog();
			 if (answer != System::Windows::Forms::DialogResult::Cancel)
			 if (this->saveFileDialog->FileName->Length>0)
				dei->SaveToFile(this->saveFileDialog->FileName);
	 
		 }

private: void InitializeChangedGridView(void)
		 {
			 ChangedGridView->Columns[0]->DefaultCellStyle->Format = "{0,20}";
			 ChangedGridView->Columns[1]->DefaultCellStyle->Format = "{0,1}";
			 ChangedGridView->Columns[2]->DefaultCellStyle->Format = "{0,8}";
			 ChangedGridView->Columns[3]->DefaultCellStyle->Format = "{0,2}";
			 ChangedGridView->Columns[5]->DefaultCellStyle->Format = "d7";
			 ChangedGridView->Columns[6]->DefaultCellStyle->Format = "d7";
			 ChangedGridView->Columns[7]->DefaultCellStyle->Format = "d7";
			 ChangedGridView->Columns[8]->DefaultCellStyle->Format = "d7";
			 ChangedGridView->Columns[9]->DefaultCellStyle->Format = "d2";
			 ChangedGridView->Columns[10]->DefaultCellStyle->Format = "d7";
 			 ChangedGridView->Columns[11]->DefaultCellStyle->Format = "d2";
			 ChangedGridView->Columns[12]->DefaultCellStyle->Format = "d4";
			 ChangedGridView->Columns[13]->DefaultCellStyle->Format = "d3";
			 ChangedGridView->Columns[14]->DefaultCellStyle->Format = "d1";
 			 ChangedGridView->Columns[15]->DefaultCellStyle->Format = "d4";
		 }


		 

private: void printHtmlfile(String^ FileName)
		 {

				ProcessStartInfo^ p =gcnew(ProcessStartInfo);
				p->Verb = "print";
				p->WindowStyle = ProcessWindowStyle::Minimized;
				p->FileName = FileName;
				p->UseShellExecute = true;
				System::Diagnostics::Process::Start(p);
		 }
    
private: void CreateHtmlReport(String^ FileName)
	 {
		System::IO::TextWriter^ tw; 
		String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
		String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
		
			
			try
				{
				tw   = gcnew StreamWriter(path+"\\"+FileName);
				tw->WriteLine("<!DOCTYPE html>	<head> <meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\"> </head> <html> 	<body> <h2><center><u>ΕΝΤΥΠΟ ΣΥΝΟΛΩΝ ΑΡΧΕΙΟΥ ΜΕΤΑΒΟΛΩΝ</u></center></h2>");
				tw->WriteLine("<table border=\"0\" width=\"100%\">");
				tw->WriteLine("<tr><td><h4>Νομός:"+this->dei->Settings->Region+"</h4></td><td>Ημερομηνία:"+DateTime::Now.ToShortDateString()+ "</td></tr>");
				tw->WriteLine("<tr><td><h4>Δήμος:"+this->dei->Settings->Municipality+"</h4></td><td>Αρ. Πρωτ. ___________</td></tr>");
				tw->WriteLine("<tr><td><h4>Κωδικός Δ/Κ: 4897 </h4></td><td> </td></tr>");
				tw->WriteLine("</table>");
				tw->WriteLine("</br>");
				tw->WriteLine("</br>");
				tw->WriteLine("<table border=\"2\" width=\"100%\">");
				tw->WriteLine("<tr><td>1.</td><td>ΠΛΗΘΟΣ ΕΓΓΡΑΦΩΝ ΑΡΧΕΙΟΥ ΜΕΤΑΒΟΛΩΝ</td><td>"+ this->ChangedGridView->Rows->Count +"</td></tr>");
				tw->WriteLine("<tr><td>2.</td><td>ΠΛΗΘΟΣ ΕΓΓΡΑΦΩΝ ΜΕ ΚΑΘΥΣΤΕΡΟΥΜΕΝΑ (ΔΤ+ΔΦ)</td><td>"+ FindDifferences(8,20) +"</td></tr>");
				tw->WriteLine("<tr><td>3.</td><td>ΣΥΝΟΛΙΚΟ ΠΟΣΟ ΚΑΘΥΣΤΕΡΟΥΜΕΝΩΝ (ΔΤ+ΔΦ)</td><td>"+ this->Total(8) +"</td></tr>");
				tw->WriteLine("<tr><td>4.</td><td>ΔΟΣΕΙΣ ΚΑΘΥΣΤΕΡΟΥΜΕΝΩΝ (ΔΤ+ΔΦ)</td><td>"+ this->Total(9) +"</td></tr>");
				tw->WriteLine("<tr><td>5.</td><td>ΠΛΗΘΟΣ ΕΓΓΡΑΦΩΝ ΜΕ ΚΑΘΥΣΤΕΡΟΥΜΕΝΑ (ΤΑΠ)</td><td>"+ FindDifferences(10,22) +"</td></tr>");
				tw->WriteLine("<tr><td>6.</td><td>ΣΥΝΟΛΙΚΟ ΠΟΣΟ ΚΑΘΥΣΤΕΡΟΥΜΕΝΩΝ (ΤΑΠ)</td><td>"+ this->Total(10) +"</td></tr>");
				tw->WriteLine("<tr><td>7.</td><td>ΔΟΣΕΙΣ ΚΑΘΥΣΤΕΡΟΥΜΕΝΩΝ (ΤΑΠ)</td><td>"+ this->Total(11) +"</td></tr>");
				tw->WriteLine("<tr><td>8.</td><td>ΠΛΗΘΟΣ ΑΛΛΑΓΩΝ ΤΕΤΡΑΓΩΝΙΚΩΝ ΜΕΤΡΩΝ ΣΕ ΔΤ-ΔΦ-ΤΑΠ</td><td>"+(FindDifferences(5,16)+FindDifferences(6,17)+FindDifferences(7,18)).ToString()  +"</td></tr>");
				tw->WriteLine("<tr><td>9.</td><td>ΠΛΗΘΟΣ ΑΛΛΑΓΩΝ ΜΕ ΚΩΔΙΚΟ ΖΩΝΗΣ</td><td>"+ FindDifferences(13,24) +"</td></tr>");
				tw->WriteLine("<tr><td>10.</td><td>ΠΛΗΘΟΣ ΑΛΛΑΓΩΝ ΣΕ ΕΤΟΣ</td><td>"+ FindDifferences(12,19) +"</td></tr>");
				tw->WriteLine("</table>");
				tw->WriteLine("</br>");
				tw->WriteLine("</br>");
				tw->WriteLine("<p><b>Τηλέφωνο Δήμου: "+this->dei->Settings->Telephone+"</b></p>");
				tw->WriteLine("<p><b>Αρμόδιος Υπάλληλος: "+this->dei->Settings->UserName+"</b></p>");
				tw->WriteLine("</br>");
				tw->WriteLine("</br>");
				tw->WriteLine("<p><center>ΘΕΣΗ ΣΦΡΑΓΙΔΑΣ</center></p>");
		
				tw->WriteLine("</body></html>"); 
				   // close the stream
				   tw->Close();
				   
				}
				   catch (System::Exception^ pe)
					{
						System::Windows::Forms::MessageBox::Show("Αδυναμία αποθήκευσης στο αρχείο","Λάθος");
				
					}
				
	 }



		 //Αποστολη πρός τον πίνακα αλλαγών
private: System::Void SendtoChangesbutton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			int i;
			int count=this->ChangedGridView->Rows->Count;
			
			if (this->OutputGridView->Rows->Count>0)
			{
				this->MakeReportButton->Enabled=true;
				this->SaveChangesbutton->Enabled=true;
				this->MassProccessButton->Enabled=true;
				this->SearchNamebutton->Enabled=true;
				this->buttonSearchProvider->Enabled=true;
			
				for (i=0; i<this->OutputGridView->Rows->Count; i++)
				{  
					this->ChangedGridView->Rows->Add();
					this->ChangedGridView->Rows[i+count]->Cells[0]->Value = this->dei->Changes[i].Onomateponimo;
					this->ChangedGridView->Rows[i+count]->Cells[1]->Value = this->dei->Changes[i].Periferia;
					this->ChangedGridView->Rows[i+count]->Cells[2]->Value = this->dei->Changes[i].Paroxi;
					this->ChangedGridView->Rows[i+count]->Cells[3]->Value = this->dei->Changes[i].Diadoxos;
					this->ChangedGridView->Rows[i+count]->Cells[4]->Value = this->dei->Changes[i].Grafeio;
					this->ChangedGridView->Rows[i+count]->Cells[5]->Value = this->dei->Changes[i].TetragonikaMetraDimTelon;
					this->ChangedGridView->Rows[i+count]->Cells[6]->Value = this->dei->Changes[i].TetragonikaMetraDimForou;
					this->ChangedGridView->Rows[i+count]->Cells[7]->Value = this->dei->Changes[i].TetragvnikaMetraTap;
					int zero=0;
					this->ChangedGridView->Rows[i+count]->Cells[8]->Value = zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[9]->Value = zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[10]->Value = zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[11]->Value =zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[12]->Value =this->dei->Changes[i].EtosAdeias;
					this->ChangedGridView->Rows[i+count]->Cells[13]->Value =this->dei->Changes[i].KodikosZonisTap;
					this->ChangedGridView->Rows[i+count]->Cells[14]->Value =this->dei->Changes[i].DiktisXreosisXrisisTap;
					this->ChangedGridView->Rows[i+count]->Cells[15]->Value =this->dei->Changes[i].KodikosDimou;
					this->ChangedGridView->Rows[i+count]->Cells[16]->Value = this->dei->Changes[i].TetragonikaMetraDimTelon;
					this->ChangedGridView->Rows[i+count]->Cells[17]->Value = this->dei->Changes[i].TetragonikaMetraDimForou;
					this->ChangedGridView->Rows[i+count]->Cells[18]->Value = this->dei->Changes[i].TetragvnikaMetraTap;
					this->ChangedGridView->Rows[i+count]->Cells[19]->Value =this->dei->Changes[i].EtosAdeias;
					this->ChangedGridView->Rows[i+count]->Cells[20]->Value =zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[21]->Value =zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[22]->Value =zero.ToString("0000000");
					this->ChangedGridView->Rows[i+count]->Cells[23]->Value =zero.ToString("00");
					this->ChangedGridView->Rows[i+count]->Cells[24]->Value =this->dei->Changes[i].KodikosZonisTap;
					this->ChangedGridView->Rows[i+count]->Cells[25]->Value =this->dei->Changes[i].DiktisXreosisXrisisTap;
				}
			}
		 }

		 //Αποθήκευση Αλαγών
private: int SaveChanges(System::String^ FileName)
		 {	
			 int i=0;
			 StreamWriter^ sw;
			 FileStream^ fs;
			 try 
			 {
				 if (File::Exists(FileName)) 
					 File::Delete(FileName);
				 fs = gcnew FileStream(FileName,System::IO::FileMode::CreateNew);
				 sw = gcnew StreamWriter(fs,System::Text::Encoding::UTF8);
				 sw->WriteLine("TMP");
				 for (i=0;i<this->ChangedGridView->Rows->Count;i++)
				 {
					sw->WriteLine("{0,20}",this->ChangedGridView->Rows[i]->Cells[0]->Value->ToString());
					sw->WriteLine("{0,1}",this->ChangedGridView->Rows[i]->Cells[1]->Value->ToString());
					sw->WriteLine("{0,8}",this->ChangedGridView->Rows[i]->Cells[2]->Value->ToString());
					sw->WriteLine("{0,2}",this->ChangedGridView->Rows[i]->Cells[3]->Value->ToString());
					sw->WriteLine("{0,2}",this->ChangedGridView->Rows[i]->Cells[4]->Value->ToString());
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[5]->Value->ToString());//->Format("D7"),
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[6]->Value->ToString());//->Format("D7"),
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[7]->Value->ToString());
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[8]->Value->ToString());
					sw->WriteLine("{0,2:D}",this->ChangedGridView->Rows[i]->Cells[9]->Value->ToString());
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[10]->Value->ToString());
					sw->WriteLine("{0,2:D}",this->ChangedGridView->Rows[i]->Cells[11]->Value->ToString());
					sw->WriteLine("{0,4:D}",this->ChangedGridView->Rows[i]->Cells[12]->Value->ToString());
					sw->WriteLine("{0,3:D}",this->ChangedGridView->Rows[i]->Cells[13]->Value->ToString());
					sw->WriteLine("{0,1:D}",this->ChangedGridView->Rows[i]->Cells[14]->Value->ToString());
					sw->WriteLine("{0,4}",this->ChangedGridView->Rows[i]->Cells[15]->Value->ToString());//->Format("{0-4}"));
					
					//---------------------------------------------------------------------------------//
					//-----------------Αρχικές τιμές των τελών και του έτους άδειας --------------------//
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[16]->Value->ToString());//->Format("D7"),
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[17]->Value->ToString());//->Format("D7"),
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[18]->Value->ToString());
					sw->WriteLine("{0,4:D}",this->ChangedGridView->Rows[i]->Cells[19]->Value->ToString());
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[8]->Value->ToString());
					sw->WriteLine("{0,2:D}",this->ChangedGridView->Rows[i]->Cells[9]->Value->ToString());
					sw->WriteLine("{0,7:D}",this->ChangedGridView->Rows[i]->Cells[10]->Value->ToString());
					sw->WriteLine("{0,2:D}",this->ChangedGridView->Rows[i]->Cells[11]->Value->ToString());
					sw->WriteLine("{0,4:D}",this->ChangedGridView->Rows[i]->Cells[13]->Value->ToString());
					sw->WriteLine("{0,1:D}",this->ChangedGridView->Rows[i]->Cells[14]->Value->ToString());
						
		}		
	
	}
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία αποθήκευσης στο αρχείο","Λάθος");
			return -1;
		}
		sw->Close();
		System::Windows::Forms::MessageBox::Show("Επιτυχής Αποθήκευση Αρχείου");
return 0;
}

	//Εύρεση αλλαγών
private: int FindDifferences(int current, int original)
		 {
			 int diff=0;
			 for  (int i=0; i<this->ChangedGridView->Rows->Count; i++)
				 if (Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[current]->Value) != Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[original]->Value))
					 diff++;
			 return diff;
		 }

	
		 //Εύρεση συνόλου
private: int Total(int column)
		 {
			 int total=0;
			 for (int i=0; i<this->ChangedGridView->Rows->Count; i++)
				 total=total+Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[column]->Value);
		     return total;
		 }
			 
	
		 //Αντικατάσταση κενών με 0
private: System::String^ FormatNumber(System::String^ in)
		 { 
			 System::String^ out;
			 out=in->Replace(" ","0");
			 return out;
		 }
	
		 //Πρόσθεση μηδενικών σε αριθμό
private: System::String^ AddZerosToNumber(System::String^ in,int TotalLength)
		 { 
			 System::String^ out;
			 for (int i=0;i<TotalLength-in->Length;i++)
				 out=out+"0";
			 out=out+in;
			 return out;
		 }

		 //Ανάγνωση αλλαγών απο αρχείο
private: int LoadChanges(System::String^ FileName)
		 {	
			 String^ FileType; 
			 int i=0;
			 StreamReader^ sr;
			 FileStream^ fs;
			 
			 //this->ClearDataGrids();
			 try 
			 {
				 
				 fs= gcnew FileStream(FileName,System::IO::FileMode::Open);
				 sr = gcnew StreamReader(fs,System::Text::Encoding::UTF8);
				 FileType=sr->ReadLine();
				 if (FileType=="TMP")
				 {
					 while  (!sr->EndOfStream)				
					 {	 this->ChangedGridView->Rows->Add();
					     this-> ChangedGridView->Rows[i]->Cells[0]->Value=sr->ReadLine();
						 this->ChangedGridView->Rows[i]->Cells[1]->Value=sr->ReadLine();
						 this->ChangedGridView->Rows[i]->Cells[2]->Value=sr->ReadLine();
						 this->ChangedGridView->Rows[i]->Cells[3]->Value=sr->ReadLine();
						 this->ChangedGridView->Rows[i]->Cells[4]->Value=sr->ReadLine();
						 this->ChangedGridView->Rows[i]->Cells[5]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[6]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[7]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[8]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[9]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[10]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[11]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[12]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[13]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[14]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[15]->Value=sr->ReadLine();
						 //---------------------------------------------------------------------------------//
					     //-----------------Αρχικές τιμές των τελών και του έτους άδειας --------------------//
						 this->ChangedGridView->Rows[i]->Cells[16]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[17]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[18]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[19]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[20]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[21]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[22]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[23]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[24]->Value=FormatNumber(sr->ReadLine());
						 this->ChangedGridView->Rows[i]->Cells[25]->Value=FormatNumber(sr->ReadLine());
						 i++;
				}		
			 }
			 else
			 {
			  System::Windows::Forms::MessageBox::Show("Το αρχείο δεν είναι της αναμενόμενης μορφοποίησης","Λάθος");
			
			  this->TransferButton->Enabled=false;
			  return -1;
			 }
		 }
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία ανάγνωσης από αρχείο","Λάθος");
			
			this->TransferButton->Enabled=false;
			return -1;
		}
		sr->Close();
		System::Windows::Forms::MessageBox::Show("Επιτυχής ανάγνωση Αρχείου");
		return 0;

}

		 //Αποθήκευση Αλλαγών κουμπί
private: System::Void SaveChangesbutton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
             if (ChangedGridView->Rows->Count>0)
			 {
			 System::Windows::Forms::DialogResult result=this->saveFileDialog->ShowDialog(); 
			 if (result!=System::Windows::Forms::DialogResult::Cancel)
				 this->SaveChanges(this->saveFileDialog->FileName);
			 }else
				 System::Windows::Forms::MessageBox::Show("Λάθος! Δεν υπάρχουν εγγραφές για αποθήκευση");
		 }


private: System::Void UpdateButtons(System::Void)
		 {
			 if (this->ChangedGridView->RowCount >0)
					{
						this->MakeReportButton->Enabled=true;
						this->SaveChangesbutton->Enabled=true;
						this->MassProccessButton->Enabled=true;
						this->buttonPrintReport->Enabled =true;
					}
					else{
						this->MakeReportButton->Enabled=false;
						this->SaveChangesbutton->Enabled=false;
						this->MassProccessButton->Enabled=false;
						this->buttonPrintReport->Enabled =false;
					}


					if (this->InputDataGrid->RowCount >0)
					{
						this->SearchNamebutton->Enabled=true;
						this->buttonSearchProvider->Enabled=true;
						this->MassSearchbutton->Enabled =true;
					}
					else{
						this->SearchNamebutton->Enabled=false;
						this->buttonSearchProvider->Enabled=false;
						this->MassSearchbutton->Enabled =false;
					}
		 }

		 //Ανάγνωση Αλλαγών κουμπί
private: System::Void InputFromFilebutton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			// this->ClearDataGrids();

			 System::Windows::Forms::DialogResult result = this->openFileDialog->ShowDialog();
			 if (result!=System::Windows::Forms::DialogResult::Cancel)
			 {
				 if (this->LoadChanges(this->openFileDialog->FileName)>-1);
				
			 }
			  UpdateButtons();
		 }


		 //Συνάρτηση που ελέγχει έαν όλες οι εγγραφές είναι απο το ίδιο χωρίο
private: bool IsFromSingleRegion(void)
		 {
			//Αυτη η συνάρτηση χρησιμοποιήθηκε σε παλαιότερες εκδόσεις
			 return true;
	    }

		 
		 //Δημιουργεία αναφοράς κουμπί
private: System::Void buttonMakeReport_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (IsFromSingleRegion())
			 {
				 System::Windows::Forms::DialogResult result= this->saveFileDialog->ShowDialog(); 
				 if (result !=System::Windows::Forms::DialogResult::Cancel)
				 {
					 if  (this->saveFileDialog->FileName->Length>0)
					 {
						 this->SaveReport(this->saveFileDialog->FileName);						
					 }
					 else
						System::Windows::Forms::MessageBox::Show("Παρακαλώ δώστε ένα όνομα αρχείου και ξαναπροσπαθήστε");
			     }
			 }
			 else
				 System::Windows::Forms::MessageBox::Show("Οι μεταβολές δεν είναι απο μία περιοχή παρακαλώ διορθώστε"); 
		 
		 }

		 //Συνάρτηση που αποθηκεύει 
		 private: void AppendLogFile(System::String^ FileName)
				  {
					  String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
					  String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
					  FileStream^ fs;
					  DateTime dt = DateTime::Now;

					   if (! File::Exists( path+"\\"+ FileName)) 
					   		 fs = gcnew FileStream(FileName,System::IO::FileMode::CreateNew);
				
					    
					   StreamWriter^ sw = File::AppendText( path+"\\"+ FileName );
					  
   				       sw->WriteLine("______________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
				       sw->WriteLine("                                                     Νέες Τιμές                                                                     |                            Αρχικές Τιμές                                    |    Μεταβολή       ");
					   sw->WriteLine("Ονοματεπώνυμο        ΠΕΡ.   ΠΑΡΟΧΗ               m2 ΔΤ     m2 ΔΦ    m2 ΤΑΠ   Αναδ.ΔΤ-ΔΦ Δόσ  Αναδ.ΤΑΠ  Δοσ  Ετος Αδειας Κ.Ζ. Κωδ.Δημ  m2 ΔΤ    m2 ΔΦ    m2 ΤΑΠ  Ετος Αδ Αναδ.ΔΤ-ΔΦ Δόσ  Αναδ.ΤΑΠ  Δοσ        Κ.Ζ. Ημερομηνία Μεταβολής");
   				       sw->WriteLine("______________________________________________________________________________________________________________________________________________________________________________________________________________________________________");

						int i;
					   try
					   {
						  for (i=0;i<this->ChangedGridView->Rows->Count;i++)
							 {
								 sw->Write("{0,20},{1,2}",this->ChangedGridView->Rows[i]->Cells[0]->Value->ToString()," ");
								sw->Write("{0,1},{1,2}",this->ChangedGridView->Rows[i]->Cells[1]->Value->ToString()," ");
								sw->Write("{0,8},{1,2}",this->ChangedGridView->Rows[i]->Cells[2]->Value->ToString()," ");
								sw->Write("{0,2},{1,2}",this->ChangedGridView->Rows[i]->Cells[3]->Value->ToString()," ");
								sw->Write("{0,2},{1,2}",this->ChangedGridView->Rows[i]->Cells[4]->Value->ToString()," ");
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[5]->Value->ToString()," ");//->Format("D7"),
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[6]->Value->ToString()," ");//->Format("D7"),
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[7]->Value->ToString()," ");
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[8]->Value->ToString()," ");
								sw->Write("{0,2:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[9]->Value->ToString()," ");
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[10]->Value->ToString()," ");
								sw->Write("{0,2:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[11]->Value->ToString()," ");
								sw->Write("{0,4:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[12]->Value->ToString()," ");
								sw->Write("{0,3:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[13]->Value->ToString()," ");
								sw->Write("{0,1:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[14]->Value->ToString()," ");
								sw->Write("{0,4},{1,2}",this->ChangedGridView->Rows[i]->Cells[15]->Value->ToString()," ");//->Format("{0-4}"));
					
								//---------------------------------------------------------------------------------//
								//-----------------Αρχικές τιμές των τελών και του έτους άδειας --------------------//
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[16]->Value->ToString()," ");//->Format("D7"),
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[17]->Value->ToString()," ");//->Format("D7"),
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[18]->Value->ToString()," ");
								sw->Write("{0,4:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[19]->Value->ToString()," ");
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[8]->Value->ToString()," ");
								sw->Write("{0,2:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[9]->Value->ToString()," ");
								sw->Write("{0,7:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[10]->Value->ToString()," ");
								sw->Write("{0,2:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[11]->Value->ToString()," ");
								sw->Write("{0,4:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[13]->Value->ToString()," ");
								sw->Write("{0,1:D},{1,2}",this->ChangedGridView->Rows[i]->Cells[14]->Value->ToString()," ");
								sw->WriteLine("{0,20}",dt);
						  }		
					   }
					   finally
					   {
						  if ( sw )
							 delete (IDisposable^)sw;
					   }
				  }

		 //Συνάρτηση που αποθηκεύει την αναφορά
		 private: int SaveReport(System::String^ FileName)
		 {
			 int i;
			 StreamWriter^ sw;
			 FileStream^ fs;
			 try 
			 {
				 if (File::Exists(FileName)) 
					 File::Delete(FileName);
				 fs = gcnew FileStream(FileName,System::IO::FileMode::CreateNew);
				 sw = gcnew StreamWriter(fs);
				 sw->WriteLine("{0,2}{1,2}{2,2}{3,2}{4,54}", "01",
					 this->AddZerosToNumber(System::DateTime::Now.Day.ToString(),2),
					 this->AddZerosToNumber(System::DateTime::Now.Month.ToString(),2),
					 this->AddZerosToNumber(System::DateTime::Now.Year.ToString(),4), 
					 "000000000000000000000000000000000000000000000000000000");
				 for (i=0;i<this->ChangedGridView->Rows->Count;i++)
				 {
                    
					 sw->WriteLine("{0,1}{1,8}{2,2}{3,2}{4,7}{5,7}{6,7}{7,7}{8,2}{9,7}{10,2}{11,4}{12,3}{13,1}{14,4}",
						this->ChangedGridView->Rows[i]->Cells[1]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[2]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[3]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[4]->Value->ToString(),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[5]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[6]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[7]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[8]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[9]->Value->ToString(),2),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[10]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[11]->Value->ToString(),2),
						this->ChangedGridView->Rows[i]->Cells[12]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[13]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[14]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[15]->Value->ToString()
						);
				 }

			 sw->WriteLine("{0,2}{1,8}{2,50}{3,4}", "99",this->AddZerosToNumber((this->ChangedGridView->Rows->Count).ToString(),8), "00000000000000000000000000000000000000000000000000",this->ChangedGridView->Rows[0]->Cells[15]->Value->ToString());	
		}		
	
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία αποθήκευσης της αναφοράς ","Λάθος");
			return -1;
		}
		
		sw->Close();
		System::Windows::Forms::MessageBox::Show("Επιτυχής Αποθήκευση Αρχείου");
		AppendLogFile("Report.txt");
		System::Windows::Forms::DialogResult answer =	 System::Windows::Forms::MessageBox::Show("Θέλετε να ενημερώσετε το αρχικό πίνακα?","Ενημέρωση δεδομένων",System::Windows::Forms::MessageBoxButtons::YesNo);
		if (answer == System::Windows::Forms::DialogResult::Yes)
			UpdateOriginalData();
		return 0;
				  }
				


private: void UpdateSingeData(int index)
		 { 
		 int count;
		 bool found =false;
		 InputData inputRec;
		
		  for (count =1; count< dei->TotalInputRecords; count++)
		  {
			  int len= ChangedGridView->Rows[index]->Cells[2]->Value->ToString()->Length;
		      if (len > dei->Input[count].Paroxi->Length) 
				  len = dei->Input[count].Paroxi->Length; 

			
		   if (this->ChangedGridView->Rows[index]->Cells[2]->Value->ToString()->Substring(0,len) == dei->Input[count].Paroxi->Substring(0,len))
		   {
			   inputRec = dei->Input[count];
			   inputRec.TetragonikaMetraDimForou= this->AddZerosToNumber(this->ChangedGridView->Rows[index]->Cells[6]->Value->ToString(),7);
			   inputRec.TetragonikaMetraDimTelon= this->AddZerosToNumber(this->ChangedGridView->Rows[index]->Cells[5]->Value->ToString(),7);
			   inputRec.TetragvnikaMetraTap= this->AddZerosToNumber(this->ChangedGridView->Rows[index]->Cells[7]->Value->ToString(),7);
			   inputRec.EtosAdeias= this->AddZerosToNumber(this->ChangedGridView->Rows[index]->Cells[12]->Value->ToString(),4);
  			   dei->UpdateInputRecord(count,inputRec);
			   break;
			}       
		  }
		 }



private: void UpdateOriginalData(void)
		 { 
		 int count=0;
		  bool found =false;
		  for (count =0; count<this->ChangedGridView->RowCount; count++)
			  UpdateSingeData(count);
		   this->InputDataGrid->Refresh();
		    
		 }       
				  //Αναζήτηση κατά όνομα 
private: int SearchName(int Start)
		 {
			 int count=Start;
				 //this->InputDataGrid->CurrentRow->Index+1;
			 bool found =false;
			 
			 if ((this->SearchBox->Text->Length>0) && (this->InputDataGrid->Rows->Count>1))
			 {
				 int exeeds = this->InputDataGrid->Rows[count]->Cells[2]->Value->ToString()->Length - this->SearchBox->Text->Length; 
				 if  (exeeds < 0)
					 this->SearchBox->Text=this->SearchBox->Text->Substring(0,this->SearchBox->Text->Length+exeeds);

				 do {
					  	 if (this->InputDataGrid->Rows[count]->Cells[2]->Value->ToString()->Substring(0,this->SearchBox->Text->Length)==this->SearchBox->Text)
							 found =true;
						 else
							 count++;
					 

				 }while ((count<=this->InputDataGrid->Rows->Count-1) && (found==false));

			 }

			 
			 if (found) 
				 return count;
			 else
				 return -1;
		 }

		 //Αναζήτηση κατά όνομα κουμπί
private: System::Void buttonSearchName_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
		 
			 int count;
			 bool found=false;
			 
			 if (this->SearchBox->Text->Length<=0)
			 {
				  System::Windows::Forms::MessageBox::Show("Παρακαλώ δώστε κάποια συμβολοσειρά για αναζήτηση","Αναζήτηση");
				  return;
			 }

			 count = SearchName(this->InputDataGrid->CurrentRow->Index+1);
			 if (count >-1)
			 {
				 this->InputDataGrid->FirstDisplayedScrollingRowIndex = this->InputDataGrid->Rows[count]->Index;
				 this->InputDataGrid->Refresh();
				 this->InputDataGrid->CurrentCell = this->InputDataGrid->Rows[count]->Cells[2];
				 this->InputDataGrid->Rows[count]->Selected = true;
			 }				
			 else
			 {
				 this->InputDataGrid->Rows[0]->Selected;
				 System::Windows::Forms::DialogResult answer =	 System::Windows::Forms::MessageBox::Show("Η αναζήτηση έφτασε στο τέλος των εγγραφών. θέλετε η αναζήτηση να συνεχιστεί απο την αρχή?","Αναζήτηση",System::Windows::Forms::MessageBoxButtons::YesNo);
				 if ((answer == System::Windows::Forms::DialogResult::Yes) || (answer == System::Windows::Forms::DialogResult::None))
					  {
						  count = SearchName(0);
						  if (count >-1)
							 {
								 this->InputDataGrid->FirstDisplayedScrollingRowIndex = this->InputDataGrid->Rows[count]->Index;
								 this->InputDataGrid->Refresh();
								 this->InputDataGrid->CurrentCell = this->InputDataGrid->Rows[count]->Cells[2];
								 this->InputDataGrid->Rows[count]->Selected = true;
							 }	
						  else
						  System::Windows::Forms::MessageBox::Show("Η αναζήτηση δεν βρήκε εγγραφές  στο τέλος των εγγραφών. θέλετε η αναζήτηση να συνεχιστεί απο την αρχή?","Αναζήτηση",System::Windows::Forms::MessageBoxButtons::YesNo);
					}
	  
			 }
			 		 

		 }

		 //Εύρεση καταναλωτή (παροχή)
private: int SearchProvider(int Start)
		 {
			 int count=Start;
			 //this->InputDataGrid->CurrentRow->Index+1;
			 bool found =false;
			 
			 if ((this->textBoxProvider->Text->Length>0) && (this->InputDataGrid->Rows->Count>1))
			 {
				 int exeeds = this->InputDataGrid->Rows[count]->Cells[1]->Value->ToString()->Length - this->textBoxProvider->Text->Length; 
				 if  (exeeds < 0)
					 this->textBoxProvider->Text=this->textBoxProvider->Text->Substring(0,this->textBoxProvider->Text->Length+exeeds);

				 do {
					  	 if (this->InputDataGrid->Rows[count]->Cells[1]->Value->ToString()->Substring(0,this->textBoxProvider->Text->Length)==this->textBoxProvider->Text)
							 found =true;
						 else
							 count++;
					 

				 }while ((count<=this->InputDataGrid->Rows->Count-1) && (found==false));

			 }
			 
			 if (found) 
				 return count;
			 else
				 return -1;
		 }

		 //Εύρεση καταναλωτή κουμπί (ονοματεπώνυμο)
private: System::Void buttonSearchProvider_Click(System::Object^  sender, System::EventArgs^  e) {
			 int count;
			 bool found=false;
			 if (this->textBoxProvider->Text->Length<=0)
			 {
				  System::Windows::Forms::MessageBox::Show("Παρακαλώ δώστε κάποια συμβολοσειρά για αναζήτηση","Αναζήτηση");
				  return;
			 }

			 count = SearchProvider(this->InputDataGrid->CurrentRow->Index+1);
			 if (count >-1)
			 {
				 this->InputDataGrid->FirstDisplayedScrollingRowIndex = this->InputDataGrid->Rows[count]->Index;
				 this->InputDataGrid->Refresh();
				 this->InputDataGrid->CurrentCell = this->InputDataGrid->Rows[count]->Cells[1];
				 this->InputDataGrid->Rows[count]->Selected = true;
				// this->InputDataGrid->CurrentRow=count;
			 }				
			 else
			 {
				 this->InputDataGrid->Rows[0]->Selected;
				 System::Windows::Forms::DialogResult answer =	 System::Windows::Forms::MessageBox::Show("Η αναζήτηση έφτασε στο τέλος των εγγραφών. θέλετε η αναζήτηση να συνεχιστεί απο την αρχή?","Αναζήτηση",System::Windows::Forms::MessageBoxButtons::YesNo);
				 if ((answer == System::Windows::Forms::DialogResult::Yes) || (answer == System::Windows::Forms::DialogResult::None))
					  {
						  count = SearchProvider(0);
						  if (count >-1)
							 {
								 this->InputDataGrid->FirstDisplayedScrollingRowIndex = this->InputDataGrid->Rows[count]->Index;
								 this->InputDataGrid->Refresh();
								 this->InputDataGrid->CurrentCell = this->InputDataGrid->Rows[count]->Cells[1];
								 this->InputDataGrid->Rows[count]->Selected = true;
								// this->InputDataGrid->CurrentRow=count;
							 }	
						  else
						  System::Windows::Forms::MessageBox::Show("Η αναζήτηση δεν βρήκε εγγραφές  στο τέλος των εγγραφών. θέλετε η αναζήτηση να συνεχιστεί απο την αρχή?","Αναζήτηση",System::Windows::Forms::MessageBoxButtons::YesNo);
				 }
	  
			 }
			     
		 }


		 //Εκτύπωση της αναφοράς
private: System::Void buttonPrintReport_Click(System::Object^  sender, System::EventArgs^  e) {
			  String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
			  String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
			 if (this->ChangedGridView->Rows->Count>0)
				if (IsFromSingleRegion())
				{
					this->dei->ReadSettings("Settings.xml");
					this->CreateHtmlReport("Report.htm");  
			
					this-> printHtmlfile(path+"\\"+"Report.htm");
				}
				else
					System::Windows::Forms::MessageBox::Show("Υπάρχουν πάνω από ένα χωριό στην αναφορά");
			 else
				 System::Windows::Forms::MessageBox::Show("Δεν υπάρχουν εγγραφές στην αναφορά");

		 }

		 
		 //Αλλαγή ρυθμίσεων  
private: System::Void buttonSettings_Click(System::Object^  sender, System::EventArgs^  e) {
			 Settings^ UserSettings = gcnew Settings;
			 UserSettings->Show();
		 }


		 //Μηδένισμα του ΤΑΠ
private: void NullTAP(void){
					  for (int i=0;i<this->ChangedGridView->Rows->Count;i++)
					  { 
						  this->ChangedGridView->Rows[i]->Cells[7]->Value=0;
					  }

		 }
		 //Εύρευση του μεγαλύτερου απο τα Δημοτικά Τέλη και Δημοτικό Φόρο και 
		 //αντικατάσταση των δημοτικών τελών - φόρων με το μέγιστο
private: void DTEqualDF(void){
					for (int i=0;i<this->ChangedGridView->Rows->Count;i++)
					  {
						  int max = Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[5]->Value);
						  if (Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[6]->Value) >max)
							  max=Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[6]->Value);
						  this->ChangedGridView->Rows[i]->Cells[5]->Value=max;
						 this->ChangedGridView->Rows[i]->Cells[6]->Value=max;
					  }
		 }

		//Εύρευση του μεγαλύτερου απο τα Δημοτικά Τέλη και Δημοτικό Φόρο και ΤΑΠ και 
		//αντικατάσταση των δημοτικών τελών - φόρων-ΤΑΠ με το μέγιστο από αυτά
private: void DTEqualDFEqualTAP(void){
					for (int i=0;i<this->ChangedGridView->Rows->Count;i++)
					  {
						  int max = Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[5]->Value);
						  if (Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[6]->Value) >max)
							  max=Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[6]->Value);
						   if (Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[7]->Value)>max)
							  max=Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[7]->Value);
						  this->ChangedGridView->Rows[i]->Cells[5]->Value=max;
						 this->ChangedGridView->Rows[i]->Cells[6]->Value=max;
						  this->ChangedGridView->Rows[i]->Cells[7]->Value=max;
					  }
		 }

private: void DTEqualDFEqualTAPEqualDT(void){
					for (int i=0;i<this->ChangedGridView->Rows->Count;i++)
					  {
						  int value = Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[5]->Value);
						  this->ChangedGridView->Rows[i]->Cells[6]->Value=value;
						  this->ChangedGridView->Rows[i]->Cells[7]->Value=value;
					  }
		 }

		 //Εύρευση του μέσου απο τα Δημοτικά Τέλη και Δημοτικό Φόρο και ΤΑΠ  σε περίπτωση μη μεδενικών και 
		 //αντικατάσταση του ΤΑΠ με το μέσο. 
private: void DTEqualDFEqualTAPEqualMean(void){
					
					int sum;
					int value;
					int total;
					for (int i=0;i<this->ChangedGridView->Rows->Count;i++)
					  {
						  total=0;
						  sum=0;
						  for (int j=5;j<=7;j++)
						  {
							  value = Convert::ToInt32(this->ChangedGridView->Rows[i]->Cells[j]->Value);
							  if (value>0)
							  {  
								  sum = sum + value;
								  total++;
							  }
						  }

						  if (total>0)
						  	this->ChangedGridView->Rows[i]->Cells[7]->Value=sum/total;
						  else
							this->ChangedGridView->Rows[i]->Cells[7]->Value=0;
					  }
		 }

private: System::Void MassProccessButton_Click(System::Object^  sender, System::EventArgs^  e) {
       
		if (ChangedGridView->Rows->Count>0)
		{
			 MassProccessForm^ ProccessForm= gcnew MassProccessForm(massproccess);
			 if (ProccessForm->ShowDialog()==System::Windows::Forms::DialogResult::OK)
			 if (*massproccess>=10000)
				 DTEqualDFEqualTAPEqualDT();
					*massproccess = *massproccess - 10000;
             if (*massproccess>=1000)
				 DTEqualDFEqualTAPEqualMean();
					*massproccess = *massproccess - 1000;
		     if (*massproccess>=100)
				{
					DTEqualDFEqualTAP();
					*massproccess = *massproccess - 100;
			    }
			 if (*massproccess>=10)
				{
					 DTEqualDF();
					*massproccess = *massproccess - 10;
			    }
			 if (*massproccess>0)
					 NullTAP();

			 }else
				 System::Windows::Forms::MessageBox::Show("Δεν υπάρχουν εγγραφές για μαζική επεξεργασία","Λάθος");
				
	 }
		 

private: System::Void MassSearchbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 int Result =0;
			 MassProccessSearchForm^ ProccessForm= gcnew MassProccessSearchForm(0, "", "" );
			 


			 if (ProccessForm->ShowDialog()==System::Windows::Forms::DialogResult::OK){
				Result =ProccessForm->Result;
				String^ diamerisma = ProccessForm->diamerisma;
				String^ ZoneCode = ProccessForm->ZoneCode;
			 
            
				 if (Result>=100000  )
				{
					
					Result = Result - 100000;
					FindDKandCodeZone(diamerisma ,ZoneCode);
			    }

			if (Result>=10000)
				{
					FindNullDF();
					Result = Result - 10000;
			    }

			if (Result>=1000)
				{
					FindNullDT();
					Result = Result - 1000;
			    }

			if (Result>=100)
				{
					FindDTEqualDFEqualTAP();
					Result = Result - 100;
			    }
			 
			if (Result>=10)
				{
					 FindDTEqualDF();
					Result = Result - 10;
			    }
			 
			 if (Result>0)
					 FindNullTAP();
		 }
		 }
		 
 private: void FindDKandCodeZone(String^ diamerisma, String^ ZoneKode)
		 {
			 int i;
			 for (i=0;i<this->InputDataGrid->RowCount;i++)
				 {
					 
					 if ((this->InputDataGrid->Rows[i]->Cells["cKodikosDK"]->Value->ToString()==diamerisma) && (this->InputDataGrid->Rows[i]->Cells["cCodeZone"]->Value->ToString()==ZoneKode)) 
					 InputDataGrid->Rows[i]->Selected=true;
				 }
		 }

private: void FindNullDT(void)
		 {
			 int i;
			 for (i=0;i<this->InputDataGrid->RowCount;i++)
				 {
					 
					 if (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["TetragonikaMetraDimTelon"]->Value->ToString())==0) 
					 InputDataGrid->Rows[i]->Selected=true;
				 }
		 }

private: void FindNullDF(void)
		 {
					 int i;
					 for (i=0;i<this->InputDataGrid->RowCount;i++)
					 {
						 if (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragonikaMetraDimForou"]->Value->ToString())==0) 
							 InputDataGrid->Rows[i]->Selected=true;

					 }

		 }


private: void FindNullTAP(void)
		 {
					 int i;
					 for (i=0;i<this->InputDataGrid->RowCount;i++)
					 {
						 if (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragvnikaMetraTap"]->Value->ToString())==0) 
							 InputDataGrid->Rows[i]->Selected=true;

					 }

		 }

private: void FindDTEqualDF(void)
		 {
					int i;
					for (i=0;i<this->InputDataGrid->RowCount;i++)
					 {
						 if (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragonikaMetraDimForou"]->Value->ToString())!=Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["TetragonikaMetraDimTelon"]->Value->ToString())) 
							 InputDataGrid->Rows[i]->Selected=true;

					 }
		 }

private: void FindDTEqualDFEqualTAP(void)
		 {
					int i;
					for (i=0;i<this->InputDataGrid->RowCount;i++)
					 {
						 if (
							 (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragonikaMetraDimForou"]->Value->ToString())!=Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["TetragonikaMetraDimTelon"]->Value->ToString()))  
							 || 
							 (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragonikaMetraDimForou"]->Value->ToString())!=Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragvnikaMetraTap"]->Value->ToString()))  
							 || 
							 (Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["TetragonikaMetraDimTelon"]->Value->ToString())!=Convert::ToInt32(this->InputDataGrid->Rows[i]->Cells["cTetragvnikaMetraTap"]->Value->ToString())))
						 this->InputDataGrid->Rows[i]->Selected=true;

					 }
		 }


		 //Η κεντρική  φόρμα κλίνει
 private: System::Void FormIsClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	 {
		dei->Settings->MaxRecords=dei->size;
		dei->SaveData();
		dei->SaveSettings();
	
		
	};
};
};