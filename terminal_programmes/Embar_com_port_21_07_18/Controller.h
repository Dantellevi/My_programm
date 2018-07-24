//---------------------------------------------------------------------------

#ifndef ControllerH
#define ControllerH

#include <AdPort.hpp>

//------------------------------------------------------
// #define Low_ tpLower          // ������� ��������� ������
// #define High_  tpTimeCritical         // ������� ��������� ������

// ������� �������� �������
			#define �� 7
			#define ��� 9

		 /// ���������� ������
			#define �I   4
			#define �II  3

class TPotokControl : public TThread
{

protected:
	void __fastcall Execute();
	void __fastcall Work();


public:
		bool IntControl, IntControlOtvetka;

		unsigned __int64	AllPocketCountForControl;
		
		
	__fastcall TPotokControl(bool CreateSuspended);

	void Process(void);

	 void  Otvetka(void);

	 TApdComPort *ApdComPortPotok;



	 ///// ������� ��� ������ ������ �� ������ / ��������� ���������� ����� ���� � ��� ��������������� ��������
	  void DigitalOutSet (int NumberBit, bool Uroven);
	  bool DigitalOutRead  (int NumberBit);

	  //// ������� ����� ��� �������� ������ � �������
	  AnsiString MassStrDOut[12];    // �������� ������
	  AnsiString MassStrDIn[8];      // �������� �����

	   AnsiString MassStrAIn[12];    // ���������� �����
       AnsiString MassStrAOut[8];    // ���������� ������


};
//---------------------------------------------------------------------------
#endif
