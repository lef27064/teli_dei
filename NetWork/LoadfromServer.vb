'EN
'   TeliDei 
'	Simple tool to Create reports forPublic Electricity Corporation of Grecce. This tool must be usefull for Municipalities. The tool can read files from P.E.C change fees factors and year of construction and save as proper files for submit to P.E.C
'	Copyright (C) 2008-2017  Eleftherios Lamprou

'	Creative Commons Attribution/Share-Alike License
'   This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by   the Free Software Foundation, either version 3 of the License, or any later version.
'	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
'	You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.

'	contact e-mail lef27064@otenet.gr
'	webpage at source forge http://sourceforge.net/projects/telidei/
'	souce code (current version) https://github.com/lef27064/teli_dei

'GR
'	TeliDei
'	Το λογισμικό teli_dei, έχει στόχο την δημιουργία αναφορών προς την ΔΕΔΗΕ, με στόχο την εξυπηρέτηση στελεχών των Δήμων για την υποβολή μεταβολών Τελών ΔΕΔΗΕ (Δημοτικά Τέλη, Δημοτικό Φόρο, ΤΑΠ). Το πρόγραμμα έχει την δυνατότητα ανάγνωσης του προτώτυπου αρχείου της ΔΕΔΗΕ, επεξεργασία μεμονομένων εγγραφών (ή μαζικών) και δημιουργεία αναφορών σύμφωνα με τα πρότυπα της ΔΕΔΗΕ (Δημιουργία αρχείου για Ψηφιακό Μέσο (Δισκέτα ή CD) για την υποβολή του στο αρμόδιο Δ/νση της ΔΕΗ). Οι εγγραφές μπορούν να τροποποιηθούν στα τετραγωνικά μέτρα των Δημοτικών Τέλων, Δημοτικού Φόρου, ΤΑΠ και έτος κατασκευής
'	Copyright (C) 2008-2017  Eleftherios Lamprou
'	Επαφή lef27064@otenet.gr
'	Ιστοσελίδα προγράμματος http://sourceforge.net/projects/telidei/
'	Πηγαίος κώδικας (current version) https://github.com/lef27064/teli_dei
	
'	Αδεια Creative Commons Attribution/Share-Alike License
'	Το  λογισμικό TeliDei, παρέχεται "ΩΣ ΕΧΕΙ", χωρίς περαιτέρω εγγύηση καταλληλότητας και υποστήριξης αυτού.
'	Η παραγωγή του συγκεκριμένου λογισμικού, δεν αποσκοπεί στην εμπορική εκμετάλλευσή και είναι επιτρεπτή η Δωρεάν Αντιγραφή, Διανομή και Χρήση του. 
'	
'	Μπορείτε αντιγράψετε, τροποποιήστε,  και να διανείμετε ελεύθερα τον παρών κώδικα με την αναφορά του δημιουργού. */

Imports System.IO
Imports System.Data.SqlClient



Public Class SqlServerFunctions
    Dim value As Double = 0
    Private Sub addEmptyElementsToXML(ByRef oDataSet As DataSet)
        For Each oDataTable As DataTable In oDataSet.Tables
            For Each oDataRow As DataRow In oDataTable.Rows
                For j As Integer = 1 To oDataRow.ItemArray.Length - 1
                    If (oDataRow.ItemArray(j).ToString = DBNull.Value.ToString) Then
                        oDataRow.SetField(j, value)
                    End If
                Next
            Next
        Next
    End Sub

    Public Function PingToHost(address As String) As Boolean
        Dim OnlyipAddress As String
        OnlyipAddress = address.Split("\")(0)
        Try
            If My.Computer.Network.Ping(OnlyipAddress) Then
                Return True
            Else
                Return False
            End If
        Catch ex As Exception
            Return False
        End Try
    End Function


    Public Function TableExists(conn As SqlConnection, database As String, name As String) As Boolean
        '    Dim oResult As Object
        '   conn.Open()
        '  Using oQuery As New SqlCommand("SELECT COUNT(*) FROM INFORMATION_SCHEMA.TABLES T WHERE T.TABLE_NAME LIKE @LookupTable", conn)
        'oQuery.Parameters.AddWithValue("@LookupTable", name)
        'oResult = oQuery.ExecuteScalar()
        'End Using
        'Return oResult
        'End Function
        Dim exists As Boolean
        Dim query As String = "Select * from " + name
        Dim command As New SqlCommand(query, conn)
        exists = False
        Try
            command.CommandTimeout = 30
            conn.Open()
            command.ExecuteNonQuery()
            exists = True

        Catch ex As Exception
            exists = False

        Finally
            conn.Close() 'Whether there is error or not. Close the connection.

        End Try
        Return exists
    End Function

    Public Function writeSQLQueryToFileAsXML(ByVal connString As String, ByVal query As String, ByVal filename As String, ByVal xmlRootName As String) As Integer
        '  Dim Reader As SqlDataReader
        Dim conn As New SqlConnection(connString)
        Dim Result As Integer
        Dim adapter As New SqlDataAdapter(query, conn)

        If File.Exists(filename) Then
            File.Delete(filename)
        End If

        Try
            adapter.SelectCommand.CommandTimeout = 30
            conn.Open()

            ' Build the DataSet
            Dim myDs As DataSet = New DataSet
            adapter.Fill(myDs, xmlRootName)
            Dim myFs As FileStream = Nothing

            ' Get a FileStream object
            myFs = New FileStream(filename, FileMode.OpenOrCreate, FileAccess.Write)

            ' Apply the WriteXml method to write an XML document
            addEmptyElementsToXML(myDs)
            myDs.WriteXml(myFs)
            ' It is always good housekeeping to close a file.
            myFs.Close()
            Result = 0
        Catch ex As Exception
            Console.Write("Communication Error with SQL Server." & ex.Message)
            Result = -1
            Console.ReadKey()
        Finally
            conn.Close() 'Whether there is error or not. Close the connection.

        End Try
        Return Result
    End Function


    Public Function RunQuery(ByVal connString As String, ByVal query As String) As DataTable
        '  Dim Reader As SqlDataReader
        Dim connection As New SqlConnection(connString)
        Dim command As New SqlCommand(query, connection)
        Dim dt As DataTable = New DataTable()

        Try
            command.CommandTimeout = 30
            connection.Open()
            Dim reader As SqlDataReader = command.ExecuteReader()

            ' Build the DataSet

            dt.Load(reader)
        Catch ex As Exception
            Debug.Write("Communication Error with SQL Server." & ex.Message)

        Finally
            connection.Close() 'Whether there is error or not. Close the connection.

        End Try
        Return dt
    End Function

    Public Function ButchRunQuery(ByVal connString As String, ByVal query() As String) As Integer()

        Dim connection As New SqlConnection(connString)
        Dim Errors(query.Count + 1) As Integer
        Dim TotalErrors As Integer
        Dim i As Integer
        TotalErrors = 0

        Try
            For i = 0 To query.Length - 1
                Dim command As New SqlCommand(query(i), connection)
                command.CommandTimeout = 30
                connection.Open()
                Dim reader As SqlDataReader = command.ExecuteReader()
                connection.Close() 'Whether there is error or not. Close the connection.
            Next
        Catch ex As Exception
            Debug.Write("Communication Error with SQL Server." & ex.Message)
            Errors(i + 1) = 1
            TotalErrors = TotalErrors + 1
        Finally
            connection.Close() 'Whether there is error or not. Close the connection.
        End Try
        Errors(0) = TotalErrors
        Return Errors
    End Function

End Class
