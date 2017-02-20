/*
Lamprou Eleftherios
lef27064@otenet.gr
Ιστοσελίδα προγράμματος http://sourceforge.net/projects/telidei/
Manual χρήσης εφαρμογής http://sourceforge.net/projects/telidei/files/Documentation/Version%200.1/Help.pdf/download
-------------------------------------------------------------------------------------------------------------------

Creative Commons Attribution/Share-Alike License
Μπορείτε αντιγράψετε, τροποποιήστε,  και να διανείμετε ελεύθερα τον παρών κώδικα με την αναφορά του δημιουργού

*/

// teli_dei.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace teli_dei;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
