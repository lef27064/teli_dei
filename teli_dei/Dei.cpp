#pragma once

#include "StdAfx.h"
#include "Dei.h"
using namespace ansiToUTF8;

//initialize με μέγεθος 
ClassDei::ClassDei(int size)
{
	  _Input  = gcnew array<InputData,1>(size);
	  Changes= gcnew array<InputData,1>(size);
	  Output = gcnew array<OutputData,1>(size);
	  SavedData = gcnew SavedDataStruct(size);
	  
	  this->_TotalInputRecords=0;
	  this->_TotalChangedRecords=0;
	  this->_size=size;
	  
	  Settings = gcnew SettingsStruct("Ιωαννίνων","Πωγωνίου","Λάμπρου Ελευθέριος","2653360113",size);
	  
}	  
//initialize χωρίς μέγεθος 
ClassDei::ClassDei(void)
{
	   int isize =20000;    //defualt μέγεθος 
	   
	  _Input  = gcnew array<InputData,1>(isize);
	   Changes= gcnew array<InputData,1>(isize);
	   Output = gcnew array<OutputData,1>(isize);
	   SavedData = gcnew SavedDataStruct(isize);

	  
	  Settings = gcnew SettingsStruct("Ιωαννίνων","Πωγωνίου","Λάμπρου Ελευθέριος","2653360113",isize);
	  this->_TotalInputRecords=0;
	  this->_TotalChangedRecords=0;
	  this->_size=isize;
}	  

//Μηδενισμός πινάκων
void ClassDei::ClearData(void)
{
	System::Array::Clear(this->_Input,0,this->_size);
	System::Array::Clear(this->Output,0,this->_size);
	System::Array::Clear(this->Changes,0,this->_size);

}

//Συνάρτηση για να ελέγξει την κωδικοποίηση του αρχείου Filename
System::String^ ClassDei::checkencoding(System::String ^FileName)
{
	System::String^ enc;
	System::IO::FileStream  file(FileName, FileMode::Open, FileAccess::Read, FileShare::Read);
		if (file.CanSeek) 
		{  
			cli::array <unsigned char,1>^  bom=gcnew cli::array <unsigned char,1>(4); 
	
		    file.Read(bom, 0, 4);
			
            if (((bom[0] == 0xef) && (bom[1] == 0xbb) && (bom[2] == 0xbf) || ((bom[0] == 0xff) && (bom[1] == 0xfe)) || ((bom[0] == 0xfe) && (bom[1] == 0xff)) || ((bom[0] == 0) && (bom[1] == 0) && (bom[2] == 0xfe) && (bom[3] == 0xff)))) 
				enc = "Unicode";
				//System::Text::Encoding::Unicode;
          else
		  enc = "ASCII";
			//System::Text::Encoding::ASCII
		  file.Seek(0, System::IO::SeekOrigin::Begin);
		}
		else
			enc = "ASCII";
			//System::Text::Encoding::ASCII
		file.Close();
	return enc;
}


//Ανάγνωση απο το προτότυπο αρχείο της ΔΕΗ
int ClassDei::ReadFromFile(System::String^ FileName)
{
	int i=1;
	StreamReader^ sr;
	FileStream^ fs;
	bool isASCII=false;
	try 
	{

	 System::String^ enc = this->checkencoding(FileName);
     if (enc=="ASCII")
			{
			 	System::String^ r=ansiToUTF8::AnsiToUtf8::readFileAsUtf8(FileName);
				int offset;
				for (i=0;i<r->Length/152;i++)
				{
					offset=i*152;
					this->_Input[i+1].AfxonArithmos =i+1;
					this->_Input[i+1].Periferia = gcnew System::String(r->Substring(0+offset,1));
					this->_Input[i+1].Paroxi= gcnew System::String(r->Substring(1+offset,8));
					this->_Input[i+1].Diadoxos= gcnew System::String(r->Substring(9+offset,2));
					this->_Input[i+1].Grafeio= gcnew System::String(r->Substring(11+offset,2));
					this->_Input[i+1].Onomateponimo= gcnew System::String(r->Substring(13+offset,20));
					this->_Input[i+1].Odos = gcnew System::String(r->Substring(33+offset,20));
					this->_Input[i+1].Arithmos= gcnew System::String(r->Substring(53+offset,6));
					this->_Input[i+1].Poli= gcnew System::String(r->Substring(59+offset,15));
					this->_Input[i+1].TaxKodikas= gcnew System::String(r->Substring(74+offset,5));
					this->_Input[i+1].KodikosDK= gcnew System::String(r->Substring(79+offset,4));
					this->_Input[i+1].KodikosXreosis= gcnew System::String(r->Substring(83+offset,3));
					this->_Input[i+1].DiktisXreosis= gcnew System::String(r->Substring(86+offset,1));
					this->_Input[i+1].KodikosApalagis= gcnew System::String(r->Substring(87+offset,2));
					this->_Input[i+1].TetragonikaMetraDimTelon= gcnew System::String(r->Substring(89+offset,7));
					this->_Input[i+1].TetragonikaMetraDimForou= gcnew System::String(r->Substring(96+offset,7));
					this->_Input[i+1].KodikosXreosisTap= gcnew System::String(r->Substring(103+offset,4));
					this->_Input[i+1].KodikosZonisTap= gcnew System::String(r->Substring(107+offset,3));
					this->_Input[i+1].DiktisXreosisXrisisTap= gcnew System::String(r->Substring(110+offset,1));
					this->_Input[i+1].KodikosApalagisTap= gcnew System::String(r->Substring(111+offset,2));
					this->_Input[i+1].TetragvnikaMetraTap= gcnew System::String(r->Substring(113+offset,7));
					this->_Input[i+1].EtosAdeias= gcnew System::String(r->Substring(120+offset,4));
					this->_Input[i+1].Keno= gcnew System::String(r->Substring(124+offset,2));
					this->_Input[i+1].OnomasiaDimou= gcnew System::String(r->Substring(126+offset,20));
					this->_Input[i+1].KodikosDimou= gcnew System::String(r->Substring(146+offset,4));
				}
				this->_TotalInputRecords =i+1;
			}
	 else 
	{
		fs= gcnew FileStream(FileName,System::IO::FileMode::Open);
		sr = gcnew StreamReader(fs);
		while  (!sr->EndOfStream)
		{
			System::String^ CurrentLine;
		    CurrentLine = sr->ReadLine();
			if (CurrentLine->Length==0)
				break;
			this->_Input[i].AfxonArithmos =i;
			this->_Input[i].Periferia = gcnew System::String(CurrentLine->Substring(0,1));
			this->_Input[i].Paroxi= gcnew System::String(CurrentLine->Substring(1,8));
			this->_Input[i].Diadoxos= gcnew System::String(CurrentLine->Substring(9,2));
			this->_Input[i].Grafeio= gcnew System::String(CurrentLine->Substring(11,2));
			this->_Input[i].Onomateponimo= gcnew System::String(CurrentLine->Substring(13,20));
			this->_Input[i].Odos = gcnew System::String(CurrentLine->Substring(33,20));
			this->_Input[i].Arithmos= gcnew System::String(CurrentLine->Substring(53,6));
			this->_Input[i].Poli= gcnew System::String(CurrentLine->Substring(59,15));
			this->_Input[i].TaxKodikas= gcnew System::String(CurrentLine->Substring(74,5));
			this->_Input[i].KodikosDK= gcnew System::String(CurrentLine->Substring(79,4));
			this->_Input[i].KodikosXreosis= gcnew System::String(CurrentLine->Substring(83,3));
			this->_Input[i].DiktisXreosis= gcnew System::String(CurrentLine->Substring(86,1));
			this->_Input[i].KodikosApalagis= gcnew System::String(CurrentLine->Substring(87,2));
			this->_Input[i].TetragonikaMetraDimTelon= gcnew System::String(CurrentLine->Substring(89,7));
			this->_Input[i].TetragonikaMetraDimForou= gcnew System::String(CurrentLine->Substring(96,7));
			this->_Input[i].KodikosXreosisTap= gcnew System::String(CurrentLine->Substring(103,4));
			this->_Input[i].KodikosZonisTap= gcnew System::String(CurrentLine->Substring(107,3));
			this->_Input[i].DiktisXreosisXrisisTap= gcnew System::String(CurrentLine->Substring(110,1));
			this->_Input[i].KodikosApalagisTap= gcnew System::String(CurrentLine->Substring(111,2));
			this->_Input[i].TetragvnikaMetraTap= gcnew System::String(CurrentLine->Substring(113,7));
			this->_Input[i].EtosAdeias= gcnew System::String(CurrentLine->Substring(120,4));
			this->_Input[i].Keno= gcnew System::String(CurrentLine->Substring(124,2));
			this->_Input[i].OnomasiaDimou= gcnew System::String(CurrentLine->Substring(126,20));
			this->_Input[i].KodikosDimou= gcnew System::String(CurrentLine->Substring(146,4));
			i++;
		}
		this->_TotalInputRecords =i;
		sr->Close();
	}
	}
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία ανάγνωσης από το αρχείο","Λάθος");
			if (sr)
				sr->Close();
			return -1;

		}
return 0;
};


int ClassDei::SaveToFile(System::String^ FileName)
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

		for (i=0;i<this->_TotalChangedRecords+1;i++)
		{
			sw->WriteLine(this->Changes[i].Periferia+
			this->Changes[i].Paroxi+
			this->Changes[i].Diadoxos+
			this->Changes[i].Grafeio+
			this->Changes[i].Onomateponimo+
			this->Changes[i].Odos +
			this->Changes[i].Arithmos+
			this->Changes[i].Poli+
			this->Changes[i].TaxKodikas+
			this->Changes[i].KodikosDK+
			this->Changes[i].KodikosXreosis+
			this->Changes[i].DiktisXreosis+
			this->Changes[i].KodikosApalagis+
			this->Changes[i].TetragonikaMetraDimTelon+
			this->Changes[i].TetragonikaMetraDimForou+
			this->Changes[i].KodikosXreosisTap+
			this->Changes[i].KodikosZonisTap+
			this->Changes[i].DiktisXreosisXrisisTap+
			this->Changes[i].KodikosApalagisTap+
			this->Changes[i].TetragvnikaMetraTap+
			this->Changes[i].EtosAdeias+
			this->Changes[i].Keno+
			this->Changes[i].OnomasiaDimou+
			this->Changes[i].KodikosDimou);
		}		
	
	}
		catch (System::Exception^ pe)
		{
			System::Windows::Forms::MessageBox::Show("Αδυναμία αποθήκευσης στο αρχείο","Λάθος");
			return -1;
		}
		
		sw->Close();
return 0;
}

//
void ClassDei::AddChangesRecord(int which)
{
	int i;
	for (i=0; i< this->TotalInputRecords; i++)
	{
		if (which == this->Changes[i].AfxonArithmos)
		{
			this->Changes[i] = this->Input[which];
			if (this->_TotalInputRecords =0)
				this->_TotalChangedRecords++;
			return;
		}
	}
	this->Changes[this->_TotalChangedRecords] = this->Input[which];
	this->_TotalChangedRecords++;
}


//
void ClassDei::RemoveChangesRecord(int which)
{
	int i;
	int found=-1;
	for (i=0; i < this->TotalInputRecords; i++)
	{
		if (which == this->Changes[i].AfxonArithmos)
		{
			found=i;
			break;
			
		}
	}

	for (i=found; i<this->_TotalChangedRecords-1; i++)
		this->Changes[i]=this->Changes[i+1];

	this->_TotalChangedRecords--;

}

//
void ClassDei::ReadFromBinaryData(void)
{
	for (int i=0; i<SavedData->Data->Count; i++)
		this->_Input[i]=SavedData->Data[i];
	
}

//
void ClassDei::UpdateTotalInputRecords(int UpdateValue)
{
	this->_TotalInputRecords = UpdateValue;
}

//
void ClassDei::UpdateInputRecord(int which, InputData inputRec)
{
	this->_Input[which] = inputRec;
}

//
void ClassDei::SaveToBinaryData(void)
{
	int i;
	SavedData->Data->Clear();
	for (i=0; i<this->_TotalInputRecords; i++)
	{
		SavedData->Data->Add(_Input[i]);
	}
}


void ClassDei::ReadSettings(ClassDei^ SettingsDei,String^ FileName )
{
	
	String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
	String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
	
	XmlSerializer^ serializer = gcnew XmlSerializer( SettingsStruct::typeid );
				   // A FileStream is needed to read the XML document.
	FileStream^ fs = gcnew FileStream( path+"\\"+ FileName,FileMode::Open );
 
				  /* Use the Deserialize method to restore the object's state with data from the XML document. */
	SettingsDei->Settings = dynamic_cast<SettingsStruct^>(serializer->Deserialize( fs ));
	

	fs->Close();
			
}

void ClassDei::ReadSettings()
{
	ReadSettings(this,"settings.xml");
}


void  ClassDei::ReadSettings(String^ FileName)
{
	ReadSettings(this,FileName);
}


void ClassDei::ReadSettings(ClassDei^ SettingsDei)
{
	ReadSettings(SettingsDei,"settings.xml");
}

void ClassDei::UpdateSettings(void)
{
		String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
		String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
		
		XmlSerializer^ serializer = gcnew XmlSerializer(SettingsStruct::typeid );
		TextWriter^ writer = gcnew StreamWriter( path+"\\settings.xml" );
		serializer->Serialize( writer, this->Settings );
		writer->Close();
}

void ClassDei::SaveSettings(SettingsStruct^ SettingsDei, String^ FileName)
{
	String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
	String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
	
	if (!Directory::Exists(path))
				Directory::CreateDirectory(path);  //Δημιουργεία του Directory teli_dei
				
	
	XmlSerializer^ serializer = gcnew XmlSerializer(SettingsStruct::typeid );
	TextWriter^ writer = gcnew StreamWriter( path+"\\"+FileName );
	serializer->Serialize( writer, SettingsDei );
	writer->Close();
}

void ClassDei::SaveSettings(SettingsStruct^ SettingsDei)
{
	this->SaveSettings(SettingsDei,"settings.xml");
}

void ClassDei::SaveSettings(void)
{
	this->SaveSettings(this->Settings,"settings.xml");
}

void ClassDei::DefaultSettings(String^ Region, String^ Municipality, String^ UserName, String^ Telephone, int MaxRecords  )
{
	

	this->Settings->Region = Region;
	this->Settings->Municipality = Municipality;
	this->Settings->UserName = UserName;
	this->Settings->Telephone = Telephone;
	this->Settings->MaxRecords = MaxRecords;

	//
	this->UpdateSettings();
}
	
void ClassDei::DefaultSettings()
{
	
	this->Settings->Region = "";
	this->Settings->Municipality = "Δήμος Πωγωνίου";
	this->Settings->UserName = "Ελευθέριος Λάμπρου";
	this->Settings->Telephone = "26533-60113";
	this->Settings->MaxRecords = 20000;

	//
	this->UpdateSettings();
}


SavedDataStruct::SavedDataStruct(void)
{
	Data = gcnew List<InputData>(100000);
}

SavedDataStruct::SavedDataStruct(int isize)
{
	Data = gcnew List<InputData>(isize);
}


void ClassDei::SaveData(ClassDei^ DataDei, String^ FileName)
{
			 
		String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
		String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
     	if (!Directory::Exists(path)){
			Directory::CreateDirectory(path);}
	

		// Αποθήκευση του τρέχοντος πίνακα για χρήση 
		//SavedDataStruct^ SavedData = gcnew SavedDataStruct;
		FileStream^ fs = gcnew FileStream(path+"\\"+FileName,FileMode::Create);
		BinaryFormatter^ formatter = gcnew BinaryFormatter;
		DataDei->SaveToBinaryData();
		formatter->Serialize( fs, DataDei->SavedData);
		fs->Close();
		
	}

void ClassDei::SaveData(ClassDei^ DataDei)
{
	this->SaveData(DataDei,"data.xml");
}

void ClassDei::SaveData(void)
{
	this->SaveData(this,"data.xml");
}


void ClassDei::ReadData(ClassDei^ DataDei, String^ FileName)
{
			 
		String ^ appDataDir = Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData);
		String ^ path = Path::Combine(appDataDir, L"Teli_Dei");
     	if (!Directory::Exists(path)){
			Directory::CreateDirectory(path);}
	

		// Αποθήκευση του τρέχοντος πίνακα για χρήση 
		//SavedDataStruct^ SavedData = gcnew SavedDataStruct;
		
		FileStream^ fsData = gcnew FileStream( path+"\\"+FileName,FileMode::Open );
		BinaryFormatter^ formatter = gcnew BinaryFormatter;
		DataDei->SavedData= dynamic_cast<SavedDataStruct^>(formatter->Deserialize(fsData));
		fsData->Close();
	
	}

void ClassDei::ReadData(ClassDei^ DataDei)
{
	this->ReadData(DataDei,"data.xml");
}

void ClassDei::ReadData(void)
{
	this->ReadData(this,"data.xml");
}

SettingsStruct::SettingsStruct(void)
{
	Region="Ιωαννίνων";
	Municipality="Πωγωνίου";
	UserName="Λάμπρου Ελευθέριος";
	Telephone="2653360104";
	MaxRecords=20000;
}

SettingsStruct::SettingsStruct(String^ iRegion,String^ iMunicipality,String^ iUserName,String^ iTelephone,int iMaxRecords)
{
	Region=iRegion;
	Municipality=iMunicipality;
	UserName=iUserName;
	Telephone=iTelephone;
	MaxRecords=iMaxRecords;
}
