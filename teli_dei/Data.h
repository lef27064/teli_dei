/*
Lamprou Eleftherios
lef27064@otenet.gr
Ιστοσελίδα προγράμματος http://sourceforge.net/projects/telidei/
Manual χρήσης εφαρμογής http://sourceforge.net/projects/telidei/files/Documentation/Version%200.1/Help.pdf/download
-------------------------------------------------------------------------------------------------------------------

Creative Commons Attribution/Share-Alike License
Μπορείτε αντιγράψετε, τροποποιήστε,  και να διανείμετε ελεύθερα τον παρών κώδικα με την αναφορά του δημιουργού

*/
/* Το αρχείο της ΔΕΗ */
#using <system.dll>
#using <system.messaging.dll>
#using <System.Runtime.Serialization.Formatters.Soap.dll>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization::Formatters::Soap;



[Serializable]
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

/*Το αρχείο πρός τη Δ.Ε.Η.*/
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

value class ResultFromSearch
{
public:
		int Result;
		String^ ZoneCode;
		String^ diamerisma; 

};