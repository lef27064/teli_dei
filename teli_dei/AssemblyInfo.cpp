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

#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// General Information about an assembly is controlled through the following
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
//
[assembly:AssemblyTitleAttribute("teli_dei")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("")];
[assembly:AssemblyProductAttribute("teli_dei")];
[assembly:AssemblyCopyrightAttribute("Copyfree Lamprou Eleftherios 2011-2012")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

//
// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version
//      Build Number
//      Revision
//
// You can specify all the value or you can default the Revision and Build Numbers
// by using the '*' as shown below:

[assembly:AssemblyVersionAttribute("1.5.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

[assembly:SecurityPermission(SecurityAction::RequestMinimum, UnmanagedCode = true)];
