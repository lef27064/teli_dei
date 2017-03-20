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

#using <system.dll>
#using <system.messaging.dll>
#using <System.Runtime.Serialization.Formatters.Soap.dll>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization::Formatters::Soap;



[Serializable]
/*Το αρχείο από την ΔΕΔΗΕ*/
value struct InputData{
	int AfxonArithmos;
	System::String^ Periferia;							//Περιφέρεια
	System::String^ Paroxi;								//Παροχή
	System::String^ Diadoxos;							//Διαδοχος
	System::String^ Grafeio;							//Γραφείο
	System::String^ Onomateponimo;						//Ονοματεπώνυμο
	System::String^ Odos;								//Οδός 
	System::String^ Arithmos;							//Αριθμός
	System::String^ Poli;								//Πόλη
	System::String^ TaxKodikas;							//Τ.Κ.
	System::String^ KodikosDK;							//Κωδικός Δ.Κ.
	System::String^ KodikosXreosis;						//Κωδικός Χρέωσης
	System::String^ DiktisXreosis;						//Δείκτης Χρέωσης
	System::String^ KodikosApalagis;					//Κωδικός Απαλαγής
	System::String^ TetragonikaMetraDimTelon;			//m2 Δημοτικών τελών
	System::String^ TetragonikaMetraDimForou;			//m2 Δημοτικού φόρου
	System::String^ KodikosXreosisTap;					//Κωδικός χρέωσης Τ.Α.Π.
	System::String^ KodikosZonisTap;					//Κωδικός Ζώνης Τ.Α.Π.
	System::String^ DiktisXreosisXrisisTap;				//Δείκτης χρέωσης χρήσης Τ.Α.Π.
	System::String^ KodikosApalagisTap;					//Κωδικός απαλαγής Τ.Α.Π.
	System::String^ TetragvnikaMetraTap;				//m2 μέτρα Τ.Α.Π.
	System::String^ EtosAdeias;							//Ετος Αδειας
	System::String^ Keno;								// --- 
	System::String^ OnomasiaDimou;						//Ονομασία Δήμου - Κοινότητας
	System::String^ KodikosDimou;						//Κωδικός Δήμου

};

/*Το αρχείο πρός τη ΔΕΔΗΕ */
value struct OutputData{
	int AfxonArithmos;									//Αυξων Αριθμός
	System::String^ Periferia;							//Περιφέρεια
	System::String^ Paroxi;								//Παροχή
	System::String^ Diadoxos;							//Διαδοχος
	System::String^ Grafeio;							//Γραφείο
	System::String^ TetragonikaMetraDimTelon;			//m2 Δημοτικών τελών
	System::String^ TetragonikaMetraDimForou;			//m2 Δημοτικού φόρου
	System::String^ TetragvnikaMetraTap;				//m2 μέτρα Τ.Α.Π.
	System::String^ PosoAnadromikisXreosisDTDF;			//Ποσό αναδρομικής χρέωσης ΔΤ-ΔΦ
	System::String^ PlithosDoseonAnadromikisXreosisDTDF;//Πλήθος δόσεων αναδρομικής χρέωσης ΔΤ-ΔΦ
	System::String^ PosoAnadromikisXreosisTAP;			//Ποσό αναδρομικής χρέωσης Τ.Α.Π.
	System::String^ PlithosDoseonAnadromikisXreosisTAP; //Πλήθος δόσεων αναδρομικής χρέωσης Τ.Α.Π.
	System::String^ EtosAdeias;							//Ετος Αδειας					
	System::String^ KodikosZonisTap;					//Κωδικός Ζώνης Τ.Α.Π.
	System::String^ DiktisXreosisXrisisTap;				//Δείκτης χρέωσης χρήσης Τ.Α.Π.
	System::String^ KodikosDimou;						//Κωδικός Δήμου
};

/*Αναζήτηση για συγκεκριμένη παροχή σε δημοτικό διαμέρισμα και συγκεκριμένο κωδικό ζώνης */
value class ResultFromSearch
{
public:
		int Result;										//Αποτέλεσμα αναζήτησης
		String^ ZoneCode;								//Κωδικός Ζώνης
		String^ diamerisma;								//Δημοτικό Διαμέρισμα

};