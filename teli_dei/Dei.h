/*
Lamprou Eleftherios
lef27064@otenet.gr
Ιστοσελίδα προγράμματος http://sourceforge.net/projects/telidei/
Manual χρήσης εφαρμογής http://sourceforge.net/projects/telidei/files/Documentation/Version%200.1/Help.pdf/download
-------------------------------------------------------------------------------------------------------------------

Creative Commons Attribution/Share-Alike License
Μπορείτε αντιγράψετε, τροποποιήστε,  και να διανείμετε ελεύθερα τον παρών κώδικα με την αναφορά του δημιουργού

*/
#pragma once
#include "Data.h"


#using <system.dll>
#using <system.messaging.dll>
#using <System.Runtime.Serialization.Formatters.Soap.dll>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization::Formatters::Soap;
using namespace System::Xml;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;	

[Serializable]
public ref class SavedDataStruct
{
public:
   List<InputData>^ Data;
   /////
   SavedDataStruct();
   SavedDataStruct(int isize);
};


[Serializable]
public ref class SettingsStruct
{
public:
    System::String^ Region;
	System::String^ Municipality;
	System::String^ UserName;
	System::String^ Telephone;
	int MaxRecords;
	////////
	SettingsStruct();
	SettingsStruct(String^ iRegion,String^ iMunicipality,String^ iUserName,String^ iTelephone,int iMaxRecords);
};

public ref class ClassDei
{
private: 
	   array<InputData,1>^  _Input ;      
	   array<OutputData,1>^  Output;
	   
	   int _TotalInputRecords;
	   int _TotalChangedRecords;
	   int _size;
	   System::String^ checkencoding(System::String^ FileName);
	  
	   
public:
	[System::Xml::Serialization::XmlIgnoreAttribute]
    array<InputData,1>^ Changes;

	[System::Xml::Serialization::XmlIgnoreAttribute]
	property 	int TotalInputRecords
	{					
		int	 get(){return  _TotalInputRecords;}
	}
	[System::Xml::Serialization::XmlIgnoreAttribute]
	property 	int TotalOutputRecords
	{					
		int	 get(){return  _TotalChangedRecords;}
	}
	[System::Xml::Serialization::XmlIgnoreAttribute]
	property 	int size
	{					
		int	 get(){return  _size;}
	}


	[System::Xml::Serialization::XmlIgnoreAttribute]
	
	property 	array<InputData,1>^ Input 
	{					
		array<InputData,1>^	 get(){return  _Input;}
	}
	
	[System::Xml::Serialization::XmlIgnoreAttribute]
	SettingsStruct^ Settings;                        	//Serialize Region, Municipality, UserName, Telephone, MaxRecords

	[System::Xml::Serialization::XmlIgnoreAttribute]
	SavedDataStruct^ SavedData;
	
	
	ClassDei(int size);
	ClassDei(void);
	int ReadFromFile(System::String^ FileName);
	int SaveToFile(System::String^ FileName);

	void AddChangesRecord(int which);
	void RemoveChangesRecord(int which);
    void ClearData(void);
	void ReadFromBinaryData(void);
	void SaveToBinaryData(void);
	void UpdateTotalInputRecords(int UpdateValue);
	void UpdateInputRecord(int which, InputData inputRec);
	//Settings
	void ReadSettings(ClassDei^ SettingsDei,String^ FileName);
	void ReadSettings(ClassDei^ SettingsDei);
	void ReadSettings(String^ FileName);
	void ReadSettings();

	void SaveSettings(SettingsStruct^ SettingsDei, String^ FileName);
	void SaveSettings(SettingsStruct^ SettingsDei);
	void SaveSettings(void);

	void UpdateSettings(void);
	void DefaultSettings(String^ Region, String^ Municipality, String^ UserName, String^ Telephone, int MaxRecords);
	void DefaultSettings();
	//Data
	void ReadData(ClassDei^ DataDei, String^ FileName);
	void ReadData(ClassDei^ DataDei);
	void ReadData(void);

	void SaveData(ClassDei^ DataDei, String^ FileName);
	void SaveData(ClassDei^ DataDei);
	void SaveData(void);





};

