#pragma once

#include "Dei.h"

namespace teli_dei {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

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
		 
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Button^  TransferAllButton;
	private: System::Windows::Forms::Button^  BackTransferButton;

	private: System::Windows::Forms::Button^  SaveButton;
	public:  Dei^ dei;
	public:  Settings CurrentSettings;

	private: System::Windows::Forms::DataGridView^  InputDataGrid;
	private: System::Windows::Forms::DataGridView^  OutputGridView;


	private: System::Windows::Forms::Button^  SendtoChangesbutton;

	private: System::Windows::Forms::DataGridView^  ChangedGridView;


	private: System::Windows::Forms::Button^  SaveChangesbutton;

	private: System::Windows::Forms::Button^  InputFromFilebutton;

	private: System::Windows::Forms::Button^  MakeReportButton;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  SearchBox;
	private: System::Windows::Forms::Button^  Serachbutton;

	private: System::Windows::Forms::Form^ SettingsForm;

	private: System::Windows::Forms::Label^  labelMunicipality;
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




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Arithmos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  iProviderNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FirstAndLastName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Poli;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TetragonikaMetraDimTelon;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxAithmos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ProviderNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxPoli;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxMetra;
	private: System::Windows::Forms::Button^  buttonSearchProvider;
	private: System::Windows::Forms::TextBox^  textBoxProvider;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label4;


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
			this->TransferAllButton = (gcnew System::Windows::Forms::Button());
			this->BackTransferButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->InputDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Arithmos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->iProviderNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FirstAndLastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Poli = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TetragonikaMetraDimTelon = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OutputGridView = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxAithmos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProviderNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxPoli = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxMetra = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SendtoChangesbutton = (gcnew System::Windows::Forms::Button());
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
			this->SaveChangesbutton = (gcnew System::Windows::Forms::Button());
			this->InputFromFilebutton = (gcnew System::Windows::Forms::Button());
			this->MakeReportButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SearchBox = (gcnew System::Windows::Forms::TextBox());
			this->Serachbutton = (gcnew System::Windows::Forms::Button());
			this->labelMunicipality = (gcnew System::Windows::Forms::Label());
			this->buttonSearchProvider = (gcnew System::Windows::Forms::Button());
			this->textBoxProvider = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OutputGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ChangedGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// ReadFromFileButton
			// 
			this->ReadFromFileButton->Location = System::Drawing::Point(13, 337);
			this->ReadFromFileButton->Name = L"ReadFromFileButton";
			this->ReadFromFileButton->Size = System::Drawing::Size(159, 37);
			this->ReadFromFileButton->TabIndex = 0;
			this->ReadFromFileButton->Text = L"Ανάγνωση από αρχείο";
			this->ReadFromFileButton->UseCompatibleTextRendering = true;
			this->ReadFromFileButton->UseVisualStyleBackColor = true;
			this->ReadFromFileButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// TransferButton
			// 
			this->TransferButton->Enabled = false;
			this->TransferButton->Location = System::Drawing::Point(553, 127);
			this->TransferButton->Name = L"TransferButton";
			this->TransferButton->Size = System::Drawing::Size(54, 23);
			this->TransferButton->TabIndex = 3;
			this->TransferButton->Text = L">";
			this->TransferButton->UseVisualStyleBackColor = true;
			this->TransferButton->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// TransferAllButton
			// 
			this->TransferAllButton->Enabled = false;
			this->TransferAllButton->Location = System::Drawing::Point(553, 172);
			this->TransferAllButton->Name = L"TransferAllButton";
			this->TransferAllButton->Size = System::Drawing::Size(54, 23);
			this->TransferAllButton->TabIndex = 4;
			this->TransferAllButton->Text = L">>";
			this->TransferAllButton->UseVisualStyleBackColor = true;
			this->TransferAllButton->Click += gcnew System::EventHandler(this, &Form1::TransferAll_Click);
			// 
			// BackTransferButton
			// 
			this->BackTransferButton->Enabled = false;
			this->BackTransferButton->Location = System::Drawing::Point(553, 244);
			this->BackTransferButton->Name = L"BackTransferButton";
			this->BackTransferButton->Size = System::Drawing::Size(54, 23);
			this->BackTransferButton->TabIndex = 5;
			this->BackTransferButton->Text = L"<";
			this->BackTransferButton->UseVisualStyleBackColor = true;
			this->BackTransferButton->Click += gcnew System::EventHandler(this, &Form1::BackTransfer_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Enabled = false;
			this->SaveButton->Location = System::Drawing::Point(599, 337);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(157, 37);
			this->SaveButton->TabIndex = 6;
			this->SaveButton->Text = L"Αποθήκευση";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &Form1::NextButton_Click);
			// 
			// InputDataGrid
			// 
			this->InputDataGrid->AllowUserToAddRows = false;
			this->InputDataGrid->AllowUserToDeleteRows = false;
			this->InputDataGrid->AllowUserToOrderColumns = true;
			this->InputDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->InputDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Arithmos, 
				this->iProviderNumber, this->FirstAndLastName, this->Poli, this->TetragonikaMetraDimTelon});
			this->InputDataGrid->Location = System::Drawing::Point(6, 63);
			this->InputDataGrid->Name = L"InputDataGrid";
			this->InputDataGrid->ReadOnly = true;
			this->InputDataGrid->Size = System::Drawing::Size(541, 268);
			this->InputDataGrid->TabIndex = 7;
			this->InputDataGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::InputDataGrid_CellContentClick);
			// 
			// Arithmos
			// 
			this->Arithmos->HeaderText = L"A/A";
			this->Arithmos->Name = L"Arithmos";
			this->Arithmos->ReadOnly = true;
			this->Arithmos->Width = 40;
			// 
			// iProviderNumber
			// 
			this->iProviderNumber->HeaderText = L"Αριθμός Παροχής";
			this->iProviderNumber->Name = L"iProviderNumber";
			this->iProviderNumber->ReadOnly = true;
			// 
			// FirstAndLastName
			// 
			this->FirstAndLastName->HeaderText = L"Ονοματεπώνυμο";
			this->FirstAndLastName->Name = L"FirstAndLastName";
			this->FirstAndLastName->ReadOnly = true;
			this->FirstAndLastName->Width = 180;
			// 
			// Poli
			// 
			this->Poli->HeaderText = L"Πόλη";
			this->Poli->Name = L"Poli";
			this->Poli->ReadOnly = true;
			// 
			// TetragonikaMetraDimTelon
			// 
			this->TetragonikaMetraDimTelon->HeaderText = L"m2 Δημ. Τελών";
			this->TetragonikaMetraDimTelon->Name = L"TetragonikaMetraDimTelon";
			this->TetragonikaMetraDimTelon->ReadOnly = true;
			this->TetragonikaMetraDimTelon->Width = 80;
			// 
			// OutputGridView
			// 
			this->OutputGridView->AllowUserToAddRows = false;
			this->OutputGridView->AllowUserToDeleteRows = false;
			this->OutputGridView->AllowUserToOrderColumns = true;
			this->OutputGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OutputGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxAithmos, 
				this->ProviderNumber, this->dataGridViewTextBoxName, this->dataGridViewTextBoxPoli, this->dataGridViewTextBoxMetra});
			this->OutputGridView->Location = System::Drawing::Point(618, 63);
			this->OutputGridView->Name = L"OutputGridView";
			this->OutputGridView->ReadOnly = true;
			this->OutputGridView->Size = System::Drawing::Size(538, 268);
			this->OutputGridView->TabIndex = 8;
			// 
			// dataGridViewTextBoxAithmos
			// 
			this->dataGridViewTextBoxAithmos->HeaderText = L"A/A";
			this->dataGridViewTextBoxAithmos->Name = L"dataGridViewTextBoxAithmos";
			this->dataGridViewTextBoxAithmos->ReadOnly = true;
			this->dataGridViewTextBoxAithmos->Width = 40;
			// 
			// ProviderNumber
			// 
			this->ProviderNumber->HeaderText = L"Αριθμός Παροχής";
			this->ProviderNumber->Name = L"ProviderNumber";
			this->ProviderNumber->ReadOnly = true;
			// 
			// dataGridViewTextBoxName
			// 
			this->dataGridViewTextBoxName->HeaderText = L"Ονοματεπώνυμο";
			this->dataGridViewTextBoxName->Name = L"dataGridViewTextBoxName";
			this->dataGridViewTextBoxName->ReadOnly = true;
			this->dataGridViewTextBoxName->Width = 180;
			// 
			// dataGridViewTextBoxPoli
			// 
			this->dataGridViewTextBoxPoli->HeaderText = L"Πόλη";
			this->dataGridViewTextBoxPoli->Name = L"dataGridViewTextBoxPoli";
			this->dataGridViewTextBoxPoli->ReadOnly = true;
			// 
			// dataGridViewTextBoxMetra
			// 
			this->dataGridViewTextBoxMetra->HeaderText = L"m2 Δημ. Τελών";
			this->dataGridViewTextBoxMetra->Name = L"dataGridViewTextBoxMetra";
			this->dataGridViewTextBoxMetra->ReadOnly = true;
			this->dataGridViewTextBoxMetra->Width = 80;
			// 
			// SendtoChangesbutton
			// 
			this->SendtoChangesbutton->Enabled = false;
			this->SendtoChangesbutton->Location = System::Drawing::Point(785, 337);
			this->SendtoChangesbutton->Name = L"SendtoChangesbutton";
			this->SendtoChangesbutton->Size = System::Drawing::Size(194, 37);
			this->SendtoChangesbutton->TabIndex = 9;
			this->SendtoChangesbutton->Text = L"Αποστολή πρός πίνακα μετοβολών";
			this->SendtoChangesbutton->UseVisualStyleBackColor = true;
			this->SendtoChangesbutton->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// ChangedGridView
			// 
			this->ChangedGridView->AllowUserToAddRows = false;
			this->ChangedGridView->AllowUserToOrderColumns = true;
			this->ChangedGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ChangedGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(16) {this->Onomateponimo, 
				this->Periferia, this->Paroxi, this->Diadoxos, this->GrafeioDei, this->MetraTelon, this->MetraForou, this->MetraTap, this->PosoAnadrXreosis, 
				this->DoseisAnadromikesDT, this->PosoAnadrXreosisTap, this->PlithosDoseonAnadrTAP, this->EtosAdeias, this->KodikosZonisTap, this->DeiktisXreosisXrisisTAP, 
				this->KodikosDimou});
			this->ChangedGridView->Location = System::Drawing::Point(13, 413);
			this->ChangedGridView->Name = L"ChangedGridView";
			this->ChangedGridView->Size = System::Drawing::Size(966, 208);
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
			// SaveChangesbutton
			// 
			this->SaveChangesbutton->Enabled = false;
			this->SaveChangesbutton->Location = System::Drawing::Point(52, 627);
			this->SaveChangesbutton->Name = L"SaveChangesbutton";
			this->SaveChangesbutton->Size = System::Drawing::Size(157, 38);
			this->SaveChangesbutton->TabIndex = 11;
			this->SaveChangesbutton->Text = L"Αποθήκευση";
			this->SaveChangesbutton->UseVisualStyleBackColor = true;
			this->SaveChangesbutton->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// InputFromFilebutton
			// 
			this->InputFromFilebutton->Location = System::Drawing::Point(286, 627);
			this->InputFromFilebutton->Name = L"InputFromFilebutton";
			this->InputFromFilebutton->Size = System::Drawing::Size(163, 38);
			this->InputFromFilebutton->TabIndex = 12;
			this->InputFromFilebutton->Text = L"Εισαγωγή από αρχείο";
			this->InputFromFilebutton->UseVisualStyleBackColor = true;
			this->InputFromFilebutton->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// MakeReportButton
			// 
			this->MakeReportButton->Enabled = false;
			this->MakeReportButton->Location = System::Drawing::Point(785, 629);
			this->MakeReportButton->Name = L"MakeReportButton";
			this->MakeReportButton->Size = System::Drawing::Size(141, 36);
			this->MakeReportButton->TabIndex = 14;
			this->MakeReportButton->Text = L"Δημιουργεία αναφοράς";
			this->MakeReportButton->UseVisualStyleBackColor = true;
			this->MakeReportButton->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Αρχικό αρχείο ΔΕΗ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(599, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Πίνακας Αλλαγών  ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 397);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Πίνακας Μεταβολών";
			// 
			// SearchBox
			// 
			this->SearchBox->Location = System::Drawing::Point(231, 342);
			this->SearchBox->Name = L"SearchBox";
			this->SearchBox->Size = System::Drawing::Size(218, 20);
			this->SearchBox->TabIndex = 19;
			// 
			// Serachbutton
			// 
			this->Serachbutton->Location = System::Drawing::Point(464, 340);
			this->Serachbutton->Name = L"Serachbutton";
			this->Serachbutton->Size = System::Drawing::Size(96, 22);
			this->Serachbutton->TabIndex = 20;
			this->Serachbutton->Text = L"Εύρεση ονο/μο";
			this->Serachbutton->UseVisualStyleBackColor = true;
			this->Serachbutton->Click += gcnew System::EventHandler(this, &Form1::SeearchButtonClick);
			// 
			// labelMunicipality
			// 
			this->labelMunicipality->AutoSize = true;
			this->labelMunicipality->Location = System::Drawing::Point(4, 692);
			this->labelMunicipality->Name = L"labelMunicipality";
			this->labelMunicipality->Size = System::Drawing::Size(791, 13);
			this->labelMunicipality->TabIndex = 15;
			this->labelMunicipality->Text = L"Η εφαρμογή αυτή είναι open source και μπορεί να αντιγραφεί να τροποποιηθεί και να" 
				L" διανεμηθεί ελεύθερα copyfree Λάμπρου Λευτέρης (lef27064@otenet.gr)";
			// 
			// buttonSearchProvider
			// 
			this->buttonSearchProvider->Location = System::Drawing::Point(464, 366);
			this->buttonSearchProvider->Name = L"buttonSearchProvider";
			this->buttonSearchProvider->Size = System::Drawing::Size(96, 22);
			this->buttonSearchProvider->TabIndex = 23;
			this->buttonSearchProvider->Text = L"Εύρεση Παροχή";
			this->buttonSearchProvider->UseVisualStyleBackColor = true;
			this->buttonSearchProvider->Click += gcnew System::EventHandler(this, &Form1::buttonSearchProvider_Click);
			// 
			// textBoxProvider
			// 
			this->textBoxProvider->Location = System::Drawing::Point(231, 368);
			this->textBoxProvider->Name = L"textBoxProvider";
			this->textBoxProvider->Size = System::Drawing::Size(218, 20);
			this->textBoxProvider->TabIndex = 22;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"File Name";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1168, 765);
			this->Controls->Add(this->buttonSearchProvider);
			this->Controls->Add(this->textBoxProvider);
			this->Controls->Add(this->Serachbutton);
			this->Controls->Add(this->SearchBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelMunicipality);
			this->Controls->Add(this->MakeReportButton);
			this->Controls->Add(this->InputFromFilebutton);
			this->Controls->Add(this->SaveChangesbutton);
			this->Controls->Add(this->ChangedGridView);
			this->Controls->Add(this->SendtoChangesbutton);
			this->Controls->Add(this->OutputGridView);
			this->Controls->Add(this->InputDataGrid);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->BackTransferButton);
			this->Controls->Add(this->TransferAllButton);
			this->Controls->Add(this->TransferButton);
			this->Controls->Add(this->ReadFromFileButton);
			this->Name = L"Form1";
			this->Text = L"ΕΦΑΡΜΟΓΗ ΔΙΟΡΘΩΣΗΣ ΔΗΜΟΤΙΚΩΝ ΤΕΛΩΝ  v 0.2 - 16/12/2011";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OutputGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ChangedGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: void ClearDataGrids(void)
			 {
			 this->InputDataGrid->SelectAll();
			 this->InputDataGrid->Rows->Clear();
			 this->InputDataGrid->Refresh();
			 this->OutputGridView->SelectAll();
			 this->OutputGridView->Rows->Clear();
			 this->OutputGridView->Refresh();
			/* this->ChangedGridView->SelectAll();
			 this->ChangedGridView->Rows->Clear();
			 this->ChangedGridView->Refresh();*/

			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 System::Windows::Forms::DialogResult answer;
				 if (this->InputDataGrid->RowCount>1)
				   answer =	 System::Windows::Forms::MessageBox::Show("Προσοχή τα υπαρχοντα δεδομένα θα καταστραφούν. Θέλετε να συνεχίσετε? ","Διαγραφή υπαρχόντων δεδομένων",System::Windows::Forms::MessageBoxButtons::YesNo);
				 if ((answer == System::Windows::Forms::DialogResult::Yes) || (answer == System::Windows::Forms::DialogResult::None)){

				 dei = gcnew Dei(100000);
				 answer = this->openFileDialog->ShowDialog(); // == System::Windows::Forms::DialogResult::OK
				 if (answer != System::Windows::Forms::DialogResult::Cancel)
				 {
					 if (this->openFileDialog->FileName->Length>0)
					 { 
						 ClearDataGrids();
						 if (dei->ReadFromFile(this->openFileDialog->FileName)>-1)
						 {
							UpdateInputGrid();
							this->TransferButton->Enabled=true;
							 this->TransferAllButton->Enabled=true;
							 this->BackTransferButton->Enabled=false;
							 this->SaveButton->Enabled=false;
							 this->SendtoChangesbutton->Enabled=false;
							 this->SaveChangesbutton->Enabled=false;
							 this->MakeReportButton->Enabled=false;
						 }
						 else
						 {
							 this->TransferButton->Enabled=false;
							 this->TransferAllButton->Enabled=false;

						 }
					 }
				 }

				 }
			 }
			

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->CopyOutPutGrid();
			 this->SaveButton->Enabled=true;
			 this->BackTransferButton->Enabled=true;
			 this->SendtoChangesbutton->Enabled=true;
		 }

private: void UpdateInputGrid()
		 {
			 int i;
			 for (i=1;i<dei->TotalInputRecords;i++)
			 {
				 this->InputDataGrid->Rows->Add();
				 this->InputDataGrid->Rows[i-1]->Cells[0]->Value=dei->Input[i].AfxonArithmos;			 
				 this->InputDataGrid->Rows[i-1]->Cells[1]->Value=dei->Input[i].Paroxi;	
				 this->InputDataGrid->Rows[i-1]->Cells[2]->Value=dei->Input[i].Onomateponimo;
				 this->InputDataGrid->Rows[i-1]->Cells[3]->Value=dei->Input[i].Poli;
				 this->InputDataGrid->Rows[i-1]->Cells[4]->Value=dei->Input[i].TetragonikaMetraDimForou;

			 }

		 }


		 private: void CopyRecord(int i)
				  {
				   this->OutputGridView->Rows->Add();
				   int j = this->OutputGridView->Rows->Count-1;
				   dei->AddChangesRecord(static_cast <int> (this->InputDataGrid->Rows[i]->Cells[0]->Value));
				   OutputGridView->Rows[j]->Cells[0]->Value=this->InputDataGrid->Rows[i]->Cells[0]->Value;			 
				   OutputGridView->Rows[j]->Cells[1]->Value=this->InputDataGrid->Rows[i]->Cells[1]->Value;
				   OutputGridView->Rows[j]->Cells[2]->Value=this->InputDataGrid->Rows[i]->Cells[2]->Value;
				   OutputGridView->Rows[j]->Cells[3]->Value=this->InputDataGrid->Rows[i]->Cells[3]->Value;
	   			   this->InputDataGrid->Rows->RemoveAt(i);
				  }

		private: void CopySelectedRecords(void)
				 {
	            //      if (this->InputDataGrid->SelectedRows->Count==this->InputDataGrid->RowCount)
				//		  this->InputDataGrid->Rows[this->InputDataGrid->Rows->Count-1]->Selected=false;

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


private: System::Void InputDataGrid_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
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
			if (this->OutputGridView->Rows->Count==0)
			{
				this->SaveButton->Enabled=false;
				this->BackTransferButton->Enabled=false;
				this->SendtoChangesbutton->Enabled=false;
			}

		 }

private: System::Void TransferAll_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
		 	 this->InputDataGrid->SelectAll();
			// this->InputDataGrid->Rows[this->InputDataGrid->Rows->Count-1]->Selected=false;
			 this->CopySelectedRecords();
			 this->SaveButton->Enabled=true;
			 this->BackTransferButton->Enabled=true;
			 this->SendtoChangesbutton->Enabled=true;
		
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




private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {
			int i;
			int count=this->ChangedGridView->Rows->Count;
			if (this->OutputGridView->Rows->Count>0)
			{
				this->MakeReportButton->Enabled=true;
				this->SaveChangesbutton->Enabled=true;
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
				this->ChangedGridView->Rows[i+count]->Cells[10]->Value = zero.ToString("0000000");;
			    this->ChangedGridView->Rows[i+count]->Cells[11]->Value =zero.ToString("00");
				this->ChangedGridView->Rows[i+count]->Cells[12]->Value =this->dei->Changes[i].EtosAdeias;
				this->ChangedGridView->Rows[i+count]->Cells[13]->Value =this->dei->Changes[i].KodikosZonisTap;
				this->ChangedGridView->Rows[i+count]->Cells[14]->Value =this->dei->Changes[i].DiktisXreosisXrisisTap;
				this->ChangedGridView->Rows[i+count]->Cells[15]->Value =this->dei->Changes[i].KodikosDimou;
			 }
			}
		 }

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
						
		}		
	
	}
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία αποθήκευσης στο αρχείο","Λάθος");
			return -1;
		}
		//finally{sw->Close();}

		sw->Close();
		System::Windows::Forms::MessageBox::Show("Επιτυχής Αποθήκευση Αρχείου");
return 0;
}

private: System::String^ FormatNumber(System::String^ in)
		 { 
			 System::String^ out;
			 out=in->Replace(" ","0");
			 return out;
		 }

private: System::String^ AddZerosToNumber(System::String^ in,int TotalLength)
		 { 
			 System::String^ out;
			 for (int i=0;i<TotalLength-in->Length;i++)
				 out=out+"0";
			 out=out+in;
			 return out;
		 }


private: int LoadChanges(System::String^ FileName)
		 {	

			 
			 int i=0;
			 StreamReader^ sr;
			 FileStream^ fs;
			 this->ClearDataGrids();
			 
			 try 
			 {
				 
				 fs= gcnew FileStream(FileName,System::IO::FileMode::Open);
				 sr = gcnew StreamReader(fs,System::Text::Encoding::UTF8);
		  	 			  
				while  (!sr->EndOfStream)
				{
					this->ChangedGridView->Rows->Add();
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
						 i++;
						
				}		
			 }
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία ανάγνωσης από αρχείο","Λάθος");
			return -1;
			this->TransferAllButton->Enabled=false;
			this->TransferButton->Enabled=false;
		}

		sr->Close();
		System::Windows::Forms::MessageBox::Show("Επιτυχής ανάγνωση Αρχείου");

return 0;
}





private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {
			 System::Windows::Forms::DialogResult result=this->saveFileDialog->ShowDialog(); 
			 if (result!=System::Windows::Forms::DialogResult::Cancel)
				this->SaveChanges(this->saveFileDialog->FileName);
		 }



		 
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->ClearDataGrids();
			 System::Windows::Forms::DialogResult result = this->openFileDialog->ShowDialog();
			 if (result!=System::Windows::Forms::DialogResult::Cancel)
			 {
				 if (this->LoadChanges(this->openFileDialog->FileName)>-1)
				    this->MakeReportButton->Enabled=true;
				 
			 }



		 }

private: bool IsFromSingleRegion(void)
		 {
			 String^ original = this->ChangedGridView->Rows[0]->Cells[15]->Value->ToString();
			 for (int i=1; i<this->ChangedGridView->Rows->Count; i++)
			 {
				 String^ region = this->ChangedGridView->Rows[i]->Cells[15]->Value->ToString();
				 if (!(original->CompareTo(region)==0))
					 return false;
			 }
			 return true;
	    }


private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (IsFromSingleRegion())
			 {
				 System::Windows::Forms::DialogResult result= this->saveFileDialog->ShowDialog(); 
				 if (result !=System::Windows::Forms::DialogResult::Cancel)
				 {
					 if  (this->saveFileDialog->FileName->Length>0)
						 this->SaveReport(this->saveFileDialog->FileName);
					else
						System::Windows::Forms::MessageBox::Show("Παρακαλώ δώστε ένα όνομα αρχείου και ξαναπροσπαθήστε");
			     }
			 }
			 else
				 System::Windows::Forms::MessageBox::Show("Οι μεταβολές δεν είναι απο μία περιοχή παρακαλώ διορθώστε"); 
		 
		 }


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
				 sw->WriteLine("{0,2}{1,2}{2,2}{3,2}{4,54}", "01",System::DateTime::Now.Day.ToString(),System::DateTime::Now.Month.ToString(),System::DateTime::Now.Year.ToString(), "000000000000000000000000000000000000000000000000000000");
				 for (i=0;i<this->ChangedGridView->Rows->Count;i++)
				 {
                    
					 sw->WriteLine("{0,1}{1,8}{2,2}{3,2}{4,7}{5,7}{6,7}{7,7}{8,2}{9,7}{10,2}{11,4}{12,3}{13,1}{14,4}",
						this->ChangedGridView->Rows[i]->Cells[1]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[2]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[3]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[4]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[5]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[6]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[7]->Value->ToString(),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[8]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[9]->Value->ToString(),2),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[10]->Value->ToString(),7),
						this->AddZerosToNumber(this->ChangedGridView->Rows[i]->Cells[11]->Value->ToString(),2),
						this->ChangedGridView->Rows[i]->Cells[12]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[13]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[14]->Value->ToString(),
						this->ChangedGridView->Rows[i]->Cells[15]->Value->ToString());
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
		 }


private: System::Void SeearchButtonClick(System::Object^  sender, System::EventArgs^  e) {
			 int count;
			 if (this->InputDataGrid->CurrentRow)
				  count=this->InputDataGrid->CurrentRow->Index+1;
			 else 
				 return;

			 bool found =false;
			 
			 if ((this->SearchBox->Text->Length>0) && (this->InputDataGrid->Rows->Count>1))
			 {
				 do {
					 if (this->InputDataGrid->Rows[count]->Cells[2]->Value->ToString()->Substring(0,this->SearchBox->Text->Length)==this->SearchBox->Text)
						 found =true;
					 else
						 count++;
				 }while ((count<=this->InputDataGrid->Rows->Count-1) && (found==false));
			 }
			 if (found ==true)
			 {
				 this->InputDataGrid->FirstDisplayedScrollingRowIndex = this->InputDataGrid->Rows[count]->Index;
				 this->InputDataGrid->Refresh();
				 this->InputDataGrid->CurrentCell = this->InputDataGrid->Rows[count]->Cells[1];
				 this->InputDataGrid->Rows[count]->Selected = true;
				// this->InputDataGrid->CurrentRow=count;
			 }				
			 else
				this->InputDataGrid->Rows[0]->Selected;

		 }

private: System::Void buttonSearchProvider_Click(System::Object^  sender, System::EventArgs^  e) {
			 int count=this->InputDataGrid->CurrentRow->Index+1;
			 bool found =false;
			 
			 if ((this->textBoxProvider->Text->Length>0) && (this->InputDataGrid->Rows->Count>1))
			 {
				 do {
					 if (this->InputDataGrid->Rows[count]->Cells[1]->Value->ToString()->Substring(0,this->textBoxProvider->Text->Length)==this->textBoxProvider->Text)
						 found =true;
					 else
						 count++;
				 }while ((count<=this->InputDataGrid->Rows->Count-1) && (found==false));
			 }
			 if (found ==true)
			 {
				 this->InputDataGrid->FirstDisplayedScrollingRowIndex = this->InputDataGrid->Rows[count]->Index;
				 this->InputDataGrid->Refresh();
				 this->InputDataGrid->CurrentCell = this->InputDataGrid->Rows[count]->Cells[2];
				 this->InputDataGrid->Rows[count]->Selected = true;
				// this->InputDataGrid->CurrentRow=count;
			 }				
			 else
				this->InputDataGrid->Rows[0]->Selected;
		 }

};
};