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
//	�� ��������� teli_dei, ���� ����� ��� ���������� �������� ���� ��� �����, �� ����� ��� ����������� �������� ��� ����� ��� ��� ������� ��������� ����� ����� (�������� ����, �������� ����, ���). �� ��������� ���� ��� ���������� ��������� ��� ���������� ������� ��� �����, ����������� ����������� �������� (� �������) ��� ����������� �������� ������� �� �� ������� ��� ����� (���������� ������� ��� ������� ���� (������� � CD) ��� ��� ������� ��� ��� ������� �/��� ��� ���). �� �������� ������� �� ������������� ��� ����������� ����� ��� ��������� �����, ��������� �����, ��� ��� ���� ����������
//	Copyright (C) 2008-2017  Eleftherios Lamprou
//	����� lef27064@otenet.gr
//	���������� ������������ http://sourceforge.net/projects/telidei/
//	������� ������� (current version) https://github.com/lef27064/teli_dei
//	
//	����� Creative Commons Attribution/Share-Alike License
//	��  ��������� TeliDei, ��������� "�� ����", ����� ��������� ������� �������������� ��� ����������� �����.
//	� �������� ��� ������������� ����������, ��� ��������� ���� �������� ������������ ��� ����� ��������� � ������ ���������, ������� ��� ����� ���. 
//	
//	�������� �����������, ������������,  ��� �� ���������� �������� ��� ����� ������ �� ��� ������� ��� ����������. 

#pragma once

namespace teli_dei {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelAboutText;
	protected: 

	protected: 

	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->labelAboutText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelAboutText
			// 
			this->labelAboutText->AutoSize = true;
			this->labelAboutText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelAboutText->Location = System::Drawing::Point(0, 0);
			this->labelAboutText->Name = L"labelAboutText";
			this->labelAboutText->Size = System::Drawing::Size(523, 364);
			this->labelAboutText->TabIndex = 0;
			this->labelAboutText->Text = resources->GetString(L"labelAboutText.Text");
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(749, 489);
			this->Controls->Add(this->labelAboutText);
			this->Name = L"AboutForm";
			this->Text = L"����";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
