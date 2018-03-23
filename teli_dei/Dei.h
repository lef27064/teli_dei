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

/*Η δομή αυτή αποθηκεύετεαι στον δίσκο με την έξοδο απο το πρόγραμμα και αφορά τα δεδομένα*/

[Serializable]
public ref class SavedDataStruct
{
public:
   List<InputData>^ Data;
   /////
   SavedDataStruct();            //initialize
   SavedDataStruct(int isize);	 //initialize
};


[Serializable]
public ref class SettingsStruct
{
public:
    System::String^ Region;       //Περιοχή
	System::String^ Municipality; //Δήμος
	System::String^ UserName;	  //Ονομα χρήστη (για τις αναφορές)	
	System::String^ Telephone;	  //Τηλέφωνο χρήστη (τηλέφωνο του χρήστη για τις αναφορές)	
	int MaxRecords;
	System::String^ Server;			//Διακομιστής βάσης δεδομένων
	System::String^ ServerDatabase;	//Ονομα Βάσης
	System::String^ ServerUserName;	//Username	
	System::String^ ServerPassword;	//Password	
	////////
	SettingsStruct();			 //	initialize
	SettingsStruct(int iMaxRecords);
	SettingsStruct(String^ iRegion,String^ iMunicipality,String^ iUserName,String^ iTelephone,int iMaxRecords,System::String^ Server,System::String^ ServerDatabase,System::String^ ServerUserName, System::String^ ServerPassword );   // initialize
};

public ref class ClassDei
{
private: 
	   array<InputData,1>^  _Input ;      //Πίνακας 
	   array<OutputData,1>^  Output;	 //	Πίνακας
	   
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
	void DefaultSettings(String^ iRegion,String^ iMunicipality,String^ iUserName,String^ iTelephone,int iMaxRecords, System::String^ iServer,System::String^ iServerDatabase,System::String^ iServerUserName, System::String^ iServerPassword);

	void DefaultSettings();
	
	//Data
	void ReadData(ClassDei^ DataDei, String^ FileName);
	void ReadData(ClassDei^ DataDei);
	void ReadData(void);

	void SaveData(ClassDei^ DataDei, String^ FileName);
	void SaveData(ClassDei^ DataDei);
	void SaveData(void);





};

