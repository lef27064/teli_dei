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

#using <system.dll>
#using <system.messaging.dll>
#using <System.Runtime.Serialization.Formatters.Soap.dll>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization::Formatters::Soap;



[Serializable]
/*�� ������ ��� ��� �����*/
value struct InputData{
	int AfxonArithmos;
	System::String^ Periferia;							//����������
	System::String^ Paroxi;								//������
	System::String^ Diadoxos;							//��������
	System::String^ Grafeio;							//�������
	System::String^ Onomateponimo;						//�������������
	System::String^ Odos;								//���� 
	System::String^ Arithmos;							//�������
	System::String^ Poli;								//����
	System::String^ TaxKodikas;							//�.�.
	System::String^ KodikosDK;							//������� �.�.
	System::String^ KodikosXreosis;						//������� �������
	System::String^ DiktisXreosis;						//������� �������
	System::String^ KodikosApalagis;					//������� ��������
	System::String^ TetragonikaMetraDimTelon;			//m2 ��������� �����
	System::String^ TetragonikaMetraDimForou;			//m2 ��������� �����
	System::String^ KodikosXreosisTap;					//������� ������� �.�.�.
	System::String^ KodikosZonisTap;					//������� ����� �.�.�.
	System::String^ DiktisXreosisXrisisTap;				//������� ������� ������ �.�.�.
	System::String^ KodikosApalagisTap;					//������� �������� �.�.�.
	System::String^ TetragvnikaMetraTap;				//m2 ����� �.�.�.
	System::String^ EtosAdeias;							//���� ������
	System::String^ Keno;								// --- 
	System::String^ OnomasiaDimou;						//�������� ����� - ����������
	System::String^ KodikosDimou;						//������� �����

};

/*�� ������ ���� �� ����� */
value struct OutputData{
	int AfxonArithmos;									//����� �������
	System::String^ Periferia;							//����������
	System::String^ Paroxi;								//������
	System::String^ Diadoxos;							//��������
	System::String^ Grafeio;							//�������
	System::String^ TetragonikaMetraDimTelon;			//m2 ��������� �����
	System::String^ TetragonikaMetraDimForou;			//m2 ��������� �����
	System::String^ TetragvnikaMetraTap;				//m2 ����� �.�.�.
	System::String^ PosoAnadromikisXreosisDTDF;			//���� ����������� ������� ��-��
	System::String^ PlithosDoseonAnadromikisXreosisDTDF;//������ ������ ����������� ������� ��-��
	System::String^ PosoAnadromikisXreosisTAP;			//���� ����������� ������� �.�.�.
	System::String^ PlithosDoseonAnadromikisXreosisTAP; //������ ������ ����������� ������� �.�.�.
	System::String^ EtosAdeias;							//���� ������					
	System::String^ KodikosZonisTap;					//������� ����� �.�.�.
	System::String^ DiktisXreosisXrisisTap;				//������� ������� ������ �.�.�.
	System::String^ KodikosDimou;						//������� �����
};

/*��������� ��� ������������ ������ �� �������� ���������� ��� ������������ ������ ����� */
value class ResultFromSearch
{
public:
		int Result;										//���������� ����������
		String^ ZoneCode;								//������� �����
		String^ diamerisma;								//�������� ����������

};