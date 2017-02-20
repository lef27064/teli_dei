/*
Lamprou Eleftherios
lef27064@otenet.gr
���������� ������������ http://sourceforge.net/projects/telidei/
Manual ������ ��������� http://sourceforge.net/projects/telidei/files/Documentation/Version%200.1/Help.pdf/download
-------------------------------------------------------------------------------------------------------------------

Creative Commons Attribution/Share-Alike License
�������� �����������, ������������,  ��� �� ���������� �������� ��� ����� ������ �� ��� ������� ��� ����������

*/
/* �� ������ ��� ��� */
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

/*�� ������ ���� �� �.�.�.*/
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

value class ResultFromSearch
{
public:
		int Result;
		String^ ZoneCode;
		String^ diamerisma; 

};